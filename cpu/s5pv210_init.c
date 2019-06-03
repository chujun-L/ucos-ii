#include "includes.h"

/*
*********************************************************************************************************
*                                              S5PV210_GPJ2Init
*
* Description: GPJ2 initialization
*
* Arguments  : none
*
* Returns    : none
*
* Notes      : 
*********************************************************************************************************
*/
void S5PV210_GPJ2Init(void)
{
    INT32U temp;                        // GPJ2 --> output 1  turn off led

    
    temp    = GPJ2CON;     
    temp   &= ~(0xFFFF);
    temp   |=  (0x1111);
    GPJ2CON = temp;
    GPJ2DAT = 0x0F;
}

/*
*********************************************************************************************************
*                                              S5PV210_TimerInit
*
* Description: timer initialization
*
* Arguments  : timer       timer's number
*              prescaler   prescaler value
*              divider     divider value
*              counter     counter value
*
* Returns    : none
*
* Notes      : timer input clock = PCLK / ( {prescaler value + 1} ) / {divider value} = PCLK/(65+1)/16=62500hz
*********************************************************************************************************
*/
void S5PV210_TimerInit(INT32U timer, INT32U prescaler, INT32U divider, INT32U counter)
{

	INT32U temp;

    
	// set prescaler value: 66 
	temp        = TCFG0;
    temp       &= ~(0xff00);
    temp       |= (prescaler  << 8);
	TCFG0       = temp;

	// set divider value: 1/16
	temp        = TCFG1;
    temp       &= ~(0x0f    << (4*timer));
    temp       |=  (divider << (4*timer));
	TCFG1       = temp;

	// timer4: set counter value
	TCNTB4      = counter;

    // timer4: manual update TCNTB4
    temp        = TCON;
    temp       |= (1 << 21);
    TCON        = temp;

    // timer4: auto-reload, start
    temp        = TCON;
    temp       &= ~(0x07 << 20);
    temp       |=  (0x05 << 20);
    TCON        = temp;
    
	// enable timer4 interrupt
	temp        = TINT_CSTAT;
	temp       |= (1 << timer);
	TINT_CSTAT  = temp;

    // select interrupt type IRQ
	VIC0INTSELECT  = 0x0;
}
