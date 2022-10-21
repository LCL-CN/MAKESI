#include "scwid.h"
#include "ui_scwid.h"
#include<QFile>
#include<QDebug>
#include<QTextCharFormat>
#include<QFont>
using namespace std;


SCWid::SCWid(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SCWid)
{
    ui->setupUi(this);
    len=0;
    num=0;
    mis=new Mistake(this);
    diso=new Disorder(this);

    //设置鼠标移动到文本框样式不变
    ui->textEdit->viewport()->setCursor(Qt::PointingHandCursor);

    //设置文本框字体字号和颜色
    QTextCharFormat fmt1;
    fmt1.setForeground(Qt::blue);
    QFont font1=QFont("宋体",14);
    fmt1.setFont(font1);
    ui->textEdit->setCurrentCharFormat(fmt1);

    //申请题目存储空间
    for(int i=0;i<100;++i){
       SC[i]=new SingleChoice(this);
    }

    //读取题目信息
    Read(SC);

    diso->setl(this->len);

    //设置单选按钮组各按钮ID
    ui->buttonGroup->setId(ui->radioButton,1);
    ui->buttonGroup->setId(ui->radioButton_2,2);
    ui->buttonGroup->setId(ui->radioButton_3,3);
    ui->buttonGroup->setId(ui->radioButton_4,4);

    //初始显示第一题信息
    ui->textEdit->setText(SC[0]->getQ());
    ui->radioButton->setText(SC[0]->getC()[0]);
    ui->radioButton_2->setText(SC[0]->getC()[1]);
    ui->radioButton_3->setText(SC[0]->getC()[2]);
    ui->radioButton_4->setText(SC[0]->getC()[3]);

    //根据单选选择对错触发正确/错误音效信号
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

    //接受正确/错误信号，播放对应音效
    player=new QSoundEffect(this);
    connect(this,&SCWid::wrong,player,[=]{
        this->mis->append(num);
        player->setSource(QUrl::fromLocalFile(":/F"));
        player->setVolume(1);
        player->play();
    });
    connect(this,&SCWid::right,player,[=]{
        player->setSource(QUrl::fromLocalFile(":/T"));
        player->setVolume(1);
        player->play();
    });

}

SCWid::~SCWid()
{
    delete ui;
}

void SCWid::Read(SingleChoice*a[])
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
                len++;
                break;
            }
        }
    }
}


void SCWid::on_pushButton_clicked()
{
    //下一题
    num++;
    if(num>len)num=0;
    //清除选中状态
    ui->buttonGroup->setExclusive(false);
    for(int i=1;i<5;++i){
        ui->buttonGroup->button(i)->setChecked(false);
    }
    ui->buttonGroup->setExclusive(true);

    //读取下一题参数
    ui->textEdit->setText(SC[num]->getQ());
    ui->radioButton->setText(SC[num]->getC()[0]);
    ui->radioButton_2->setText(SC[num]->getC()[1]);
    ui->radioButton_3->setText(SC[num]->getC()[2]);
    ui->radioButton_4->setText(SC[num]->getC()[3]);

    ui->pushButton_3->setText("查看答案");
}




void SCWid::on_pushButton_3_clicked()
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



void SCWid::on_pushButton_2_clicked()
{
    //上一题
    num--;
    if(num<0)num=len;
    //清除选中状态
    ui->buttonGroup->setExclusive(false);
    for(int i=1;i<5;++i){
        ui->buttonGroup->button(i)->setChecked(false);
    }
    ui->buttonGroup->setExclusive(true);

    //读取上一题参数
    ui->textEdit->setText(SC[num]->getQ());
    ui->radioButton->setText(SC[num]->getC()[0]);
    ui->radioButton_2->setText(SC[num]->getC()[1]);
    ui->radioButton_3->setText(SC[num]->getC()[2]);
    ui->radioButton_4->setText(SC[num]->getC()[3]);

    ui->pushButton_3->setText("查看答案");
}

void SCWid::on_pushButton_4_clicked()
{
    emit closed();
    this->close();
}
void SCWid::change(int a){
    if(a==1){
        ui->pushButton_5->hide();
        ui->pushButton_6->hide();
        ui->pushButton_7->hide();
        ui->pushButton->show();
        ui->pushButton_2->show();
        ui->textEdit->setText(SC[num]->getQ());
        ui->radioButton->setText(SC[num]->getC()[0]);
        ui->radioButton_2->setText(SC[num]->getC()[1]);
        ui->radioButton_3->setText(SC[num]->getC()[2]);
        ui->radioButton_4->setText(SC[num]->getC()[3]);
        ui->pushButton_3->setText("查看答案");
    }
    else if(a==0){
        ui->pushButton->hide();
        ui->pushButton_2->hide();
        ui->pushButton_7->hide();
        ui->pushButton_5->show();
        ui->pushButton_6->show();
        on_pushButton_5_clicked();
    }
    else{
        ui->pushButton_5->hide();
        ui->pushButton_6->hide();
        ui->pushButton->hide();
        ui->pushButton_2->hide();
        ui->pushButton_7->show();
        on_pushButton_7_clicked();
    }
}


void SCWid::on_pushButton_6_clicked()
{

}


void SCWid::on_pushButton_5_clicked()
{
    //下一题
    if(this->mis->getN(this->mis->num)==-1){
        ui->textEdit->setText("无错题");
        ui->radioButton->setText("");
        ui->radioButton_2->setText("");
        ui->radioButton_3->setText("");
        ui->radioButton_4->setText("");
        ui->pushButton_3->setText("查看答案");
        return;
    }

    num=this->mis->getN(this->mis->num);

    //清除选中状态
    ui->buttonGroup->setExclusive(false);
    for(int i=1;i<5;++i){
        ui->buttonGroup->button(i)->setChecked(false);
    }
    ui->buttonGroup->setExclusive(true);

    //读取下一题参数
    ui->textEdit->setText(SC[num]->getQ());
    ui->radioButton->setText(SC[num]->getC()[0]);
    ui->radioButton_2->setText(SC[num]->getC()[1]);
    ui->radioButton_3->setText(SC[num]->getC()[2]);
    ui->radioButton_4->setText(SC[num]->getC()[3]);

    ui->pushButton_3->setText("查看答案");

    this->mis->num++;
}
void SCWid::closeEvent(QCloseEvent*event){
    on_pushButton_4_clicked();
}


void SCWid::on_pushButton_7_clicked()
{

    num=this->diso->random();
    //清除选中状态
    ui->buttonGroup->setExclusive(false);
    for(int i=1;i<5;++i){
        ui->buttonGroup->button(i)->setChecked(false);
    }
    ui->buttonGroup->setExclusive(true);

    //读取下一题参数
    ui->textEdit->setText(SC[num]->getQ());
    ui->radioButton->setText(SC[num]->getC()[0]);
    ui->radioButton_2->setText(SC[num]->getC()[1]);
    ui->radioButton_3->setText(SC[num]->getC()[2]);
    ui->radioButton_4->setText(SC[num]->getC()[3]);

    ui->pushButton_3->setText("查看答案");

}

