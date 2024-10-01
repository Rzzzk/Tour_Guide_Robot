


#ifndef _GPIO_H_
#define _GPIO_H_

typedef struct
{
	u8 GPIO_Port;
	u8 GPIO_PinNumber;
	u8 GPIO_Mode;
}GPIO_Handle_t;

/*Port ID*/
#define GPIO_u8PORTA      0
#define GPIO_u8PORTB      1
#define GPIO_u8PORTC      2

/*Pins*/
#define GPIO_u8PIN0       0
#define GPIO_u8PIN1       1
#define GPIO_u8PIN2       2
#define GPIO_u8PIN3       3
#define GPIO_u8PIN4       4
#define GPIO_u8PIN5       5
#define GPIO_u8PIN6       6
#define GPIO_u8PIN7       7
#define GPIO_u8PIN8       8
#define GPIO_u8PIN9       9
#define GPIO_u8PIN10      10
#define GPIO_u8PIN11      11
#define GPIO_u8PIN12      12
#define GPIO_u8PIN13      13
#define GPIO_u8PIN14      14
#define GPIO_u8PIN15      15

/*Modes*/
/*Output 10 MHz*/
#define GPIO_u8OUTPUT_10MHZ_PP      0b0001
#define GPIO_u8OUTPUT_10MHZ_OD      0b0101
#define GPIO_u8OUTPUT_10MHZ_AF_PP   0b1001
#define GPIO_u8OUTPUT_10MHZ_AF_OD   0b1101

/*Output 2 MHz*/
#define GPIO_u8OUTPUT_2MHZ_PP       0b0010
#define GPIO_u8OUTPUT_2MHZ_OD       0b0110
#define GPIO_u8OUTPUT_2MHZ_AF_PP    0b1010
#define GPIO_u8OUTPUT_2MHZ_AF_OD    0b1110

/*Output 50 MHz*/
#define GPIO_u8OUTPUT_50MHZ_PP      0b0011
#define GPIO_u8OUTPUT_50MHZ_OD      0b0111
#define GPIO_u8OUTPUT_50MHZ_AF_PP   0b1011
#define GPIO_u8OUTPUT_50MHZ_AF_OD   0b1111

/*Input*/
#define GPIO_u8INPUT_ANALOG         0b0000
#define GPIO_u8INPUT_FLOATING       0b0100
#define GPIO_u8INPUT_PULL_UP_DOWN   0b1000

/*Pin values*/
#define GPIO_u8HIGH  1
#define GPIO_u8LOW   0



ES_t GPIO_enuInit(GPIO_Handle_t *Copy_pstrGPIO);
ES_t GPIO_enuWriteOutputPin(u8 Copy_u8PortID, u8 Copy_u8Pin , u8 Copy_u8Value);
ES_t GPIO_enuTogleOutputPin(u8 Copy_u8PortID, u8 Copy_u8Pin);
ES_t GPIO_enuReadInputPin(u8 Copy_u8PortID, u8 Copy_u8Pin, u8 *Copy_pu8Value);


#endif
