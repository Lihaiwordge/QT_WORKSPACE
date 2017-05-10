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
	char time_c[10];      //ACSII形式的时间
}data_time;

typedef struct{
	data_time D;          //时间
	char status;          //接收状态
	double latitude;      //纬度
	char latitude_c[11];  //ASCII形式的纬度
	double longitude;     //经度
	char longitude_c[11]; //ASCII形式的经度
	char NS;              //南北
	char EW;              //东西
	double speed;         //速度
	char speed_c[10];     //ASCII形式的速度
	double high;          //高度
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
