#include <stdio.h>
#include <unistd.h>
#include "gps_item.h" 
#include "gps.h"

char buf_t[128];
int GPS_read(int fd,char *buf,int len)
{
    int p = 0;
    int q = 0;
    char com[1024];
    read(fd,buf,1);
    strcpy(com,buf);
    while(com[p] != '\n')
    {
        buf[q++] = com[p];
        p++;
    }
    return 0;
}
int GPS_parse(const char *line,GPS_INFO *GPS)
{
	int tmp;
	char c;
	char *buf;
	int time;

	buf = (char *)line;
	c = buf[5];
	if(c == 'C')   //"GPRMC"
	{
		time = getcomma(1,buf);
		GPS->D.hour   =(buf[time+0]-'0')*10 + (buf[time+1]-'0');
		GPS->D.minute =(buf[time+2]-'0')*10 + (buf[time+3]-'0');
		GPS->D.second =(buf[time+4]-'0')*10+  (buf[time+5]-'0');
		tmp = getcomma(9,buf);
		GPS->D.day    =(buf[tmp+0]-'0')*10 + (buf[tmp+1]-'0');
		GPS->D.month  =(buf[tmp+2]-'0')*10 + (buf[tmp+3]-'0');
		GPS->D.year   =(buf[tmp+4]-'0')*10 + (buf[tmp+5]-'0')+2000;
		get_char(&buf[7]);
		strcpy(GPS->D.time_c,buf_t);
        ///////////////////////////////////////////////////////////////////////
		GPS->status   =buf[getcomma(2,buf)];

		GPS->latitude =get_double_number(&buf[getcomma(3,buf)]);
		GPS->NS       =buf[getcomma(4,buf)];
		get_char(&buf[getcomma(3,buf)]);
		strcpy(GPS->latitude_c,buf_t);

		GPS->longitude=get_double_number(&buf[getcomma(5,buf)]);
		GPS->EW       =buf[getcomma(6,buf)];
		get_char(&buf[getcomma(5,buf)]);
		strcpy(GPS->longitude_c,buf_t);
		UTC2BTC(&GPS->D);
		return 1;
	}
	else
		return 0;
}
double get_double_number(char *s)
{
	char buf[128];
	int t;
	double result = 0;
	t = getcomma(1,s);
	t = t-1;
	strncpy(buf,s,t);
	buf[t] = '\n';
	result = atof(buf);
	return result;
}
void get_char(char *s)
{
	int m;
	m = getcomma(1,s);
	m = m-1;
	if(m > 9) m=9;
	strncpy(buf_t,s,m);
	buf_t[m] = '\n';
}
int getcomma(int num,char *str)
{
	int i,j=0;
	int len = strlen(str);
	for(i=0;i<len;i++)
	{
		if(str[i] == ',') j++;
		if(j == num) return i+1;
	}
	return 0;
}
void UTC2BTC(data_time *GPS)
{
    GPS->second++;
	if(GPS->second > 59)
	{
		GPS->second = 0;
		GPS->minute++;
		if(GPS->minute > 59)
		{
			GPS->minute = 0;
			GPS->hour++;
		}
	}
//------------------------------转化为北京时间-----------------------------//
	GPS->hour = GPS->hour + 8;
	if(GPS->hour > 23)
	{
		GPS->hour -= 24;
		GPS->day += 1;
		if(GPS->month == 2 || GPS->month == 4 || GPS->month == 6 || GPS->month == 9 || GPS->month == 11)
		{
			if(GPS->day > 30)
			{
				GPS->day = 1;
				GPS->month++;
			}
		}
		else
		{
			if(GPS->day > 31)
			{
				GPS->day = 1;
				GPS->month++;
			}
		}
		if(GPS->year % 4 == 0)
		{
			if(GPS->day > 29 && GPS->month == 2)
			{
				GPS->day = 1;
				GPS->month++;
			}
		}
		else
		{
			if(GPS->day > 28 && GPS ->month == 2)
			{
				GPS->day = 1;
				GPS->month++;
			}
		}
		if(GPS->month > 12)
		{
			GPS->month -= 12;
			GPS->year;
		}
	}
}
