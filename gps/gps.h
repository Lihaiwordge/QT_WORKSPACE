#ifndef _GPS_H_
#define _GPS_H_

#include <string.h>
#include <stdlib.h>

typedef struct{
	int year;
	int month;
	int day;
	int hour;
	int minute;
	int second;
	char time_c[10];      //ACSII��ʽ��ʱ��
}data_time;

typedef struct{
	data_time D;          //ʱ��
	char status;          //����״̬
	double latitude;      //γ��
	char latitude_c[11];  //ASCII��ʽ��γ��
	double longitude;     //����
	char longitude_c[11]; //ASCII��ʽ�ľ���
	char NS;              //�ϱ�
	char EW;              //����
	double speed;         //�ٶ�
	char speed_c[10];     //ASCII��ʽ���ٶ�
	double high;          //�߶�
}GPS_INFO;

extern char buf_t[128];
extern GPS_INFO GPS;

extern int GPS_read(int fd,char *buf,int len);
extern int GPS_parse(const char *line,GPS_INFO *GPS);
extern int getcomma(int num,char *str);
extern void UTC2BTC(data_time *GPS);
extern double get_double_number(char *s);
extern void get_char(char *s);

#endif  //_GPS_H_
