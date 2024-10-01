


#ifndef _GPIO_REG_H_
#define _GPIO_REG_H_

/*Registers Addresses*/

/*GPIOA Registers*/
#define GPIOA_BASE_ADDR        0x40010800U
#define GPIOB_BASE_ADDR        0x40010C00U
#define GPIOC_BASE_ADDR        0x40011000U
#define GPIOD_BASE_ADDR        0x40011400U
#define GPIOE_BASE_ADDR        0x40011800U
#define GPIOF_BASE_ADDR        0x40011C00U
#define GPIOG_BASE_ADDR        0x40012000U

typedef struct
{
    __vo u32 CRL;
    __vo u32 CRH;
    __vo u32 IDR;
    __vo u32 ODR;
    __vo u32 BSRR;
    __vo u32 BRR;
    __vo u32 LCKR;
	
}GPIO_RegDef_t;



#define GPIOA    ((GPIO_RegDef_t*)GPIOA_BASE_ADDR)
#define GPIOB    ((GPIO_RegDef_t*)GPIOB_BASE_ADDR)
#define GPIOC    ((GPIO_RegDef_t*)GPIOC_BASE_ADDR)
#define GPIOD    ((GPIO_RegDef_t*)GPIOD_BASE_ADDR)
#define GPIOE    ((GPIO_RegDef_t*)GPIOE_BASE_ADDR)
#define GPIOF    ((GPIO_RegDef_t*)GPIOF_BASE_ADDR)
#define GPIOG    ((GPIO_RegDef_t*)GPIOG_BASE_ADDR)

#define PORTA    0
#define PORTB    1
#define PORTC    2
#define PORTD    3
#define PORTE    4
#define PORTF    5
#define PORTG    6

#endif
