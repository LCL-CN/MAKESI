#ifndef MISTAKE_H
#define MISTAKE_H

#include <QObject>

class Mistake : public QObject
{
    Q_OBJECT
public:
    explicit Mistake(QObject *parent = nullptr);
    void append(int n);
    int getN(int n);
    int num;

signals:
private:
    int mis[100];
    int len;

};

#endif // MISTAKE_H
