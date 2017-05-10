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
                // 定义串口属性结构体变量，其中options用于重新设置串口属性，oldoptions用于原设置，用于恢复到原来的属性
        char *uart[3]={"/dev/ttyS0","/dev/ttyS1","/dev/ttyS2"};
        fd = open(uart[num],O_RDWR);       //打开串口
        tcgetattr(fd, &oldoptions);       //获得当前的串口设置信息
        tcgetattr(fd, &options);

        cfsetispeed(&options, B9600);    //设置输入波特率为115200
        cfsetospeed(&options, B9600);    //设置输出波特率为115200

        options.c_iflag &= ~(IGNBRK|BRKINT|PARMRK|ISTRIP|IGNCR|ICRNL|IXON);
        options.c_cflag &= ~PARENB;    //无奇偶校验位
        options.c_cflag &= ~CSTOPB;    //停止位为1位
        options.c_cflag &= ~CSIZE;
        options.c_cflag |= CS8;        //数据位为8位
        options.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG); //设置串口为Raw模式

        tcsetattr(fd,TCSANOW,&options); //将上述设置生效
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
    ioctl(fd,GPIO_SET_MULTI_PIN_OUT,0x1);   // 启动GPS模组
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

