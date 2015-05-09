#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;

void rutafinal(int matr[][], int in, int out, int mintemp, int *minm){
    if(matr[in][out]!=-1){
        mintemp+=matr[in][out];
        if(matr[in][out]<minm;){
            minm=matr[in][out];
        }
    }
}



void rutaintermedia(int matr[][], int in, int out, int mintemp, int *minm){
    for(int i; i< (int)sqrt(sizeof.matr[][]/sizeof.matr[0][0]); i++){
        if(r===2){
            rutafinal(matr[][], in, out, *mintemp, *minm);
        }else{
            if(matr[i][out]!=-1){
                for(int h, h<(sizeof.matr[][]/sizeof.matr[0][0]); h++){
                    if(out==recorrido[h]){
                        goto skip;
                    }
                }
                mintemp+=matr[i][out];
                rutaintermedia(matr[][], i, out, mintemp, minm);
                }
        }
        skip:{}

    }
}

int main(){
    int h=8;
    int recorrido[sqrt(sizeof.matr[][]/sizeof.matr[0][0])];
    for (int f; f<(sizeof.matr[][]/sizeof.matr[0][0]); f++){
        recorrido[i]=-1;
        }
    rutafinal(33);
    return 0;
}
