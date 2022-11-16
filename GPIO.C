/**
  ******************************************************************************
  * @file    GPIO.C
  * @author  korsan meriam
  * @brief   GPIOD DRIVER
  * @version V1.0.1
  * @date    16-11-2022
  *****************************************************************************/

/* Includes ------------------------------------------------------------------*/

#include "GPIO.h"
/* Macros --------------------------------------------------------------------*/
#define MODER_OFFSET          0x00
#define GPIOx_OTYPER_OFFSET   0x04
#define GPIOA_BASE            0x40020000
#define GPIOB_BASE            0x40020400
#define GPIOC_BASE            0x40020800
#define GPIOD_BASE            0x40020c00

/* Functions --------------------------------------------------------------------*/
void GPIO_CLOCK_Enable(uint32_t *GPIOx)
{
  assert(GPIOx == GPIOA || GPIOx == GPIOB || GPIOx == GPIOC || GPIOx == GPIOD );
  uint16_t *RCCAHB1 = (uint16_t *)(0x40023830);
 
  if ( GPIOx ==GPIOA )
  {
    *RCCAHB1 |= (1<<0);
  }
  else if ( GPIOx ==GPIOB )
  {
    *RCCAHB1 |= (1<<1);
  }
  else if ( GPIOx ==GPIOC )
  {
    *RCCAHB1 |= (1<<2);
  }
  else if ( GPIOx ==GPIOD )
  {
    *RCCAHB1 |= (1<<3);
  }
 
}

void GPIO_Config (uint32_t *GPIOx, uint8_t Pin,  uint8_t Mode, uint8_t Type)
{
 assert(GPIOx == GPIOA || GPIOx == GPIOB || GPIOx == GPIOC || GPIOx == GPIOD );
 assert (Mode == OUTPUT || Mode == INPUT ||Mode == ALTERNATE || Mode == ANALOG_INPUT);
 assert (Type == OUTPUT_PUSH_PULL || Type == OUTPUT_OPEN_DRAIN  );
 
uint32_t *GPIOA_MODER=(uint32_t *)(  GPIOA_BASE + MODER_OFFSET);
uint32_t *GPIOB_MODER=(uint32_t *)(  GPIOB_BASE + MODER_OFFSET);
uint32_t *GPIOC_MODER=(uint32_t *)(  GPIOC_BASE + MODER_OFFSET);
uint32_t *GPIOD_MODER=(uint32_t *)(  GPIOD_BASE + MODER_OFFSET);

uint16_t *GPIOA_OTYPER=(uint16_t *)(  GPIOA_BASE + GPIOx_OTYPER_OFFSET);
uint16_t *GPIOB_OTYPER=(uint16_t *)(  GPIOB_BASE + GPIOx_OTYPER_OFFSET);
uint16_t *GPIOC_OTYPER=(uint16_t *)(  GPIOC_BASE + GPIOx_OTYPER_OFFSET);
uint16_t *GPIOD_OTYPER=(uint16_t *)(  GPIOD_BASE + GPIOx_OTYPER_OFFSET);


 if( GPIOx == GPIOA){
   switch (Mode)
   {
      case (INPUT):   
        *GPIOA_MODER &= ~((1<<(2*Pin)) | (1<<(2*Pin+1))); /* Pin PAx as INPUT*/
        break;
      case (OUTPUT):
        *GPIOA_MODER |=(1<<(2*Pin));                      /* Pin PAx as OUTPUT*/
        break;     
      case (ALTERNATE):
        *GPIOA_MODER |=(1<<(2*Pin+1));                    /* Pin PAx as ALTERNATE*/
        break;
      case (ANALOG_INPUT):
        *GPIOA_MODER |= ((1<<(2*Pin)) | (1<<(2*Pin+1)));  /* Pin PAx as ANALOG_INPUT*/
        break;
   }
   
   switch (Type)
   {
      case (OUTPUT_PUSH_PULL):
        *GPIOA_OTYPER &=~(1<<Pin);                         /* Pin PAx as OUTPUT PUSH PULL*/
        break;
      case ( OUTPUT_OPEN_DRAIN):
        *GPIOA_OTYPER |=(1<<Pin);                         /* Pin PAx as OUTPUT OPEN DRAIN*/
        break;
      
   }       
 }
  
 else if( GPIOx == GPIOB){
   switch (Mode)
   {
      case (INPUT):   
        *GPIOB_MODER &= ~((1<<(2*Pin)) | (1<<(2*Pin+1)));  /* Pin PBx as INPUT*/
        break;
      case (OUTPUT):
         *GPIOB_MODER |=(1<<(2*Pin));                      /* Pin PBx as OUTPUT*/
        break;     
      case (ALTERNATE):
        *GPIOB_MODER &=~(1<<(2*Pin));
        *GPIOB_MODER |=(1<<(2*Pin+1));                    /* Pin PBx as ALTERNATE*/
        break;
      case (ANALOG_INPUT):
        *GPIOB_MODER |= ((1<<(2*Pin)) | (1<<(2*Pin+1)));  /* Pin PBx as ANALOG_INPUT*/
        break;
   }
   
   switch (Type)
   {
      case (OUTPUT_PUSH_PULL):
        *GPIOB_OTYPER &=~(1<<Pin);                        /* Pin PBx as OUTPUT PUSH PULL*/
        break;
      case (OUTPUT_OPEN_DRAIN):
        *GPIOB_OTYPER |=(1<<Pin);                        /* Pin PBx as OUTPUT OPEN DRAIN*/
        break;
   }        
 }
 else if( GPIOx == GPIOC){
   switch (Mode)
   {
      case (INPUT):   
        *GPIOC_MODER &= ~((1<<(2*Pin)) | (1<<(2*Pin+1))); /* Pin PCx as INPUT*/
        break;
      case (OUTPUT):
        *GPIOC_MODER |=(1<<(2*Pin));                       /* Pin PCx as OUTPUT*/
        break;     
     
      case (ALTERNATE):                                    /* Pin PCx as ALTERNATE*/
        *GPIOC_MODER &=~(1<<(2*Pin));
        *GPIOC_MODER |=(1<<(2*Pin+1));
        break;
      case (ANALOG_INPUT):
        *GPIOC_MODER |= ((1<<(2*Pin)) | (1<<(2*Pin+1)));   /* Pin PCx as ANALOG_INPUT*/
        break;
   }
   switch (Type )
   {
      case (OUTPUT_PUSH_PULL):
        *GPIOC_OTYPER &=~(1<<Pin);                        /* Pin PCx as OUTPUT PUSH PULL*/
        break;
      case (OUTPUT_OPEN_DRAIN):
        *GPIOC_OTYPER |=(1<<Pin);                         /* Pin PCx as OUTPUT OPEN DRAIN*/
        break;
     
   }        
 } 
 
 else if( GPIOx == GPIOD){
   switch (Mode)
   {
      case (INPUT):   
        *GPIOD_MODER &= ~((1<<(2*Pin)) | (1<<(2*Pin+1))); /* Pin PDx as INPUT*/
        break;
      case (OUTPUT):
        *GPIOD_MODER |=(1<<(2*Pin));                     /* Pin PDx as OUTPUT*/
        break;     
      case (ALTERNATE):
        *GPIOD_MODER &=~(1<<(2*Pin));
        *GPIOD_MODER |=(1<<(2*Pin+1));                   /* Pin PDx as ALTERNATE*/
        break;
      case (ANALOG_INPUT):
        *GPIOD_MODER |= ((1<<(2*Pin)) | (1<<(2*Pin+1))); /* Pin PDx as ANALOG_INPUT*/
        break;
   }
   switch (Type )
   {
      case (OUTPUT_PUSH_PULL):
        *GPIOD_OTYPER &=~(1<<Pin);                       /* Pin PDx as OUTPUT PUSH PULL*/
        break;
      case (OUTPUT_OPEN_DRAIN):
        *GPIOD_OTYPER |=(1<<Pin);                        /* Pin PDx as OUTPUT OPEN DRAIN*/
        break;
     
   }        
 }
    
}
