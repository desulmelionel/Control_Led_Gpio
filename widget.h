#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QString>
#include <QChar>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();


    int getLedPin() const;

private slots:

    void on_onButton_clicked();

    void on_offButton_clicked();

    void on_led1RadioButton_clicked();

    void on_led2RadioButton_clicked();

    void on_led3RadioButton_clicked();

    void on_led4RadioButton_clicked();

    void on_Sw1Radio_pressed();

    void on_Sw2Radio_pressed();

    void on_Sw3Radio_pressed();

    void on_Sw4Radio_pressed();

private:
    Ui::Widget *ui;
//Led pin control
    int ledPin;
//switch status control

};

#endif // WIDGET_H
