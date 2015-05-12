#include <iostream>
#include <math.h>
using namespace std;

void rutafinal(int siz, int *matr, int in, int out, int mintemp, int *minm){ //Este método se utiliza para evaluar los recorridos de 1 tramo, o el último tramo del recorrido

    if( *((matr+(siz*in))+out) !=-1){ //En caso de que haya conexión
        int mein=mintemp;
        mein+= *((matr+siz*in)+out);//Se suma el costo del tramo al del recorrido final
        /*cout <<mein<<endl;
        cout<<"added:";
        cout <<*((matr+siz*in)+out)  << endl;
        cout<<"in:";
        cout << in  << endl;
        cout<<"out:";
        cout << out  << endl;*/

        if(mein<*minm){ //Si el costo es menor al de los otro tramos evaluados, este será el nuevo menor

            *minm=mein;
            //cout << *minm << endl;
        }
    }
}


void rutaintermedia(int siz, int *matr, int in, int out, int mintemp, int *minm, int rec[], int r){
    //cout << *(matr+1) << endl;
    for(int i=0; i< siz; i++){ //Para evaluar cada una de las filas de la columna de destino
        if(r==2){ //r es el número de nodos del recorrido a evaluar
            /*cout<<"subr:";
            cout << r << endl;
            cout<<"i:";
            cout << i << endl;*/

            if(rec[i]==1){          //Evalúa qué camino ha sido atravesado para no repetir nodos
                    //cout<<"nope"<<endl;
                    goto skip;
                }

            rutafinal(siz, matr, in, out, mintemp, minm);

        }else{
            int recorr[siz]; //inicializa una matriz vacía que almacenará los nodos visitados
            for (int f=0; f<siz; f++){
                recorr[f]=rec[f]; //-1 significa que no está visitado
            }
            //cout << "wutt" << endl;
            if(*((matr+siz*i)+out)!=-1 && i!=in){

                /*cout<<"subr:";
                cout << r << endl;
                cout<<"I:";
                cout << i << endl;*/
                if(recorr[i]==1){          //Evalúa qué camino ha sido atravesado para no repetir nodos
                    //cout<<"nope"<<endl;
                    goto skip;
                }

                mintemp+=*((matr+siz*i)+out);
                recorr[out]=1;//marca el nodo para que no vuelva a ser visitado
                /*cout<< "rec:";
                cout << recorr[0];
                cout << recorr[1];
                cout << recorr[2];
                cout << recorr[3]<<endl;
                cout << "suma:";
                cout << mintemp<<endl;*/

                rutaintermedia(siz, matr, in, i, mintemp, minm, recorr, r-1); //Se va al siguiente posible nodo del recorrido, se disminuye r en 1 para poder llegar a "recorridofinal" a su debido tiempo
                mintemp-=*((matr+siz*i)+out);
            }

        }
        skip:{

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
    int recorrido[siz]; //inicializa una matriz vacía que almacenará los nodos visitados
    for (int f=0; f<siz; f++){
        recorrido[f]=-1; //-1 significa que no está visitado
    }
    recorrido[io[0]]=1;


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
        //cout<<"r:";
        //cout<<c<<endl;
        if(c==2){
            rutafinal(siz, (int *)matr, io[0], io[1], 0, minm);
        }else{
            rutaintermedia(siz, (int *)matr, io[0], io[1], 0, minm, recorrido, c);
        }
    }
    cout << "Costo minimo para llegar al nodo:";
    cout << minn << endl;

    return 0;
}
