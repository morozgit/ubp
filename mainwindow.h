#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QTime>
#include<QTimer>
#include<QFile>
#include<QtDebug>
#include <QDate>
#include<QtEndian>
#include <QPainter>
#include "Shcema.h"
#include "tables.h"
#include "data.h"
#include<QFileDialog>
#include<QPixmap>
#include<QBrush>
#include<QBitmap>
//#include<QGridLayout>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


//static QString filename;

//static QFile file ("History.txt");
//static QByteArray tmp;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
     //friend class Shcema;

private slots:

     void slotTimerAlarm();
     void on_Tables_clicked();
     void on_Schema_clicked();
     void on_play_clicked();
     void timerEvent(QTimerEvent* event);
     QByteArray get_data_array();

    // void on_play_speed2_clicked();

     void on_Button_next_clicked();

     void on_Button_prev_clicked();

     void closeEvent(QCloseEvent *event);

     void on_EnterFileName_clicked();

     void on_comboBox_activated(const QString &arg1);

     void on_OpenFile_clicked();

signals:
     void receiveData(QByteArray);
     //void rec(int*);

private:
    Ui::MainWindow *ui;
    QTimer *timer;

    bool ok = true;
    QDateTime dt;
    //QDateTime dt_end;
    int id1;
    int count;
    int *qwer = &count;
    QByteArray data_array;
    Tables* window_tables= nullptr;
    Shcema* window_schema = nullptr;
    int cur = 0; // курсор в файле
    Data *m_data = nullptr;
    QString m_filename = " ";

};
#endif // MAINWINDOW_H
