#include "mistake.h"

Mistake::Mistake(QObject *parent)
    : QObject{parent}
{
    for(int i=0;i<100;++i){
        mis[i]=0;
    }
    len=0;
    num=0;
}
void Mistake::append(int n){
    mis[len]=n;
    len++;
}
int Mistake::getN(int n){
    if(len==0)
    return -1;
    return mis[n%len];
}
