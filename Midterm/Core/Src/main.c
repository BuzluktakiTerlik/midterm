
#include "main.h"
#include "stm32f407xx.h"
int main(void)
{
	RCC->AHB1ENR=0x8;
	RCC->APB2ENR=0x40000;

	TIM11->PSC=0x20; //değeri değiştirdim çünkü duration değerime ulaşamıyodu
	TIM11->ARR=0x65536;

	GPIOD->MODER =0x10000000;
	GPIOD->OTYPER=0x0;
	GPIOD->PUPDR = 0x0;
	GPIOD->OSPEEDR=0xFF000000;

	TIM11->CR1=0x0;
	while(1)
	{
		TIM11->CR1=0x1;
		if( TIM11->CNT >19860){
			GPIOD->ODR^=GPIO_ODR_ODR_14;
			TIM11->CR1=0x0;
			TIM11->CNT=1;
		}
	}
}

