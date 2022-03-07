#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStackedWidget>
#include<QDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    //ui->fileline->setPlaceholderText("Enter path to file");
   // ui->fileline->setPlaceholderText("Введите путь к файлу");
    //this->setStyleSheet("background-color: rgb(50, 50, 50)");
   // file.open(QIODevice::ReadOnly); // открытие файла архива
   // m_data->file.open(QIODevice::ReadOnly); // открытие файла архива
    //tmp = file.readAll();
   // m_filename = ui->fileline->text();

   // m_data = new Data(m_filename);


    //this->setWindowIcon(QIcon("hourglass.png"));



    window_schema = new Shcema();
    window_tables = new Tables();


    ui->play->setCheckable(true);
    //ui->play_speed2->setCheckable(true);
    ui->Button_next->setCheckable(true);
    ui->Button_prev->setCheckable(true);

    ui->play->setEnabled(false);
    //ui->play_speed2->setEnabled(false);
    ui->Button_next->setEnabled(false);
    ui->Button_prev->setEnabled(false);




//    out << "The current date is " << cdt.date().toString() << endl; // выводим только дату
//    out << "The current time is " << cdt.time().toString() << endl; // выводим только время
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slotTimerAlarm()
{

    //ui->label_timer->setText(QTime::currentTime().toString("hh:mm:ss"));

}

void MainWindow::timerEvent(QTimerEvent *event)
{



    if(event->timerId() == id1 ){
    count++;
    data_array = m_data->file.read(3480).toHex();

    dt.setTime_t(qToBigEndian(data_array.mid(0,8).toUInt(&ok, 16)));//переворот байт(считывание 8 байт с 0 позиции)
    ui->label_timer_2->setText(dt.toString("yyyy-MM-dd hh:mm:ss"));
    connect(this,SIGNAL(receiveData(QByteArray)),window_tables,SLOT(slotReadArr(QByteArray)));
    connect(this,SIGNAL(receiveData(QByteArray)),window_schema,SLOT(slotReadArr(QByteArray)));
    emit receiveData(data_array);


repaint();
   }
}


void MainWindow::on_Tables_clicked() // открытие окна таблицы
{

    window_tables->setWindowTitle("Таблицы измерений");
    window_tables->setStyleSheet("background-color: rgb(50, 50, 50)");
    //window_tables->move(1130,0);

    window_tables->show();


}

void MainWindow::on_Schema_clicked() // открытие окна мнемосхемы
{

    window_schema->setWindowTitle("Мнемосхема");
    window_schema->setStyleSheet("background-color: rgb(50, 50, 50)");
    window_schema->move(0,250);

    window_schema->show();

}

void MainWindow::on_play_clicked()
{

    if(ui->play->isChecked()){
        ui->play->setText("Стоп");
        //ui->play_speed2->setChecked(false);
        id1 = startTimer(1000);
       // qDebug()<<"true";
    }
    else {
        killTimer(id1);
         //ui->pushButton->setCheckable(false);
        ui->play->setText("Старт");

        //ui->play_speed2->setChecked(false);
//        ui->Button_prev->setChecked(false);
//        ui->Button_next->setChecked(false);
       // qDebug()<<"sssss";
        //qDebug()<<"false";
    }
        QFont font("Times", 28, QFont::Bold);
        //ui->label_timer->setFont(font);
        //ui->label_timer->setText(QTime::currentTime().toString("hh:mm:ss"));
        timer = new QTimer();
        connect(timer, SIGNAL(timeout()), this, SLOT(slotTimerAlarm()));
        timer->start(1000);

}


QByteArray MainWindow::get_data_array()
{
    return data_array;
}



//void MainWindow::on_play_speed2_clicked()
//{
//    if(ui->play_speed2->isChecked()){
//        ui->play->setChecked(false);
//        id1 = startTimer(250);
//        //qDebug()<<"true";
//    }
//    else {
//        killTimer(id1);
//        // ui->play->setCheckable(false);
//        //qDebug()<<"false";
//    }
//}



void MainWindow::on_Button_next_clicked()
{
    if(ui->Button_next->isChecked()){
         ui->play->setChecked(false);
         //ui->play_speed2->setChecked(false);
         ui->Button_prev->setChecked(false);
         if(!ui->play->isChecked())
         {
          killTimer(id1);
         }
    data_array = m_data->file.read(3480).toHex();
         //tmp= m_data->gettmp();
   // cur +=3480;

     //file.pos();
     ui->Button_next->setChecked(false);
      //qDebug() <<  file.pos() << cur;
      dt.setTime_t(qToBigEndian(data_array.mid(0,8).toUInt(&ok, 16)));//переворот байт(считывание 8 байт с 0 позиции)
      ui->label_timer_2->setText(dt.toString("yyyy-MM-dd hh:mm:ss"));
      connect(this,SIGNAL(receiveData(QByteArray)),window_tables,SLOT(slotReadArr(QByteArray)));
      connect(this,SIGNAL(receiveData(QByteArray)),window_schema,SLOT(slotReadArr(QByteArray)));
      emit receiveData(data_array);
    }
}

void MainWindow::on_Button_prev_clicked()//чтение файла назад
{
    // qDebug() <<  "prev";
    if(ui->Button_prev->isChecked()){
         ui->play->setChecked(false);
         //ui->play_speed2->setChecked(false);
         ui->Button_next->setChecked(false);
         if(!ui->play->isChecked())
         {
          killTimer(id1);
         }
    cur = m_data->file.pos() - (3480 + 3480);
         //cur = m_data->m_file.pos() - (3480 + 3480);
   // qDebug() << file.pos()<< cur ;
    m_data->file.seek(cur);
    data_array = m_data->file.read(3480).toHex();
    //tmp = m_data->m_file.read(3480).toHex();


      ui->Button_prev->setChecked(false);
      //qDebug() << file.pos()<< cur ;
      dt.setTime_t(qToBigEndian(data_array.mid(0,8).toUInt(&ok, 16)));//переворот байт(считывание 8 байт с 0 позиции)
      ui->label_timer_2->setText(dt.toString("yyyy-MM-dd hh:mm:ss"));
      connect(this,SIGNAL(receiveData(QByteArray)),window_tables,SLOT(slotReadArr(QByteArray)));
      connect(this,SIGNAL(receiveData(QByteArray)),window_schema,SLOT(slotReadArr(QByteArray)));
      emit receiveData(data_array);
    }
}

void MainWindow::closeEvent(QCloseEvent *event)
{
     Q_UNUSED(event);
    if(window_schema != nullptr)
    {
       window_schema->close();
       delete window_schema;
    }
    if(window_tables != nullptr)
    {
       window_tables->close();
       delete window_tables;
    }
    delete m_data;

}

void MainWindow::on_EnterFileName_clicked()
{
   // m_filename = ui->fileline->text();
    qDebug()<<"m_filename"<<m_filename;
    m_data = new Data(m_filename);
    //if(!ui->EnterFileName->isChecked())
    if(m_filename!= "")
    {

    ui->play->setEnabled(true);
    ui->Button_next->setEnabled(true);
    ui->Button_prev->setEnabled(true);
    //ui->play_speed2->setEnabled(true);
    //buttonDisable->setText("Enable");
    //ui->EnterFileName->setDefault(false);
    }
//    else if(!ui->EnterFileName->isDefault())
//    {
//        ui->play->setEnabled(true);
//        //buttonDisable->setText("Disable");
//        ui->EnterFileName->setDefault(false);
//    }

}



void MainWindow::on_comboBox_activated(const QString &arg1)
{
    if(arg1 == "X1")
    {
        id1 = startTimer(1000);
    }
    else if(arg1 == "X2")
    {
        id1 = startTimer(500);
    }
    else if (arg1 == "X4")
    {
        id1 = startTimer(250);
    }
    else if (arg1 == "X8")
    {
        id1 = startTimer(125);
    }
    else if (arg1 == "X16")
    {
        id1 = startTimer(62);
    }
}

void MainWindow::on_OpenFile_clicked()
{
    m_filename = QFileDialog::getOpenFileName();
    //qDebug()<<"m_filename"<<m_filename;
    m_data = new Data(m_filename);

}
