/*
**********************************************************************************************************
*                   			FUNCTION PROTOTYPES
*                              
**********************************************************************************************************
*/
	.equ		IRQMODE,0x12
	.equ 		SVCMODE,0x13
	.equ 		NOINT,  0xc0

	.extern 	ucos
	.extern 	IRQStk
	.extern 	SVCStk

	.extern 	OSTaskSwHook
        .extern 	OSRunning

        .extern 	OSTCBCur
        .extern 	OSTCBHighRdy
        .extern 	OSPrioCur
        .extern 	OSPrioHighRdy

        .extern 	OSIntEnter
	.extern 	OSIntExit
	.extern 	OSTimeTick
	.extern 	OSIntNesting

	
	.global		_start
	.global 	OSTickISR
	.global 	OSStartHighRdy
	.global 	OSCtxSw
	.global 	OSIntCtxSw
	.global 	OSTickISR
	.global 	OSCPUSaveSR
        .global 	OSCPURestoreSR

/*
**********************************************************************************************************
*                   			_start       
* note:	1) disable watch dog
*	2) set irq stack (IRQStk defined in test.c)
*	3) set svc stack (SVCStk defined in test.c)
*	4) load irq service routine
*	5) call ucos function (defined in test.c)
*                              
**********************************************************************************************************
*/
	
_start:
	
	ldr 	r0,=0xE2700000			// disable watch dog
	mov 	r1,#0
	str 	r1,[r0]


	msr 	cpsr,#IRQMODE|NOINT		// change to irq mode and disable interrupt
	ldr 	r1,=IRQStk			// set irq stack
	ldr 	r0,=0x3ff0
	add 	r1,r1,r0
	mov 	sp,r1
	
        			
        msr 	cpsr,#SVCMODE|NOINT		// change to svc mode and disable interrupt
	ldr 	r1,=SVCStk			// set svc stack
	ldr 	r0,=0x3ff0
	add 	r1,r1,r0
	mov 	sp,r1
	
		
	ldr 	r0,=OSTickISR			// 将OSTickISR载入IRQ中断向量地址0xD0037418
	ldr 	r1,=0xD0037418
	str 	r0,[r1]
	
	bl 	ucos				
	

/*
**********************************************************************************************************
*                                          START MULTITASKING
*                                       void OSStartHighRdy(void)
*
* Note : OSStartHighRdy() MUST:
*           a) Call OSTaskSwHook() then,
*           b) Set OSRunning to TRUE,
*           c) Switch to the highest priority task.
**********************************************************************************************************
*/

OSStartHighRdy:  

        bl 	OSTaskSwHook             	// Call user defined task switch hook

        ldr 	r4,=OSRunning           	// OSRunning = true
        mov 	r5,#1
        strb 	r5,[r4]

        ldr 	r4,=OSTCBHighRdy        	// Get highest priority task TCB address
        ldr 	r4,[r4]                 	// get stack pointer
        ldr 	sp,[r4]                 	// switch to the new stack

        ldmfd 	sp!,{r4}              		// pop new task''s spsr
        msr 	spsr,r4
        ldmfd 	sp!,{r0-r12,lr,pc}^   		// pop new task''s r0-r12,lr,pc & cpsr


/*
**********************************************************************************************************
*                                PERFORM A CONTEXT SWITCH (From task level)
*                                           void OSCtxSw(void)
*
* Note(s):    Upon entry, 
*             OSTCBCur     points to the OS_TCB of the task to suspend
*             OSTCBHighRdy points to the OS_TCB of the task to resume
*
**********************************************************************************************************
*/

OSCtxSw:  

        stmfd 	sp!,{lr}         		// push pc (lr should be pushed in place of PC)
        stmfd 	sp!,{r0-r12,lr}       		// push lr & r12-r0
        mrs 	r4,cpsr				// task level switch push cpsr
        stmfd 	sp!,{r4}              		// push current cpsr

	ldr 	r4,=OSTCBCur           		// OSTCBCur->OSTCBStkPtr = SP
        ldr 	r5,[r4]
        str 	sp,[r5]

        bl 	OSTaskSwHook             	// call Task Switch Hook

        ldr 	r4,=OSPrioCur           	// OSPrioCur = OSPrioHighRdy
        ldr 	r5,=OSPrioHighRdy
        ldrb 	r6,[r5]
        strb 	r6,[r4]

        ldr 	r4,=OSTCBCur            	// OSTCBCur = OSTCBHighRdy   
        ldr 	r5,=OSTCBHighRdy        
        ldr 	r6,[r5]
        str 	r6,[r4]               

        ldr 	sp,[r6]                 	// SP = OSTCBHighRdy->OSTCBStkPtr
        ldmfd 	sp!,{r4}              		// pop highest priority task''s spsr
        msr 	spsr,r4
        ldmfd 	sp!,{r0-r12,lr,pc}^   		// pop highest priority task''s r0-r12,lr,pc & cpsr

    

/*
**********************************************************************************************************
*                                PERFORM A CONTEXT SWITCH (From an ISR)
*                                        void OSIntCtxSw(void)
*
* Note(s): 1) call OSTaskSwHook
*	   2) OSPrioCur = OSPrioHighRdy
*	   3) OSTCBCur = OSTCBHighRdy
*          4) SP = OSTCBHighRdy->OSTCBStkPtr and switch to highest priority task
*
**********************************************************************************************************
*/
 	
OSIntCtxSw:

	bl 	OSTaskSwHook             	// call Task Switch Hook
        
        ldr 	r4,=OSPrioCur           	// OSPrioCur = OSPrioHighRdy 
        ldr 	r5,=OSPrioHighRdy
        ldrb 	r6,[r5]
        strb 	r6,[r4]

        ldr 	r4,=OSTCBCur           		// OSTCBCur = OSTCBHighRdy   
        ldr 	r5,=OSTCBHighRdy        
        ldr 	r6,[r5]
        str 	r6,[r4]               

        ldr 	sp,[r6]                 	// SP = OSTCBHighRdy->OSTCBStkPtr
	ldmfd 	sp!,{r4}
	msr 	spsr,r4
	ldmfd 	sp!,{r0-r12,lr,pc}^

        

/*
**********************************************************************************************************
*                                          OSTickISR
* note: 1) handle irq return address(lr -4) and push lr, r0~r12
*	2) save current mode(irq)''s sp,lr,cpsr,spsr to r4,r3,r2,r1
*	3) change to svc mode and disable interrupts
*	4) save breakpoint context to task''s stack
*	5) OSIntNesting++
*	6) OSTCBCur->OSTCBStkPtr = sp
*	7) change to irq mode, then call OSTimeTick and adjust sp pointer
*	8) change to svc mode, then call OSIntExit(it may be call OSIntCtxSw)
*	9) if no interrupt context switch, then interrupt return 
*                                       
**********************************************************************************************************
*/
 
OSTickISR:	

	sub 	lr,lr,#4
	stmfd 	sp!,{r0-r12,lr}			// handle irq return address

	mov 	r4,sp				// save sp,lr,cpsr,spsr
	mov 	r3,lr
	mrs 	r2,cpsr
	mrs 	r1,spsr

	msr 	cpsr,#SVCMODE|NOINT		// change to svc mode

	stmfd 	sp!,{r3}			// push pc(lr_irq)
	stmfd 	sp!,{r5-r12,lr}			// push lr, r12~r5
	ldmfd 	r4!,{r5-r9}			// pop sp_irq(r4 saved above) to r5~r9
	stmfd 	sp!,{r5-r9}			// push r4~r0
	stmfd 	sp!,{r1}			// push spsr_irq


	ldr 	r4,=OSIntNesting		// OSIntNesting++
	ldrb 	r5,[r4]
	add 	r5,r5,#1
	strb 	r5,[r4]
	
        cmp 	r5,#1				// if(OSIntNesting==1){
	bne 	_OSIntNesting
	
        ldr 	r4,=OSTCBCur			// OSTCBCur->OSTCBStkPtr = sp
        ldr 	r5,[r4]
        str 	sp,[r5]				// }

        
_OSIntNesting:

        msr 	cpsr,r2				// restore irq mode(r2 saved above)
	bl 	OSTimeTick
	add 	sp,sp,#(14*4)			// adjust sp pointer

	msr 	cpsr,#SVCMODE|NOINT		// change to svc mode
	bl 	OSIntExit

	ldmfd 	sp!,{r0}			// interrupt return 
	msr 	spsr,r0
	ldmfd 	sp!,{r0-r12,lr,pc}^

	
/*
**********************************************************************************************************
*                                   CRITICAL SECTION METHOD 3 FUNCTIONS
*
* Description: Disable/Enable interrupts by preserving the state of interrupts.  Generally speaking you
*              would store the state of the interrupt disable flag in the local variable 'cpu_sr' and then
*              disable interrupts.  'cpu_sr' is allocated in all of uC/OS-II's functions that need to 
*              disable interrupts.  You would restore the interrupt disable state by copying back 'cpu_sr'
*              into the CPU's status register.
*
*              OS_CPU_SR OSCPUSaveSR()
* Arguments  : none
*
* Returns    : OS_CPU_SR
*
*              OSCPURestoreSR(OS_CPU_SR cpu_sr)
* Arguments  : OS_CPU_SR
*
* Returns    : none
*
* Note(s)    : These functions are used in general like this,
*
*            void Task (void *data)
*            {
*                    #if OS_CRITICAL_METHOD == 3 // Allocate storage for CPU status register 
*                          OS_CPU_SR  cpu_sr;
*                    #endif
*                         :
*                         :
*                    OS_ENTER_CRITICAL(); // cpu_sr = OSCPUSaveSR(); 
*                         :
*                         :
*                    OS_EXIT_CRITICAL();  // OSCPURestoreSR(cpu_sr); 
*                         :
*                         :
*            }
**********************************************************************************************************
*/
     
OSCPUSaveSR:
        mrs 	r0,cpsr
        orr 	r1,r0,#NOINT
        msr 	cpsr,r1
        mov 	pc,lr
       
OSCPURestoreSR:
        msr 	cpsr,r0
        mov 	pc,lr

        .end       
