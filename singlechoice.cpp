#include "singlechoice.h"

SingleChoice::SingleChoice(QObject *parent)
    : QObject{parent}
{
    question = "";
    answer = 0;
    for(int i=0;i<4;++i){
        choice[i]="";
    }
}

QString SingleChoice::getQ()
{
    return question;
}

void SingleChoice::setQ(QString a)
{
    question = a;
}

QString* SingleChoice::getC()
{
    return choice;
}

void SingleChoice::setC(QString a, int n)
{
    choice[n] = a;
}

int SingleChoice::getA()
{
    return answer;
}

void SingleChoice::setA(int n)
{
    answer = n;
}


