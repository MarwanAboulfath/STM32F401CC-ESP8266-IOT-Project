
/*****************************************************/
/*					FILES INCLUSIONS				 */
/*****************************************************/

/************************LIB**************************/
#include "../include/LIB/BIT_MATH.h"
#include "../include/LIB/STD_TYPES.h"
#include "../include/LIB/ARM_Delay.h"
/************************MCAL*************************/
#include "../include/MCAL/MRCC/MRCC_Interface.h"
#include "../include/MCAL/MGPIO/MGPIO_Interface.h"
#include "../include/MCAL/MNVIC/MNVIC_Interface.h"
#include "../include/MCAL/MUSART/USART_INTERFACE.h"
/************************HAL**************************/
#include "../include/HAL/HESP/ESP8266_INTERFACE.h"

/************************************************************************/
/*							ENTRY POINT <main>							*/
/************************************************************************/


int main ( void ){

	/***********************Local Variable*************************/
	u8 LOC_u8Data = 0;
	/***********************Clock initialization*************************/
	/* Initialize RCC */
	MRCC_voidInit();
	MRCC_voidEnablePeripheral(RCC_AHB1,RCC_AHB1_GPIOA);
	MRCC_voidEnablePeripheral(RCC_APB2,RCC_APB2_USART1);

	/* Configure UART pins  */
	MGPIO_voidSetPinMode(GPIO_PORTA,GPIO_PIN9,GPIO_ALT_FUNC);
	MGPIO_voidSetPinMode(GPIO_PORTA,GPIO_PIN10,GPIO_ALT_FUNC);
	MGPIO_voidSetAF(GPIO_PORTA,GPIO_PIN9,7);
	MGPIO_voidSetAF(GPIO_PORTA,GPIO_PIN10,7);

	/* Configure Pin for Led */
	MGPIO_voidSetPinMode(GPIO_PORTA,GPIO_PIN0,GPIO_OUTPUT);//pin for the led
	MGPIO_voidSetPinOutputMode(GPIO_PORTA,GPIO_PIN0,GPIO_PUSH_PULL,GPIO_LOW_SPEED);

	/* Enable NVIC For UART1 */
	MNVIC_voidEnablePeripheralInterrupt(USART1_IRQ);
	/* Initialize UART */
	MUSART_VidInit();
	/* Initialize ESP8266 */
	ESP8266_VidInit();

	/* Connect to WIFI Network */
	ESP8266_VidConnectToWiFi((u8*)"DESKTOP-3BBBL7U3833",(u8*)"033t34OR");

	while(1){

		/* Connecting To SERVER marwan1.atwebpages.com */
		ESP8266_VidConnectToSrvTcp((u8*)"185.176.43.108",(u8*)"80");

		/* Fetch data from SERVER marwan1.atwebpages.com */
		LOC_u8Data = ESP8266_u8ReceiveHttpReq((u8*)"marwan1.atwebpages.com",(u8*)"47");

		Delay_MS(100);

		/* Check for received signal from server */
		if(LOC_u8Data == '1')
		{
			/* Set Led pin to high */
			MGPIO_voidSetPinValue(GPIO_PORTA,GPIO_PIN0,GPIO_PIN_HIGH);
		}
		else if(LOC_u8Data == '0')
		{
			/* Set Led pin to low */
			MGPIO_voidSetPinValue(GPIO_PORTA,GPIO_PIN0,GPIO_PIN_LOW);
		}

	}

	return 0;

}


