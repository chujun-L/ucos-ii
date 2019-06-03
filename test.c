#include "includes.h"


/*
*********************************************************************************************************
*                                       FUNCTION PROTOTYPES
*********************************************************************************************************
*/

#define TASK_STACK_SIZE 0x4000                  // 64k
#define MODE_STACK_SIZE 0x4000                  // 64k
 
OS_STK MyTaskStk[TASK_STACK_SIZE];
OS_STK MyTaskStk2[TASK_STACK_SIZE];
OS_STK MyTaskStk3[TASK_STACK_SIZE];


OS_STK IRQStk[MODE_STACK_SIZE];
OS_STK SVCStk[MODE_STACK_SIZE];



       void MyTask(void *pdata);
       void MyTask2(void *pdata);
       void MyTask3(void *pdata);

extern void S5PV210_TimerInit(INT32U timer, INT32U prescaler, INT32U divider, INT32U counter);
extern void S5PV210_GPJ2Init(void);

/*
*********************************************************************************************************
*                                              ucos
*
* Description: called by os_cpu_a.S
*
* Arguments  : none
*
* Returns    : none
*
* Notes      : 
*********************************************************************************************************
*/
void ucos(void)
{
    S5PV210_GPJ2Init();
    S5PV210_TimerInit(4, 65, 4, 1250);  // 初始化timer4
    
    OSInit();
    
    //OSTaskCreate(MyTask, (void *)0, MyTaskStk + TASK_STACK_SIZE - 0x10, 2);也可以用这种方式

    // 0x10:  在栈顶预留了16*4个字节，这样栈之间就不容易互相改写
    OSTaskCreate(MyTask, (void *)0, &MyTaskStk[TASK_STACK_SIZE - 0x10], 2);         
    OSTaskCreate(MyTask2, (void *)0,&MyTaskStk2[TASK_STACK_SIZE - 0x10], 3);
    OSTaskCreate(MyTask3, (void *)0,&MyTaskStk3[TASK_STACK_SIZE - 0x10], 5);
    
    OSStart();                         //  OSStart()里调用OSStartHighRdy()执行 MyTask
}


/*
*********************************************************************************************************
*                                              MyTask
*
* Description: 
*
* Arguments  : none
*
* Returns    : none
*
* Notes      : 
*********************************************************************************************************
*/

void MyTask(void *pdata)
{
    pdata = pdata;

	VIC0INTENABLE |= (1 << NUM_TIMER4);  // 使能timer4

    for (;;) {
        GPJ2DAT ^= (1 << 0);   
        OSTimeDly(50);
    }
}


/*
*********************************************************************************************************
*                                              MyTask2
*
* Description: 
*
* Arguments  : none
*
* Returns    : none
*
* Notes      : 
*********************************************************************************************************
*/
void MyTask2(void *pdata)
{
    pdata = pdata;

    for (;;){        
        GPJ2DAT ^= (1 << 2);
        OSTimeDly(2);
    }
}

/*
*********************************************************************************************************
*                                              MyTask3
*
* Description: 
*
* Arguments  : none
*
* Returns    : none
*
* Notes      : 
*********************************************************************************************************
*/
void MyTask3(void *pdata)
{
    pdata = pdata;

    for (;;){        
        GPJ2DAT ^= (1 << 3);
        OSTimeDly(12);
    }
}

