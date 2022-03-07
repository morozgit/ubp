#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>
#include<QTime>
#include<QTimer>
#include<QtEndian>
#include<QTextStream>
#include<QBitArray>
#include<QDebug>
#include <QPoint>
#include <QPainterPath>
#include<QResizeEvent>

//#include "data.h"

//#include"mainwindow.h"

 static QByteArray arr;
namespace Ui {

class Shcema;
}

class Shcema :  public QWidget
{
    Q_OBJECT

public:
    explicit Shcema(QWidget *parent = 0);
    ~Shcema();

protected:
    /* Определяем виртуальный метод родительского класса
     * для отрисовки содержимого виджета
     * */
    void paintEvent(QPaintEvent *event);


private slots:
    void slotTimerAlarm();
    void resizeEvent(QResizeEvent *event);

public slots:
    void slotReadArr(QByteArray);

private:
    Ui::Shcema *ui;
    QTimer *timer;
     int flag = 0;
     int Node_31 = 0;
     int Node_102 = 0;
     //int Node_102_Color = 0;
     int Node_103 = 0;
     int Node_104 = 0;
     int Node_105 = 0;
     int Node_106 = 0;
     int Node_107 = 0;
     int Node_108 = 0;
     int Node_109 = 0;
     //int Node_109_Color = 0;
     int Node_110 = 0;
     int Node_111 = 0;
     int Node_112 = 0;
     //int Node_112_Color = 0;
     int Node_113 = 0;
     int Node_114 = 0;
     int Node_116 = 0;
     int Node_117 = 0;
     int Node_118 = 0;
     int Node_119 = 0;
     int Node_120 = 0;
     int Node_121 = 0;
     int Node_124 = 0;
     //int Node_116_Color = 0;
     int Node_123 = 0;
     int Node_125 = 0;
     int Node_126 = 0;
     int Node_127 = 0;
     int Node_132 = 0;
     int Node_135 = 0;
     int Node_134 = 0;
     int Node_136 = 0;
     int Node_137 = 0;
     int Node_138 = 0;
     QDateTime dt;
     //Data *s_data = nullptr;
    // QByteArray arr;

};

#endif // WIDGET_H
