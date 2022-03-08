/********************************************************************************
** Form generated from reading UI file 'shcema.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHCEMA_H
#define UI_SHCEMA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Shcema
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QGraphicsView *graphicsView;

    void setupUi(QWidget *Shcema)
    {
        if (Shcema->objectName().isEmpty())
            Shcema->setObjectName(QString::fromUtf8("Shcema"));
        Shcema->resize(1124, 576);
        Shcema->setStyleSheet(QString::fromUtf8(""));
        gridLayout = new QGridLayout(Shcema);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(Shcema);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(10);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        graphicsView = new QGraphicsView(Shcema);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));

        gridLayout->addWidget(graphicsView, 1, 0, 1, 1);


        retranslateUi(Shcema);

        QMetaObject::connectSlotsByName(Shcema);
    } // setupUi

    void retranslateUi(QWidget *Shcema)
    {
        label->setText(QCoreApplication::translate("Shcema", "<html><head/><body><p><span style=\" color:#ffffff;\">TextLabel</span></p></body></html>", nullptr));
        (void)Shcema;
    } // retranslateUi

};

namespace Ui {
    class Shcema: public Ui_Shcema {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHCEMA_H
