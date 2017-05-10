#ifndef GPS_ITEM_H
#define GPS_ITEM_H

#include <QtWidgets/QWidget>

namespace Ui
{
    class gps_item;
}

class gps_item : public QWidget
{
    Q_OBJECT

public:
    gps_item(QWidget *parent = 0);
    ~gps_item();
    void star_move(int x,int y);

public slots:
    void mypos();
    void myreturn();
    void mystar();
    void mapup();
    void mapdown();
    void mapleft();
    void mapright();

protected:
    void mousePressEvent(QMouseEvent *event);

public:
    static int mx;
    static int my;
    static int num;
    int lat;
    int lgt;
    int mylat;
    int mylgt;
    static int mapWidth;
    static int mapHeight;
    static int lcdWidth;
    static int lcdHeight;

private:
    Ui::gps_item *ui;
};

#endif // GPS_ITEM_H
