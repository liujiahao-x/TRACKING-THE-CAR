/*
*uart.c
*/
#include "main.h"


void uart_init(void)
{
	TMOD=0x20;//即0010 0000,定时器/计数器1,工作方式2
	TH1=0xfd;//设置波特率为9600
	TL1=0xfd;
	TR1=1;//启动定时器/计数器1
	
	SCON=0x50; //0101 0000.串口工作方式1，允许串行控制
	PCON=0x00;//设置SMOD=0
	IE=0x90; //CPU允许中断，串行允许中断
	
	TI=1;//直接使用printf必须加入此句才能实现发送
}