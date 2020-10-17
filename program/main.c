/*
*main.c
*/


#include "main.h"
#include "delay.h"
#include "servo.h"
#include "uart.h"
#include "sensor.h"

extern int BEARDTIME;

int main(void)
{
		
		int i = 0,j = 0;
		//Æô¶¯
		SetGreenLed;
		SetRedLed;
#if (UARTON == 1)
	uart_init();
#endif
	BEARDTIME = 0;
	while(1)
	{	
		
//		ServoMove(200,200);
		
	
		ServoMoveFollowLine();

if((ReadLeftBeard() == 0)||ReadLeftBeard()==0)
		{
			if(!BEARDTIME)
			{
				ResetRedLed;
				ResetGreenLed;
				for(i = 0;i<26;i++){ ServoMove(-250,250); }
				BEARDTIME++;
				ServoMove(1,1);
				delay_nms(1000);
				delay_nms(1000);
				delay_nms(1000);
				delay_nms(1000);
				delay_nms(1000);	
	  	}
 		}
	
		
	if((ReadLeftBeard() == 0)||ReadLeftBeard()==0)
		{
			if(BEARDTIME)
			{
			ResetRedLed;
			ResetGreenLed;
			for(j = 0;j<26;j++){ ServoMove(250,-250); }
			BEARDTIME=0;}
			ServoMove(1,1);
			delay_nms(1000);   
			delay_nms(1000);
			delay_nms(1000);
			delay_nms(1000);
			delay_nms(1000);	
			BEARDTIME=0;
	}	
	}
		return 0;
}


