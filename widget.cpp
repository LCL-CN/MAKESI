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


    connect(this->scw,&QWidget::windowTitleChanged,this,[=]{
        this->resize(1000,600);
    });

}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_4_clicked()
{
    scw->show();
    this->resize(0,0);
}

