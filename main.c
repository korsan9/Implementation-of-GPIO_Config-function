/**
  ******************************************************************************
  * @file    main.c
  * @author  korsan meriam
  * @brief   GPIOD DRIVER
  * @version V1.0.1
  * @date    16-11-2022
  *****************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "GPIO.h"

int main()

{
 GPIO_CLOCK_Enable(GPIOD);                              /*Activate GPIOx clock*/
 GPIO_Config(GPIOB,PIN4,ALTERNATE,OUTPUT_PUSH_PULL);   /*Config PXx */

while(1)
 {
 }
}


/**************************************END OF FILE**************************************/
