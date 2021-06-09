/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdio.h>
#include <string.h>
extern UART_HandleTypeDef huart1;

int fputc(int ch, FILE *f)
{
  HAL_UART_Transmit(&huart1, (uint8_t *)&ch, 1, 0xffff);
  return ch;
}

int fgetc(FILE *f)
{
  uint8_t ch = 0;
  HAL_UART_Receive(&huart1, &ch, 1, 0xffff);
  return ch;
}
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */
#define RXBUFFERSIZE  512
/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
char RxBuffer[RXBUFFERSIZE]; 
uint8_t aRxBuffer;
int Uart1_Rx_Cnt = 0;

char receive[RXBUFFERSIZE];
char solve_record[RXBUFFERSIZE];

int motor_state[6];

int pwm_delay=1;

int reset_flag=0;

int new_command_flag=0;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
int CommandReceive(void)
{
	if(new_command_flag==1){
	new_command_flag=0;
	int i=0;
	
	if(strcmp(receive,"o\n")==0){ 
		for(i=0;i<RXBUFFERSIZE;i++){
			receive[i]=0;
		}
		return 2; //drop out
	}else if(strcmp(receive,"i\n")==0){
		for(i=0;i<RXBUFFERSIZE;i++){
			receive[i]=0;
		}
		return 3; //load on
	}
	else if(receive[0]=='c'){
		int number=(receive[1]-48)*100+(receive[2]-48)*10+(receive[3]-48);
		if(number>=0 && number<=999){
			pwm_delay=number+1;
		}else{
			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_5,GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOE,GPIO_PIN_5,GPIO_PIN_RESET);
		}
		for(i=0;i<RXBUFFERSIZE;i++){
			receive[i]=0;
		}
		return 4; //changed speed;
	}else if(receive[0]=='U'||receive[0]=='u'||receive[0]=='D'||receive[0]=='d'||receive[0]=='L'||receive[0]=='l'||receive[0]=='R'||receive[0]=='r'||receive[0]=='F'||receive[0]=='f'||receive[0]=='B'||receive[0]=='b'){ //solvecode
		for(i=0;i<RXBUFFERSIZE;i++){
			if(receive[i]=='U'||receive[i]=='u'||receive[i]=='D'||receive[i]=='d'||receive[i]=='L'||receive[i]=='l'||receive[i]=='R'||receive[i]=='r'||receive[i]=='F'||receive[i]=='f'||receive[i]=='B'||receive[i]=='b'){
				solve_record[i]=receive[i];
			}else if(receive[i]=='\r'|| receive[i]=='\n' || receive[i]==' '||receive[i]=='\0'){
				solve_record[i]='\0';
				for(i=0;i<RXBUFFERSIZE;i++){
					receive[i]=0;
				}
				return 1; //receive solve message
			}
		}for(i=0;i<RXBUFFERSIZE;i++){
					receive[i]=0;
				}
				return 1; //receive solve message
	}else if(strcmp(receive,"x\n")==0){
		for(i=0;i<RXBUFFERSIZE;i++){
			receive[i]=0;
		}
		return 6; //reset 
	}else{
				for(i=0;i<RXBUFFERSIZE;i++){
					solve_record[i]=0;
				}
				for(i=0;i<RXBUFFERSIZE;i++){
					receive[i]=0;
				}
				HAL_GPIO_WritePin(GPIOB,GPIO_PIN_5,GPIO_PIN_RESET);
				HAL_GPIO_WritePin(GPIOE,GPIO_PIN_5,GPIO_PIN_RESET);
				return 0; //error
	}
}else {
	return 5; //wait data
}
}

int SingleMotorDrive(char s)
{
	if(reset_flag==1){
		return 0;
	}
	//Solve Code udlrfb ---------->>>>>>>> 012345 Motor Number
	if(s=='u'){
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_6,GPIO_PIN_SET);
		for(int i=0;i<100;i++){
		HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_4);
		HAL_Delay(pwm_delay);
		}
		motor_state[0]++;
	}else if(s=='U'){
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_6,GPIO_PIN_RESET);
		for(int i=0;i<100;i++){
		HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_4);
		HAL_Delay(pwm_delay);
		}
		motor_state[0]--;
	}else if(s=='d'){
		HAL_GPIO_WritePin(GPIOG,GPIO_PIN_13,GPIO_PIN_SET);
		for(int i=0;i<100;i++){
		HAL_GPIO_TogglePin(GPIOG,GPIO_PIN_11);
		HAL_Delay(pwm_delay);
		}
		motor_state[1]++;
	}else if(s=='D'){
		HAL_GPIO_WritePin(GPIOG,GPIO_PIN_13,GPIO_PIN_RESET);
		for(int i=0;i<100;i++){
		HAL_GPIO_TogglePin(GPIOG,GPIO_PIN_11);
		HAL_Delay(pwm_delay);
		}
		motor_state[1]--;
	}else if(s=='l'){
		HAL_GPIO_WritePin(GPIOD,GPIO_PIN_6,GPIO_PIN_SET);
		for(int i=0;i<100;i++){
		HAL_GPIO_TogglePin(GPIOD,GPIO_PIN_4);
		HAL_Delay(pwm_delay);
		}
		motor_state[2]++;
	}else if(s=='L'){
		HAL_GPIO_WritePin(GPIOD,GPIO_PIN_6,GPIO_PIN_RESET);
		for(int i=0;i<100;i++){
		HAL_GPIO_TogglePin(GPIOD,GPIO_PIN_4);
		HAL_Delay(pwm_delay);
		}
		motor_state[2]--;
	}else if(s=='r'){
		HAL_GPIO_WritePin(GPIOD,GPIO_PIN_0,GPIO_PIN_SET);
		for(int i=0;i<100;i++){
		HAL_GPIO_TogglePin(GPIOC,GPIO_PIN_11);
		HAL_Delay(pwm_delay);
		}
		motor_state[3]++;
	}else if(s=='R'){
		HAL_GPIO_WritePin(GPIOD,GPIO_PIN_0,GPIO_PIN_RESET);
		for(int i=0;i<100;i++){
		HAL_GPIO_TogglePin(GPIOC,GPIO_PIN_11);
		HAL_Delay(pwm_delay);
		}
		motor_state[3]--;
	}else if(s=='f'){
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_7,GPIO_PIN_SET);
		for(int i=0;i<100;i++){
		HAL_GPIO_TogglePin(GPIOG,GPIO_PIN_8);
		HAL_Delay(pwm_delay);
		}
		motor_state[4]++;
	}else if(s=='F'){
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_7,GPIO_PIN_RESET);
		for(int i=0;i<100;i++){
		HAL_GPIO_TogglePin(GPIOG,GPIO_PIN_8);
		HAL_Delay(pwm_delay);
		}
		motor_state[4]--;
	}else if(s=='b'){
		HAL_GPIO_WritePin(GPIOG,GPIO_PIN_4,GPIO_PIN_SET);
		for(int i=0;i<100;i++){
		HAL_GPIO_TogglePin(GPIOG,GPIO_PIN_2);
		HAL_Delay(pwm_delay);
		}
		motor_state[5]++;
	}else if(s=='B'){
		HAL_GPIO_WritePin(GPIOG,GPIO_PIN_4,GPIO_PIN_RESET);
		for(int i=0;i<100;i++){
		HAL_GPIO_TogglePin(GPIOG,GPIO_PIN_2);
		HAL_Delay(pwm_delay);
		}
		motor_state[5]--;
	}
	return 0;
}

int MultiMotorDrive(char *control_order)
{
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_5,GPIO_PIN_RESET);
	for(int i=0;i<RXBUFFERSIZE;i++){
		if(control_order[i]=='\0'){
			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_5,GPIO_PIN_SET);
			return 0;
		}else{
			SingleMotorDrive(control_order[i]);
		}
	}
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_5,GPIO_PIN_SET);
	return 0;
}

int ResetToStraight()
{
	int point_state[6];
	for(int i=0;i<6;i++){
		point_state[i]=motor_state[i]%4;
		if(point_state[i]<0){
			point_state[i]=point_state[i]+4;
		}
	}
	if(point_state[0]==1){
		SingleMotorDrive('u');
	}else if(point_state[0]==2){
		SingleMotorDrive('u');
		SingleMotorDrive('u');
	}else if(point_state[0]==3){
		SingleMotorDrive('U');
	}else if(point_state[1]==1){
		SingleMotorDrive('d');
	}else if(point_state[1]==2){
		SingleMotorDrive('d');
		SingleMotorDrive('d');
	}else if(point_state[1]==3){
		SingleMotorDrive('D');
	}else if(point_state[2]==1){
		SingleMotorDrive('l');
	}else if(point_state[2]==2){
		SingleMotorDrive('l');
		SingleMotorDrive('l');
	}else if(point_state[2]==3){
		SingleMotorDrive('L');
	}else if(point_state[3]==1){
		SingleMotorDrive('r');
	}else if(point_state[3]==2){
		SingleMotorDrive('r');
		SingleMotorDrive('r');
	}else if(point_state[3]==3){
		SingleMotorDrive('R');
	}else if(point_state[4]==1){
		SingleMotorDrive('f');
	}else if(point_state[4]==2){
		SingleMotorDrive('f');
		SingleMotorDrive('f');
	}else if(point_state[4]==3){
		SingleMotorDrive('F');
	}else if(point_state[5]==1){
		SingleMotorDrive('b');
	}else if(point_state[5]==2){
		SingleMotorDrive('b');
		SingleMotorDrive('b');
	}else if(point_state[5]==3){
		SingleMotorDrive('B');
	}
	return 0;
}

int ResetToOrigin(char *order)
{
	int count=0;
	char reorder[RXBUFFERSIZE];
	for(int i=0;i<RXBUFFERSIZE;i++){
		if(order[i]=='\0'){
			break;
		}
		count++;
	}
	for(int i=0;i<count;i++)
	{
		reorder[i]=(order[count-i-1]>'a'?(order[count-i-1]-32):(order[count-i-1]+32));
	}
	MultiMotorDrive(reorder);
	return 0;
}

int IfDropOut(int x)
{
	if(x==1){//drop out
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_8,GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOG,GPIO_PIN_15,GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOG,GPIO_PIN_9,GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOD,GPIO_PIN_2,GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_9,GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOG,GPIO_PIN_6,GPIO_PIN_SET);
	}else if(x==0){
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_8,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOG,GPIO_PIN_15,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOG,GPIO_PIN_9,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOD,GPIO_PIN_2,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_9,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOG,GPIO_PIN_6,GPIO_PIN_RESET);
	}
	return 0;
}

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */

  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART1_UART_Init();
  /* USER CODE BEGIN 2 */
	int command_number=0;
	HAL_UART_Receive_IT(&huart1, (uint8_t *)&aRxBuffer, 1);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
		command_number=CommandReceive();
		if(reset_flag==1){
			for(int i=0;i<RXBUFFERSIZE;i++){
				receive[i]=0;
				solve_record[i]=0;
			}
			pwm_delay=1;
			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_5,GPIO_PIN_SET);
			IfDropOut(0);
			HAL_GPIO_WritePin(GPIOE,GPIO_PIN_5,GPIO_PIN_SET);
			reset_flag=0;
		}
		if(command_number==1){
			MultiMotorDrive(solve_record);
		}else if(command_number==2){
			HAL_GPIO_WritePin(GPIOE,GPIO_PIN_5,GPIO_PIN_RESET);
			IfDropOut(1);
		}else if(command_number==3){
			HAL_GPIO_WritePin(GPIOE,GPIO_PIN_5,GPIO_PIN_SET);
			IfDropOut(0);
		}else if(command_number==4 || command_number==5){
			;
		}else if(command_number==6){
			for(int i=0;i<6;i++){
				HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_5);
				HAL_GPIO_TogglePin(GPIOE,GPIO_PIN_5);
				HAL_Delay(300);
			}
		}
		else{
			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_5,GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOE,GPIO_PIN_5,GPIO_PIN_RESET);
		}
		
    /* USER CODE END WHILE */
		
    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(huart);
  /* NOTE: This function Should not be modified, when the callback is needed,
           the HAL_UART_TxCpltCallback could be implemented in the user file
   */
 
	if(Uart1_Rx_Cnt >= RXBUFFERSIZE-1)  //full judge
	{
		Uart1_Rx_Cnt = 0;
		memset(RxBuffer,0x00,sizeof(RxBuffer));	   
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_5,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOE,GPIO_PIN_5,GPIO_PIN_RESET);
	}
	else
	{
		RxBuffer[Uart1_Rx_Cnt++] = aRxBuffer;   //receive to temp
	
		if(RxBuffer[Uart1_Rx_Cnt-1] == '\n') //stop symbol bit
		{
			if(strcmp(RxBuffer,"x\n")==0){
				reset_flag=1;
			}
			for(int i=0;i<Uart1_Rx_Cnt;i++)
			{
				receive[i]=RxBuffer[i];
			}
			new_command_flag=1;
			Uart1_Rx_Cnt = 0;
			memset(RxBuffer,0x00,sizeof(RxBuffer)); //reset Rxbuffer
		}
	}
	
	HAL_UART_Receive_IT(&huart1, (uint8_t *)&aRxBuffer, 1);   //continue open irq
}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{ 
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
