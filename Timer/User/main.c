/* Includes ------------------------------------------------------------------*/
#include "stm8s.h"
#include "stm8s103.h"


void main(void)
{
  //CLK_CONFIG_16MHZ_HSE();  //ham nay dung cho thach anh ngoai
  //Thach anh trong chi co 2MHz thoi
 
  
  /* GPIO configuration -----------------------------------------*/
  GPIO_Init(GPIOB, GPIO_PIN_5, GPIO_MODE_OUT_PP_HIGH_FAST);

  /* TIM2 configuration -----------------------------------------*/
  TIM2_TimeBaseInit(TIM2_PRESCALER_16, 62499); //500ms
  TIM2_ClearFlag(TIM2_FLAG_UPDATE);
  TIM2_ITConfig(TIM2_IT_UPDATE, ENABLE);
  
  enableInterrupts();
  TIM2_Cmd(ENABLE);
  
  while (1)
  {} 
}



#ifdef USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *   where the assert_param error has occurred.
  * @param file: pointer to the source file name
  * @param line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif

/**
  * @}
  */


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
