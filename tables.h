#ifndef TABLES_H
#define TABLES_H

#include <QWidget>
#include<QTableWidgetItem>
#include<QTime>
#include<QTimer>
#include<QtEndian>

namespace Ui {
class Tables;
}
//static int cou = 0;
static QByteArray arr_tab;
class Tables : public QWidget
{
    Q_OBJECT

public:
    explicit Tables(QWidget *parent = nullptr);

    ~Tables();
public slots:
    void slotReadArr(QByteArray);
private:
     void paintEvent(QPaintEvent *event);
    int change_type(quint16);
    Ui::Tables *ui;
    QTableWidgetItem *item;
    QDateTime dt;
    QDateTime dt_end;


    const char* str_INV_U_AC1 = "60000f0000000100";
    float UBP_1INV1_U_AC1 = 0;
    float UBP_1INV2_U_AC1 = 0;
    float UBP_1INV3_U_AC1 = 0;
    float UBP_1INV4_U_AC1 = 0;
    float UBP_2INV1_U_AC1 = 0;
    float UBP_2INV2_U_AC1 = 0;
    float UBP_2INV3_U_AC1 = 0;
    float UBP_2INV4_U_AC1 = 0;
    float UBP_3INV1_U_AC1 = 0;
    float UBP_3INV2_U_AC1 = 0;
    float UBP_3INV3_U_AC1 = 0;
    float UBP_3INV4_U_AC1 = 0;

    float UBP_1INV1_U_DC = 0;
    float UBP_1INV2_U_DC = 0;
    float UBP_1INV3_U_DC = 0;
    float UBP_1INV4_U_DC = 0;
    float UBP_2INV1_U_DC = 0;
    float UBP_2INV2_U_DC = 0;
    float UBP_2INV3_U_DC = 0;
    float UBP_2INV4_U_DC = 0;
    float UBP_3INV1_U_DC = 0;
    float UBP_3INV2_U_DC = 0;
    float UBP_3INV3_U_DC = 0;
    float UBP_3INV4_U_DC = 0;

    float UBP_1INV1_U_AC2 = 0;
    float UBP_1INV2_U_AC2 = 0;
    float UBP_1INV3_U_AC2 = 0;
    float UBP_1INV4_U_AC2 = 0;
    float UBP_2INV1_U_AC2 = 0;
    float UBP_2INV2_U_AC2 = 0;
    float UBP_2INV3_U_AC2 = 0;
    float UBP_2INV4_U_AC2 = 0;
    float UBP_3INV1_U_AC2 = 0;
    float UBP_3INV2_U_AC2 = 0;
    float UBP_3INV3_U_AC2 = 0;
    float UBP_3INV4_U_AC2 = 0;

    int UBP_1INV1_T = 0;
    int UBP_1INV2_T = 0;
    int UBP_1INV3_T = 0;
    int UBP_1INV4_T = 0;
    int UBP_2INV1_T = 0;
    int UBP_2INV2_T = 0;
    int UBP_2INV3_T = 0;
    int UBP_2INV4_T = 0;
    int UBP_3INV1_T = 0;
    int UBP_3INV2_T = 0;
    int UBP_3INV3_T = 0;
    int UBP_3INV4_T = 0;

    float UBP_PM_U_DC = 0;

    float UBP_DT1_I = 0;
    float UBP_DT3_I = 0;
    float UBP_DT4_I = 0;


    int UBP_4UZ1_U_DC = 0;
    int UBP_4UZ2_U_DC = 0;
    int UBP_4UZ3_U_DC = 0;
    int UBP_4UZ4_U_DC = 0;

    float UBP_4UZ1_I_DC = 0;
    float UBP_4UZ2_I_DC = 0;
    float UBP_4UZ3_I_DC = 0;
    float UBP_4UZ4_I_DC = 0;

    int UBP_4UZ1_T_DC = 0;
    int UBP_4UZ2_T_DC = 0;
    int UBP_4UZ3_T_DC = 0;
    int UBP_4UZ4_T_DC = 0;

    float UBP_Bat1_U_DC = 0;
    float UBP_Bat2_U_DC = 0;
    float UBP_Bat1_I_DC = 0;
    float UBP_Bat2_I_DC = 0;
    int UBP_Bat1_T_DC = 0;
    int UBP_Bat2_T_DC = 0;

};

#endif // TABLES_H
