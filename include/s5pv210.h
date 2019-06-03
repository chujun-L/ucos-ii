/*
*********************************************************************************************************
*                                       s5pv210 include file
*********************************************************************************************************
*/

#ifndef _S5PV210_H_
#define _S5PV210_H_


/*
*********************************************************************************************************
*                                       s5pv210 GENERAL PURPOSE INPUT/OUTPUT register
*********************************************************************************************************
*/
#define      GPIO_BASE			(0xE0200000)

// GPJ2
#define      GPJ2CON            ( *((volatile INT32U *)(GPIO_BASE + 0x280)) )
#define      GPJ2DAT            ( *((volatile INT32U *)(GPIO_BASE + 0x284)) )
#define      GPJ2PUD            ( *((volatile INT32U *)(GPIO_BASE + 0x288)) )
#define      GPJ2DRV            ( *((volatile INT32U *)(GPIO_BASE + 0x28C)) )
#define      GPJ2CONPDN         ( *((volatile INT32U *)(GPIO_BASE + 0x290)) )
#define      GPJ2PUDPDN         ( *((volatile INT32U *)(GPIO_BASE + 0x294)) )

/*
*********************************************************************************************************
*                                       s5pv210 interrupt victor control register
*********************************************************************************************************
*/

#define     VIC0_BASE			(0xF2000000)
#define     VIC1_BASE			(0xF2100000)
#define     VIC2_BASE			(0xF2200000)
#define     VIC3_BASE			(0xF2300000)

// VIC0
#define		VIC0IRQSTATUS			( *((volatile INT32U *)(VIC0_BASE + 0x00)) )
#define		VIC0FIQSTATUS			( *((volatile INT32U *)(VIC0_BASE + 0x04)) )
#define		VIC0RAWINTR			    ( *((volatile INT32U *)(VIC0_BASE + 0x08)) )
#define		VIC0INTSELECT			( *((volatile INT32U *)(VIC0_BASE + 0x0c)) )
#define		VIC0INTENABLE			( *((volatile INT32U *)(VIC0_BASE + 0x10)) )
#define		VIC0INTENCLEAR			( *((volatile INT32U *)(VIC0_BASE + 0x14)) )
#define		VIC0SOFTINT			    ( *((volatile INT32U *)(VIC0_BASE + 0x18)) )
#define		VIC0SOFTINTCLEAR		( *((volatile INT32U *)(VIC0_BASE + 0x1c)) )
#define		VIC0PROTECTION			( *((volatile INT32U *)(VIC0_BASE + 0x20)) )
#define		VIC0SWPRIORITYMASK		( *((volatile INT32U *)(VIC0_BASE + 0x24)) )
#define		VIC0PRIORITYDAISY		( *((volatile INT32U *)(VIC0_BASE + 0x28)) )
#define     VIC0VECTADDR			(VIC0_BASE + 0x100)
#define     VIC0VECPRIORITY			( *((volatile INT32U *)(VIC0_BASE + 0x200)) )
#define     VIC0ADDR		    	( *((volatile INT32U *)(VIC0_BASE + 0xf00)) )
#define     VIC0PERID0			    ( *((volatile INT32U *)(VIC0_BASE + 0xfe0)) )
#define     VIC0PERID1              ( *((volatile INT32U *)(VIC0_BASE + 0xfe4)) )
#define     VIC0PERID2			    ( *((volatile INT32U *)(VIC0_BASE + 0xfe8)) )
#define     VIC0PERID3			    ( *((volatile INT32U *)(VIC0_BASE + 0xfec)) )
#define     VIC0PCELLID0			( *((volatile INT32U *)(VIC0_BASE + 0xff0)) )
#define     VIC0PCELLID1			( *((volatile INT32U *)(VIC0_BASE + 0xff4)) )
#define     VIC0PCELLID2			( *((volatile INT32U *)(VIC0_BASE + 0xff8)) )
#define     VIC0PCELLID3			( *((volatile INT32U *)(VIC0_BASE + 0xffc)) )

// VIC1
#define		VIC1IRQSTATUS			( *((volatile INT32U *)(VIC1_BASE + 0x00)) )
#define		VIC1FIQSTATUS			( *((volatile INT32U *)(VIC1_BASE + 0x04)) )
#define		VIC1RAWINTR             ( *((volatile INT32U *)(VIC1_BASE + 0x08)) )
#define		VIC1INTSELECT			( *((volatile INT32U *)(VIC1_BASE + 0x0c)) )
#define		VIC1INTENABLE			( *((volatile INT32U *)(VIC1_BASE + 0x10)) )
#define		VIC1INTENCLEAR			( *((volatile INT32U *)(VIC1_BASE + 0x14)) )
#define		VIC1SOFTINT			    ( *((volatile INT32U *)(VIC1_BASE + 0x18)) )
#define		VIC1SOFTINTCLEAR		( *((volatile INT32U *)(VIC1_BASE + 0x1c)) )
#define		VIC1PROTECTION			( *((volatile INT32U *)(VIC1_BASE + 0x20)) )
#define		VIC1SWPRIORITYMASK		( *((volatile INT32U *)(VIC1_BASE + 0x24)) )
#define		VIC1PRIORITYDAISY		( *((volatile INT32U *)(VIC1_BASE + 0x28)) )
#define     VIC1VECTADDR			(VIC1_BASE + 0x100)
#define     VIC1VECPRIORITY			( *((volatile INT32U *)(VIC1_BASE + 0x200)) )
#define     VIC1ADDR		    	( *((volatile INT32U *)(VIC1_BASE + 0xf00)) )
#define     VIC1PERID0			    ( *((volatile INT32U *)(VIC1_BASE + 0xfe0)) )
#define     VIC1PERID1			    ( *((volatile INT32U *)(VIC1_BASE + 0xfe4)) )
#define     VIC1PERID2			    ( *((volatile INT32U *)(VIC1_BASE + 0xfe8)) )
#define     VIC1PERID3              ( *((volatile INT32U *)(VIC1_BASE + 0xfec)) )
#define     VIC1PCELLID0			( *((volatile INT32U *)(VIC1_BASE + 0xff0)) )
#define     VIC1PCELLID1			( *((volatile INT32U *)(VIC1_BASE + 0xff4)) )
#define     VIC1PCELLID2			( *((volatile INT32U *)(VIC1_BASE + 0xff8)) )
#define     VIC1PCELLID3			( *((volatile INT32U *)(VIC1_BASE + 0xffc)) )

// VIC2
#define		VIC2IRQSTATUS			( *((volatile INT32U *)(VIC2_BASE + 0x00)) )
#define		VIC2FIQSTATUS			( *((volatile INT32U *)(VIC2_BASE + 0x04)) )
#define		VIC2RAWINTR			    ( *((volatile INT32U *)(VIC2_BASE + 0x08)) )
#define		VIC2INTSELECT			( *((volatile INT32U *)(VIC2_BASE + 0x0c)) )
#define		VIC2INTENABLE			( *((volatile INT32U *)(VIC2_BASE + 0x10)) )
#define		VIC2INTENCLEAR			( *((volatile INT32U *)(VIC2_BASE + 0x14)) )
#define		VIC2SOFTINT             ( *((volatile INT32U *)(VIC2_BASE + 0x18)) )
#define		VIC2SOFTINTCLEAR		( *((volatile INT32U *)(VIC2_BASE + 0x1c)) )
#define		VIC2PROTECTION			( *((volatile INT32U *)(VIC2_BASE + 0x20)) )
#define		VIC2SWPRIORITYMASK		( *((volatile INT32U *)(VIC2_BASE + 0x24)) )
#define		VIC2PRIORITYDAISY		( *((volatile INT32U *)(VIC2_BASE + 0x28)) )
#define     VIC2VECTADDR			(VIC2_BASE + 0x100)
#define     VIC2VECPRIORITY			( *((volatile INT32U *)(VIC2_BASE + 0x200)) )
#define     VIC2ADDR			    ( *((volatile INT32U *)(VIC2_BASE + 0xf00)) )
#define     VIC2PERID0			    ( *((volatile INT32U *)(VIC2_BASE + 0xfe0)) )
#define     VIC2PERID1			    ( *((volatile INT32U *)(VIC2_BASE + 0xfe4)) )
#define     VIC2PERID2			    ( *((volatile INT32U *)(VIC2_BASE + 0xfe8)) )
#define     VIC2PERID3			    ( *((volatile INT32U *)(VIC2_BASE + 0xfec)) )
#define     VIC2PCELLID0			( *((volatile INT32U *)(VIC2_BASE + 0xff0)) )
#define     VIC2PCELLID1			( *((volatile INT32U *)(VIC2_BASE + 0xff4)) )
#define     VIC2PCELLID2			( *((volatile INT32U *)(VIC2_BASE + 0xff8)) )
#define     VIC2PCELLID3			( *((volatile INT32U *)(VIC2_BASE + 0xffc)) )

// VIC3
#define		VIC3IRQSTATUS			( *((volatile INT32U *)(VIC3_BASE + 0x00)) )
#define     VIC3FIQSTATUS			( *((volatile INT32U *)(VIC3_BASE + 0x04)) )
#define     VIC3RAWINTR			    ( *((volatile INT32U *)(VIC3_BASE + 0x08)) )
#define     VIC3INTSELECT			( *((volatile INT32U *)(VIC3_BASE + 0x0c)) )
#define     VIC3INTENABLE			( *((volatile INT32U *)(VIC3_BASE + 0x10)) )
#define     VIC3INTENCLEAR			( *((volatile INT32U *)(VIC3_BASE + 0x14)) )
#define     VIC3SOFTINT			    ( *((volatile INT32U *)(VIC3_BASE + 0x18)) )
#define     VIC3SOFTINTCLEAR		( *((volatile INT32U *)(VIC3_BASE + 0x1c)) )
#define     VIC3PROTECTION			( *((volatile INT32U *)(VIC3_BASE + 0x20)) )
#define     VIC3SWPRIORITYMASK		( *((volatile INT32U *)(VIC3_BASE + 0x24)) )
#define     VIC3PRIORITYDAISY		( *((volatile INT32U *)(VIC3_BASE + 0x28)) )
#define     VIC3VECTADDR            (VIC3_BASE + 0x100)
#define     VIC3VECPRIORITY         ( *((volatile INT32U *)(VIC3_BASE + 0x200)) )
#define     VIC3ADDR                ( *((volatile INT32U *)(VIC3_BASE + 0xf00)) )
#define     VIC3PERID0              ( *((volatile INT32U *)(VIC3_BASE + 0xfe0)) )
#define     VIC3PERID1              ( *((volatile INT32U *)(VIC3_BASE + 0xfe4)) )
#define     VIC3PERID2              ( *((volatile INT32U *)(VIC3_BASE + 0xfe8)) )
#define     VIC3PERID3              ( *((volatile INT32U *)(VIC3_BASE + 0xfec)) )
#define     VIC3PCELLID0            ( *((volatile INT32U *)(VIC3_BASE + 0xff0)) )
#define     VIC3PCELLID1            ( *((volatile INT32U *)(VIC3_BASE + 0xff4)) )
#define     VIC3PCELLID2            ( *((volatile INT32U *)(VIC3_BASE + 0xff8)) )
#define     VIC3PCELLID3            ( *((volatile INT32U *)(VIC3_BASE + 0xffc)) )

#define		_Exception_Vector		(0xD0037400)
#define		pExceptionRESET			( *((volatile INT32U *)(_Exception_Vector + 0x0)) )
#define		pExceptionUNDEF			( *((volatile INT32U *)(_Exception_Vector + 0x4)) )
#define		pExceptionSWI			( *((volatile INT32U *)(_Exception_Vector + 0x8)) )
#define     pExceptionPABORT		( *((volatile INT32U *)(_Exception_Vector + 0xc)) )
#define     pExceptionDABORT        ( *((volatile INT32U *)(_Exception_Vector + 0x10)) )
#define		pExceptionRESERVED		( *((volatile INT32U *)(_Exception_Vector + 0x14)) )
#define     pExceptionIRQ			( *((volatile INT32U *)(_Exception_Vector + 0x18)) )
#define     pExceptionFIQ			( *((volatile INT32U *)(_Exception_Vector + 0x1c)) )


#define     INT_LIMIT				  (96)

//INT NUM - VIC0
#define        NUM_EINT0				(0)
#define        NUM_EINT1				(1)
#define        NUM_EINT2				(2)
#define        NUM_EINT3				(3)
#define        NUM_EINT4				(4)
#define        NUM_EINT5				(5)
#define        NUM_EINT6				(6)
#define        NUM_EINT7				(7)
#define        NUM_EINT8				(8)
#define        NUM_EINT9				(9)
#define        NUM_EINT10				(10)
#define        NUM_EINT11				(11)
#define        NUM_EINT12				(12)
#define        NUM_EINT13				(13)
#define        NUM_EINT14				(14)
#define        NUM_EINT15				(15)
#define        NUM_EINT16_31            (16)
#define        NUM_Reserved17           (17)
#define        NUM_MDMA                 (18)
#define        NUM_PDMA0				(19)
#define        NUM_PDMA1				(20)
#define        NUM_TIMER0				(21)
#define        NUM_TIMER1				(22)
#define        NUM_TIMER2				(23)
#define        NUM_TIMER3				(24)
#define        NUM_TIMER4				(25)
#define        NUM_SYSTIMER             (26)
#define        NUM_WDT					(27)
#define        NUM_RTC_ALARM            (28)
#define        NUM_RTC_TICK             (29)
#define        NUM_GPIOINT				(30)
#define        NUM_FIMC3				(31)

//INT NUM - VIC1
#define        NUM_CORTEX0				(32+0)
#define        NUM_CORTEX1				(32+1)
#define        NUM_CORTEX2				(32+2)
#define        NUM_CORTEX3				(32+3)
#define        NUM_CORTEX4				(32+4)
#define        NUM_IEM_APC				(32+5)
#define        NUM_IEM_IEC				(32+6)
#define        NUM_Reserved39           (32+7)
#define        NUM_NFC					(32+8)
#define        NUM_CFC					(32+9)
#define        NUM_UART0				(32+10)
#define        NUM_UART1				(32+11)
#define        NUM_UART2				(32+12)
#define        NUM_UART3				(32+13)
#define        NUM_I2C					(32+14)
#define        NUM_SPI0                 (32+15)
#define        NUM_SPI1                 (32+16)
#define        NUM_SPI2                 (32+17)
#define        NUM_AUDIO				(32+18)
#define        NUM_I2C_PMIC             (32+19)
#define        NUM_I2C_HDMI             (32+20)
#define        NUM_HSIRX				(32+21)
#define        NUM_HSITX				(32+22)
#define        NUM_UHOST				(32+23)
#define        NUM_OTG					(32+24)
#define        NUM_MSM					(32+25)
#define        NUM_HSMMC0				(32+26)
#define        NUM_HSMMC1				(32+27)
#define        NUM_HSMMC2				(32+28)
#define        NUM_MIPI_CSI             (32+29)
#define        NUM_MIPI_DSI             (32+30)
#define        NUM_ONENAND_AUDI         (32+31)

//INT NUM - VIC2
#define        NUM_LCD0                 (64+0)
#define        NUM_LCD1                 (64+1)
#define        NUM_LCD2                 (64+2)
#define        NUM_LCD3                 (64+3)
#define        NUM_ROTATOR				(64+4)
#define        NUM_FIMC_A				(64+5)
#define        NUM_FIMC_B				(64+6)
#define        NUM_FIMC_C				(64+7)
#define        NUM_JPEG                 (64+8)
#define        NUM_2D					(64+9)
#define        NUM_3D					(64+10)
#define        NUM_MIXER				(64+11)
#define        NUM_HDMI                 (64+12)
#define        NUM_HDMI_I2C             (64+13)
#define        NUM_MFC					(64+14)
#define        NUM_TVENC				(64+15)
#define        NUM_I2S0                 (64+16)
#define        NUM_I2S1                 (64+17)
#define        NUM_I2S2                 (64+18)
#define        NUM_AC97                 (64+19)
#define        NUM_PCM0                 (64+20)
#define        NUM_PCM1                 (64+21)
#define        NUM_SPDIF				(64+22)
#define        NUM_ADC                  (64+23)
#define        NUM_PENDN				(64+24)
#define        NUM_KEYPAD				(64+25)
#define        NUM_Reserved90           (64+26)
#define        NUM_HASH                 (64+27)
#define        NUM_FEEDCTRL             (64+28)
#define        NUM_PCM2                 (64+29)
#define        NUM_SDM_IRQ				(64+30)
#define        NUM_SMD_FIQ				(64+31)

//INT NUM - VIC3
#define        NUM_IPC					(96+0)
#define        NUM_HOSTIF				(96+1)
#define        NUM_HSMMC3				(96+2)
#define        NUM_CEC					(96+3)
#define        NUM_TSI					(96+4)
#define        NUM_MDNIE0				(96+5)
#define        NUM_MDNIE1				(96+6)
#define        NUM_MDNIE2				(96+7)
#define        NUM_MDNIE3				(96+8)
#define        NUM_ADC1                 (96+9)
#define        NUM_PENDN1				(96+10)
#define        NUM_ALL					(200)


/*
*********************************************************************************************************
*                                       s5pv210 timer register
*********************************************************************************************************
*/

#define		PWMTIMER_BASE           (0xE2500000)

#define		TCFG0                   ( *((volatile INT32U *)(PWMTIMER_BASE+0x00)) )
#define		TCFG1                   ( *((volatile INT32U *)(PWMTIMER_BASE+0x04)) )
#define		TCON                    ( *((volatile INT32U *)(PWMTIMER_BASE+0x08)) )
#define		TCNTB0                  ( *((volatile INT32U *)(PWMTIMER_BASE+0x0C)) )
#define		TCMPB0                  ( *((volatile INT32U *)(PWMTIMER_BASE+0x10)) )
#define		TCNTO0                  ( *((volatile INT32U *)(PWMTIMER_BASE+0x14)) )
#define		TCNTB1                  ( *((volatile INT32U *)(PWMTIMER_BASE+0x18)) )
#define		TCMPB1                  ( *((volatile INT32U *)(PWMTIMER_BASE+0x1C)) )
#define		TCNTO1                  ( *((volatile INT32U *)(PWMTIMER_BASE+0x20)) )
#define		TCNTB2                  ( *((volatile INT32U *)(PWMTIMER_BASE+0x24)) )
#define		TCMPB2                  ( *((volatile INT32U *)(PWMTIMER_BASE+0x28)) )
#define		TCNTO2                  ( *((volatile INT32U *)(PWMTIMER_BASE+0x2C)) )
#define		TCNTB3                  ( *((volatile INT32U *)(PWMTIMER_BASE+0x30)) )
#define		TCMPB3                  ( *((volatile INT32U *)(PWMTIMER_BASE+0x34)) )
#define		TCNTO3                  ( *((volatile INT32U *)(PWMTIMER_BASE+0x38)) )
#define		TCNTB4                  ( *((volatile INT32U *)(PWMTIMER_BASE+0x3C)) )
#define		TCNTO4                  ( *((volatile INT32U *)(PWMTIMER_BASE+0x40)) )
#define		TINT_CSTAT              ( *((volatile INT32U *)(PWMTIMER_BASE+0x44)) )



/*
*********************************************************************************************************
*                                       s5pv210 system clock register
*********************************************************************************************************
*/

#define         APLL_LOCK                       ( *((volatile INT32U *)0xE0100000) )
#define         MPLL_LOCK                       ( *((volatile INT32U *)0xE0100008) )

#define         APLL_CON0                       ( *((volatile INT32U *)0xE0100100) )
#define         APLL_CON1                       ( *((volatile INT32U *)0xE0100104) )
#define         MPLL_CON                        ( *((volatile INT32U *)0xE0100108) )

#define         CLK_SRC0                        ( *((volatile INT32U *)0xE0100200) )
#define         CLK_SRC1                        ( *((volatile INT32U *)0xE0100204) )
#define         CLK_SRC2                        ( *((volatile INT32U *)0xE0100208) )
#define         CLK_SRC3                        ( *((volatile INT32U *)0xE010020c) )
#define         CLK_SRC4                        ( *((volatile INT32U *)0xE0100210) )
#define         CLK_SRC5                        ( *((volatile INT32U *)0xE0100214) )
#define         CLK_SRC6                        ( *((volatile INT32U *)0xE0100218) )
#define         CLK_SRC_MASK0                   ( *((volatile INT32U *)0xE0100280) )
#define         CLK_SRC_MASK1                   ( *((volatile INT32U *)0xE0100284) )

#define         CLK_DIV0                        ( *((volatile INT32U *)0xE0100300) )
#define         CLK_DIV1                        ( *((volatile INT32U *)0xE0100304) )
#define         CLK_DIV2                        ( *((volatile INT32U *)0xE0100308) )
#define         CLK_DIV3                        ( *((volatile INT32U *)0xE010030c) )
#define         CLK_DIV4                        ( *((volatile INT32U *)0xE0100310) )
#define         CLK_DIV5                        ( *((volatile INT32U *)0xE0100314) )
#define         CLK_DIV6                        ( *((volatile INT32U *)0xE0100318) )
#define         CLK_DIV7                        ( *((volatile INT32U *)0xE010031c) )

#define         CLK_DIV0_MASK                   (0x7fffffff)

#define         APLL_MDIV                       (0x7d)
#define         APLL_PDIV                       (0x3)
#define         APLL_SDIV                       (0x1)
#define         MPLL_MDIV                       (0x29b)
#define         MPLL_PDIV                       (0xc)
#define         MPLL_SDIV                       (0x1)

#define set_pll(mdiv, pdiv, sdiv)               (1<<31 | mdiv<<16 | pdiv<<8 | sdiv)
#define         APLL_VAL                        set_pll(APLL_MDIV,APLL_PDIV,APLL_SDIV)
#define         MPLL_VAL                        set_pll(MPLL_MDIV,MPLL_PDIV,MPLL_SDIV)


#endif /* _S5PV210_H_ */

