#ifndef SINGLECHOICE_H
#define SINGLECHOICE_H

#include <QObject>
#include <QString>
class SingleChoice : public QObject
{
    Q_OBJECT
public:
    explicit SingleChoice(QObject *parent = nullptr);

        QString getQ();
        void setQ(QString a);
        QString* getC();
        void setC(QString a, int n);
        int getA();
        void setA(int n);
    private:
        QString question;
        QString choice[4];
        int answer;//1、2、3、4——A、B、C、D

signals:

};

#endif // SINGLECHOICE_H
