#ifndef CARINFO
#define CARINFO

#include <QMainWindow>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QMessageBox>
#include <QDebug>


class CarInfo{
    friend class MainWindow ;
public :

    CarInfo( );

    void setChikaren( QString strs );
    void setYue( QString yue );
    void setKahao( QString kahao);
    void setChexing(QString chexing);
    void setCheqing(QString cheqing);
    void setKazhong( QString kazhong );
    void setChepaihao( QString chepaihao );
    void setFloatYue( float f);
    void setIntKazhong( int kazhong );
    void setTimeInhour( int timeinhour );
    void setTimeInmm(int timeinmm);
    void setTimeOuthour(int timeouthour);
    void setTimeOutmm(int timeoutmm);

    int getTimeInhour(void);
    int getTimeInmm(void);
    int getTimeOuthour(void);
    int getTimeOutmm(void);

    QString getChikaren( void );
    QString getYue(void);
    QString getKahao( void );
    QString getChexing(void);
    QString getCheqing(void);
    QString getKazhong(void);
    QString getChepaihao(void);

    int getIntKazhong(void);
    float getFloatYue( void );
    bool isIn;


private:

    int time;
    QString chikaren;
    QString yue;
    QString kahao;
    QString chexing;
    QString cheqing;
    QString kazhong;
    QString chepaihao;
    int timeinhour;
    int timeinmm;
    int timeouthour;
    int timeoutmm;
    int int_kazhong;

    float   f_yu_e;



};

class CarStation{
    friend class MainWindow ;
public :

    CarStation();
    void setJiluhao(QString jiluhao);
    void setShoufeizhan(QString shoufeizhan);
    void setChedao(QString chedao);
    void setShoufeiyuan(QString shoufeiyuan);
    void setChewei( QString chewei );
    void setKoufei( QString koufei );
    void setIntChewei( int cheweinum );
    void setFloatKoufei( float kf );

    QString getKoufei(void);
    QString getJiluhao(void);
    QString getShoufeiyuan(void);
    QString getShoufeizhan(void);
    QString getChedao(void);
    QString getChewei( void );

    float getFloatKoufei( void );
    int getIntChewei( void  );

private:


    QString chewei;
    QString jiluhao;
    QString shoufeizhan;
    QString chedao;
    QString shoufeiyuan;
    QString koufei;

    float float_koufei;
    int int_cheWei;
};
#endif // CARINFO

