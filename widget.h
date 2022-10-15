#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "singlechoice.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void Read(SingleChoice*a[]);
private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();


private:
    Ui::Widget *ui;
    SingleChoice * SC[100];
    static int num;
signals:
    void wrong();
    void right();
};
#endif // WIDGET_H
