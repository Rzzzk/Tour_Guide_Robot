


#include "../common_lib/imp_data_types.h"
#include "../common_lib/error_state.h"
#include "../common_lib/bit_math.h"

#include "gpio.h"
#include "gpio_reg.h"


ES_t GPIO_enuInit(GPIO_Handle_t *Copy_pstrGPIO)
{
	ES_t Local_enuErrorState=ES_NOT_OK;

	u8 temp=0;
	
	switch(Copy_pstrGPIO->GPIO_Port)
	{
	case GPIO_u8PORTA:
		if(Copy_pstrGPIO->GPIO_PinNumber <= 7)
		{
			//CRL
			GPIOA->CRL &= ~(0b1111 << (Copy_pstrGPIO->GPIO_PinNumber*4));
			GPIOA->CRL |= (Copy_pstrGPIO->GPIO_Mode << (Copy_pstrGPIO->GPIO_PinNumber*4));
		}
		else if(Copy_pstrGPIO->GPIO_PinNumber <= 15)
		{

			//CRH
			temp = Copy_pstrGPIO->GPIO_PinNumber - 8;
			GPIOA->CRH &= ~(0b1111 << (temp*4));
			GPIOA->CRH |= (Copy_pstrGPIO->GPIO_Mode << (temp*4));
		}
		break;


	case GPIO_u8PORTB:
		if(Copy_pstrGPIO->GPIO_PinNumber <= 7)
		{
			//CRL
			GPIOB->CRL &= ~(0b1111 << (Copy_pstrGPIO->GPIO_PinNumber*4));
			GPIOB->CRL |= (Copy_pstrGPIO->GPIO_Mode << (Copy_pstrGPIO->GPIO_PinNumber*4));
		}
		else if(Copy_pstrGPIO->GPIO_PinNumber <= 15)
		{

			//CRH
			temp = Copy_pstrGPIO->GPIO_PinNumber - 8;
			GPIOB->CRH &= ~(0b1111 << (temp*4));
			GPIOB->CRH |= (Copy_pstrGPIO->GPIO_Mode << (temp*4));
		}
		break;


	case GPIO_u8PORTC:
		if(Copy_pstrGPIO->GPIO_PinNumber <= 7)
		{
			//CRL
			GPIOC->CRL &= ~(0b1111 << (Copy_pstrGPIO->GPIO_PinNumber*4));
			GPIOC->CRL |= (Copy_pstrGPIO->GPIO_Mode << (Copy_pstrGPIO->GPIO_PinNumber*4));
		}
		else if(Copy_pstrGPIO->GPIO_PinNumber <= 15)
		{

			//CRH
			temp = Copy_pstrGPIO->GPIO_PinNumber - 8;
			GPIOC->CRH &= ~(0b1111 << (temp*4));
			GPIOC->CRH |= (Copy_pstrGPIO->GPIO_Mode << (temp*4));
		}

		break;
	}


	return Local_enuErrorState;
}

ES_t GPIO_enuWriteOutputPin(u8 Copy_u8PortID, u8 Copy_u8Pin , u8 Copy_u8Value)
{
	ES_t Local_enuErrorState=ES_NOT_OK;

	switch(Copy_u8PortID)
	{
	case GPIO_u8PORTA :
		if(Copy_u8Value == GPIO_u8HIGH)
		{
			SET_BIT(GPIOA->ODR,Copy_u8Pin);
		}
		else if(Copy_u8Value == GPIO_u8LOW)
		{
			CLR_BIT(GPIOA->ODR,Copy_u8Pin);
		}
		break;

	case GPIO_u8PORTB :
		if(Copy_u8Value == GPIO_u8HIGH)
		{
			SET_BIT(GPIOB->ODR,Copy_u8Pin);
		}
		else if(Copy_u8Value == GPIO_u8LOW)
		{
			CLR_BIT(GPIOB->ODR,Copy_u8Pin);
		}
		break;

	case GPIO_u8PORTC :
		if(Copy_u8Value == GPIO_u8HIGH)
		{
			SET_BIT(GPIOC->ODR,Copy_u8Pin);
		}
		else if(Copy_u8Value == GPIO_u8LOW)
		{
			CLR_BIT(GPIOC->ODR,Copy_u8Pin);
		}
		break;
	}

	return Local_enuErrorState;
}

ES_t GPIO_enuTogleOutputPin(u8 Copy_u8PortID, u8 Copy_u8Pin)
{
	ES_t Local_enuErrorState=ES_NOT_OK;
	switch(Copy_u8PortID)
	{
	case GPIO_u8PORTA : TOG_BIT(GPIOA->ODR,Copy_u8Pin); break;

	case GPIO_u8PORTB : TOG_BIT(GPIOB->ODR,Copy_u8Pin); break;

	case GPIO_u8PORTC : TOG_BIT(GPIOC->ODR,Copy_u8Pin); break;
	}

	return Local_enuErrorState;
}

ES_t GPIO_enuReadInputPin(u8 Copy_u8PortID, u8 Copy_u8Pin, u8 *Copy_pu8Value)
{
	ES_t Local_enuErrorState=ES_NOT_OK;
	switch(Copy_u8PortID)
	{
	case GPIO_u8PORTA:
		*Copy_pu8Value= GET_BIT(GPIOA->IDR,Copy_u8Pin);
		break;

	case GPIO_u8PORTB:
		*Copy_pu8Value = GET_BIT(GPIOB->IDR,Copy_u8Pin);
		break;

	case GPIO_u8PORTC:
		*Copy_pu8Value = GET_BIT(GPIOC->IDR,Copy_u8Pin);
		break;
	}
}
