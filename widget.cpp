#include "widget.h"
#include "ui_widget.h"
//#include "main.cpp"
#include <QString>
#include <QFile>
#include <QIODevice>
#include <QtDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //creates a timer
    swTimer = new QTimer(this);
    pbTimer = new QTimer(this);
    //setup signal and slot for updating the switch status change
    connect(swTimer, SIGNAL(timeout()),this,SLOT(sw1Reader()));
    connect(swTimer, SIGNAL(timeout()),this,SLOT(sw2Reader()));
    connect(swTimer, SIGNAL(timeout()),this,SLOT(sw3Reader()));
    connect(swTimer, SIGNAL(timeout()),this,SLOT(sw4Reader()));

    //setup signal and slot for updating the switch status change
    connect(pbTimer, SIGNAL(timeout()),this,SLOT(pb1Reader()));
    connect(pbTimer, SIGNAL(timeout()),this,SLOT(pb2Reader()));
    connect(pbTimer, SIGNAL(timeout()),this,SLOT(pb3Reader()));
    connect(pbTimer, SIGNAL(timeout()),this,SLOT(pb4Reader()));
    //msec
    swTimer->start(500);
    pbTimer->start(500);

}

Widget::~Widget()
{

    delete ui;
}

void Widget::on_led1RadioButton_clicked()
{
    ledPin = 1016;

}

void Widget::on_led2RadioButton_clicked()
{
    ledPin = 1017;
}

void Widget::on_led3RadioButton_clicked()
{
    ledPin = 1018;
}

void Widget::on_led4RadioButton_clicked()
{
    ledPin = 1019;
}


int Widget::getLedPin() const
{
    return ledPin;
}

void Widget::on_onButton_clicked()
{
    qDebug()<<"ON Command";

    int pin = ledPin;
    enum direction {In,Out,Err};

    // accessing the Gpio files and turn the leds on
    QString valueString =
            QString("/sys/class/gpio/gpio%1/value").arg(pin);
    QString directionString =
            QString("/sys/class/gpio/gpio%1/direction").arg(pin);
    // accessing the Gpio files and turn the leds on
    FILE * fp;
    fp = fopen(valueString.toLatin1(),"rb+");
    fwrite("1", sizeof(char),4,fp);
    //rewind(fp);

    fclose(fp);
}

void Widget::on_offButton_clicked()
{
    qDebug()<<"OFF Command";

    int pin = ledPin;
    enum direction {In,Out,Err};

    // accessing the Gpio files and turn the leds on
    QString valueString =
            QString("/sys/class/gpio/gpio%1/value").arg(pin);
    QString directionString =
            QString("/sys/class/gpio/gpio%1/direction").arg(pin);
    // accessing the Gpio files and turn the leds on
    FILE * fp;
    fp = fopen(valueString.toLatin1(),"rb+");
    fwrite("0", sizeof(char),4,fp);
    //rewind(fp);

    fclose(fp);
}




void Widget::sw1Reader()
{
    int pin = 1012;
    char value;
     QString swGlobalValue;
    FILE * fp;
    QString valueString =
            QString("/sys/class/gpio/gpio%1/value").arg(pin);
    fp = fopen(valueString.toLatin1(), "rb+");
    rewind(fp);//Set pointer to begining of the file
    fread(&value, sizeof(char),1, fp);
    fclose(fp);
    if(value=='1')
    {
        swGlobalValue = QString("1");
    };
    if(value=='0')
    {
        swGlobalValue =  QString("0");
    }
    ui->sw1Label->setText(swGlobalValue);
}

void Widget::sw2Reader()
{
    int pin = 1013;
    char value;
     QString swGlobalValue;
    FILE * fp;
    QString valueString =
            QString("/sys/class/gpio/gpio%1/value").arg(pin);
    fp = fopen(valueString.toLatin1(), "rb+");
    rewind(fp);//Set pointer to begining of the file
    fread(&value, sizeof(char),1, fp);
    fclose(fp);
    if(value=='1')
    {
        swGlobalValue = QString("1");
    };
    if(value=='0')
    {
        swGlobalValue =  QString("0");
    }
    ui->sw2Label->setText(swGlobalValue);
}

void Widget::sw3Reader()
{
    int pin = 1014;
    char value;
     QString swGlobalValue;
    FILE * fp;
    QString valueString =
            QString("/sys/class/gpio/gpio%1/value").arg(pin);
    fp = fopen(valueString.toLatin1(), "rb+");
    rewind(fp);//Set pointer to begining of the file
    fread(&value, sizeof(char),1, fp);
    fclose(fp);
    if(value=='1')
    {
        swGlobalValue = QString("1");
    };
    if(value=='0')
    {
        swGlobalValue =  QString("0");
    }
    ui->sw3Label->setText(swGlobalValue);
}

void Widget::sw4Reader()
{
    int pin = 1015;
    char value;
     QString swGlobalValue;
    FILE * fp;
    QString valueString =
            QString("/sys/class/gpio/gpio%1/value").arg(pin);
    fp = fopen(valueString.toLatin1(), "rb+");
    rewind(fp);//Set pointer to begining of the file
    fread(&value, sizeof(char),1, fp);
    fclose(fp);
    if(value=='1')
    {
        swGlobalValue = QString("1");
    };
    if(value=='0')
    {
        swGlobalValue =  QString("0");
    }
    ui->sw4Label->setText(swGlobalValue);
}

void Widget::pb1Reader()
{
    int pin = 1020;
    char value;
     QString swGlobalValue;
    FILE * fp;
    QString valueString =
            QString("/sys/class/gpio/gpio%1/value").arg(pin);
    fp = fopen(valueString.toLatin1(), "rb+");
    rewind(fp);//Set pointer to begining of the file
    fread(&value, sizeof(char),1, fp);
    fclose(fp);
    if(value=='1')
    {
        swGlobalValue = QString("1");
    };
    if(value=='0')
    {
        swGlobalValue =  QString("0");
    }
    ui->pb1Label->setText(swGlobalValue);
}

void Widget::pb2Reader()
{
    int pin = 1021;
    char value;
     QString swGlobalValue;
    FILE * fp;
    QString valueString =
            QString("/sys/class/gpio/gpio%1/value").arg(pin);
    fp = fopen(valueString.toLatin1(), "rb+");
    rewind(fp);//Set pointer to begining of the file
    fread(&value, sizeof(char),1, fp);
    fclose(fp);
    if(value=='1')
    {
        swGlobalValue = QString("1");
    };
    if(value=='0')
    {
        swGlobalValue =  QString("0");
    }
    ui->pb2Label->setText(swGlobalValue);
}

void Widget::pb3Reader()
{
    int pin = 1022;
    char value;
     QString swGlobalValue;
    FILE * fp;
    QString valueString =
            QString("/sys/class/gpio/gpio%1/value").arg(pin);
    fp = fopen(valueString.toLatin1(), "rb+");
    rewind(fp);//Set pointer to begining of the file
    fread(&value, sizeof(char),1, fp);
    fclose(fp);
    if(value=='1')
    {
        swGlobalValue = QString("1");
    };
    if(value=='0')
    {
        swGlobalValue =  QString("0");
    }
    ui->pb3Label->setText(swGlobalValue);
}

void Widget::pb4Reader()
{
    int pin = 1023;
    char value;
     QString swGlobalValue;
    FILE * fp;
    QString valueString =
            QString("/sys/class/gpio/gpio%1/value").arg(pin);
    fp = fopen(valueString.toLatin1(), "rb+");
    rewind(fp);//Set pointer to begining of the file
    fread(&value, sizeof(char),1, fp);
    fclose(fp);
    if(value=='1')
    {
        swGlobalValue = QString("1");
    };
    if(value=='0')
    {
        swGlobalValue =  QString("0");
    }
    ui->pb4Label->setText(swGlobalValue);
}
