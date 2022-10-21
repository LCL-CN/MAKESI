#include "widget.h"
#include "ui_widget.h"
#include<QFile>
#include<QDebug>
#include<QTextCharFormat>
#include<QFont>
using namespace std;
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    scw=new SCWid();
    scw->hide();


    connect(this->scw,&SCWid::closed,this,[=]{
        this->resize(1000,600);
    });

}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_4_clicked()
{
    scw->change(1);
    scw->show();
    this->resize(0,0);
}


void Widget::on_pushButton_10_clicked()
{
    scw->change(0);
    scw->show();
    this->resize(0,0);
}


void Widget::on_pushButton_5_clicked()
{
    scw->change(-1);
    scw->show();
    this->resize(0,0);
}

