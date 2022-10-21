#include "disorder.h"
#include<QTime>
#include<QRandomGenerator>
Disorder::Disorder(QObject *parent)
    : QObject{parent}
{
    len=0;
    num=0;
    for(int i=0;i<100;++i){
        diso[i]=0;
    }
}
void Disorder::setl(int n){
    len=n;
    for(int i=0;i<len;++i){
        diso[i]=i;
    }
    num=len;
}
void Disorder::remove(int n){
    for(int i=n;i<num-1;++i){
        diso[i]=diso[i+1];
    }
    num--;
}
int Disorder::random(){
    int s=QRandomGenerator::global()->bounded(num);
    int ret=diso[s];
    remove(s);
    return ret;
}
