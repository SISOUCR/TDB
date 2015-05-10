#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;

void rutafinal(int siz, int *matr, int in, int out, int mintemp, int *minm){ //Este m�todo se utiliza para evaluar los recorridos de 1 tramo, o el �ltimo tramo del recorrido
    if( *((matr+siz*in)+out) !=-1){ //En caso de que haya conexi�n
        mintemp+= *((matr+siz*in)+out); //Se suma el costo del tramo al del recorrido final
        if(mintemp<(int)minm){ //Si el costo es menor al de los otro tramos evaluados, este ser� el nuevo menor
            *minm=mintemp;
            cout << "wut" << endl;
        }
    }
}


void rutaintermedia(int siz, int *matr, int in, int out, int mintemp, int *minm, int recorrido[], int r){
    cout << "wat" << endl;
    for(int i=0; i< siz; i++){ //Para evaluar cada una de las filas de la columna de destino
        if(r==2){ //r es el n�mero de nodos del recorrido a evaluar
            cout << "wutr" << endl;
            rutafinal(siz, matr, in, out, mintemp, minm);

        }else{
            cout << "wutt" << endl;
            if(*((matr+siz*i)+out)!=-1&& i!=in){
                for(int h=0; h<siz; h++){ //Eval�a qu� camino ha sido atravesado para no repetir nodos
                    if(out==recorrido[h]){
                        //goto skip;
                    }
                }
                mintemp+=*((matr+siz*i)+out);
                recorrido[siz-r]=out; //marca el nodo para que no vuelva a ser visitado
                rutaintermedia(siz, matr, in, i, mintemp, minm, recorrido, r-1); //Se va al siguiente posible nodo del recorrido, se disminuye r en 1 para poder llegar a "recorridofinal" a su debido tiempo
            }

        }
        skip:{}

    }
}

int main(){
    int matr[3][3];
    matr[0][0]=-1;
    matr[0][1]=6;
    matr[0][2]=3;
    matr[1][0]=2;
    matr[1][1]=-1;
    matr[1][2]=1;
    matr[2][0]=1;
    matr[2][1]=2;
    matr[2][2]=-1;


    int siz= sqrt((sizeof matr)/(sizeof matr[0][0]));
    int recorrido[siz]; //inicializa una matriz vac�a que almacenar� los nodos visitados
    for (int f; f<siz; f++){
        recorrido[f]=-1; //-1 significa que no est� visitado
        }
    int minn=0;

    int *minm= &minn;
    for(int c=siz-1; c>1; c--){
            cout << c << endl;
        rutaintermedia(siz, (int *)matr[0][0], 0, 1, 0, minm, recorrido, c);
    }
    cout << minn << endl;
    return 0;
}
