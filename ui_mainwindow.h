/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QPushButton *play;
    QComboBox *comboBox;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *Button_prev;
    QPushButton *Button_next;
    QLabel *label_timer_2;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *OpenFile;
    QPushButton *EnterFileName;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *Tables;
    QPushButton *Schema;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(538, 189);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color:rgb(50, 50, 50)"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setEnabled(true);
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        play = new QPushButton(centralwidget);
        play->setObjectName(QString::fromUtf8("play"));
        QFont font;
        font.setPointSize(10);
        play->setFont(font);
        play->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        horizontalLayout->addWidget(play);

        comboBox = new QComboBox(centralwidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setMinimumSize(QSize(0, 30));
        comboBox->setFont(font);
        comboBox->setLayoutDirection(Qt::LeftToRight);
        comboBox->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        horizontalLayout->addWidget(comboBox);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        Button_prev = new QPushButton(centralwidget);
        Button_prev->setObjectName(QString::fromUtf8("Button_prev"));
        Button_prev->setFont(font);
        Button_prev->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        horizontalLayout_2->addWidget(Button_prev);

        Button_next = new QPushButton(centralwidget);
        Button_next->setObjectName(QString::fromUtf8("Button_next"));
        Button_next->setFont(font);
        Button_next->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        horizontalLayout_2->addWidget(Button_next);


        verticalLayout_3->addLayout(horizontalLayout_2);


        gridLayout->addLayout(verticalLayout_3, 1, 0, 1, 1);

        label_timer_2 = new QLabel(centralwidget);
        label_timer_2->setObjectName(QString::fromUtf8("label_timer_2"));
        label_timer_2->setMinimumSize(QSize(200, 0));
        QFont font1;
        font1.setFamily(QString::fromUtf8("MS Shell Dlg 2"));
        font1.setPointSize(14);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(9);
        font1.setStyleStrategy(QFont::PreferDefault);
        label_timer_2->setFont(font1);
        label_timer_2->setLayoutDirection(Qt::LeftToRight);
        label_timer_2->setStyleSheet(QString::fromUtf8("font: 75 14pt \"MS Shell Dlg 2\";\n"
"color: rgb(255, 255, 255);\n"
""));

        gridLayout->addWidget(label_timer_2, 1, 1, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        OpenFile = new QPushButton(centralwidget);
        OpenFile->setObjectName(QString::fromUtf8("OpenFile"));
        OpenFile->setMinimumSize(QSize(0, 0));
        OpenFile->setSizeIncrement(QSize(0, 0));
        OpenFile->setFont(font);
        OpenFile->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        horizontalLayout_3->addWidget(OpenFile);

        EnterFileName = new QPushButton(centralwidget);
        EnterFileName->setObjectName(QString::fromUtf8("EnterFileName"));
        EnterFileName->setFont(font);
        EnterFileName->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        horizontalLayout_3->addWidget(EnterFileName);


        gridLayout->addLayout(horizontalLayout_3, 0, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        Tables = new QPushButton(centralwidget);
        Tables->setObjectName(QString::fromUtf8("Tables"));
        Tables->setFont(font);
        Tables->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"\n"
"\n"
""));

        horizontalLayout_4->addWidget(Tables);

        Schema = new QPushButton(centralwidget);
        Schema->setObjectName(QString::fromUtf8("Schema"));
        Schema->setFont(font);
        Schema->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
""));

        horizontalLayout_4->addWidget(Schema);


        gridLayout->addLayout(horizontalLayout_4, 0, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\320\220\321\200\321\205\320\270\320\262", nullptr));
        play->setText(QApplication::translate("MainWindow", "\320\241\321\202\320\260\321\200\321\202", nullptr));
        comboBox->setItemText(0, QApplication::translate("MainWindow", "X1", nullptr));
        comboBox->setItemText(1, QApplication::translate("MainWindow", "X2", nullptr));
        comboBox->setItemText(2, QApplication::translate("MainWindow", "X4", nullptr));
        comboBox->setItemText(3, QApplication::translate("MainWindow", "X8", nullptr));
        comboBox->setItemText(4, QApplication::translate("MainWindow", "X16", nullptr));

        Button_prev->setText(QApplication::translate("MainWindow", "<<", nullptr));
        Button_next->setText(QApplication::translate("MainWindow", ">>", nullptr));
        label_timer_2->setText(QApplication::translate("MainWindow", "\320\220\321\200\321\205\320\270\320\262\320\275\320\276\320\265 \320\262\321\200\320\265\320\274\321\217", nullptr));
        OpenFile->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214", nullptr));
        EnterFileName->setText(QApplication::translate("MainWindow", "OK", nullptr));
        Tables->setText(QApplication::translate("MainWindow", "\320\242\320\260\320\261\320\273\320\270\321\206\321\213 \320\270\320\267\320\274\320\265\321\200\320\265\320\275\320\270\320\271", nullptr));
        Schema->setText(QApplication::translate("MainWindow", "\320\234\320\275\320\265\320\274\320\276\321\201\321\205\320\265\320\274\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
