#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;

void rutafinal(int siz, int *matr, int in, int out, int mintemp, int *minm){ //Este método se utiliza para evaluar los recorridos de 1 tramo, o el último tramo del recorrido

    if( *((matr+(siz*in))+out) !=-1){ //En caso de que haya conexión

        mintemp+= *((matr+siz*in)+out);//Se suma el costo del tramo al del recorrido final
        //cout <<mintemp<<endl;
        if(mintemp<*minm){ //Si el costo es menor al de los otro tramos evaluados, este será el nuevo menor

            *minm=mintemp;
            //cout << *minm << endl;
        }
    }
}


void rutaintermedia(int siz, int *matr, int in, int out, int mintemp, int *minm, int rec[], int r){
    //cout << *(matr+1) << endl;
    for(int i=0; i< siz; i++){ //Para evaluar cada una de las filas de la columna de destino
        if(r==2){ //r es el número de nodos del recorrido a evaluar
            //cout << i << endl;
            rutafinal(siz, matr, in, out, mintemp, minm);

        }else{
            int recorr[siz]; //inicializa una matriz vacía que almacenará los nodos visitados
            for (int f=0; f<siz; f++){
                recorr[f]=rec[f]; //-1 significa que no está visitado
            }
            //cout << "wutt" << endl;
            if(*((matr+siz*i)+out)!=-1 && i!=in){
                if(recorr[out]==1){          //Evalúa qué camino ha sido atravesado para no repetir nodos
                    goto skip;
                }

                mintemp+=*((matr+siz*i)+out);
                recorr[out]=1;//marca el nodo para que no vuelva a ser visitado
                cout<< "rec:";
                cout << recorr[0];
                cout << recorr[1];
                cout << recorr[2];
                cout << recorr[3]<<endl;
                cout << "suma:";
                cout << mintemp<<endl;

                rutaintermedia(siz, matr, in, i, mintemp, minm, recorr, r-1); //Se va al siguiente posible nodo del recorrido, se disminuye r en 1 para poder llegar a "recorridofinal" a su debido tiempo
            }

        }
        skip:{
            cout<<"wadup"<<endl;
        }

    }
}

int main(){
    int matr[4][4];
    matr[0][0]=-1;
    matr[0][1]=2;
    matr[0][2]=-1;
    matr[0][3]=-1;
    matr[1][0]=1;
    matr[1][1]=-1;
    matr[1][2]=1;
    matr[1][3]=-1;
    matr[2][0]=-1;
    matr[2][1]=2;
    matr[2][2]=-1;
    matr[2][3]=2;
    matr[3][0]=8;
    matr[3][1]=-1;
    matr[3][2]=1;
    matr[3][3]=-1;

    int io[]={3,0};


    int siz= sqrt((sizeof matr)/(sizeof matr[0][0]));
    cout<<siz<<endl;
    int recorrido[siz]; //inicializa una matriz vacía que almacenará los nodos visitados
    for (int f=0; f<siz; f++){
        recorrido[f]=-1; //-1 significa que no está visitado
    }

    int minn=0;



    for(int i=0; i<siz;i++){ //Se parte del valor mayor del arreglo
        for(int t=0; t<siz; t++){
            if(matr[i][t]>minn){
                minn= matr[i][t];
            }
        }
    }

    int *minm= &minn;

    for(int c=siz; c>1; c--){
    cout<<"r:";
        cout<<c<<endl;

        rutaintermedia(siz, (int *)matr, io[0], io[1], 0, minm, recorrido, c);
    }
    cout << minn << endl;
    cout << recorrido[0]<<endl;
                cout << recorrido[1]<<endl;
                cout << recorrido[2]<<endl;
                cout << recorrido[3]<<endl;
    return 0;
}
