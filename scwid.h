#ifndef SCWID_H
#define SCWID_H

#include <QWidget>
#include "singlechoice.h"
#include<QSoundEffect>
#include<QCloseEvent>
namespace Ui {
class SCWid;
}

class SCWid : public QWidget
{
    Q_OBJECT

public:
    explicit SCWid(QWidget *parent = nullptr);
    ~SCWid();
    void Read(SingleChoice*a[]);//读取题目信息
    void closeEvent(QCloseEvent*event);
private slots:
    void on_pushButton_clicked();//下一题

    void on_pushButton_3_clicked();//查看答案

    void on_pushButton_2_clicked();//上一题
private:
    Ui::SCWid *ui;
    SingleChoice * SC[100];
    static int num;//当前题数
    QSoundEffect *player;//音效播放
signals:
    void wrong();//单选错误信号
    void right();//单选错误信号
};

#endif // SCWID_H
