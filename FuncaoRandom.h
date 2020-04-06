#ifndef FUNCAORANDOM_H
#define FUNCAORANDOM_H
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

using namespace std;



int tempo(){
    struct timespec tempo;



    clock_gettime(CLOCK_MONOTONIC, &tempo);

    return tempo.tv_nsec;
}


int sorteio(int maximo,int minimo=0){
    int i;

    srand(tempo());

    i=rand()%maximo+minimo;


    return i;
}





#endif // FUNCAORANDOM_H

