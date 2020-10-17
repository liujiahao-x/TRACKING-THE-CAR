/*
*senvo.c
*/
#ifndef _SERVO_H
#define _SERVO_H


void SetLeftServo(void);
void ResetLeftServo(void);

void SetRightServo(void);
void ResetRightServo(void);

int ServoLeft(int left_speed);
int ServoRight(int right_speed);

int ServoMove(int servo_left_speed,int servo_right_speed);
void ServoMoveFollowLine(void);
void ServoMoveFollowBeard(void);
void bread_touch_1(int a,int b);
void bread_touch_2(int a,int b);
void bread_touch_3(int a,int b);



#endif