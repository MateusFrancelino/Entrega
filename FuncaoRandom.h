#ifndef FUNCAORANDOM_H
#define FUNCAORANDOM_H
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

using namespace std;



float tempo(){
    struct timespec tempo;
    clock_gettime(CLOCK_REALTIME, &tempo);
    cout<<tempo.tv_sec<<endl;
    return tempo.tv_nsec;
}


int sorteio(int maximo,int minimo=0){
    int i;
    srand(tempo());
    i=rand()%maximo+minimo;
    return i;
}





#endif // FUNCAORANDOM_H

