/*
*senvo.c
*/
#include "main.h"
#include "delay.h"
#include "servo.h"
#include "sensor.h"

#define SERVOLEFTON 					SetLeftServo()
#define SERVOLEFTOFF 					ResetLeftServo()
#define SERVORIGHTON 					SetRightServo()
#define SERVORIGHTOFF 				ResetRightServo()

int BEARDTIME = 0;

int ServoLeft(int left_speed)			
{	
	SERVOLEFTON;
	delay_nus(1400+left_speed);
	SERVOLEFTOFF;
	delay_nms(20);				//20ms
	return 0;
}

int ServoRight(int right_speed)			
{	
	SERVORIGHTON;
	delay_nus(1500-right_speed);
	SERVORIGHTOFF;
	delay_nms(20);				//20ms
	return 0;
}

int ServoMove(int servo_left_speed,int servo_right_speed)
{	
	#if 1
	SERVOLEFTON;
	delay_nus(1400-servo_left_speed);
	SERVOLEFTOFF;
	SERVORIGHTON;
	delay_nus(1500+servo_right_speed);
	SERVORIGHTOFF;
	delay_nms(20);
	#endif
//	ServoLeft(servo_left_speed);
//	ServoRight(servo_right_speed);
	return 0;
}

void SetLeftServo(void)
{
	P1 |= (1<<0);
}

void ResetLeftServo(void)
{
	P1 &= ~(1<<0);
}

void SetRightServo(void)
{
	P1 |= (1<<1);			//P1.1 = 1
}

void ResetRightServo(void)
{
	P1 &= ~(1<<1);			//P1.1 = 0
}


void ServoMoveFollowLine(void)
{
		
		int  irDetectLeft,irDetectRight;
		SetGreenLed;
		ResetRedLed;
		IRLaunch('R'); 																//右边发射
		irDetectRight = ReadRightSensor();							//右边接收
		IRLaunch('L'); 																//左边发射
		irDetectLeft = ReadLeftSensor();								//左边接收
		printf("ReadLeftSensor = %d                        ReadRightSensor= %d\n",irDetectLeft,irDetectRight);
//	  if((irDetectLeft==0)&&(irDetectRight==0))    		{ ServoMove(200,200); }						//IR传感器
//		else if((irDetectLeft==0)&&(irDetectRight==1))	{ ServoMove(200,-100); }					//turn right
//		else if((irDetectLeft==1)&&(irDetectRight==0))	{ ServoMove(-100,200); }					//turn left				
//		else  {  ServoMove(-100,200);}																											//
	
	  if((irDetectLeft==1)&&(irDetectRight==1))    		{ ServoMove(250,250); }						//光电管
		else if((irDetectLeft==1)&&(irDetectRight==0))	{ ServoMove(250,-200); }					//turn right
		else if((irDetectLeft==0)&&(irDetectRight==1))	{ ServoMove(-200,250); }					//turn left				
		else  {  ServoMove(-250,250);}																											//
}	

void test_sesor(void)
{
		int  irDetectLeft,irDetectRight;
		IRLaunch('R'); 																//右边发射
		irDetectRight = ReadRightSensor();							//右边接收
		IRLaunch('L'); 																//左边发射
		irDetectLeft = ReadLeftSensor();								//左边接收
		printf("ReadLeftSensor = %d                        ReadRightSensor= %d\n",irDetectLeft,irDetectRight);																							//
}	

void ServoMoveFollowBeard(void)
{
	int BeardDetectLeft,BeardDetectRight;
	BeardDetectLeft = ReadLeftBeard();
	BeardDetectRight = ReadRightBeard();
	if((BeardDetectLeft == 0)||BeardDetectRight==0){ BEARDTIME++; }
	if(1 == BEARDTIME){ServoMove(0,200);delay_nms(500);}
	if(2 == BEARDTIME){ServoMove(200,0);delay_nms(500);}
}


void bread_touch_1(int a,int b)
{
		
	  int i=0;
		if((a == 0)||b == 0)
		{
			if(!BEARDTIME)
			{
	  	ResetGreenLed;
			SetRedLed;
			for(i = 0;i<26;i++){ ServoMove(-250,250); }
			BEARDTIME++;
			ResetRedLed;
			ResetGreenLed;
			ServoMove(1,1);
			delay_nms(1000);
			delay_nms(1000);
			delay_nms(1000);
			delay_nms(1000);
			delay_nms(1000);	
		  }
		}	
}
		
void bread_touch_2(int a,int b)
{
		
		int j=0;
		if((a == 0)||b ==0 )
		{
			if(BEARDTIME)
			{
			ResetGreenLed;
			SetRedLed;
			for(j = 0;j<26;j++){ ServoMove(250,-250); }
			BEARDTIME=0;
			ServoMove(1,1);
			ResetRedLed;
			ResetGreenLed;
			delay_nms(1000);
			delay_nms(1000);
			delay_nms(1000);
			delay_nms(1000);
			delay_nms(1000);	
			BEARDTIME++;
		}
	}
}

void bread_touch_3(int a,int b)
{
		
		if((a == 0)||b ==0 )
		{
			if(BEARDTIME==2)
			{
				ResetGreenLed;
				ResetRedLed;
				ServoMove(1,1);
				BEARDTIME=0;	
				while(1){;}
		}
	}
}