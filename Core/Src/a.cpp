///* USER CODE BEGIN Header */
///**
//  ******************************************************************************
//  * @file           : main.c
//  * @brief          : Main program body
//  ******************************************************************************
//  * @attention
//  *
//  * Copyright (c) 2024 STMicroelectronics.
//  * All rights reserved.
//  *
//  * This software is licensed under terms that can be found in the LICENSE file
//  * in the root directory of this software component.
//  * If no LICENSE file comes with this software, it is provided AS-IS.
//  *
//  ******************************************************************************
//  */
//// Add a new state for reading the results
//// Implement everything with event classes
///* USER CODE END Header */
///* Includes ------------------------------------------------------------------*/
//#include "main.h"
//#include "string.h"
//
///* Private includes ----------------------------------------------------------*/
///* USER CODE BEGIN Includes */
//
//#include <string>
//#include <queue>
//#include "Events.h"
//extern "C"
//{
//	#include "lcd/lcd.h"
//}
//
///* USER CODE END Includes */
//
///* Private typedef -----------------------------------------------------------*/
///* USER CODE BEGIN PTD */
//
//typedef enum
//{
//  IDLE,
//  OPERATING,
//  CLEANING_UP
//
//} State;
//
///* USER CODE END PTD */
//
///* Private define ------------------------------------------------------------*/
///* USER CODE BEGIN PD */
//
//#define GPIO_PIN_BUTTON GPIO_PIN_13
//#define GPIO_PIN_YELLOW GPIO_PIN_0
//#define GPIO_PIN_BLUE GPIO_PIN_7
//#define GPIO_PIN_RED GPIO_PIN_14
//#define DEBOUNCE_THRESHOLD 20 // ms
//
///* USER CODE END PD */
//
///* Private macro -------------------------------------------------------------*/
///* USER CODE BEGIN PM */
//
///* USER CODE END PM */
//
///* Private variables ---------------------------------------------------------*/
//
//ETH_TxPacketConfig TxConfig;
//ETH_DMADescTypeDef  DMARxDscrTab[ETH_RX_DESC_CNT]; /* Ethernet Rx DMA Descriptors */
//ETH_DMADescTypeDef  DMATxDscrTab[ETH_TX_DESC_CNT]; /* Ethernet Tx DMA Descriptors */
//
//ETH_HandleTypeDef heth;
//
//I2C_HandleTypeDef hi2c2;
//
//UART_HandleTypeDef huart3;
//
//PCD_HandleTypeDef hpcd_USB_OTG_FS;
//
///* USER CODE BEGIN PV */
//
//State currentState = IDLE;
//uint32_t currentTime;
//uint32_t lastButtonPressTime;
//uint32_t buttonPressCount;
//LCD_HandleTypeDef lcd;
//bool cleanScreen = false;
//
//// std::queue<Event*> event_queue;
//
//
///* USER CODE END PV */
//
///* Private function prototypes -----------------------------------------------*/
//void SystemClock_Config(void);
//static void MX_GPIO_Init(void);
//static void MX_ETH_Init(void);
//static void MX_USART3_UART_Init(void);
//static void MX_USB_OTG_FS_PCD_Init(void);
//static void MX_I2C2_Init(void);
//
///* USER CODE BEGIN PFP */
//
///* USER CODE END PFP */
//
///* Private user code ---------------------------------------------------------*/
///* USER CODE BEGIN 0 */
//
//void cleanup()
//{
//  HAL_Delay(10000);
//}
//
//void startOperation()
//{
//  HAL_Delay(10000);
//}
//
//
//void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
//{
//  if (GPIO_Pin == GPIO_PIN_BUTTON)
//  {
//    currentTime = HAL_GetTick();
//    cleanScreen = true;
//    if (currentTime - lastButtonPressTime > DEBOUNCE_THRESHOLD)
//    {
//      if (currentState == IDLE)
//      {
//        currentState = OPERATING;
//
//      }
//      else if (currentState == OPERATING)
//      {
//        currentState = CLEANING_UP;
//      }
//
//      lastButtonPressTime = currentTime;
//    }
//  }
//}
//
//
///* USER CODE END 0 */
//
///**
//  * @brief  The application entry point.
//  * @retval int
//  */
//int main(void)
//{
//
//  /* USER CODE BEGIN 1 */
//
//  /* USER CODE END 1 */
//
//  /* MCU Configuration--------------------------------------------------------*/
//
//  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
//  HAL_Init();
//
//  /* USER CODE BEGIN Init */
//
//  /* USER CODE END Init */
//
//  /* Configure the system clock */
//  SystemClock_Config();
//
//  /* USER CODE BEGIN SysInit */
//
//  /* USER CODE END SysInit */
//
//  /* Initialize all configured peripherals */
//  MX_GPIO_Init();
//  MX_ETH_Init();
//  MX_USART3_UART_Init();
//  MX_USB_OTG_FS_PCD_Init();
//  MX_I2C2_Init();
//  /* USER CODE BEGIN 2 */
//
//  lcd.i2c = &hi2c2;
//  lcd.i2c_addr = LCD_DEFAULT_ADDR; // 0x27 << 1
//  lcd.backlight_enable = true;
//  LCD_Begin(&lcd);
//  LCD_Clear(&lcd);
//
//  uint32_t currentBlinkTime = 0;
//  uint32_t lastBlinkTime = 0;
//  const uint32_t blinkInterval = 500;
//
//  /* USER CODE END 2 */
//
//  /* Infinite loop */
//  /* USER CODE BEGIN WHILE */
//  while (1)
//  {
////	if(!event_queue.empty())
////	{
////	  Event* e = event_queue.front();
////
////	  event_queue.pop();
////
////	  e->handleEvent();
////
////	  delete e;
////
////	  e = nullptr;
////   }
//
//
//	if (cleanScreen)
//	{
//	  LCD_Clear(&lcd);
//	  cleanScreen = false;
//	}
//	if (currentState == IDLE)
//	{
////	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_RED, GPIO_PIN_RESET);
////	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_YELLOW, GPIO_PIN_SET);
//	  // Implement external LED using timer, interrupt and pulse (2.4), toggle function
//	  LCD_SetCursor(&lcd, 0, 0);
//	  LCD_Printf(&lcd, "Ready to");
//	  LCD_SetCursor(&lcd, 1, 0);
//	  LCD_Printf(&lcd, "receive input.");
//	}
//	else if (currentState == OPERATING)
//	{
////	  currentBlinkTime = HAL_GetTick(); // ms
////	  if (currentBlinkTime - lastBlinkTime >= blinkInterval)
////	  {
////		HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_YELLOW);
////
////		lastBlinkTime = currentBlinkTime;
////	  }
//	  // Implement external LED using timer, interrupt and pulse (2.4), toggle function
//	  LCD_SetCursor(&lcd, 0, 0);
//	  LCD_Printf(&lcd, "Operating...");
//	  LCD_SetCursor(&lcd, 1, 0);
//	  LCD_Printf(&lcd, "");
//      startOperation();
//      currentState = IDLE;
//      cleanScreen = true;
//	}
//	else if (currentState == CLEANING_UP)
//	{
////	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_YELLOW, GPIO_PIN_RESET);
////	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_RED, GPIO_PIN_SET);
//	  // Implement external LED using timer, interrupt and pulse (2.4), toggle function
//	  LCD_SetCursor(&lcd, 0, 0);
//	  LCD_Printf(&lcd, "Cancelled.");
//	  LCD_SetCursor(&lcd, 1, 0);
//	  LCD_Printf(&lcd, "Cleanup started.");
//      cleanup();
//      currentState = IDLE;
//      cleanScreen = true;
//	}
//
//
//    /* USER CODE END WHILE */
//
//    /* USER CODE BEGIN 3 */
//  }
//  /* USER CODE END 3 */
//}
//
///**
//  * @brief System Clock Configuration
//  * @retval None
//  */
//void SystemClock_Config(void)
//{
//  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
//  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
//
//  /** Configure the main internal regulator output voltage
//  */
//  __HAL_RCC_PWR_CLK_ENABLE();
//  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
//
//  /** Initializes the RCC Oscillators according to the specified parameters
//  * in the RCC_OscInitTypeDef structure.
//  */
//  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
//  RCC_OscInitStruct.HSEState = RCC_HSE_BYPASS;
//  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
//  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
//  RCC_OscInitStruct.PLL.PLLM = 4;
//  RCC_OscInitStruct.PLL.PLLN = 168;
//  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
//  RCC_OscInitStruct.PLL.PLLQ = 7;
//  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
//  {
//    Error_Handler();
//  }
//
//  /** Initializes the CPU, AHB and APB buses clocks
//  */
//  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
//                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
//  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
//  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
//  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
//  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;
//
//  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
//  {
//    Error_Handler();
//  }
//}
//
///**
//  * @brief ETH Initialization Function
//  * @param None
//  * @retval None
//  */
//static void MX_ETH_Init(void)
//{
//
//  /* USER CODE BEGIN ETH_Init 0 */
//
//  /* USER CODE END ETH_Init 0 */
//
//   static uint8_t MACAddr[6];
//
//  /* USER CODE BEGIN ETH_Init 1 */
//
//  /* USER CODE END ETH_Init 1 */
//  heth.Instance = ETH;
//  MACAddr[0] = 0x00;
//  MACAddr[1] = 0x80;
//  MACAddr[2] = 0xE1;
//  MACAddr[3] = 0x00;
//  MACAddr[4] = 0x00;
//  MACAddr[5] = 0x00;
//  heth.Init.MACAddr = &MACAddr[0];
//  heth.Init.MediaInterface = HAL_ETH_RMII_MODE;
//  heth.Init.TxDesc = DMATxDscrTab;
//  heth.Init.RxDesc = DMARxDscrTab;
//  heth.Init.RxBuffLen = 1524;
//
//  /* USER CODE BEGIN MACADDRESS */
//
//  /* USER CODE END MACADDRESS */
//
//  if (HAL_ETH_Init(&heth) != HAL_OK)
//  {
//    Error_Handler();
//  }
//
//  memset(&TxConfig, 0 , sizeof(ETH_TxPacketConfig));
//  TxConfig.Attributes = ETH_TX_PACKETS_FEATURES_CSUM | ETH_TX_PACKETS_FEATURES_CRCPAD;
//  TxConfig.ChecksumCtrl = ETH_CHECKSUM_IPHDR_PAYLOAD_INSERT_PHDR_CALC;
//  TxConfig.CRCPadCtrl = ETH_CRC_PAD_INSERT;
//  /* USER CODE BEGIN ETH_Init 2 */
//
//  /* USER CODE END ETH_Init 2 */
//
//}
//
///**
//  * @brief I2C2 Initialization Function
//  * @param None
//  * @retval None
//  */
//static void MX_I2C2_Init(void)
//{
//  /* USER CODE BEGIN I2C2_Init 0 */
//  /* USER CODE END I2C2_Init 0 */
//  /* USER CODE BEGIN I2C2_Init 1 */
//  /* USER CODE END I2C2_Init 1 */
//  hi2c2.Instance = I2C2;
//  hi2c2.Init.ClockSpeed = 100000;
//  hi2c2.Init.DutyCycle = I2C_DUTYCYCLE_2;
//  hi2c2.Init.OwnAddress1 = 0;
//  hi2c2.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
//  hi2c2.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
//  hi2c2.Init.OwnAddress2 = 0;
//  hi2c2.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
//  hi2c2.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
//  if (HAL_I2C_Init(&hi2c2) != HAL_OK)
//  {
//    Error_Handler();
//  }
//  /** Configure Analogue filter
//  */
//  if (HAL_I2CEx_ConfigAnalogFilter(&hi2c2, I2C_ANALOGFILTER_ENABLE) != HAL_OK)
//  {
//    Error_Handler();
//  }
//  /** Configure Digital filter
//  */
//  if (HAL_I2CEx_ConfigDigitalFilter(&hi2c2, 0) != HAL_OK)
//  {
//    Error_Handler();
//  }
//  /* USER CODE BEGIN I2C2_Init 2 */
//  /* USER CODE END I2C2_Init 2 */
//}
//
///**
//  * @brief USART3 Initialization Function
//  * @param None
//  * @retval None
//  */
//static void MX_USART3_UART_Init(void)
//{
//
//  /* USER CODE BEGIN USART3_Init 0 */
//
//  /* USER CODE END USART3_Init 0 */
//
//  /* USER CODE BEGIN USART3_Init 1 */
//
//  /* USER CODE END USART3_Init 1 */
//  huart3.Instance = USART3;
//  huart3.Init.BaudRate = 115200;
//  huart3.Init.WordLength = UART_WORDLENGTH_8B;
//  huart3.Init.StopBits = UART_STOPBITS_1;
//  huart3.Init.Parity = UART_PARITY_NONE;
//  huart3.Init.Mode = UART_MODE_TX_RX;
//  huart3.Init.HwFlowCtl = UART_HWCONTROL_NONE;
//  huart3.Init.OverSampling = UART_OVERSAMPLING_16;
//  if (HAL_UART_Init(&huart3) != HAL_OK)
//  {
//    Error_Handler();
//  }
//  /* USER CODE BEGIN USART3_Init 2 */
//
//  /* USER CODE END USART3_Init 2 */
//
//}
//
///**
//  * @brief USB_OTG_FS Initialization Function
//  * @param None
//  * @retval None
//  */
//static void MX_USB_OTG_FS_PCD_Init(void)
//{
//
//  /* USER CODE BEGIN USB_OTG_FS_Init 0 */
//
//  /* USER CODE END USB_OTG_FS_Init 0 */
//
//  /* USER CODE BEGIN USB_OTG_FS_Init 1 */
//
//  /* USER CODE END USB_OTG_FS_Init 1 */
//  hpcd_USB_OTG_FS.Instance = USB_OTG_FS;
//  hpcd_USB_OTG_FS.Init.dev_endpoints = 4;
//  hpcd_USB_OTG_FS.Init.speed = PCD_SPEED_FULL;
//  hpcd_USB_OTG_FS.Init.dma_enable = DISABLE;
//  hpcd_USB_OTG_FS.Init.phy_itface = PCD_PHY_EMBEDDED;
//  hpcd_USB_OTG_FS.Init.Sof_enable = ENABLE;
//  hpcd_USB_OTG_FS.Init.low_power_enable = DISABLE;
//  hpcd_USB_OTG_FS.Init.lpm_enable = DISABLE;
//  hpcd_USB_OTG_FS.Init.vbus_sensing_enable = ENABLE;
//  hpcd_USB_OTG_FS.Init.use_dedicated_ep1 = DISABLE;
//  if (HAL_PCD_Init(&hpcd_USB_OTG_FS) != HAL_OK)
//  {
//    Error_Handler();
//  }
//  /* USER CODE BEGIN USB_OTG_FS_Init 2 */
//
//  /* USER CODE END USB_OTG_FS_Init 2 */
//
//}
//
///**
//  * @brief GPIO Initialization Function
//  * @param None
//  * @retval None
//  */
//static void MX_GPIO_Init(void)
//{
//  GPIO_InitTypeDef GPIO_InitStruct = {0};
///* USER CODE BEGIN MX_GPIO_Init_1 */
///* USER CODE END MX_GPIO_Init_1 */
//
//  /* GPIO Ports Clock Enable */
//  __HAL_RCC_GPIOC_CLK_ENABLE();
//  __HAL_RCC_GPIOF_CLK_ENABLE();
//  __HAL_RCC_GPIOH_CLK_ENABLE();
//  __HAL_RCC_GPIOA_CLK_ENABLE();
//  __HAL_RCC_GPIOB_CLK_ENABLE();
//  __HAL_RCC_GPIOD_CLK_ENABLE();
//  __HAL_RCC_GPIOG_CLK_ENABLE();
//
//  /*Configure GPIO pin Output Level */
//  HAL_GPIO_WritePin(GPIOB, LD1_Pin|LD3_Pin|LD2_Pin, GPIO_PIN_RESET);
//
//  /*Configure GPIO pin Output Level */
//  HAL_GPIO_WritePin(USB_PowerSwitchOn_GPIO_Port, USB_PowerSwitchOn_Pin, GPIO_PIN_RESET);
//
//  /*Configure GPIO pin : USER_Btn_Pin */
//  GPIO_InitStruct.Pin = USER_Btn_Pin;
//  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
//  GPIO_InitStruct.Pull = GPIO_NOPULL;
//  HAL_GPIO_Init(USER_Btn_GPIO_Port, &GPIO_InitStruct);
//
//  /*Configure GPIO pins : LD1_Pin LD3_Pin LD2_Pin */
//  GPIO_InitStruct.Pin = LD1_Pin|LD3_Pin|LD2_Pin;
//  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
//  GPIO_InitStruct.Pull = GPIO_NOPULL;
//  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
//  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
//
//  /*Configure GPIO pin : USB_PowerSwitchOn_Pin */
//  GPIO_InitStruct.Pin = USB_PowerSwitchOn_Pin;
//  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
//  GPIO_InitStruct.Pull = GPIO_NOPULL;
//  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
//  HAL_GPIO_Init(USB_PowerSwitchOn_GPIO_Port, &GPIO_InitStruct);
//
//  /*Configure GPIO pin : USB_OverCurrent_Pin */
//  GPIO_InitStruct.Pin = USB_OverCurrent_Pin;
//  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
//  GPIO_InitStruct.Pull = GPIO_NOPULL;
//  HAL_GPIO_Init(USB_OverCurrent_GPIO_Port, &GPIO_InitStruct);
//
//  /* EXTI interrupt init*/
//  HAL_NVIC_SetPriority(EXTI15_10_IRQn, 0, 0);
//  HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
//
///* USER CODE BEGIN MX_GPIO_Init_2 */
///* USER CODE END MX_GPIO_Init_2 */
//}
//
///* USER CODE BEGIN 4 */
//
///* USER CODE END 4 */
//
///**
//  * @brief  This function is executed in case of error occurrence.
//  * @retval None
//  */
//void Error_Handler(void)
//{
//  /* USER CODE BEGIN Error_Handler_Debug */
//  /* User can add his own implementation to report the HAL error return state */
//  __disable_irq();
//  while (1)
//  {
//  }
//  /* USER CODE END Error_Handler_Debug */
//}
//
//#ifdef  USE_FULL_ASSERT
///**
//  * @brief  Reports the name of the source file and the source line number
//  *         where the assert_param error has occurred.
//  * @param  file: pointer to the source file name
//  * @param  line: assert_param error line source number
//  * @retval None
//  */
//void assert_failed(uint8_t *file, uint32_t line)
//{
//  /* USER CODE BEGIN 6 */
//  /* User can add his own implementation to report the file name and line number,
//     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
//  /* USER CODE END 6 */
//}
//#endif /* USE_FULL_ASSERT */