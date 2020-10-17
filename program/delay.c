/*
*delay.c
*/

#include "main.h"
#include "delay.h"
static g_time_end = 0;

void delay_nus(unsigned int i)  //��ʱ:i>=12 ,i����С��ʱ��12 us
{ 
  i=i/10;
  while(--i);
}   

void delay_nms(unsigned int n)  //��ʱn ms
{ 
  n=n+1;
  while(--n)  
  delay_nus(900);         //��ʱ 1ms,ͬʱ���в���
}  

/********��ʱ����ȷ��ʱ*********/

//�������� = 1.0851us
void Time0_Init()          //��ʱ����ʼ��
{
	TMOD = 0x01;           //��ʱ��0�����ڷ�ʽ1  
	IE   = 0x82;
	TH0  = 0xff;
	TL0  = 0xa4;     //11.0592MZ����100us
}

void Time0_Int() interrupt 1 //�жϳ���
{
	TR0=0;                 //�ض�ʱ��
	TH0  = 0xff;
	TL0  = 0xa4;     //11.0592MZ����100us
	g_time_end = 1;
}

void delay_100us_t0()
{
	TR0=1;                 //��ʱ����ʼ
	g_time_end = 0;
	while(g_time_end)
	{
		return;
	}
}