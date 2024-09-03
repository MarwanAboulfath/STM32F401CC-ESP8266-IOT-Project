
#include "../include/LIB/BIT_MATH.h"
#include "../include/LIB/STD_TYPES.h"
#include "../include/LIB/ARM_Delay.h"
#include "../include/MCAL/MUSART/USART_INTERFACE.h"
#include "../include/HAL/HESP/ESP8266_INTERFACE.h"

u8 volatile Iterator = 0  ;
u8 volatile DataCome[1500] ;

void MUSART_CallBack ( void ){

	/* Receive ESP8266 Response */
	DataCome[ Iterator ] = MUSART1_u8ReadDataRegister();
	/* ------------------ */
	Iterator++;
	MUSART1_VidClearFlags();

}

void ESP8266_VidInit ( void ){

	/* Set USART1 CallBack To Receive The Response Of The ESP8266 */
	MUSART1_VidSetCallBack( MUSART_CallBack );

	MUSART1_VidSendStringSynch( (u8 *)"ATE0\r\n" );

	/* Sending AT Command To Check ESP8266 Is Working Or Not  */
	MUSART1_VidSendStringSynch( (u8 *)"AT\r\n" );



	Delay_MS( 3000 );

	/* Clear ESP8266 Buffer */
	ESP8266_VidClearBuffer();

	MUSART1_VidSendStringSynch( (u8 *)"AT+CWMODE=3\r\n" );
	Delay_MS( 3000 );

	ESP8266_VidClearBuffer();

	MUSART1_VidSendStringSynch( (u8 *)"AT+CIPMODE=0\r\n" );
	Delay_MS( 3000 );

}

void ESP8266_VidConnectToWiFi ( u8 * SSID , u8 * Password ){

	ESP8266_VidClearBuffer();

	MUSART1_VidSendStringSynch( (u8 *) "AT+CWJAP=\"" );
	MUSART1_VidSendStringSynch( (u8 *) SSID );
	MUSART1_VidSendStringSynch( (u8 *) "\",\"" );
	MUSART1_VidSendStringSynch( (u8 *) Password);
	MUSART1_VidSendStringSynch( (u8 *) "\"\r\n");
	Delay_MS( 8000 );

}


void ESP8266_VidConnectToSrvTcp ( u8 * Copy_u8Domain , u8 * Copy_u8Port ){

	ESP8266_VidClearBuffer();

	MUSART1_VidSendStringSynch( (u8 *) "AT+CIPSTART=\"TCP\",\"" );
	MUSART1_VidSendStringSynch( (u8 *) Copy_u8Domain );
	MUSART1_VidSendStringSynch( (u8 *) "\"," );
	MUSART1_VidSendStringSynch( (u8 *) Copy_u8Port );
	MUSART1_VidSendStringSynch( (u8 *) "\r\n" );
	Delay_MS( 2000 );

}

void ESP8266_VidSendHttpReq( u8 * Copy_u8Key , u8 * Copy_u8Data , u8 * Copy_u8Length ){

	ESP8266_VidClearBuffer();

	MUSART1_VidSendStringSynch( (u8 *) "AT+CIPSEND=" );
	MUSART1_VidSendStringSynch( (u8 *) Copy_u8Length );
	MUSART1_VidSendStringSynch( (u8 *) "\r\n" );
	Delay_MS( 4000 );

	ESP8266_VidClearBuffer();

	MUSART1_VidSendStringSynch( (u8 *) "GET /update?api_key=" );
	MUSART1_VidSendStringSynch( (u8 *) Copy_u8Key );
	MUSART1_VidSendStringSynch( (u8 *) "&field1=" );
	MUSART1_VidSendStringSynch( (u8 *) Copy_u8Data );
	MUSART1_VidSendStringSynch( (u8 *) "\r\n" );
	Delay_MS( 20000 );

}

u8   ESP8266_u8ReceiveHttpReq( u8 * Copy_u8ChannelID , u8 * Copy_u8Length ){

	ESP8266_VidClearBuffer();

	MUSART1_VidSendStringSynch( (u8 *) "AT+CIPSEND=" );
	MUSART1_VidSendStringSynch( (u8 *) Copy_u8Length );
	MUSART1_VidSendStringSynch( (u8 *) "\r\n" );
	Delay_MS( 4000 );

	ESP8266_VidClearBuffer();

	MUSART1_VidSendStringSynch( (u8 *) "GET http://" );
	MUSART1_VidSendStringSynch( (u8 *) Copy_u8ChannelID );
	MUSART1_VidSendStringSynch( (u8 *) "/status.txt\r\n" );

	Delay_MS( 2000 );

	ESP8266_VidConnectToSrvTcp( (u8 *)"185.176.43.108" , (u8 *)"80" );

	/*For yrabiot3.freevar.com ( Value Array Index )*/
	return  DataCome[31] ;

}

void ESP8266_VidClearBuffer ( void ){

	u8 LOC_u8Iterator1 = 0 ;
	Iterator     = 0 ;

	for( LOC_u8Iterator1 = 0 ; LOC_u8Iterator1 < 150 ; LOC_u8Iterator1++ ){

		DataCome[ LOC_u8Iterator1 ] = 0 ;

	}

}
