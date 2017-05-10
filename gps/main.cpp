 #include<QtWidgets/QApplication>
#include <stdio.h>
//#include <termios.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
//#include <sys/ioctl.h>
#include <unistd.h>
#include "gps_item.h"
#include "gps.h"
/*int uart_init(int num)
{
        int fd;
        struct termios options,oldoptions;
                // ���崮�����Խṹ�����������options�����������ô������ԣ�oldoptions����ԭ���ã����ڻָ���ԭ��������
        char *uart[3]={"/dev/ttyS0","/dev/ttyS1","/dev/ttyS2"};
        fd = open(uart[num],O_RDWR);       //�򿪴���
        tcgetattr(fd, &oldoptions);       //��õ�ǰ�Ĵ���������Ϣ
        tcgetattr(fd, &options);

        cfsetispeed(&options, B9600);    //�������벨����Ϊ115200
        cfsetospeed(&options, B9600);    //�������������Ϊ115200

        options.c_iflag &= ~(IGNBRK|BRKINT|PARMRK|ISTRIP|IGNCR|ICRNL|IXON);
        options.c_cflag &= ~PARENB;    //����żУ��λ
        options.c_cflag &= ~CSTOPB;    //ֹͣλΪ1λ
        options.c_cflag &= ~CSIZE;
        options.c_cflag |= CS8;        //����λΪ8λ
        options.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG); //���ô���ΪRawģʽ

        tcsetattr(fd,TCSANOW,&options); //������������Ч
        return fd;
}*/
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    gps_item w;
    //w.showFullScreen();
    GPS_INFO GPS;
    int len = 128;
    int fd;
    char buf[]="$GPRMC,081229.48,A,4123.2475,N,11558.3416,W,0.13,309.62,150510,,*10\n";//beijing
    //char buf[]="$GPRMC,081229.48,A,4223.2475,N,8658.3416,W,0.13,309.62,150510,,*10\n";//wulumuqi
    //char buf[]="$GPRMC,081229.48,A,2523.2475,N,11958.3416,W,0.13,309.62,150510,,*10\n";//taibei
    /*fd = open("/dev/gpf/0", O_RDWR);
    ioctl(fd,GPIO_SET_MULTI_PIN_OUT,0x1);   // ����GPSģ��
    ioctl(fd,GPIO_CLR_PIN,0x0);
    usleep(300);
    ioctl(fd,GPIO_SET_PIN,0x0);

    fd = uart_init(2);*/
    while(1)
    {
        GPS_read(fd,buf,len);
        if(GPS_parse(buf,&GPS))
        {
            if(GPS.status == 'A')
            {
                w.mylat = (int)GPS.latitude;
                w.mylgt = (int)GPS.longitude;
                printf("mylat = %d\n",w.mylat);
                printf("mylgt = %d\n",w.mylgt);
                w.lat =(54 - GPS.latitude/100) * 5.08 + 25;
                w.lgt =(GPS.longitude/100 - 74) * 5.33;
                printf("mylat = %d\n",w.lat);
                printf("mylgt = %d\n",w.lgt);
                w.star_move(w.lat,w.lgt);
                w.show();
                return a.exec();
             }
         }
    }
   // w.show();
   // return a.exec();
   return 0;
}

