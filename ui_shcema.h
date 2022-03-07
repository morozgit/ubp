/********************************************************************************
** Form generated from reading UI file 'shcema.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHCEMA_H
#define UI_SHCEMA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Shcema
{
public:
    QLabel *label;

    void setupUi(QWidget *Shcema)
    {
        if (Shcema->objectName().isEmpty())
            Shcema->setObjectName(QString::fromUtf8("Shcema"));
        Shcema->resize(1124, 576);
        Shcema->setStyleSheet(QString::fromUtf8(""));
        label = new QLabel(Shcema);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(780, 20, 251, 41));
        QFont font;
        font.setPointSize(10);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));

        retranslateUi(Shcema);

        QMetaObject::connectSlotsByName(Shcema);
    } // setupUi

    void retranslateUi(QWidget *Shcema)
    {
        label->setText(QApplication::translate("Shcema", "<html><head/><body><p><span style=\" color:#ffffff;\">TextLabel</span></p></body></html>", nullptr));
        Q_UNUSED(Shcema);
    } // retranslateUi

};

namespace Ui {
    class Shcema: public Ui_Shcema {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHCEMA_H
