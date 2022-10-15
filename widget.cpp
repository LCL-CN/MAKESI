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
    ui->textEdit->viewport()->setCursor(Qt::PointingHandCursor);
    QTextCharFormat fmt1;
    fmt1.setForeground(Qt::blue);
    QFont font1=QFont("宋体",14);
    fmt1.setFont(font1);
    ui->textEdit->setCurrentCharFormat(fmt1);
    for(int i=0;i<100;++i){
       SC[i]=new SingleChoice(this);
    }

    Read(SC);

    ui->buttonGroup->setId(ui->radioButton,1);
    ui->buttonGroup->setId(ui->radioButton_2,2);
    ui->buttonGroup->setId(ui->radioButton_3,3);
    ui->buttonGroup->setId(ui->radioButton_4,4);

    ui->textEdit->setText(SC[0]->getQ());
    ui->radioButton->setText(SC[0]->getC()[0]);
    ui->radioButton_2->setText(SC[0]->getC()[1]);
    ui->radioButton_3->setText(SC[0]->getC()[2]);
    ui->radioButton_4->setText(SC[0]->getC()[3]);

    for(int i=1;i<5;++i){
        connect(ui->buttonGroup->button(i),&QRadioButton::clicked,this,[=]{
            on_pushButton_3_clicked();
            int a=SC[num]->getA();
            if(i==a)
                emit right();
            else
                emit wrong();
        });
    }

    player=new QSoundEffect(this);
    connect(this,&Widget::wrong,player,[=]{
        player->setSource(QUrl::fromLocalFile(":/F"));
        player->setVolume(1);
        player->play();
    });
    connect(this,&Widget::right,player,[=]{
        player->setSource(QUrl::fromLocalFile(":/T"));
        player->setVolume(1);
        player->play();
    });
}

Widget::~Widget()
{
    delete ui;
}
void Widget::Read(SingleChoice*a[])
{
    QFile file1(":/s");
    file1.open(QIODevice::ReadOnly);
    QString line;
    int lineNum = 0;
    int SC_Num = 0;
    while (!file1.atEnd()) {
        line=file1.readLine();
        if (line != "\r\n") {
             line.chop(2);
            lineNum++;
            switch (lineNum % 6) {
            case 1:
                a[SC_Num]->setQ(line);
                break;
            case 2:
                a[SC_Num]->setC(line, 0);
                break;
            case 3:
                a[SC_Num]->setC(line, 1);
                break;
            case 4:
                a[SC_Num]->setC(line, 2);
                break;
            case 5:
                a[SC_Num]->setC(line, 3);
                break;
            case 0:
                a[SC_Num]->setA(line.toInt());
                SC_Num++;
                break;
            }
        }
    }
}


void Widget::on_pushButton_clicked()
{

    num++;
    ui->buttonGroup->setExclusive(false);
    for(int i=1;i<5;++i){
        ui->buttonGroup->button(i)->setChecked(false);
    }
    ui->buttonGroup->setExclusive(true);

    ui->textEdit->setText(SC[num]->getQ());
    ui->radioButton->setText(SC[num]->getC()[0]);
    ui->radioButton_2->setText(SC[num]->getC()[1]);
    ui->radioButton_3->setText(SC[num]->getC()[2]);
    ui->radioButton_4->setText(SC[num]->getC()[3]);

    ui->pushButton_3->setText("查看答案");
}




void Widget::on_pushButton_3_clicked()
{
   int a=SC[num]->getA();
   QString ans;
   switch(a){
   case 1:
       ans="A";
       break;
   case 2:
       ans="B";
       break;
   case 3:
       ans="C";
       break;
   case 4:
       ans="D";
       break;
   }

   ui->pushButton_3->setText(ans);
}


