/********************************************************************************
** Form generated from reading UI file 'scwid.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCWID_H
#define UI_SCWID_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SCWid
{
public:
    QPushButton *pushButton_3;
    QTextEdit *textEdit;
    QPushButton *pushButton_2;
    QRadioButton *radioButton_4;
    QPushButton *pushButton;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton;
    QRadioButton *radioButton_3;
    QPushButton *pushButton_4;
    QButtonGroup *buttonGroup;

    void setupUi(QWidget *SCWid)
    {
        if (SCWid->objectName().isEmpty())
            SCWid->setObjectName(QString::fromUtf8("SCWid"));
        SCWid->resize(1000, 600);
        pushButton_3 = new QPushButton(SCWid);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(310, 511, 80, 21));
        textEdit = new QTextEdit(SCWid);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(50, 40, 861, 131));
        textEdit->setMouseTracking(false);
        textEdit->setReadOnly(true);
        textEdit->setAcceptRichText(false);
        textEdit->setTextInteractionFlags(Qt::NoTextInteraction);
        pushButton_2 = new QPushButton(SCWid);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(51, 511, 80, 21));
        radioButton_4 = new QRadioButton(SCWid);
        buttonGroup = new QButtonGroup(SCWid);
        buttonGroup->setObjectName(QString::fromUtf8("buttonGroup"));
        buttonGroup->addButton(radioButton_4);
        radioButton_4->setObjectName(QString::fromUtf8("radioButton_4"));
        radioButton_4->setGeometry(QRect(52, 413, 88, 20));
        pushButton = new QPushButton(SCWid);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(570, 511, 80, 21));
        radioButton_2 = new QRadioButton(SCWid);
        buttonGroup->addButton(radioButton_2);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setGeometry(QRect(52, 307, 88, 20));
        radioButton = new QRadioButton(SCWid);
        buttonGroup->addButton(radioButton);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(52, 254, 88, 20));
        radioButton_3 = new QRadioButton(SCWid);
        buttonGroup->addButton(radioButton_3);
        radioButton_3->setObjectName(QString::fromUtf8("radioButton_3"));
        radioButton_3->setGeometry(QRect(52, 360, 88, 20));
        pushButton_4 = new QPushButton(SCWid);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(830, 511, 80, 21));

        retranslateUi(SCWid);

        QMetaObject::connectSlotsByName(SCWid);
    } // setupUi

    void retranslateUi(QWidget *SCWid)
    {
        SCWid->setWindowTitle(QCoreApplication::translate("SCWid", "Form", nullptr));
        pushButton_3->setText(QCoreApplication::translate("SCWid", "\346\237\245\347\234\213\347\255\224\346\241\210", nullptr));
        pushButton_2->setText(QCoreApplication::translate("SCWid", "\344\270\212\344\270\200\351\242\230", nullptr));
        radioButton_4->setText(QCoreApplication::translate("SCWid", "RadioButton", nullptr));
        pushButton->setText(QCoreApplication::translate("SCWid", "\344\270\213\344\270\200\351\242\230", nullptr));
        radioButton_2->setText(QCoreApplication::translate("SCWid", "RadioButton", nullptr));
        radioButton->setText(QCoreApplication::translate("SCWid", "RadioButton", nullptr));
        radioButton_3->setText(QCoreApplication::translate("SCWid", "RadioButton", nullptr));
        pushButton_4->setText(QCoreApplication::translate("SCWid", "\350\277\224\345\233\236\350\217\234\345\215\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SCWid: public Ui_SCWid {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCWID_H
