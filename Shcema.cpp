#include "Shcema.h"
#include"ui_shcema.h"


Shcema::Shcema(QWidget *parent) :
    QWidget (parent),
    ui(new Ui::Shcema)
{
    ui->setupUi(this);
    this->setMinimumHeight(100);
    this->setMinimumWidth(100);
//    scene = new QGraphicsScene(this);
//    ui->graphicsView->setScene(scene);
//    rect = scene->addRect(300, 200, 70, 70);
//    rect = scene->addRect(200, 100, 70, 70);
    QFile* file = new QFile("SpuM1Schemes.xml");
    if (!file->open(QFile::ReadOnly | QFile::Text))
       {
           qDebug()<<"file not open";
    }
        QXmlStreamReader *xmlReader = new QXmlStreamReader(file);


        //Parse the XML until we reach end of it
        while(!xmlReader->atEnd() && !xmlReader->error()) {
                // Read next element
                QXmlStreamReader::TokenType token = xmlReader->readNext();
                //If token is just StartDocument - go to next
                if(token == QXmlStreamReader::StartDocument) {
                        continue;
                }
                //If token is StartElement - read it
                if(token == QXmlStreamReader::StartElement) {

                        if(xmlReader->name() == "NameRus") {
                                continue;
                        }

                        if(xmlReader->name() == "id") {
                            qDebug() << xmlReader->readElementText();
                        }
                }
        }

        if(xmlReader->hasError()) {
                QMessageBox::critical(this,
                "xmlFile.xml Parse Error",xmlReader->errorString(),
                QMessageBox::Ok);
                return;
        }

        //close reader and flush file
        xmlReader->clear();
        file->close();

qDebug()<<"constr";



}

Shcema::~Shcema()
{
    delete ui;
}
void Shcema::slotTimerAlarm() // обнавление часов реального времении с интервалом 1с
{

//    ui->label_timer->setText(QTime::currentTime().toString("hh:mm:ss"));
//    flag++;
//    ui->flag->setText(QString::number(flag,'g',15));
//      repaint();
//      file.open(QIODevice::ReadOnly);
//      tmp = file.read(1500).toHex();
//      qDebug() << QString(tmp)  << " flag = " << flag; // Выводим данные в консоль, предварительно создав строку из полученных данных
//      ui->ReadFile->setCheckable(false);
}

/* Метод, в котором происходит рисование
 * */
 void Shcema:: slotReadArr(QByteArray tmp)
 {

     arr = tmp;
    //qDebug()<<arr;
 }


void Shcema::paintEvent(QPaintEvent *event)
{
      bool ok;
    Q_UNUSED(event);
      int width = this->width();      // определяем ширину нашего виджета
      int height = this->height();
      //qDebug()<<arr;

      ui->label->setStyleSheet("color: rgb(255,255, 255)");
      dt.setTime_t(qToBigEndian(arr.mid(0,8).toUInt(&ok, 16)));//переворот байт(считывание 8 байт с 0 позиции)
      ui->label->setText(dt.toString("yyyy-MM-dd hh:mm:ss"));
    QPainter painter(this); // Создаём объект отрисовщика
      // Устанавливаем кисть абриса
    painter.setPen(QPen(Qt::white, 2, Qt::SolidLine, Qt::FlatCap));
    //Node_102
    Node_102 = arr.mid(1776,2).toUInt(&ok,16);
    //qDebug() << "Node_102" << Node_102;
   // Node_102_Color = arr.mid(1777,1).toUInt(&ok,16);
   // qDebug() <<"Node_102"<< Node_102;
    if(Node_102 == 24)
    {
    painter.setPen(QPen(Qt::green, 2, Qt::SolidLine, Qt::FlatCap));
    painter.drawLine(130, 225, 170, 225);
    }else if (Node_102== 34) {
        painter.setPen(QPen(Qt::red, 2, Qt::SolidLine, Qt::FlatCap));
        painter.drawLine(130, 225, 170, 210);
    }
    else {
        painter.setPen(QPen(Qt::gray, 2, Qt::SolidLine, Qt::FlatCap));
        painter.drawLine(130, 225, 170, 210);
    }


    //Node_103
    Node_103 = arr.mid(1785,1).toUInt(&ok,16);
    QPolygon polygonQS1,polygon103,polygon103invH,polygon103invV;   // Используем класс полигона, чтобы отрисовать треугольник
            // Помещаем координаты точек в полигональную модель
            polygonQS1 << QPoint(100,235) << QPoint(80,230) << QPoint(80,240);
            polygon103 << QPoint(250,235) << QPoint(230,230) << QPoint(230,240);
            polygon103invH << QPoint(650,120) << QPoint(630,115) << QPoint(630,125);
            polygon103invV << QPoint(805,160) << QPoint(800,140) << QPoint(810,140);
        if(Node_103 == 0){
            painter.setBrush(Qt::black);     // цвет заливки стрелочек
            painter.setPen(QPen(Qt::black, 2, Qt::SolidLine, Qt::FlatCap)); // цвет линий Node_103
        }
        else if (Node_103 == 8) {
            painter.setBrush(Qt::green);     // цвет заливки стрелочек
            painter.setPen(QPen(Qt::green, 2, Qt::SolidLine, Qt::FlatCap)); // цвет линий Node_103
        }
        else {
            painter.setBrush(Qt::gray);     // цвет заливки стрелочек
            painter.setPen(QPen(Qt::gray, 2, Qt::SolidLine, Qt::FlatCap)); // цвет линий Node_103
        }
     painter.drawLine(30, 235, 130, 235);//до QS1
     painter.drawLine(130, 235, 130, 225);//верт линия QS1
     painter.drawLine(165, 235, 300, 235);// после QS1
     painter.drawLine(165, 235, 165, 220);// верт линия QS1
     painter.drawPolygon(polygonQS1);  //  треугольник Node_103
     painter.drawPolygon(polygon103);  //  треугольник пред выпрямителями
     painter.drawPolygon(polygon103invH);  //  треугольник пред ивертором горизонт
     painter.drawPolygon(polygon103invV);  //  треугольник пред ивертором верт
     painter.drawLine(200, 235, 200, 120);// верт линия
     painter.drawLine(200, 120, 805, 120);// горизонт линия
     painter.drawLine(805, 235, 805, 120);// верт линия inv in


    //Выпрямилели Node_104
    painter.setPen(QPen(Qt::white, 2, Qt::SolidLine, Qt::FlatCap));
    painter.setBrush(QColor(53, 52, 54));
    painter.drawRect(300, 200, 70, 70);
    painter.drawLine(300, 270, 370, 200);
    painter.drawLine(342, 250, 360, 250);
    painter.drawLine(342, 255, 360, 255);
    painter.setPen(QPen(Qt::white, 1, Qt::SolidLine, Qt::FlatCap));
    painter.setBrush(QBrush(Qt::black, Qt::SolidPattern));
    painter.drawRect(320, 230, 30, 10);

    //painter.drawRect(width-300, height-200, 70, 70);

    painter.setPen(QPen(Qt::white, 2, Qt::SolidLine, Qt::FlatCap));
    QPainterPath pathRectAC;
    pathRectAC.moveTo(310,220);
    pathRectAC.cubicTo(320,200,330,230,340,215);
    painter.setBrush(Qt::NoBrush);
    painter.drawPath(pathRectAC);// значок переменки
    /* Проверяем, какой из радиобаттонов выбран
     * */
//     Node_107 = arr.mid(1072,2).toInt(&ok, 16);
    Node_104 = arr.mid(1793,1).toUInt(&ok,16);
    // qDebug()<< Node_104;
     if(Node_104 == 8){
        // Если красный, то отрисовываем красный прямоугольник
       painter.setPen(QPen(Qt::white, 1, Qt::SolidLine, Qt::FlatCap));
        painter.setBrush(QBrush(Qt::green, Qt::SolidPattern));
         painter.drawRect(320, 230, 30, 10);
        // ui->kpp->setText("<font color=green>KAP</font>");

    } else  if(Node_104 == 4){
        // Если зелёный, то отрисовываем зеленый прямоугольник

         painter.setPen(QPen(Qt::white, 1, Qt::SolidLine, Qt::FlatCap));
          painter.setBrush(QBrush(Qt::yellow, Qt::SolidPattern));
          painter.drawRect(320, 230, 30, 10);
//         painter.setPen(QPen(Qt::yellow, 3, Qt::SolidLine, Qt::FlatCap));
//        painter.drawLine(100, 50, 150, 250);
        //ui->kpp->setText("<font color=red>KAP</font>");
    }
     else if(Node_104 == 2)
     {
         painter.setPen(QPen(Qt::white, 1, Qt::SolidLine, Qt::FlatCap));
          painter.setBrush(QBrush(Qt::red, Qt::SolidPattern));
          painter.drawRect(320, 230, 30, 10);
     }
     else if(Node_104 == 0)
     {
         painter.setPen(QPen(Qt::white, 1, Qt::SolidLine, Qt::FlatCap));
          painter.setBrush(QBrush(Qt::black, Qt::SolidPattern));
          painter.drawRect(320, 230, 30, 10);
     }
    else {
         painter.setPen(QPen(Qt::white, 1, Qt::SolidLine, Qt::FlatCap));
          painter.setBrush(QBrush(Qt::gray, Qt::SolidPattern));
          painter.drawRect(320, 230, 30, 10);
    }

     //Node_105
     QPolygon polygon105;   // Используем класс полигона, чтобы отрисовать треугольник
             // Помещаем координаты точек в полигональную модель
             polygon105 << QPoint(450,235) << QPoint(430,230) << QPoint(430,240);
    Node_105 = arr.mid(1801,1).toUInt(&ok,16);
     if(Node_105 == 8){
        painter.setBrush(Qt::green);     // Устанавливаем кисть, которой будем отрисовывать объект
        painter.setPen(QPen(Qt::green, 2, Qt::SolidLine, Qt::FlatCap));
     }
     else if(Node_105 == 2)
     {
         painter.setBrush(Qt::red);     // Устанавливаем кисть, которой будем отрисовывать объект
         painter.setPen(QPen(Qt::red, 2, Qt::SolidLine, Qt::FlatCap));
     }
     else if (Node_105 == 0)
     {
         painter.setBrush(Qt::black);     // Устанавливаем кисть, которой будем отрисовывать объект
         painter.setPen(QPen(Qt::black, 2, Qt::SolidLine, Qt::FlatCap));
     }
     else {
         painter.setBrush(Qt::gray);     // Устанавливаем кисть, которой будем отрисовывать объект
         painter.setPen(QPen(Qt::gray, 2, Qt::SolidLine, Qt::FlatCap));
     }
      painter.drawLine(370, 235, 550, 235);//Node_105
     painter.drawPolygon(polygon105);  //  треугольник Node_105

     //Node_106
     QPolygon polygon106_inv,polygon106_DC;   // Используем класс полигона, чтобы отрисовать треугольник
             // Помещаем координаты точек в полигональную модель
             polygon106_inv << QPoint(650,235) << QPoint(630,230) << QPoint(630,240);
             polygon106_DC << QPoint(650,430) << QPoint(630,425) << QPoint(630,435);
     Node_106 = arr.mid(1809,1).toUInt(&ok,16);
     if(Node_106 == 8){
     painter.setBrush(Qt::green);     // Устанавливаем кисть, которой будем отрисовывать объект
      painter.setPen(QPen(Qt::green, 2, Qt::SolidLine, Qt::FlatCap));
     }
     else if(Node_106 == 2){
         painter.setBrush(Qt::red);     // Устанавливаем кисть, которой будем отрисовывать объект
          painter.setPen(QPen(Qt::red, 2, Qt::SolidLine, Qt::FlatCap));
     }
     else if (Node_106 == 0) {
         painter.setBrush(Qt::black);     // Устанавливаем кисть, которой будем отрисовывать объект
          painter.setPen(QPen(Qt::black, 2, Qt::SolidLine, Qt::FlatCap));
     }
     else {
         painter.setBrush(Qt::gray);     // Устанавливаем кисть, которой будем отрисовывать объект
          painter.setPen(QPen(Qt::gray, 2, Qt::SolidLine, Qt::FlatCap));
     }
      painter.drawLine(550, 235, 770, 235);//Node_106 к инверторам
      painter.drawLine(550, 235, 550, 500);//Node_106 верт
      painter.drawLine(550, 370, 450, 370);//Node_106 к АКБ1
      painter.drawLine(450, 370, 450, 356);//Node_106 к АКБ1 верт
      painter.drawLine(550, 500, 450, 500);//Node_106 к АКБ2
      painter.drawLine(450, 500, 450, 486);//Node_106 к АКБ2 верт
      painter.drawPolygon(polygon106_inv);  //  треугольник Node_106 inv
      painter.drawLine(550, 430, 770, 430);//Node_106 к DC/DC
      painter.drawPolygon(polygon106_DC);  //  треугольник Node_106 DC

      //Инвертора Node_107
      painter.setPen(QPen(Qt::white, 2, Qt::SolidLine, Qt::FlatCap));
      painter.setBrush(QColor(53, 52, 54));
      painter.drawRect(770, 200, 70, 70);
      painter.drawLine(770, 270, 840, 200);
      painter.drawLine(770, 200, 840, 270);
      painter.drawLine(775, 233, 785, 233);//линии DC in
      painter.drawLine(775, 238, 785, 238);//линии DC in

      //AC IN
      painter.setPen(QPen(Qt::white, 2, Qt::SolidLine, Qt::FlatCap));
      QPainterPath path_InvAC1;
      path_InvAC1.moveTo(790,215);
      path_InvAC1.cubicTo(800,195,810,225,820,210);
      painter.setBrush(Qt::NoBrush);
      painter.drawPath(path_InvAC1);// значок переменки

      //AC out
      painter.setPen(QPen(Qt::white, 2, Qt::SolidLine, Qt::FlatCap));
      QPainterPath path_InvAC2;
      path_InvAC2.moveTo(825,235);
      path_InvAC2.cubicTo(830,215,833,245,836,230);
      painter.setBrush(Qt::NoBrush);
      painter.drawPath(path_InvAC2);// значок переменки

      //внутренний прямоугольник
      painter.setPen(QPen(Qt::white, 1, Qt::SolidLine, Qt::FlatCap));
      Node_107 = arr.mid(1817,1).toUInt(&ok,16);
      if(Node_107 == 8)
      {
            painter.setBrush(QBrush(Qt::green, Qt::SolidPattern));
      }
      else if (Node_107 == 4) {
           painter.setBrush(QBrush(Qt::yellow, Qt::SolidPattern));
      }
      else if (Node_107 == 2) {
           painter.setBrush(QBrush(Qt::red, Qt::SolidPattern));
      }
      else if (Node_107 == 0) {
           painter.setBrush(QBrush(Qt::black, Qt::SolidPattern));
      }
      else {
           painter.setBrush(QBrush(Qt::gray, Qt::SolidPattern));
      }
      painter.drawRect(790, 230, 30, 10); //внутренний прямоугольник

      //Инвертора Node_108
      Node_108 = arr.mid(1825,1).toUInt(&ok,16);
      if(Node_108 == 8)
      {
          painter.setPen(QPen(Qt::green, 2, Qt::SolidLine, Qt::FlatCap));
      }
      else if (Node_108 == 2) {
          painter.setPen(QPen(Qt::red, 2, Qt::SolidLine, Qt::FlatCap));
      }
      else if (Node_108 == 0) {
           painter.setPen(QPen(Qt::black, 2, Qt::SolidLine, Qt::FlatCap));
      }
      else {
           painter.setPen(QPen(Qt::gray, 2, Qt::SolidLine, Qt::FlatCap));
      }

      painter.drawLine(840, 235, 900, 235);//Node_108 от инверторам
      painter.drawLine(900, 235, 900, 225);//Node_108 от инверторам
      painter.drawLine(935, 235, 935, 220);//Node_108 от инверторам

      //Инвертора Node_109
       Node_109 = arr.mid(1832,2).toUInt(&ok,16);
       //Node_109_Color = arr.mid(1833,1).toUInt(&ok,16);
      if(Node_109 == 24 )
      {
          painter.setPen(QPen(Qt::green, 2, Qt::SolidLine, Qt::FlatCap));
          painter.drawLine(900, 225, 940, 225);//Node_109
      }
      else if (Node_109 == 34 )
      {
          painter.setPen(QPen(Qt::red, 2, Qt::SolidLine, Qt::FlatCap));
          painter.drawLine(900, 225, 940, 205);//Node_109
      }
      else {
          painter.setPen(QPen(Qt::gray, 2, Qt::SolidLine, Qt::FlatCap));
          painter.drawLine(900, 225, 940, 205);//Node_109
      }


      //Инвертора Node_110
      painter.setPen(QPen(Qt::white, 2, Qt::SolidLine, Qt::FlatCap));
      painter.setBrush(QColor(53, 52, 54));
      painter.drawRect(770, 400, 70, 70);
      painter.drawLine(770, 470, 840, 400);
      painter.setPen(QPen(Qt::white, 1, Qt::SolidLine, Qt::FlatCap));

       Node_110 = arr.mid(1841,1).toUInt(&ok,16);
       if(Node_110 == 8)
       {
            painter.setBrush(QBrush(Qt::green, Qt::SolidPattern));
       }
       else if (Node_110 == 4) {
           painter.setBrush(QBrush(Qt::yellow, Qt::SolidPattern));
       }
       else if (Node_110 == 2){
           painter.setBrush(QBrush(Qt::red, Qt::SolidPattern));
       }
       else if (Node_110 == 0) {
           painter.setBrush(QBrush(Qt::black, Qt::SolidPattern));
       }
       else {
           painter.setBrush(QBrush(Qt::gray, Qt::SolidPattern));
       }

      painter.drawRect(790, 430, 30, 10); //внутренний прямоугольник
      painter.setPen(QPen(Qt::white, 2, Qt::SolidLine, Qt::FlatCap));
      painter.drawLine(780, 413, 797, 413);//линии DC in
      painter.drawLine(780, 418, 797, 418);//линии DC in
      painter.drawLine(810, 453, 827, 453);//линии DC out
      painter.drawLine(810, 458, 827, 458);//линии DC out

      //Инвертора Node_111
      Node_111 = arr.mid(1849,1).toUInt(&ok,16);
      if(Node_111 == 8)
      {
          painter.setPen(QPen(Qt::green, 2, Qt::SolidLine, Qt::FlatCap));
      }
      else if (Node_111 == 2) {
          painter.setPen(QPen(Qt::red, 2, Qt::SolidLine, Qt::FlatCap));
      }
      else if (Node_111 == 0) {
          painter.setPen(QPen(Qt::black, 2, Qt::SolidLine, Qt::FlatCap));
      }
      else {
          painter.setPen(QPen(Qt::gray, 2, Qt::SolidLine, Qt::FlatCap));
      }

      painter.drawLine(840, 430, 900, 430);//Node_111
      painter.drawLine(900, 430, 900, 420);//Node_111 от DC/DC
      painter.drawLine(935, 430, 935, 415);//Node_111 от DC/DC

      //Инвертора Node_112
       Node_112 = arr.mid(1856,2).toUInt(&ok,16);
       //Node_112_Color = arr.mid(1857,1).toUInt(&ok,16);
      if(Node_112 == 24)
      {
      painter.setPen(QPen(Qt::green, 2, Qt::SolidLine, Qt::FlatCap));
      painter.drawLine(900, 420, 940, 420);//Node_109
      }
      else if (Node_112 == 34)
      {
      painter.setPen(QPen(Qt::red, 2, Qt::SolidLine, Qt::FlatCap));
      painter.drawLine(900, 420, 940, 400);//Node_109
      }
      else {
          painter.setPen(QPen(Qt::gray, 2, Qt::SolidLine, Qt::FlatCap));
          painter.drawLine(900, 420, 940, 400);//Node_109
      }

      //Инвертора Node_113
      Node_113 = arr.mid(1865,1).toUInt(&ok,16);
      if(Node_113 == 8)
      {
          painter.setPen(QPen(Qt::green, 2, Qt::SolidLine, Qt::FlatCap));
          painter.setBrush(QBrush(Qt::green, Qt::SolidPattern));
      }
      else if (Node_113 == 2) {
          painter.setPen(QPen(Qt::red, 2, Qt::SolidLine, Qt::FlatCap));
          painter.setBrush(QBrush(Qt::red, Qt::SolidPattern));
      }
      else if(Node_113 == 0) {
          painter.setPen(QPen(Qt::black, 2, Qt::SolidLine, Qt::FlatCap));
          painter.setBrush(QBrush(Qt::black, Qt::SolidPattern));
      }
      else {
          painter.setPen(QPen(Qt::gray, 2, Qt::SolidLine, Qt::FlatCap));
          painter.setBrush(QBrush(Qt::gray, Qt::SolidPattern));
      }
      painter.drawLine(935, 430, 1100, 430);//Node_113
      QPolygon polygon113;   // Используем класс полигона, чтобы отрисовать треугольник
      polygon113 << QPoint(980,430) << QPoint(960,425) << QPoint(960,435);
      painter.drawPolygon(polygon113);  //  треугольник Node_113
      painter.setPen(QPen(Qt::white, 2, Qt::SolidLine, Qt::FlatCap));
      painter.setFont(QFont("Arial", 10));
      painter.drawText(1030,425,"П-М");


      //Node_116
      Node_116 = arr.mid(1888,2).toUInt(&ok,16);
      //Node_116_Color = arr.mid(1889,1).toUInt(&ok,16);
      if(Node_116 == 24)
      {
          painter.setPen(QPen(Qt::green, 2, Qt::SolidLine, Qt::FlatCap));
          painter.drawLine(457, 360, 417, 360);
      }
      else if (Node_116 == 34) {
          painter.setPen(QPen(Qt::red, 2, Qt::SolidLine, Qt::FlatCap));
          painter.drawLine(457, 340, 417, 360);
      }
      else {
          painter.setPen(QPen(Qt::gray  , 2, Qt::SolidLine, Qt::FlatCap));
          painter.drawLine(457, 340, 417, 360);
      }

      //Node_114
      Node_114 = arr.mid(1872,2).toUInt(&ok,16);
      QPolygon polygon114;   // Используем класс полигона, чтобы отрисовать треугольник
              // Помещаем координаты точек в полигональную модель
      if (Node_114 == 24)
      {
           painter.setBrush(Qt::green);
          polygon114 << QPoint(370,370) << QPoint(390,365) << QPoint(390,375);
      }

      else if(Node_114 == 34){
        painter.setBrush(Qt::green);     // Устанавливаем кисть, которой будем отрисовывать объект
         polygon114 << QPoint(370,370) << QPoint(350,365) << QPoint(350,375);
      }
      else {
          painter.setBrush(Qt::gray);     // Устанавливаем кисть, которой будем отрисовывать объект
          polygon114 << QPoint(370,370) << QPoint(390,365) << QPoint(390,375);
      }


      //Node_132
     Node_132 = arr.mid(2017,1).toUInt(&ok,16);
     if(Node_132 == 8)
     {
         painter.setPen(QPen(Qt::green, 2, Qt::SolidLine, Qt::FlatCap));
     }
     else if (Node_132 == 2) {
          painter.setPen(QPen(Qt::red, 2, Qt::SolidLine, Qt::FlatCap));
     }
     else if (Node_132 == 0) {
          painter.setPen(QPen(Qt::black, 2, Qt::SolidLine, Qt::FlatCap));
     }
     else {
         painter.setPen(QPen(Qt::gray, 2, Qt::SolidLine, Qt::FlatCap));
     }
     painter.drawLine(417, 370, 417, 360);
     painter.drawLine(300, 370, 417, 370);
     painter.drawPolygon(polygon114);  //  треугольник Node_114


      //Инвертора Node_123
      Node_123 = arr.mid(1945,1).toUInt(&ok,16);
      if(Node_123 == 8)
      {
          painter.setPen(QPen(Qt::green, 2, Qt::SolidLine, Qt::FlatCap));
      }
      else if (Node_123 == 2) {
          painter.setPen(QPen(Qt::red, 2, Qt::SolidLine, Qt::FlatCap));
      }
      else if (Node_123 == 0) {
          painter.setPen(QPen(Qt::black, 2, Qt::SolidLine, Qt::FlatCap));
      }
      else {
          painter.setPen(QPen(Qt::gray, 2, Qt::SolidLine, Qt::FlatCap));
      }
      painter.drawLine(935, 235, 1100, 235);//Node_123
      QPolygon polygon123;   // Используем класс полигона, чтобы отрисовать треугольник
      polygon123 << QPoint(980,235) << QPoint(960,230) << QPoint(960,240);
      painter.drawPolygon(polygon123);  //  треугольник Node_123
      painter.setPen(QPen(Qt::white, 2, Qt::SolidLine, Qt::FlatCap));
      painter.setFont(QFont("Arial", 10));
      painter.drawText(1030,230,"ШБП");




      //Node_136
      painter.setPen(QPen(Qt::green, 2, Qt::SolidLine, Qt::FlatCap));
      QPolygon polygon136;   // Используем класс полигона, чтобы отрисовать треугольник
              // Помещаем координаты точек в полигональную модель
      Node_136 = arr.mid(2048,2).toUInt(&ok,16);
      if (Node_136 == 24)
      {
           painter.setBrush(Qt::green);
           polygon136 << QPoint(370,500) << QPoint(390,495) << QPoint(390,505);
      }

       else if(Node_136 == 34){
        painter.setBrush(Qt::green);     // Устанавливаем кисть, которой будем отрисовывать объект
         polygon136 << QPoint(370,500) << QPoint(350,495) << QPoint(350,505);
      }

      else {
          painter.setBrush(Qt::gray);     // Устанавливаем кисть, которой будем отрисовывать объект
          polygon136 << QPoint(370,500) << QPoint(350,495) << QPoint(350,505);
      }
      //Node_135
      Node_135 = arr.mid(2041,1).toUInt(&ok,16);

      if(Node_135 == 8)
      {
          painter.setPen(QPen(Qt::green, 2, Qt::SolidLine, Qt::FlatCap));
      }
      else if (Node_135 == 2) {
           painter.setPen(QPen(Qt::red, 2, Qt::SolidLine, Qt::FlatCap));
      }
      else if (Node_135 == 0) {
           painter.setPen(QPen(Qt::black, 2, Qt::SolidLine, Qt::FlatCap));
      }
      else {
          painter.setPen(QPen(Qt::gray, 2, Qt::SolidLine, Qt::FlatCap));
      }
      painter.drawLine(417, 500, 417, 490);
      painter.drawLine(300, 500, 417, 500);
      painter.drawPolygon(polygon136);  //  треугольник Node_136






      //Node_138

      Node_138 = arr.mid(2064,2).toUInt(&ok,16);
      //Node_116_Color = arr.mid(1889,1).toUInt(&ok,16);
      if(Node_138 == 24)
      {
          painter.setPen(QPen(Qt::green, 2, Qt::SolidLine, Qt::FlatCap));
          painter.drawLine(457, 490, 417, 490);
      }
      else if (Node_138 == 34) {
          painter.setPen(QPen(Qt::red, 2, Qt::SolidLine, Qt::FlatCap));
          painter.drawLine(457, 475, 417, 490);
      }
      else {
          painter.setPen(QPen(Qt::gray  , 2, Qt::SolidLine, Qt::FlatCap));
          painter.drawLine(457, 475, 417, 490);
      }





      //АКБ1
      painter.setPen(QPen(Qt::white, 2, Qt::SolidLine, Qt::FlatCap));
      painter.setBrush(QColor(53, 52, 54));
      painter.drawRect(150, 320, 150, 100);

      //Node_117
      Node_117 = arr.mid((arr.indexOf("7600") - 3),1).toUInt(&ok,16);
      if(Node_117 == 1)
      {
           painter.setPen(QPen(Qt::red, 1, Qt::SolidLine, Qt::FlatCap));
      }
      else if(Node_117 == 8){
           painter.setPen(QPen(Qt::green, 1, Qt::SolidLine, Qt::FlatCap));
      }
      else  {
          painter.setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::FlatCap));
      }
      // Леавя сторона
      painter.drawLine(160, 370, 190, 370);//гор левая
      painter.drawLine(195, 340, 195, 400);//верт левая
      painter.drawLine(205, 350, 205, 390);//ветр правая
      painter.drawLine(210, 370, 220, 370);//гор правая
      // правая сторона
      painter.drawLine(225, 370, 255, 370);//гор левая
      painter.drawLine(260, 340, 260, 400);//верт левая
      painter.drawLine(270, 350, 270, 390);//ветр правая
      painter.drawLine(275, 370, 295, 370);//гор правая

      //надпись АКБ1
      painter.setPen(QPen(Qt::NoPen));
      painter.drawRect(230, 310, 50, 20);
      painter.setPen(QPen(Qt::white, 2, Qt::SolidLine, Qt::FlatCap));
      painter.setFont(QFont("Arial", 10));
      painter.drawText(235,326,"АКБ1");


      //АКБ2
      painter.setPen(QPen(Qt::white, 2, Qt::SolidLine, Qt::FlatCap));
      painter.setBrush(QColor(53, 52, 54));
      painter.drawRect(150, 450, 150, 100);
      //Node_134
      Node_134 = arr.mid((arr.indexOf("8700") - 3),1).toUInt(&ok,16);
      if(Node_134 == 1)
      {
           painter.setPen(QPen(Qt::red, 1, Qt::SolidLine, Qt::FlatCap));
      }
      else if(Node_134 == 8){
           painter.setPen(QPen(Qt::green, 1, Qt::SolidLine, Qt::FlatCap));
      }
      else  {
          painter.setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::FlatCap));
      }
      // Леавя сторона
      painter.drawLine(160, 500, 190, 500);//гор левая
      painter.drawLine(195, 470, 195, 530);//верт левая
      painter.drawLine(205, 480, 205, 520);//ветр правая
      painter.drawLine(210, 500, 220, 500);//гор правая
      // правая сторона
      painter.drawLine(225, 500, 255, 500);//гор левая
      painter.drawLine(260, 470, 260, 530);//верт левая
      painter.drawLine(270, 480, 270, 520);//ветр правая
      painter.drawLine(275, 500, 295, 500);//гор правая
      //надпись АКБ2
      painter.setPen(QPen(Qt::NoPen));
      painter.drawRect(230, 440, 50, 20);
      painter.setPen(QPen(Qt::white, 2, Qt::SolidLine, Qt::FlatCap));
      painter.setFont(QFont("Arial", 10));
      painter.drawText(235,456,"АКБ2");

      //Надписи значки
      painter.setFont(QFont("Arial", 10));
      //Node_118
      //Node_118 = arr.mid(1905,1).toUInt(&ok,16);
      Node_118 = arr.mid((arr.indexOf("7700") - 3),1).toUInt(&ok,16); // поиск 77 в HEX Node_118 (- 3 для значения нода)
      //qDebug() << Node_118 << "118";
      if(Node_118 == 8)
      {
          painter.setPen(QPen(Qt::green, 2, Qt::SolidLine, Qt::FlatCap));
      }
      else if (Node_118 == 2) {
          painter.setPen(QPen(Qt::red, 2, Qt::SolidLine, Qt::FlatCap));
      }
      else if (Node_118 == 1) {
          painter.setPen(QPen(Qt::black, 2, Qt::SolidLine, Qt::FlatCap));
      }
      else {
          painter.setPen(QPen(Qt::gray, 2, Qt::SolidLine, Qt::FlatCap));
      }
      painter.drawText(100,70,"КПП");

      //Node_126
      Node_126 = arr.mid((arr.indexOf("7f00") - 3),1).toUInt(&ok,16);
      if(Node_126 == 8)
      {
          painter.setPen(QPen(Qt::green, 2, Qt::SolidLine, Qt::FlatCap));
      }
      else if (Node_126 == 2) {
          painter.setPen(QPen(Qt::red, 2, Qt::SolidLine, Qt::FlatCap));
      }
      else if (Node_126 == 1) {
          painter.setPen(QPen(Qt::black, 2, Qt::SolidLine, Qt::FlatCap));
      }
      else {
          painter.setPen(QPen(Qt::gray, 2, Qt::SolidLine, Qt::FlatCap));
      }
      painter.drawText(150,70,"УЗИП");

      //Node_119
      Node_119 = arr.mid(1913,1).toUInt(&ok,16);
      if(Node_119 == 1)
      {
           painter.setPen(QPen(Qt::red, 1, Qt::SolidLine, Qt::FlatCap));
      }
      else if(Node_119 == 8){
           painter.setPen(QPen(Qt::green, 1, Qt::SolidLine, Qt::FlatCap));
      }
      else  {
          painter.setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::FlatCap));
      }
      painter.drawLine(215, 62, 225, 62); // DC
      painter.drawLine(215, 67, 225, 67); //DC
      painter.drawLine(227, 75, 237, 55); // /
      painter.drawLine(243, 62, 253, 62); //DC
      painter.drawLine(243, 67, 253, 67); //DC

      //Node_120
      Node_120 = arr.mid((arr.indexOf("7900") - 3),1).toUInt(&ok,16);
      if(Node_120 == 8)
      {
          painter.setPen(QPen(Qt::green, 2, Qt::SolidLine, Qt::FlatCap));
      }
      else if (Node_120 == 2) {
          painter.setPen(QPen(Qt::red, 2, Qt::SolidLine, Qt::FlatCap));
      }
      else if (Node_120 == 1) {
          painter.setPen(QPen(Qt::black, 2, Qt::SolidLine, Qt::FlatCap));
      }
      else {
          painter.setPen(QPen(Qt::gray, 2, Qt::SolidLine, Qt::FlatCap));
      }
      painter.drawText(270,70,"ШПТ");

      //Node_121
      Node_121 = arr.mid((arr.indexOf("7a00") - 3),1).toUInt(&ok,16);
      //qDebug()<< Node_121 << arr.indexOf("7a00");
      if(Node_121 == 8)
      {
          painter.setPen(QPen(Qt::green, 2, Qt::SolidLine, Qt::FlatCap));
      }
      else if (Node_121 == 2) {
          painter.setPen(QPen(Qt::red, 2, Qt::SolidLine, Qt::FlatCap));
      }
      else if (Node_121 == 1) {
          painter.setPen(QPen(Qt::black, 2, Qt::SolidLine, Qt::FlatCap));
      }
      else {
          painter.setPen(QPen(Qt::gray, 2, Qt::SolidLine, Qt::FlatCap));
      }
      painter.drawText(540,70,"ТБ");

      //Node_124

      Node_124 = arr.mid((arr.indexOf("7d00") - 3),1).toUInt(&ok,16);
      if(Node_124 == 8)
      {
          painter.setPen(QPen(Qt::green, 2, Qt::SolidLine, Qt::FlatCap));
      }
      else if (Node_124 == 2) {
          painter.setPen(QPen(Qt::red, 2, Qt::SolidLine, Qt::FlatCap));
      }
      else if (Node_124 == 1) {
          painter.setPen(QPen(Qt::black, 2, Qt::SolidLine, Qt::FlatCap));
      }
      else {
          painter.setPen(QPen(Qt::gray, 2, Qt::SolidLine, Qt::FlatCap));
      }
      painter.drawText(320,70,"Вен");

      //Node_127
     // Node_127 = arr.mid((arr.indexOf("8000") - 3),1).toUInt(&ok,16);
     Node_127 = arr.mid(1977,1).toUInt(&ok,16);
     // qDebug() << arr.indexOf("8000") << "Node_127";
      if(Node_127 == 8)
      {
          painter.setPen(QPen(Qt::green, 2, Qt::SolidLine, Qt::FlatCap));
      }
      else if (Node_127 == 2) {
          painter.setPen(QPen(Qt::red, 2, Qt::SolidLine, Qt::FlatCap));
      }
      else if (Node_127 == 1) {
          painter.setPen(QPen(Qt::black, 2, Qt::SolidLine, Qt::FlatCap));
      }
      else {
          painter.setPen(QPen(Qt::gray, 2, Qt::SolidLine, Qt::FlatCap));
      }
      painter.drawText(370,70,"СД");

      //Node_125

      //Node_125 = arr.mid(1961,1).toUInt(&ok,16);
      Node_125 = arr.mid((arr.indexOf("7e00") - 3),1).toUInt(&ok,16);
      if(Node_125 == 1)
      {
           painter.setPen(QPen(Qt::red, 1, Qt::SolidLine, Qt::FlatCap));
      }
      else if(Node_125 == 8){
           painter.setPen(QPen(Qt::green, 1, Qt::SolidLine, Qt::FlatCap));
      }
      else  {
          painter.setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::FlatCap));
      }
      painter.drawLine(420, 67, 430, 67); // DC
      painter.drawLine(420, 72, 430, 72); //DC
      QPainterPath Node_125_AC_in;// значок переменки входа
      Node_125_AC_in.moveTo(420,60);
      Node_125_AC_in.cubicTo(425,45,428,67,431,54);
      painter.setBrush(Qt::NoBrush);
      painter.drawPath(Node_125_AC_in);// отрисовка значка переменки входа
      painter.drawLine(435, 80, 447, 50); // /
      QPainterPath Node_125_AC_out; // значок переменки выхода
      Node_125_AC_out.moveTo(450,70);
      Node_125_AC_out.cubicTo(455,55,458,77,462,65);
      painter.setBrush(Qt::NoBrush);
      painter.drawPath(Node_125_AC_out);// отрисовка значка переменки выхода
      //Node_137

      Node_137 = arr.mid(2057,1).toUInt(&ok,16);
      if(Node_137 == 1)
      {
           painter.setPen(QPen(Qt::red, 1, Qt::SolidLine, Qt::FlatCap));
      }
      else if(Node_137 == 8){
           painter.setPen(QPen(Qt::green, 1, Qt::SolidLine, Qt::FlatCap));
      }
      else  {
          painter.setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::FlatCap));
      }
      painter.drawText(480,70,"АУБП");

      //Node_31
      Node_31 = arr.mid(1209,1).toUInt(&ok,16);
      if(Node_31 == 1)
      {
           painter.setPen(QPen(Qt::red, 1, Qt::SolidLine, Qt::FlatCap));
      }
      else if(Node_31 == 8){
           painter.setPen(QPen(Qt::green, 1, Qt::SolidLine, Qt::FlatCap));
      }
      else  {
          painter.setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::FlatCap));
      }
      painter.drawText(580,70,"АО");
      update();
//     painter.setPen(QPen(Qt::white, 1, Qt::SolidLine, Qt::FlatCap));
//      painter.setBrush(QBrush(Qt::gray, Qt::SolidPattern));
//     //ВУФ1
//      painter.drawRect(20, 50, 70, 70);
//      painter.drawText(33,40,"VUF1");
//      painter.drawLine(100,85 ,40, 85);
//      //ВУФ2
//      painter.drawRect(20, 200, 70, 70);
//      painter.drawText(33, 190,"VUF2");
//      //ВУФ3
//      painter.drawRect(20, 350, 70, 70);
//      painter.drawText(33, 340,"VUF3");

}


void Shcema::resizeEvent(QResizeEvent *event)
{



}
