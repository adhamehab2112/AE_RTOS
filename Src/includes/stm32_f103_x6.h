/*
 * stm32_f103_x6.h
 *
 *  Created on: Jul 4, 2023
 *      Author: adham
 */

#ifndef INCLUDES_STM32_F103_X6_H_
#define INCLUDES_STM32_F103_X6_H_
//-----------------------------
//Includes
#include "stdlib.h"
#include "std_macros.h"
#include "std_types.h"
//-----------------------------



//-----------------------------
//Base addresses for Memories

#define FLASH_MEMORY_BASE	 		  0x08000000UL
#define SYSTEM_MEMORY_BASE			  0x1FFFF000UL
#define SRAM_MEMORY_BASE			  0x20000000UL

#define PERIPHRALS_BASE		  		  0x40000000UL
#define INT_PERIPHRALS_BASE	  		  0xE0000000UL
//-----------------------------



//-----------------------------
//Base addresses for BUS Peripherals

//@RCC: Reset and Control Circuit base address -> AHB bus
#define RCC_BASE 		0x40021000UL


//@NVIC	Base Address
#define NVIC_BASE		0xE000E100UL

//@GPIO : General Purpose Input Output base addresses -> APB2 bus
//**************************LQFP48***********************************//

//GPIOA&&GPIOB -> ARE FULLY INCLUDED
#define GPIOA_BASE 		0x40010800UL
#define GPIOB_BASE 		0x40010C00UL

//GPIOC&&GPIOD -> ARE PARTIAL INCLUDED
#define GPIOC_BASE 		0x40011000UL
#define GPIOD_BASE 		0x40011400UL

//GPIOE IS NOT INCULDED
#define GPIOE_BASE 		0x40011800UL


//@AFIO: Alternative Functions Input Output Base addresses -> APB2 bus
#define AFIO_BASE 		0x40010000UL

//@EXTI : External Interrupt peripheral base address -> APB2 bus
#define EXTI_BASE 		0x40010400UL

//@USAR :Universal Synchronous Asynchronous Reciver Transmitter Base Address
#define USART1_BASE		0x40013800UL
#define USART2_BASE		0x40004400UL
#define USART3_BASE		0x40004800UL


//@SPI : Serial Peripheral Interface Base Addresses
#define SPI1_BASE		0x40013000
#define SPI2_BASE		0x40003800


//@I2C : Inter Integrated Circuit Base Addresses
#define I2C1_BASE		0x40005400
#define I2C2_BASE		0x40005800

//-----------------------------


//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register:

//@NVIC Registers
#define NVIC_ISER0		*(volatile uint32_t *)(NVIC_BASE+0x00)
#define NVIC_ISER1		*(volatile uint32_t *)(NVIC_BASE+0x04)
#define NVIC_ISER2		*(volatile uint32_t *)(NVIC_BASE+0x08)
#define NVIC_ICER0		*(volatile uint32_t *)(NVIC_BASE+0x80)
#define NVIC_ICER1		*(volatile uint32_t *)(NVIC_BASE+0x84)
#define NVIC_ICER2		*(volatile uint32_t *)(NVIC_BASE+0x88)


//@RCC peripheral REGISTERS
typedef struct
{
	volatile uint32_t RCC_CR 		; // CR : Clock Control Register
	volatile uint32_t RCC_CFGR 		; // CFGR : CLOCK CONFIGURATION REGISTER
	volatile uint32_t RCC_CIR		; // CIR : CLOCK INTERRUPT REGISTER
	volatile uint32_t RCC_APB2RSTR	; // APB2RSTR : APB2 RESET REGISTER
	volatile uint32_t RCC_APB1RSTR	; // APB1RSTR : APB1 RESET REGISTER
	volatile uint32_t RCC_AHBENR	; // AHBENR : AHB CLOCK ENABLE REGISTER
	volatile uint32_t RCC_APB2ENR	; // APB2ENR : APB2 CLOCK ENABLE REGISTER
	volatile uint32_t RCC_APB1ENR	; // APB1ENR : APB1 CLOCK ENABLE REGISTER
	volatile uint32_t RCC_BDCR		; //BDCR : BACKUP DOMAIN CONTROL REGISTER
	volatile uint32_t RCC_CSR		; // CSR : CONTROL / STATUS REGISTER
	volatile uint32_t RCC_AHBSTR		; // AHBSTR : AHB CLOCK RESET REGISTER
}RCC_Registers_t;

//@GPIOx peripheral REGISTERS -> SAME FOR A,B,C,D,E (each port consists of 16 pin)
typedef struct
{
	volatile uint32_t GPIOx_CRL 	; // CRL : GPIO CONTROL REGISTER LOW
	volatile uint32_t GPIOx_CRH 	; // CRH : GPIO CONTROL REGISTER LOW
	volatile uint32_t GPIOx_IDR 	; // IDR : GPIO INPUT DATA REGUSTER
	volatile uint32_t GPIOx_ODR 	; // ODR : GPIO OUTPUT DATA REGISTER
	volatile uint32_t GPIOx_BSRR ; // BSRR : GPIO BIT SET/RESET REGISTER
	volatile uint32_t GPIOx_BRR 	; // BRR : GPIO BIT RESET REGISTER
	volatile uint32_t GPIOx_LCKR ; // LCKR : GPIO LOCK REGISTER
}GPIOx_Registers_t;


//@AFIO peripheral registers
typedef struct
{
	volatile uint32_t AFIO_EVCR 	; //EVCR : EVENT CONTROL REGISTER
	volatile uint32_t AFIO_MAPR 	; //MAPR : REMAP AND DEBUG I/O CONFIGURATION REGSITER
	volatile uint32_t ADIO_EXTICR[4]; //EXTICR1 : EXTERNAL INTERRUPT CONFIGURATION REGISTER 1
	volatile uint32_t reserved 		;
	volatile uint32_t AFIO_MAPR2 	; //MAPR2 : REMAP AND DEBUG I/O CONFIGURATION REGSITER 2
}AFIO_Registers_t;


//@EXTI Peripheral Registers
typedef struct
{
	volatile uint32_t EXTI_IMR 		; //IMR : INTERRUPT MASK REGISTER
	volatile uint32_t EXTI_EMR 		; //EMR : EVENT MASK REGISTER
	volatile uint32_t EXTI_RTSR 	; //RTSR : RISING TRIGGER SELECTION REGISTER
	volatile uint32_t EXTI_FTSR 	; //FTSR : FALLING TRIGGER SELECTION REGISTER
	volatile uint32_t EXTI_SWIER	; //SWIER : SOFTWARE INTERRUPT EVENT REGISTER
	volatile uint32_t EXTI_PR		; //PR : PENDING REGISTER
}EXTI_Registers_t;

//USART Peripheral Registers
typedef struct
{
	volatile uint32_t USART_SR   ;
	volatile uint32_t USART_DR   ;
	volatile uint32_t USART_BRR  ;
	volatile uint32_t USART_CR1  ;
	volatile uint32_t USART_CR2  ;
	volatile uint32_t USART_CR3  ;
	volatile uint32_t USART_GTPR ;
}USART_Registers_t;

//SPI Peripheral Registers
typedef struct
{
	volatile uint32_t SPI_CR1 ;
	volatile uint32_t SPI_CR2 ;
	volatile uint32_t SPI_SR  ;
	volatile uint32_t SPI_DR  ;
}SPI_Registers_t;


//I2C Peripheral Registers
typedef struct
{
	volatile uint32_t I2C_CR1   ;
	volatile uint32_t I2C_CR2   ;
	volatile uint32_t I2C_OAR1  ;
	volatile uint32_t I2C_OAR2  ;
	volatile uint32_t I2C_DR    ;
	volatile uint32_t I2C_SR1   ;
	volatile uint32_t I2C_SR2   ;
	volatile uint32_t I2C_CCR   ;
	volatile uint32_t I2C_TRISE ;
}I2C_Registers_t;
//-*-*-*-*-*-*-*-*-*-*-*


//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral Instants:
//@GPIO Peripheral instants
#define GPIOA	((volatile GPIOx_Registers_t *)GPIOA_BASE )
#define GPIOB	((volatile GPIOx_Registers_t *)GPIOB_BASE )
#define GPIOC	((volatile GPIOx_Registers_t *)GPIOC_BASE )
#define GPIOD	((volatile GPIOx_Registers_t *)GPIOD_BASE )
#define GPIOE	((volatile GPIOx_Registers_t *)GPIOE_BASE )

//@RCC Peripheral instants
#define RCC	   ((volatile RCC_Registers_t *)RCC_BASE )

//@AFIO Peripheral instants
#define AFIO	((volatile AFIO_Registers_t *)AFIO_BASE )

//@EXTI Peripheral instants
#define EXTI	((volatile EXTI_Registers_t *)EXTI_BASE )


//@USART Peripheral instants
#define USART1	((volatile USART_Registers_t *)USART1_BASE)
#define USART2	((volatile USART_Registers_t *)USART2_BASE)
#define USART3	((volatile USART_Registers_t *)USART3_BASE)

//@SPI Peripheral instants
#define SPI1	((volatile SPI_Registers_t *)SPI1_BASE)
#define SPI2	((volatile SPI_Registers_t *)SPI2_BASE)

//@I2C Peripheral instants
#define I2C1	((volatile I2C_Registers_t*)I2C1_BASE)
#define I2C2	((volatile I2C_Registers_t*)I2C2_BASE)

//-*-*-*-*-*-*-*-*-*-*-*

//-*-*-*-*-*-*-*-*-*-*-*-
//clock enable Macros:

//@GPIOA : ENABLE
#define RCC_GPIOA_CLK_EN()	(RCC->RCC_APB2ENR |= 1<<2)
#define RCC_GPIOB_CLK_EN()	(RCC->RCC_APB2ENR |= 1<<3)
#define RCC_GPIOC_CLK_EN()	(RCC->RCC_APB2ENR |= 1<<4)
#define RCC_GPIOD_CLK_EN()	(RCC->RCC_APB2ENR |= 1<<5)
#define RCC_GPIOE_CLK_EN()	(RCC->RCC_APB2ENR |= 1<<6)

//@AFIO : ENABLE
#define RCC_AFIO_CLK_EN()	(RCC->RCC_APB2ENR |= 1<<0)

//@USART : ENABLE
#define RCC_USART1_CLK_EN()	(RCC->RCC_APB2ENR |= 1<<14)
#define RCC_USART2_CLK_EN()	(RCC->RCC_APB1ENR |= 1<<17)
#define RCC_USART3_CLK_EN()	(RCC->RCC_APB1ENR |= 1<<18)

//@USART : RESET
#define RCC_USART1_CLK_DIS()	(RCC->RCC_APB2RSTR |= 1<<14)
#define RCC_USART2_CLK_DIS()	(RCC->RCC_APB1RSTR |= 1<<17)
#define RCC_USART3_CLK_DIS()	(RCC->RCC_APB1RSTR |= 1<<18)

//@SPI : ENABLE
#define RCC_SPI1_CLK_EN()		(RCC->RCC_APB2ENR |= 1<<12)
#define RCC_SPI2_CLK_EN()		(RCC->RCC_APB1ENR |= 1<<14)

//@SPI : RESET
#define RCC_SPI1_CLK_DIS()		(RCC->RCC_APB2RSTR |= 1<<12)
#define RCC_SPI2_CLK_DIS()		(RCC->RCC_APB1RSTR |= 1<<14)

//@I2C : ENABLE
#define RCC_I2C1_CLK_EN()    	(RCC->RCC_APB1ENR |= 1<<21)
#define RCC_I2C2_CLK_EN()		(RCC->RCC_APB1ENR |= 1<<22)

//-*-*-*-*-*-*-*-*-*-*-*

//@IRQ according to IVT
#define EXTI0_IRQ		6
#define EXTI1_IRQ		7
#define EXTI2_IRQ		8
#define EXTI3_IRQ		9
#define EXTI4_IRQ		10
#define EXTI5_IRQ		23
#define EXTI6_IRQ		23
#define EXTI7_IRQ		23
#define EXTI8_IRQ		23
#define EXTI9_IRQ		23
#define EXTI10_IRQ		40
#define EXTI11_IRQ		40
#define EXTI12_IRQ		40
#define EXTI13_IRQ		40
#define EXTI14_IRQ		40
#define EXTI15_IRQ		40
#define USART1_IRQ		37
#define USART2_IRQ		38
#define USART3_IRQ		39
#define SPI1_IRQ		35
#define SPI2_IRQ		36
#define I2C1_EV_IRQ		31
#define I2C1_ER_IEQ		32
#define I2C2_EV_IRQ		33
#define I2C2_ER_IRQ		34
//-*-*-*-*-*-*-*-*-*-*-*

//@ref : NVIC IRQ EN/DIS MACROS
//Enable macros
#define NVIC_IRQ6_EXTI0_EN()			(NVIC_ISER0 |= 1<<6)
#define NVIC_IRQ7_EXTI1_EN()			(NVIC_ISER0 |= 1<<7)
#define NVIC_IRQ8_EXTI2_EN()			(NVIC_ISER0 |= 1<<8)
#define NVIC_IRQ9_EXTI3_EN()			(NVIC_ISER0 |= 1<<9)
#define NVIC_IRQ10_EXTI4_EN()			(NVIC_ISER0 |= 1<<10)
#define NVIC_IRQ23_EXTI9_5_EN()			(NVIC_ISER0 |= 1<<23)
#define NVIC_IRQ40_EXTI15_10_EN()		(NVIC_ISER1 |= 1<<8)
#define NVIC_IRQ37_USART1_EN()			(NVIC_ISER1 |= 1<<(USART1_IRQ-32))
#define NVIC_IRQ38_USART2_EN()			(NVIC_ISER1 |= 1<<(USART2_IRQ-32))
#define NVIC_IRQ39_USART3_EN()			(NVIC_ISER1 |= 1<<(USART3_IRQ-32))
#define NVIC_IRQ35_SPI1_EN()			(NVIC_ISER1 |= 1<<(SPI1_IRQ-32))
#define NVIC_IRQ36_SPI2_EN()			(NVIC_ISER1 |= 1<<(SPI2_IRQ-32))
#define NVIC_IRQ31_I2C1_EV_EN()			(NVIC_ISER0 |= 1<<I2C1_EV_IRQ)
#define NVIC_IRQ32_I2C1_ER_EN()			(NVIC_ISER0 |= 1<<I2C1_ER_IRQ)
#define NVIC_IRQ33_I2C2_EV_EN()			(NVIC_ISER1 |= 1<<(I2C2_EV_IRQ-32))
#define NVIC_IRQ34_I2C2_ER_EN()			(NVIC_ISER1 |= 1<<(I2C2_ER_IRQ-32))
//Disable macros
#define NVIC_IRQ6_EXTI0_DIS()			(NVIC_ICER0 |= 1<<6)
#define NVIC_IRQ7_EXTI1_DIS()			(NVIC_ICER0 |= 1<<7)
#define NVIC_IRQ8_EXTI2_DIS()			(NVIC_ICER0 |= 1<<8)
#define NVIC_IRQ9_EXTI3_DIS()			(NVIC_ICER0 |= 1<<9)
#define NVIC_IRQ10_EXTI4_DIS()			(NVIC_ICER0 |= 1<<10)
#define NVIC_IRQ23_EXTI9_5_DIS()		(NVIC_ICER0 |= 1<<23)
#define NVIC_IRQ40_EXTI15_10_DIS()		(NVIC_ICER1 |= 1<<8)
#define NVIC_IRQ37_USART1_DIS()			(NVIC_ICER1 |= 1<<(USART1_IRQ-32))
#define NVIC_IRQ38_USART2_DIS()			(NVIC_ICER1 |= 1<<(USART2_IRQ-32))
#define NVIC_IRQ39_USART3_DIS()			(NVIC_ICER1 |= 1<<(USART3_IRQ-32))
#define NVIC_IRQ35_SPI1_DIS()			(NVIC_ICER1 |= 1<<(SPI1_IRQ-32))
#define NVIC_IRQ36_SPI2_DIS()			(NVIC_ICER1 |= 1<<(SPI2_IRQ-32))
#define NVIC_IRQ31_I2C1_EV_DIS()		(NVIC_ICER0 |= 1<<I2C1_EV_IRQ)
#define NVIC_IRQ32_I2C1_ER_DIS()		(NVIC_ICER0 |= 1<<I2C1_ER_IRQ)
#define NVIC_IRQ33_I2C2_EV_DIS()		(NVIC_ICER1 |= 1<<(I2C2_EV_IRQ-32))
#define NVIC_IRQ34_I2C2_ER_DIS()		(NVIC_ICER1 |= 1<<(I2C2_ER_IRQ-32))
#endif /* INCLUDES_STM32_F103_X6_H_ */
