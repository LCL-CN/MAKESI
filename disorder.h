#ifndef DISORDER_H
#define DISORDER_H

#include <QObject>


class Disorder : public QObject
{
    Q_OBJECT
public:
    explicit Disorder(QObject *parent = nullptr);
    void setl(int n);
    int random();
    void remove(int n);
signals:
private:
    int len;
    int num;
    int diso[100];

};

#endif // DISORDER_H
