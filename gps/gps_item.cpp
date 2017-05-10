#include "gps_item.h"
#include "ui_gps_item.h"
#include <QPixmap>
#include <QPainter>
#include <QPaintEvent>
#include <QtDebug>
#include <QTimer>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSizePolicy>
int gps_item::mx = 0;
int gps_item::my = 0;
int gps_item::num = 0;
int gps_item::mapWidth = 0;
int gps_item::mapHeight = 0;
int gps_item::lcdWidth = 320;
int gps_item::lcdHeight = 240;
static int i;
static int j;

gps_item::gps_item(QWidget *parent)
    : QWidget(parent), ui(new Ui::gps_item)
{
    ui->setupUi(this);
    ui->label_2->setPixmap(QPixmap("./china.bmp"));
    ui->label_star->setPixmap(QPixmap("./star2.bmp"));
    ui->pushButton_up->setIconSize(QSize(30,30));
    ui->pushButton_up->setIcon(QIcon(tr("./up.bmp")));
    ui->pushButton_down->setIconSize(QSize(30,30));
    ui->pushButton_down->setIcon(QIcon(tr("./down.bmp")));
    ui->pushButton_left->setIconSize(QSize(30,30));
    ui->pushButton_left->setIcon(QIcon(tr("./left.bmp")));
    ui->pushButton_right->setIconSize(QSize(30,30));
    ui->pushButton_right->setIcon(QIcon(tr("./right.bmp")));
    ui->pushButton_goto->setIconSize(QSize(30,30));
    ui->pushButton_goto->setIcon(QIcon(tr("./gps.bmp")));
    ui->pushButton_return->setIconSize(QSize(30,30));
    ui->pushButton_return->setIcon(QIcon(tr("./exit.bmp")));

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(mystar()));
    timer->start(500);
    connect(ui->pushButton_goto,SIGNAL(clicked()),this,SLOT(mypos()));
    connect(ui->pushButton_return,SIGNAL(clicked()),this,SLOT(myreturn()));

    connect(ui->pushButton_up,SIGNAL(clicked()),this,SLOT(mapup()));
    connect(ui->pushButton_down,SIGNAL(clicked()),this,SLOT(mapdown()));
    connect(ui->pushButton_left,SIGNAL(clicked()),this,SLOT(mapleft()));
    connect(ui->pushButton_right,SIGNAL(clicked()),this,SLOT(mapright()));
    update();
}
void gps_item::mousePressEvent(QMouseEvent *event)
{
    QWidget::mousePressEvent(event);
    mx = event->x();
    my = event->y();
    qDebug()<<"the mx is"<<mx;
    qDebug()<<"the my is"<<my;
    if((mx > 218)&&(mx < 230)&&(my > 91)&&(my < 101))
    {
        ui->label_2->hide();
        ui->label_1->setPixmap(QPixmap("./beijing.bmp"));
        //ui->label_1->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored); //忽视初始图片值
        //ui->label_1->setScaledContents(true);  //设置可改变的内容
        ui->label_1->resize(1960,3250);
        mapWidth = ui->label_1->width();
        mapHeight = ui->label_1->height();
        i = -mapWidth/2;
        j = -mapHeight/2;
        ui->label_1->setGeometry(i,j,mapWidth,mapHeight);
        ui->label_1->setAlignment(Qt::AlignCenter | Qt::AlignVCenter | Qt::AlignHCenter);
    }
    else if((mx > 70)&&(mx < 80)&&(my > 80)&&(my < 90))
    {
        ui->label_2->hide();
        ui->label_1->setPixmap(QPixmap("./wulumuqi.bmp"));
        ui->label_1->resize(1424,2057);
        mapWidth = ui->label_1->width();
        mapHeight = ui->label_1->height();
        i = -mapWidth/2;
        j = -mapHeight/2;
        ui->label_1->setGeometry(i,j,mapWidth,mapHeight);
        ui->label_1->setAlignment(Qt::AlignCenter | Qt::AlignVCenter | Qt::AlignHCenter);
    }
    else if((mx > 240)&&(mx < 250)&&(my > 170)&&(my < 180))
    {
        ui->label_2->hide();
        ui->label_1->setPixmap(QPixmap("./taibei.bmp"));
        ui->label_1->resize(771,481);
        mapWidth = ui->label_1->width();
        mapHeight = ui->label_1->height();
        i = -mapWidth/2;
        j = -mapHeight/2;
        ui->label_1->setGeometry(i,j,mapWidth,mapHeight);
        ui->label_1->setAlignment(Qt::AlignCenter);
    }
}
void gps_item::mystar()
{
    num++;
    if(num %2 == 0)
    {
        ui->label_star->setPixmap(QPixmap("./star1.bmp"));
    }
    else
    {
        ui->label_star->setPixmap(QPixmap("./star2.bmp"));
    }
}
void gps_item::mapup()
{
    j = j+10;
    ui->label_1->setGeometry(i,j,mapWidth,mapHeight);
}
void gps_item::mapdown()
{
    j = j-10;
    ui->label_1->setGeometry(i,j,mapWidth,mapHeight);
}
void gps_item::mapleft()
{
    i = i+10;
    ui->label_1->setGeometry(i,j,mapWidth,mapHeight);
}
void gps_item::mapright()
{
    i = i-10;
    ui->label_1->setGeometry(i,j,mapWidth,mapHeight);
}
void gps_item::mypos()
{
    int m = 0,n = 0;
    qDebug()<<"the latitude is:"<<this->mylat;
    qDebug()<<"the longitude is:"<<this->mylgt;
    m = ((this->mylat/100) + (this->mylat%100)*0.01 - 41.05) * 11.07;
    n = ((this->mylgt/100) + (this->mylgt%100)*0.01 - 115.24) * 15.78;
    qDebug()<<"the m is:"<<m;
    qDebug()<<"the n is:"<<n;
    i = n;
    j = m;
    ui->label_1->setGeometry(n,m,mapWidth,mapHeight);
}
void gps_item::star_move(int x,int y)
{
        qDebug()<<"the x is:"<<x;
        qDebug()<<"the y is:"<<y;
        ui->label_star->setGeometry(y,x,14,14);
}
void gps_item::myreturn()
{
    int m=0,n=0;
    ui->label_2->show();
    m = this->lat;
    n = this->lgt;
    ui->label_star->setGeometry(n,m,14,14);
}
gps_item::~gps_item()
{
    delete ui;
}
