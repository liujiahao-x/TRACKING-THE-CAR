/*
*delay.c
*/

#include "main.h"
#include "delay.h"
static g_time_end = 0;

void delay_nus(unsigned int i)  //延时:i>=12 ,i的最小延时单12 us
{ 
  i=i/10;
  while(--i);
}   

void delay_nms(unsigned int n)  //延时n ms
{ 
  n=n+1;
  while(--n)  
  delay_nus(900);         //延时 1ms,同时进行补偿
}  

/********定时器精确延时*********/

//机器周期 = 1.0851us
void Time0_Init()          //定时器初始化
{
	TMOD = 0x01;           //定时器0工作在方式1  
	IE   = 0x82;
	TH0  = 0xff;
	TL0  = 0xa4;     //11.0592MZ晶振，100us
}

void Time0_Int() interrupt 1 //中断程序
{
	TR0=0;                 //关定时器
	TH0  = 0xff;
	TL0  = 0xa4;     //11.0592MZ晶振，100us
	g_time_end = 1;
}

void delay_100us_t0()
{
	TR0=1;                 //定时器开始
	g_time_end = 0;
	while(g_time_end)
	{
		return;
	}
}