/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QPushButton *pushButton_11;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(1000, 600);
        pushButton_4 = new QPushButton(Widget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(310, 173, 80, 21));
        pushButton_5 = new QPushButton(Widget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(520, 173, 80, 21));
        pushButton_6 = new QPushButton(Widget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(310, 261, 80, 21));
        pushButton_7 = new QPushButton(Widget);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setGeometry(QRect(520, 261, 80, 21));
        pushButton_8 = new QPushButton(Widget);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setGeometry(QRect(310, 349, 80, 21));
        pushButton_9 = new QPushButton(Widget);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setGeometry(QRect(520, 349, 80, 21));
        pushButton_10 = new QPushButton(Widget);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));
        pushButton_10->setGeometry(QRect(310, 437, 80, 21));
        pushButton_11 = new QPushButton(Widget);
        pushButton_11->setObjectName(QString::fromUtf8("pushButton_11"));
        pushButton_11->setGeometry(QRect(520, 437, 80, 21));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        pushButton_4->setText(QCoreApplication::translate("Widget", "\345\215\225\351\200\211\357\274\210\351\241\272\345\272\217\357\274\211", nullptr));
        pushButton_5->setText(QCoreApplication::translate("Widget", "\345\215\225\351\200\211\357\274\210\344\271\261\345\272\217\357\274\211", nullptr));
        pushButton_6->setText(QCoreApplication::translate("Widget", "\345\244\232\351\200\211\357\274\210\351\241\272\345\272\217\357\274\211", nullptr));
        pushButton_7->setText(QCoreApplication::translate("Widget", "\345\244\232\351\200\211\357\274\210\344\271\261\345\272\217\357\274\211", nullptr));
        pushButton_8->setText(QCoreApplication::translate("Widget", "\345\210\244\346\226\255\357\274\210\351\241\272\345\272\217\357\274\211", nullptr));
        pushButton_9->setText(QCoreApplication::translate("Widget", "\345\210\244\346\226\255\357\274\210\344\271\261\345\272\217\357\274\211", nullptr));
        pushButton_10->setText(QCoreApplication::translate("Widget", "\351\224\231\351\242\230\351\233\206", nullptr));
        pushButton_11->setText(QCoreApplication::translate("Widget", "\346\224\266\350\227\217\345\244\271", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
