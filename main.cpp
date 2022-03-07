#include "mainwindow.h"
#include"Shcema.h"
#include"tables.h"


#include <QApplication>
#include <QScreen>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Shcema s;
    QRect screenrect = a.primaryScreen()->geometry();
    //qDebug() << screenrect;
   // w.resize(1920,150);
        w.move(screenrect.left(), screenrect.top());

        w.show();

      // s.move(screenrect.left(), screenrect.top());
      // s.show();

    return a.exec();
}
