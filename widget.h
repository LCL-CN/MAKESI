#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include"scwid.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
private slots:

    void on_pushButton_4_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::Widget *ui;
    SCWid *scw;
signals:

};
#endif // WIDGET_H
