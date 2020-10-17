/*
*sensor.h
*/

#ifndef _SENSOR_H
#define _SENSOR_H

typedef enum
{
  false = 0,
  true = 1
}_bool;

#define GetLeftIR       			((P3&(1<<5)) != 0 ? true:false)									//左边红外接收连接到P3_5//jiahao
#define GetRightIR      			((P0&(1<<1)) != 0 ? true:false)  							//右边红外接收连接到P0_1


#define GetRightBeard						((P1&(1<<5)) != 0 ? true:false)								//右边胡须接收连接到P1_5
#define GetLeftBeard      			((P2&(1<<3)) != 0 ? true:false)  							//左边胡须接收连接到P2_3

//左边红外发射连接到P1_3
#define SetLeftLaunch   			P3|=(1<<6)				//P3.6 = 1
#define ResetLeftLaunch   		P3&=~(1<<6)				//P3.6 = 0

//右边红外发射连接到P3_6
#define SetRightLaunch  			P1|=(1<<4)    		//P1.4 = 1
#define ResetRightLaunch  		P1&=~(1<<4)				//P1.4 = 0

//黄显示灯
#define SetGreenLed  			P2|=(1<<4)    		//P2.4 = 1
#define ResetGreenLed 		P2&=~(1<<4)				//P2.4 = 0

//蓝显示灯
#define SetRedLed  			P2|=(1<<2)    			//P2.2 = 1
#define ResetRedLed 		P2&=~(1<<2)					//P2.2 = 0


_bool ReadLeftSensor(void);
_bool ReadRightSensor(void);

_bool ReadLeftBeard(void);
_bool ReadRightBeard(void);

void IRLaunch(unsigned char IR);



#endif