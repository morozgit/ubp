#include "tables.h"
#include "ui_tables.h"
#include<QtDebug>


Tables::Tables(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Tables)
{
    ui->setupUi(this);

//    // Создание Таблицы выпрямителей
//        ui->tableWidget->setRowCount(4); // указываем количество строк
//        ui->tableWidget->setColumnCount(5); // указываем количество столбцов
//        ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
//        ui->tableWidget->setStyleSheet("QHeaderView::section { background-color:rgb(118,118,118) };");
//        ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
//        ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "" <<"4UZ1" << "4UZ2" << "4UZ3" << "4UZ4");
}
void Tables:: slotReadArr(QByteArray tmp)
{

    arr_tab = tmp;


//cou++;

//    Tables g;
//    g.readFile();

    //qDebug()<<"slotReadArrtabl" << cou;


}
int Tables::change_type(quint16 byte) //замена типа данных для нормального отображения
{
    quint16 tmp = byte;
    int result = qToBigEndian(tmp);
    return result;

}

void Tables::paintEvent(QPaintEvent *event)
{

    Q_UNUSED(event);
          bool ok;
          ui->labeltab->setStyleSheet("color: rgb(255,255, 255)");
          dt.setTime_t(qToBigEndian(arr_tab.mid(0,8).toUInt(&ok, 16)));//переворот байт(считывание 8 байт с 0 позиции)
          ui->labeltab->setText(dt.toString("yyyy-MM-dd hh:mm:ss"));
          //ui->U_4UZ1->setStyleSheet("background-color: rgb(255,0, 0)");
//          UBP_1INV1_U_AC1_tmp = (arr_tab.mid(352,4).toUInt(&ok,16));
//          UBP_1INV1_U_AC1 = qToBigEndian(UBP_1INV1_U_AC1_tmp);

        //UBP_1INV1_U_AC1 = change_type(arr_tab.mid(352,4).toUInt(&ok,16));
          UBP_1INV1_U_AC1 = change_type(arr_tab.mid((arr_tab.lastIndexOf(str_INV_U_AC1) + strlen(str_INV_U_AC1)),4).toUInt(&ok,16));
           QTableWidgetItem *item1 = new QTableWidgetItem(tr("%1").arg(UBP_1INV1_U_AC1/10));

          //qDebug() <<(arr_tab.lastIndexOf("60000f0000000100")) << strlen(str_T2S) << qstrlen(str_T2S);
        if(UBP_1INV1_U_AC1 >1500 && UBP_1INV1_U_AC1 < 2650)
        {
//           ui->tableWidget->setItem(1,2,item1);
//           ui->tableWidget->item(1,2)->setBackground(Qt::gray);
        ui->U_AC_1INV1_in->setNum(UBP_1INV1_U_AC1/10);
        ui->U_AC_1INV1_in->setStyleSheet("background-color: rgb(118, 118, 118);");
        }
        else {
//            ui->tableWidget->setItem(1,2,item1);
//            ui->tableWidget->item(1,2)->setBackground(Qt::red);
        ui->U_AC_1INV1_in->setNum(UBP_1INV1_U_AC1/10);
        ui->U_AC_1INV1_in->setStyleSheet("background-color: rgb(255,0, 0)");
        }

       // UBP_1INV2_U_AC1 = change_type(arr_tab.mid(356,4).toUInt(&ok,16));
        UBP_1INV2_U_AC1 = change_type(arr_tab.mid((arr_tab.lastIndexOf(str_INV_U_AC1) + strlen(str_INV_U_AC1) + 4),4).toUInt(&ok,16));
        if(UBP_1INV2_U_AC1 >1500 && UBP_1INV2_U_AC1 < 2650)
        {
        ui->U_AC_1INV2_in->setNum(UBP_1INV2_U_AC1/10);
        ui->U_AC_1INV2_in->setStyleSheet("background-color: rgb(118, 118, 118);");
        }
        else {
        ui->U_AC_1INV2_in->setNum(UBP_1INV2_U_AC1/10);
        ui->U_AC_1INV2_in->setStyleSheet("background-color: rgb(255,0, 0)");
        }

        //UBP_1INV3_U_AC1 = change_type(arr_tab.mid(360,4).toUInt(&ok,16));
        UBP_1INV3_U_AC1 = change_type(arr_tab.mid((arr_tab.lastIndexOf(str_INV_U_AC1) + strlen(str_INV_U_AC1) + 8),4).toUInt(&ok,16));
        if(UBP_1INV3_U_AC1 >1500 && UBP_1INV3_U_AC1 < 2650)
        {
        ui->U_AC_1INV3_in->setNum(UBP_1INV3_U_AC1/10);
        ui->U_AC_1INV3_in->setStyleSheet("background-color: rgb(118, 118, 118);");
        }
        else {
        ui->U_AC_1INV3_in->setNum(UBP_1INV3_U_AC1/10);
        ui->U_AC_1INV3_in->setStyleSheet("background-color: rgb(255,0, 0)");
        }

        UBP_1INV4_U_AC1 = change_type(arr_tab.mid(364,4).toUInt(&ok,16));
        if(UBP_1INV4_U_AC1 >1500 && UBP_1INV4_U_AC1 < 2650)
        {
        ui->U_AC_1INV4_in->setNum(UBP_1INV4_U_AC1/10);
        ui->U_AC_1INV4_in->setStyleSheet("background-color: rgb(118, 118, 118);");
        }
        else {
        ui->U_AC_1INV4_in->setNum(UBP_1INV4_U_AC1/10);
        ui->U_AC_1INV4_in->setStyleSheet("background-color: rgb(255,0, 0)");
        }

        UBP_2INV1_U_AC1 = change_type(arr_tab.mid(368,4).toUInt(&ok,16));
        if(UBP_2INV1_U_AC1 >1500 && UBP_2INV1_U_AC1 < 2650)
        {
        ui->U_AC_2INV1_in->setNum(UBP_2INV1_U_AC1/10);
        ui->U_AC_2INV1_in->setStyleSheet("background-color: rgb(118, 118, 118);");
        }
        else {
        ui->U_AC_2INV1_in->setNum(UBP_2INV1_U_AC1/10);
        ui->U_AC_2INV1_in->setStyleSheet("background-color: rgb(255,0, 0)");
        }

        UBP_2INV2_U_AC1 = change_type(arr_tab.mid(372,4).toUInt(&ok,16));
        if(UBP_2INV2_U_AC1 >1500 && UBP_2INV2_U_AC1 < 2650)
        {
        ui->U_AC_2INV2_in->setNum(UBP_2INV2_U_AC1/10);
        ui->U_AC_2INV2_in->setStyleSheet("background-color: rgb(118, 118, 118);");
        }
        else {
        ui->U_AC_2INV2_in->setNum(UBP_2INV2_U_AC1/10);
        ui->U_AC_2INV2_in->setStyleSheet("background-color: rgb(255,0, 0)");
        }

        UBP_2INV3_U_AC1 = change_type(arr_tab.mid(376,4).toUInt(&ok,16));
        if(UBP_2INV3_U_AC1 >1500 && UBP_2INV3_U_AC1 < 2650)
        {
        ui->U_AC_2INV3_in->setNum(UBP_2INV3_U_AC1/10);
        ui->U_AC_2INV3_in->setStyleSheet("background-color: rgb(118, 118, 118);");
        }
        else {
        ui->U_AC_2INV3_in->setNum(UBP_2INV3_U_AC1/10);
        ui->U_AC_2INV3_in->setStyleSheet("background-color: rgb(255,0, 0)");
        }

        UBP_2INV4_U_AC1 = change_type(arr_tab.mid(380,4).toUInt(&ok,16));
        if(UBP_2INV4_U_AC1 >1500 && UBP_2INV4_U_AC1 < 2650)
        {
        ui->U_AC_2INV4_in->setNum(UBP_2INV4_U_AC1/10);
        ui->U_AC_2INV4_in->setStyleSheet("background-color: rgb(118, 118, 118);");
        }
        else {
        ui->U_AC_2INV4_in->setNum(UBP_2INV4_U_AC1/10);
        ui->U_AC_2INV4_in->setStyleSheet("background-color: rgb(255,0, 0)");
        }

        UBP_3INV1_U_AC1 = change_type(arr_tab.mid(384,4).toUInt(&ok,16));
        if(UBP_3INV1_U_AC1 >1500 && UBP_3INV1_U_AC1 < 2650)
        {
        ui->U_AC_3INV1_in->setNum(UBP_3INV1_U_AC1/10);
        ui->U_AC_3INV1_in->setStyleSheet("background-color: rgb(118, 118, 118);");
        }
        else {
        ui->U_AC_3INV1_in->setNum(UBP_3INV1_U_AC1/10);
        ui->U_AC_3INV1_in->setStyleSheet("background-color: rgb(255,0, 0)");
        }

        UBP_3INV2_U_AC1 = change_type(arr_tab.mid(388,4).toUInt(&ok,16));
        if(UBP_3INV2_U_AC1 >1500 && UBP_3INV2_U_AC1 < 2650)
        {
        ui->U_AC_3INV2_in->setNum(UBP_3INV2_U_AC1/10);
        ui->U_AC_3INV2_in->setStyleSheet("background-color: rgb(118, 118, 118);");
        }
        else {
        ui->U_AC_3INV2_in->setNum(UBP_3INV2_U_AC1/10);
        ui->U_AC_3INV2_in->setStyleSheet("background-color: rgb(255,0, 0)");
        }

        UBP_3INV3_U_AC1 = change_type(arr_tab.mid(392,4).toUInt(&ok,16));
        if(UBP_3INV3_U_AC1 >1500 && UBP_3INV3_U_AC1 < 2650)
        {
        ui->U_AC_3INV3_in->setNum(UBP_3INV3_U_AC1/10);
        ui->U_AC_3INV3_in->setStyleSheet("background-color: rgb(118, 118, 118);");
        }
        else {
        ui->U_AC_3INV3_in->setNum(UBP_3INV3_U_AC1/10);
        ui->U_AC_3INV3_in->setStyleSheet("background-color: rgb(255,0, 0)");
        }

        UBP_3INV4_U_AC1 = change_type(arr_tab.mid(396,4).toUInt(&ok,16));
        if(UBP_3INV4_U_AC1 >1500 && UBP_3INV4_U_AC1 < 2650)
        {
        ui->U_AC_3INV4_in->setNum(UBP_3INV4_U_AC1/10);
        ui->U_AC_3INV4_in->setStyleSheet("background-color: rgb(118, 118, 118);");
        }
        else {
        ui->U_AC_3INV4_in->setNum(UBP_3INV4_U_AC1/10);
        ui->U_AC_3INV4_in->setStyleSheet("background-color: rgb(255,0, 0)");
        }

        // входное DC
        UBP_1INV1_U_DC = change_type(arr_tab.mid(508,4).toUInt(&ok,16));
        if(UBP_1INV1_U_DC >1700 && UBP_1INV1_U_DC < 2700)
        {
        ui->U_DC_1INV1->setNum(UBP_1INV1_U_DC/10);
        ui->U_DC_1INV1->setStyleSheet("background-color: rgb(118, 118, 118);");
        }
        else {
        ui->U_DC_1INV1->setNum(UBP_1INV1_U_DC/10);
        ui->U_DC_1INV1->setStyleSheet("background-color: rgb(255,0, 0)");
        }

        UBP_1INV2_U_DC = change_type(arr_tab.mid(512,4).toUInt(&ok,16));
        if(UBP_1INV2_U_DC >1700 && UBP_1INV2_U_DC < 2700)
        {
        ui->U_DC_1INV2->setNum(UBP_1INV2_U_DC/10);
        ui->U_DC_1INV2->setStyleSheet("background-color: rgb(118, 118, 118);");
        }
        else {
        ui->U_DC_1INV2->setNum(UBP_1INV2_U_DC/10);
        ui->U_DC_1INV2->setStyleSheet("background-color: rgb(255,0, 0)");
        }

        UBP_1INV3_U_DC = change_type(arr_tab.mid(516,4).toUInt(&ok,16));
        if(UBP_1INV3_U_DC >1700 && UBP_1INV3_U_DC < 2700)
        {
        ui->U_DC_1INV3->setNum(UBP_1INV3_U_DC/10);
        ui->U_DC_1INV3->setStyleSheet("background-color: rgb(118, 118, 118);");
        }
        else {
        ui->U_DC_1INV3->setNum(UBP_1INV3_U_DC/10);
        ui->U_DC_1INV3->setStyleSheet("background-color: rgb(255,0, 0)");
        }

        UBP_1INV4_U_DC = change_type(arr_tab.mid(520,4).toUInt(&ok,16));
        if(UBP_1INV4_U_DC >1700 && UBP_1INV4_U_DC < 2700)
        {
         ui->U_DC_1INV4->setNum(UBP_1INV4_U_DC/10);
         ui->U_DC_1INV4->setStyleSheet("background-color: rgb(118, 118, 118);");
        }
        else {
         ui->U_DC_1INV4->setNum(UBP_1INV4_U_DC/10);
         ui->U_DC_1INV4->setStyleSheet("background-color: rgb(255,0, 0)");
        }

        UBP_2INV1_U_DC = change_type(arr_tab.mid(524,4).toUInt(&ok,16));
        if(UBP_2INV1_U_DC >1700 && UBP_2INV1_U_DC < 2700)
        {
          ui->U_DC_2INV1->setNum(UBP_2INV1_U_DC/10);
          ui->U_DC_2INV1->setStyleSheet("background-color: rgb(118, 118, 118);");
        }
        else {
          ui->U_DC_2INV1->setNum(UBP_2INV1_U_DC/10);
          ui->U_DC_2INV1->setStyleSheet("background-color: rgb(255,0, 0)");
        }

        UBP_2INV2_U_DC = change_type(arr_tab.mid(528,4).toUInt(&ok,16));
        if(UBP_2INV2_U_DC >1700 && UBP_2INV2_U_DC < 2700)
        {
           ui->U_DC_2INV2->setNum(UBP_2INV2_U_DC/10);
           ui->U_DC_2INV2->setStyleSheet("background-color: rgb(118, 118, 118);");
        }
        else {
           ui->U_DC_2INV2->setNum(UBP_2INV2_U_DC/10);
           ui->U_DC_2INV2->setStyleSheet("background-color: rgb(255,0, 0)");
        }

        UBP_2INV3_U_DC = change_type(arr_tab.mid(532,4).toUInt(&ok,16));
        if(UBP_2INV3_U_DC >1700 && UBP_2INV3_U_DC < 2700)
        {
            ui->U_DC_2INV3->setNum(UBP_2INV3_U_DC/10);
            ui->U_DC_2INV3->setStyleSheet("background-color: rgb(118, 118, 118);");
        }
        else {
            ui->U_DC_2INV3->setNum(UBP_2INV3_U_DC/10);
            ui->U_DC_2INV3->setStyleSheet("background-color: rgb(255,0, 0)");
        }

        UBP_2INV4_U_DC = change_type(arr_tab.mid(536,4).toUInt(&ok,16));
        if(UBP_2INV4_U_DC >1700 && UBP_2INV4_U_DC < 2700)
        {
            ui->U_DC_2INV4->setNum(UBP_2INV4_U_DC/10);
            ui->U_DC_2INV4->setStyleSheet("background-color: rgb(118, 118, 118);");
        }
        else {
            ui->U_DC_2INV4->setNum(UBP_2INV4_U_DC/10);
            ui->U_DC_2INV4->setStyleSheet("background-color: rgb(255,0, 0)");
        }

        UBP_3INV1_U_DC = change_type(arr_tab.mid(540,4).toUInt(&ok,16));
        if(UBP_3INV1_U_DC >1700 && UBP_3INV1_U_DC < 2700)
        {
            ui->U_DC_3INV1->setNum(UBP_3INV1_U_DC/10);
            ui->U_DC_3INV1->setStyleSheet("background-color: rgb(118, 118, 118);");
        }
        else {
            ui->U_DC_3INV1->setNum(UBP_3INV1_U_DC/10);
            ui->U_DC_3INV1->setStyleSheet("background-color: rgb(255,0, 0)");
        }

        UBP_3INV2_U_DC = change_type(arr_tab.mid(544,4).toUInt(&ok,16));
        if(UBP_3INV2_U_DC >1700 && UBP_3INV2_U_DC < 2700)
        {
            ui->U_DC_3INV2->setNum(UBP_3INV2_U_DC/10);
            ui->U_DC_3INV2->setStyleSheet("background-color: rgb(118, 118, 118);");
        }
        else {
            ui->U_DC_3INV2->setNum(UBP_3INV2_U_DC/10);
            ui->U_DC_3INV2->setStyleSheet("background-color: rgb(255,0, 0)");
        }

        UBP_3INV3_U_DC = change_type(arr_tab.mid(548,4).toUInt(&ok,16));
        if(UBP_3INV3_U_DC >1700 && UBP_3INV3_U_DC < 2700)
        {
            ui->U_DC_3INV3->setNum(UBP_3INV3_U_DC/10);
            ui->U_DC_3INV3->setStyleSheet("background-color: rgb(118, 118, 118);");
        }
        else {
            ui->U_DC_3INV3->setNum(UBP_3INV3_U_DC/10);
            ui->U_DC_3INV3->setStyleSheet("background-color: rgb(255,0, 0)");
        }

        UBP_3INV4_U_DC = change_type(arr_tab.mid(552,4).toUInt(&ok,16));
        if(UBP_3INV4_U_DC >1700 && UBP_3INV4_U_DC < 2700)
        {
            ui->U_DC_3INV4->setNum(UBP_3INV4_U_DC/10);
            ui->U_DC_3INV4->setStyleSheet("background-color: rgb(118, 118, 118);");
        }
        else {
            ui->U_DC_3INV4->setNum(UBP_3INV4_U_DC/10);
            ui->U_DC_3INV4->setStyleSheet("background-color: rgb(255,0, 0)");
        }

        UBP_1INV1_U_AC2 = change_type(arr_tab.mid(664,4).toUInt(&ok,16));
        if(UBP_1INV1_U_AC2 >2150 && UBP_1INV1_U_AC2 < 2255)
        {
            ui->U_AC_1INV1_out->setNum(UBP_1INV1_U_AC2/10);
            ui->U_AC_1INV1_out->setStyleSheet("background-color: rgb(118, 118, 118);");
        }
        else {
            ui->U_AC_1INV1_out->setNum(UBP_1INV1_U_AC2/10);
            ui->U_AC_1INV1_out->setStyleSheet("background-color: rgb(255,0, 0)");
        }

        UBP_1INV2_U_AC2 = change_type(arr_tab.mid(668,4).toUInt(&ok,16));
        if(UBP_1INV2_U_AC2 >2150 && UBP_1INV2_U_AC2 < 2255)
        {
            ui->U_AC_1INV2_out->setNum(UBP_1INV2_U_AC2/10);
            ui->U_AC_1INV2_out->setStyleSheet("background-color: rgb(118, 118, 118);");
        }
        else {
            ui->U_AC_1INV2_out->setNum(UBP_1INV2_U_AC2/10);
            ui->U_AC_1INV2_out->setStyleSheet("background-color: rgb(255,0, 0)");
        }

        UBP_1INV3_U_AC2 = change_type(arr_tab.mid(672,4).toUInt(&ok,16));
        if(UBP_1INV3_U_AC2 >2150 && UBP_1INV3_U_AC2 < 2255)
        {
            ui->U_AC_1INV3_out->setNum(UBP_1INV3_U_AC2/10);
            ui->U_AC_1INV3_out->setStyleSheet("background-color: rgb(118, 118, 118);");
        }
        else {
            ui->U_AC_1INV3_out->setNum(UBP_1INV3_U_AC2/10);
            ui->U_AC_1INV3_out->setStyleSheet("background-color: rgb(255,0, 0)");
        }

        UBP_1INV4_U_AC2 = change_type(arr_tab.mid(676,4).toUInt(&ok,16));
        if(UBP_1INV4_U_AC2 >2150 && UBP_1INV4_U_AC2 < 2255)
        {
            ui->U_AC_1INV4_out->setNum(UBP_1INV4_U_AC2/10);
            ui->U_AC_1INV4_out->setStyleSheet("background-color: rgb(118, 118, 118);");
        }
        else {
            ui->U_AC_1INV4_out->setNum(UBP_1INV4_U_AC2/10);
            ui->U_AC_1INV4_out->setStyleSheet("background-color: rgb(255,0, 0)");
        }

        UBP_2INV1_U_AC2 = change_type(arr_tab.mid(680,4).toUInt(&ok,16));
        if(UBP_2INV1_U_AC2 >2150 && UBP_2INV1_U_AC2 < 2255)
        {
            ui->U_AC_2INV1_out->setNum(UBP_2INV1_U_AC2/10);
            ui->U_AC_2INV1_out->setStyleSheet("background-color: rgb(118, 118, 118);");
        }
        else {
            ui->U_AC_2INV1_out->setNum(UBP_2INV1_U_AC2/10);
            ui->U_AC_2INV1_out->setStyleSheet("background-color: rgb(255,0, 0)");
        }

        UBP_2INV2_U_AC2 = change_type(arr_tab.mid(684,4).toUInt(&ok,16));
        if(UBP_2INV2_U_AC2 >2150 && UBP_2INV2_U_AC2 < 2255)
        {
            ui->U_AC_2INV2_out->setNum(UBP_2INV2_U_AC2/10);
            ui->U_AC_2INV2_out->setStyleSheet("background-color: rgb(118, 118, 118);");
        }
        else {
            ui->U_AC_2INV2_out->setNum(UBP_2INV2_U_AC2/10);
            ui->U_AC_2INV2_out->setStyleSheet("background-color: rgb(255,0, 0)");
        }

        UBP_2INV3_U_AC2 = change_type(arr_tab.mid(688,4).toUInt(&ok,16));
        if(UBP_2INV3_U_AC2 >2150 && UBP_2INV3_U_AC2 < 2255)
        {
            ui->U_AC_2INV3_out->setNum(UBP_2INV3_U_AC2/10);
            ui->U_AC_2INV3_out->setStyleSheet("background-color: rgb(118, 118, 118);");
        }
        else {
            ui->U_AC_2INV3_out->setNum(UBP_2INV3_U_AC2/10);
            ui->U_AC_2INV3_out->setStyleSheet("background-color: rgb(255,0, 0)");
        }

        UBP_2INV4_U_AC2 = change_type(arr_tab.mid(692,4).toUInt(&ok,16));
        if(UBP_2INV4_U_AC2 >2150 && UBP_2INV4_U_AC2 < 2255)
        {
            ui->U_AC_2INV4_out->setNum(UBP_2INV4_U_AC2/10);
            ui->U_AC_2INV4_out->setStyleSheet("background-color: rgb(118, 118, 118);");
        }
        else {
            ui->U_AC_2INV4_out->setNum(UBP_2INV4_U_AC2/10);
            ui->U_AC_2INV4_out->setStyleSheet("background-color: rgb(255,0, 0)");
        }

        UBP_3INV1_U_AC2 = change_type(arr_tab.mid(696,4).toUInt(&ok,16));
        if(UBP_3INV1_U_AC2 >2150 && UBP_3INV1_U_AC2 < 2255)
        {
            ui->U_AC_3INV1_out->setNum(UBP_3INV1_U_AC2/10);
            ui->U_AC_3INV1_out->setStyleSheet("background-color: rgb(118, 118, 118);");
        }
        else {
            ui->U_AC_3INV1_out->setNum(UBP_3INV1_U_AC2/10);
            ui->U_AC_3INV1_out->setStyleSheet("background-color: rgb(255,0, 0)");
        }

        UBP_3INV2_U_AC2 = change_type(arr_tab.mid(700,4).toUInt(&ok,16));
        if(UBP_3INV2_U_AC2 >2150 && UBP_3INV2_U_AC2 < 2255)
        {
            ui->U_AC_3INV2_out->setNum(UBP_3INV2_U_AC2/10);
            ui->U_AC_3INV2_out->setStyleSheet("background-color: rgb(118, 118, 118);");
        }
        else {
            ui->U_AC_3INV2_out->setNum(UBP_3INV2_U_AC2/10);
            ui->U_AC_3INV2_out->setStyleSheet("background-color: rgb(255,0, 0)");
        }

        UBP_3INV3_U_AC2 = change_type(arr_tab.mid(704,4).toUInt(&ok,16));
        if(UBP_3INV3_U_AC2 >2150 && UBP_3INV3_U_AC2 < 2255)
        {
            ui->U_AC_3INV3_out->setNum(UBP_3INV3_U_AC2/10);
            ui->U_AC_3INV3_out->setStyleSheet("background-color: rgb(118, 118, 118);");
        }
        else {
            ui->U_AC_3INV3_out->setNum(UBP_3INV3_U_AC2/10);
            ui->U_AC_3INV3_out->setStyleSheet("background-color: rgb(255,0, 0)");
        }

        UBP_3INV4_U_AC2 = change_type(arr_tab.mid(708,4).toUInt(&ok,16));
        if(UBP_3INV4_U_AC2 >2150 && UBP_3INV4_U_AC2 < 2255)
        {
            ui->U_AC_3INV4_out->setNum(UBP_3INV4_U_AC2/10);
            ui->U_AC_3INV4_out->setStyleSheet("background-color: rgb(118, 118, 118);");
        }
        else {
            ui->U_AC_3INV4_out->setNum(UBP_3INV4_U_AC2/10);
            ui->U_AC_3INV4_out->setStyleSheet("background-color: rgb(255,0, 0)");
        }

        UBP_1INV1_T = arr_tab.mid(820,2).toUInt(&ok,16);
        if(UBP_1INV1_T >-20 && UBP_1INV1_T < 50)
        {
            ui->T_1INV1->setNum(UBP_1INV1_T);
            ui->T_1INV1->setStyleSheet("background-color: rgb(118, 118, 118);");
        }
        else {
            ui->T_1INV1->setNum(UBP_1INV1_T);
            ui->T_1INV1->setStyleSheet("background-color: rgb(255,0, 0)");
        }

        UBP_1INV2_T = arr_tab.mid(824,2).toUInt(&ok,16);
        if(UBP_1INV2_T >-20 && UBP_1INV2_T < 50)
        {
            ui->T_1INV2->setNum(UBP_1INV2_T);
            ui->T_1INV2->setStyleSheet("background-color: rgb(118, 118, 118);");
        }
        else {
            ui->T_1INV2->setNum(UBP_1INV2_T);
            ui->T_1INV2->setStyleSheet("background-color: rgb(255,0, 0)");
        }

        UBP_1INV3_T = arr_tab.mid(828,2).toUInt(&ok,16);
        if(UBP_1INV3_T >-20 && UBP_1INV3_T < 50)
        {
            ui->T_1INV3->setNum(UBP_1INV3_T);
            ui->T_1INV3->setStyleSheet("background-color: rgb(118, 118, 118);");
        }
        else {
            ui->T_1INV3->setNum(UBP_1INV3_T);
            ui->T_1INV3->setStyleSheet("background-color: rgb(255,0, 0)");
        }

        UBP_1INV4_T = arr_tab.mid(832,2).toUInt(&ok,16);
        if(UBP_1INV4_T >-20 && UBP_1INV4_T < 50)
        {
            ui->T_1INV4->setNum(UBP_1INV4_T);
            ui->T_1INV4->setStyleSheet("background-color: rgb(118, 118, 118);");
        }
        else {
            ui->T_1INV4->setNum(UBP_1INV4_T);
            ui->T_1INV4->setStyleSheet("background-color: rgb(255,0, 0)");
        }

        UBP_2INV1_T = arr_tab.mid(836,2).toUInt(&ok,16);
        if(UBP_2INV1_T >-20 && UBP_2INV1_T < 50)
        {
            ui->T_2INV1->setNum(UBP_2INV1_T);
            ui->T_2INV1->setStyleSheet("background-color: rgb(118, 118, 118);");
        }
        else {
            ui->T_2INV1->setNum(UBP_2INV1_T);
            ui->T_2INV1->setStyleSheet("background-color: rgb(255,0, 0)");
        }

        UBP_2INV2_T = arr_tab.mid(840,2).toUInt(&ok,16);
        if(UBP_2INV2_T >-20 && UBP_2INV2_T < 50)
        {
            ui->T_2INV2->setNum(UBP_2INV2_T);
            ui->T_2INV2->setStyleSheet("background-color: rgb(118, 118, 118);");
        }
        else {
            ui->T_2INV2->setNum(UBP_2INV2_T);
            ui->T_2INV2->setStyleSheet("background-color: rgb(255,0, 0)");
        }

        UBP_2INV3_T = arr_tab.mid(844,2).toUInt(&ok,16);
        if(UBP_2INV3_T >-20 && UBP_2INV3_T < 50)
        {
            ui->T_2INV3->setNum(UBP_2INV3_T);
            ui->T_2INV3->setStyleSheet("background-color: rgb(118, 118, 118);");
        }
        else {
            ui->T_2INV3->setNum(UBP_2INV3_T);
            ui->T_2INV3->setStyleSheet("background-color: rgb(255,0, 0)");
        }

        UBP_2INV4_T = arr_tab.mid(848,2).toUInt(&ok,16);
        if(UBP_2INV4_T >-20 && UBP_2INV4_T < 50)
        {
            ui->T_2INV4->setNum(UBP_2INV4_T);
            ui->T_2INV4->setStyleSheet("background-color: rgb(118, 118, 118);");
        }
        else {
            ui->T_2INV4->setNum(UBP_2INV4_T);
            ui->T_2INV4->setStyleSheet("background-color: rgb(255,0, 0)");
        }

        UBP_3INV1_T = arr_tab.mid(852,2).toUInt(&ok,16);
        if(UBP_3INV1_T >-20 && UBP_3INV1_T < 50)
        {
            ui->T_3INV1->setNum(UBP_3INV1_T);
            ui->T_3INV1->setStyleSheet("background-color: rgb(118, 118, 118);");
        }
        else {
            ui->T_3INV1->setNum(UBP_3INV1_T);
            ui->T_3INV1->setStyleSheet("background-color: rgb(255,0, 0)");
        }

        UBP_3INV2_T = arr_tab.mid(856,2).toUInt(&ok,16);
        if(UBP_3INV2_T >-20 && UBP_3INV2_T < 50)
        {
            ui->T_3INV2->setNum(UBP_3INV2_T);
            ui->T_3INV2->setStyleSheet("background-color: rgb(118, 118, 118);");
        }
        else {
            ui->T_3INV2->setNum(UBP_3INV2_T);
            ui->T_3INV2->setStyleSheet("background-color: rgb(255,0, 0)");
        }

        UBP_3INV3_T = arr_tab.mid(860,2).toUInt(&ok,16);
        if(UBP_3INV3_T >-20 && UBP_3INV3_T < 50)
        {
            ui->T_3INV3->setNum(UBP_3INV3_T);
            ui->T_3INV3->setStyleSheet("background-color: rgb(118, 118, 118);");
        }
        else {
            ui->T_3INV3->setNum(UBP_3INV3_T);
            ui->T_3INV3->setStyleSheet("background-color: rgb(255,0, 0)");
        }

        UBP_3INV4_T = arr_tab.mid(864,2).toUInt(&ok,16);
        if(UBP_3INV4_T >-20 && UBP_3INV4_T < 50)
        {
            ui->T_3INV4->setNum(UBP_3INV4_T);
            ui->T_3INV4->setStyleSheet("background-color: rgb(118, 118, 118);");
        }
        else {
            ui->T_3INV4->setNum(UBP_3INV4_T);
            ui->T_3INV4->setStyleSheet("background-color: rgb(255,0, 0)");
        }

        // напряжение ПМ
       UBP_PM_U_DC = change_type(arr_tab.mid(920,4).toUInt(&ok,16));
       if(UBP_PM_U_DC/100 > 210 && UBP_PM_U_DC/100 < 280)
       {
           ui->U_PM->setNum(UBP_PM_U_DC/1000);
           ui->U_PM->setStyleSheet("background-color: rgb(118, 118, 118);");
       }

       else {
           ui->U_PM->setNum(UBP_PM_U_DC/1000);
           ui->U_PM->setStyleSheet("background-color: rgb(255,0, 0)");
       }

         // ток ПМ
        UBP_DT1_I = change_type(arr_tab.mid(940,4).toUInt(&ok,16));
        if(UBP_DT1_I > 0 && UBP_DT1_I < 3200)
        {
            ui->I_PM->setNum(UBP_DT1_I/100);
            ui->I_PM->setStyleSheet("background-color: rgb(118, 118, 118);");
        }
        else if(UBP_DT1_I > 3200 && UBP_DT1_I < 4000) {
            ui->I_PM->setNum(UBP_DT1_I/100);
            ui->I_PM->setStyleSheet("background-color: rgb(255,230, 0)");
        }
        else {
            ui->I_PM->setNum(UBP_DT1_I/100);
            ui->I_PM->setStyleSheet("background-color: rgb(255,0, 0)");
        }


        // Входной ток 7UZ1
        UBP_DT3_I = arr_tab.mid(948,2).toUInt(&ok,16);
        if(UBP_DT3_I > 0  && UBP_DT3_I < 66)
        {
            ui->I_7UZ1_in->setNum(UBP_DT3_I/100);
            ui->I_7UZ1_in->setStyleSheet("background-color: rgb(118, 118, 118);");
        }
        else {
            ui->I_7UZ1_in->setNum(UBP_DT3_I/100);
            ui->I_7UZ1_in->setStyleSheet("background-color: rgb(255,0, 0)");
        }

        UBP_DT4_I = arr_tab.mid(952,2).toUInt(&ok,16);
        if(UBP_DT4_I > 0  && UBP_DT4_I < 66)
        {
            ui->I_7UZ2_in->setNum(UBP_DT4_I/100);
            ui->I_7UZ2_in->setStyleSheet("background-color: rgb(118, 118, 118);");
        }
        else {
            ui->I_7UZ2_in->setNum(UBP_DT4_I/100);
            ui->I_7UZ2_in->setStyleSheet("background-color: rgb(255,0, 0)");
        }


            // Rectifier
          UBP_4UZ1_U_DC = arr_tab.mid(76,2).toUInt(&ok,16);

          if(UBP_4UZ1_U_DC> 178.5 && UBP_4UZ1_U_DC < 297){
              ui->U_4UZ1->setNum(UBP_4UZ1_U_DC);
              ui->U_4UZ1->setStyleSheet("background-color: rgb(118, 118, 118);");
          }
          else {
              ui->U_4UZ1->setNum(UBP_4UZ1_U_DC);
              ui->U_4UZ1->setStyleSheet("background-color: rgb(255,0, 0)");
          }

          UBP_4UZ2_U_DC = arr_tab.mid(80,2).toUInt(&ok,16);

          if(UBP_4UZ2_U_DC> 178.5 && UBP_4UZ2_U_DC < 297){
              ui->U_4UZ2->setNum(UBP_4UZ2_U_DC);
              ui->U_4UZ2->setStyleSheet("background-color: rgb(118, 118, 118);");
          }
          else {
              ui->U_4UZ2->setNum(UBP_4UZ2_U_DC);
              ui->U_4UZ2->setStyleSheet("background-color: rgb(255,0, 0)");
          }

          UBP_4UZ3_U_DC = arr_tab.mid(84,2).toUInt(&ok,16);
          if(UBP_4UZ3_U_DC> 178.5 && UBP_4UZ3_U_DC < 297){
              ui->U_4UZ3->setNum(UBP_4UZ3_U_DC);
              ui->U_4UZ3->setStyleSheet("background-color: rgb(118, 118, 118);");
          }
          else {
              ui->U_4UZ3->setNum(UBP_4UZ3_U_DC);
              ui->U_4UZ3->setStyleSheet("background-color: rgb(255,0, 0)");
          }

          UBP_4UZ4_U_DC = arr_tab.mid(88,2).toUInt(&ok,16);
          if(UBP_4UZ4_U_DC> 178.5 && UBP_4UZ4_U_DC < 297){
              ui->U_4UZ4->setNum(UBP_4UZ4_U_DC);
              ui->U_4UZ4->setStyleSheet("background-color: rgb(118, 118, 118);");
          }
          else {
              ui->U_4UZ4->setNum(UBP_4UZ4_U_DC);
              ui->U_4UZ4->setStyleSheet("background-color: rgb(255,0, 0)");
          }

           UBP_4UZ1_I_DC = arr_tab.mid(128,2).toUInt(&ok,16);
           ui->I_4UZ1->setNum(UBP_4UZ1_I_DC / 10);


           UBP_4UZ2_I_DC = arr_tab.mid(132,2).toUInt(&ok,16);
           ui->I_4UZ2->setNum(UBP_4UZ2_I_DC / 10);

           UBP_4UZ3_I_DC = arr_tab.mid(136,2).toUInt(&ok,16);
           ui->I_4UZ3->setNum(UBP_4UZ3_I_DC / 10);

           UBP_4UZ4_I_DC = arr_tab.mid(140,2).toUInt(&ok,16);
           ui->I_4UZ4->setNum(UBP_4UZ4_I_DC / 10);

           UBP_4UZ1_T_DC = arr_tab.mid(180,2).toUInt(&ok,16);
           ui->T_4UZ1->setNum(UBP_4UZ1_T_DC);


           UBP_4UZ2_T_DC = arr_tab.mid(184,2).toUInt(&ok,16);
           ui->T_4UZ2->setNum(UBP_4UZ2_T_DC);

           UBP_4UZ3_T_DC = arr_tab.mid(188,2).toUInt(&ok,16);
           ui->T_4UZ3->setNum(UBP_4UZ3_T_DC);

           UBP_4UZ4_T_DC = arr_tab.mid(192,2).toUInt(&ok,16);
           ui->T_4UZ4->setNum(UBP_4UZ4_T_DC);

           // напряжение АКБ1
          UBP_Bat1_U_DC = change_type(arr_tab.mid(232,4).toUInt(&ok,16));
          if(UBP_Bat1_U_DC/100 > 189 && UBP_Bat1_U_DC/100 < 251)
          {
              ui->U_AKB1->setNum(UBP_Bat1_U_DC/100);
              ui->U_AKB1->setStyleSheet("background-color: rgb(118, 118, 118);");
          }

          else {
              ui->U_AKB1->setNum(UBP_Bat1_U_DC/100);
              ui->U_AKB1->setStyleSheet("background-color: rgb(255,0, 0)");
          }

          // напряжение АКБ2
         UBP_Bat2_U_DC = change_type(arr_tab.mid(236,4).toUInt(&ok,16));
         if(UBP_Bat2_U_DC/100 > 189 && UBP_Bat2_U_DC/100 < 251)
         {
             ui->U_AKB2->setNum(UBP_Bat2_U_DC/100);
             ui->U_AKB2->setStyleSheet("background-color: rgb(118, 118, 118);");
         }

         else {
             ui->U_AKB2->setNum(UBP_Bat2_U_DC/100);
             ui->U_AKB2->setStyleSheet("background-color: rgb(255,0, 0)");
         }

         // ток АКБ1
        UBP_Bat1_I_DC = arr_tab.mid(244,2).toUInt(&ok,16);

            ui->I_AKB1->setNum(UBP_Bat1_I_DC/10);
            ui->I_AKB1->setStyleSheet("background-color: rgb(118, 118, 118);");

        // ток АКБ1
       UBP_Bat2_I_DC = arr_tab.mid(248,2).toUInt(&ok,16);

           ui->I_AKB2->setNum(UBP_Bat2_I_DC/10);
           ui->I_AKB2->setStyleSheet("background-color: rgb(118, 118, 118);");

        // температура АКБ1
       UBP_Bat1_T_DC = arr_tab.mid(256,2).toUInt(&ok,16);
       if(UBP_Bat1_T_DC > 1 && UBP_Bat1_T_DC < 30)
       {
           ui->T_AKB1->setNum(UBP_Bat1_T_DC);
           ui->T_AKB1->setStyleSheet("background-color: rgb(118, 118, 118);");
       }

       else {
           ui->T_AKB1->setNum(UBP_Bat1_T_DC);
           ui->T_AKB1->setStyleSheet("background-color: rgb(255,0, 0)");
       }

       // температура АКБ2
      UBP_Bat2_T_DC = arr_tab.mid(260,2).toUInt(&ok,16);
      if(UBP_Bat2_T_DC > 1 && UBP_Bat2_T_DC < 30)
      {
          ui->T_AKB2->setNum(UBP_Bat2_T_DC);
          ui->T_AKB2->setStyleSheet("background-color: rgb(118, 118, 118);");
      }

      else {
          ui->T_AKB2->setNum(UBP_Bat2_T_DC);
          ui->T_AKB2->setStyleSheet("background-color: rgb(255,0, 0)");
      }
      update();
}
Tables::~Tables()
{
    delete ui;
}
