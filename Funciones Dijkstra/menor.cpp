#include <iostream>
#include <math.h>
using namespace std;

void rutafinal(int siz, int *matr, int in, int out, int mintemp, int *maxm, int *recMin, int rec[]){ //Este m�todo se utiliza para evaluar los recorridos de 1 tramo, o el �ltimo tramo del recorrido

    if( *((matr+(siz*in))+out) !=-1){ //En caso de que haya conexi�n
        int mein=mintemp;
        mein+= *((matr+siz*in)+out);//Se suma el costo del tramo al del recorrido final

        if(mein>*maxm){ //Si el costo es menor al de los otro tramos evaluados, este ser� el nuevo menor

            *maxm=mein;

        }
    }
}


void rutaintermedia(int siz, int *matr, int in, int out, int mintemp, int *maxm, int rec[], int r, int *recMin){
    //cout << *(matr+1) << endl;
    for(int i=0; i< siz; i++){
      if(rec[i]==1){  //Para evaluar cada una de las filas de la columna de destino
        if(r==2){

            rutafinal(siz, matr, in, out, mintemp, maxm, recMin, rec);

        }else{
            int recorr[siz]; //inicializa una matriz vac�a que almacenar� los nodos visitados
            for (int f=0; f<siz; f++){
                recorr[f]=rec[f]; //-1 significa que no est� visitado
            }
            //cout << "wutt" << endl;
            if(*((matr+siz*i)+out)!=-1 && i!=in){

                /*cout<<"subr:";
                cout << r << endl;
                cout<<"I:";
                cout << i << endl;*/


                mintemp+=*((matr+siz*i)+out);
                recorr[out]=1;//marca el nodo para que no vuelva a ser visitado
                /*cout<< "rec:";
                cout << recorr[0];
                cout << recorr[1];
                cout << recorr[2];
                cout << recorr[3]<<endl;
                cout << "suma:";
                cout << mintemp<<endl;*/

                rutaintermedia(siz, matr, in, i, mintemp, maxm, recorr, r-1, recMin); //Se va al siguiente posible nodo del recorrido, se disminuye r en 1 para poder llegar a "recorridofinal" a su debido tiempo
                mintemp-=*((matr+siz*i)+out);
            }

        }


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
    int recorrido[siz]; //inicializa una matriz vac�a que almacenar� los nodos visitados
    int recorrMin[siz];
    for (int f=0; f<siz; f++){
        recorrido[f]=-1; //-1 significa que no est� visitado
        recorrMin[f]=-1;
    }

    int *recMin= recorrMin;

    recorrido[io[0]]=1;


    int maxx=0;


    int *maxm= &maxx;

    for(int c=siz; c>1; c--){
        //cout<<"r:";
        //cout<<c<<endl;
        if(c==2){
            rutafinal(siz, (int *)matr, io[0], io[1], 0, maxm, recorr);
        }else{
            rutaintermedia(siz, (int *)matr, io[0], io[1], 0, maxm, recorrido, c, recMin);
        }
    }
    cout << "Costo m�ximo para llegar al nodo (sin repetir nodos):";
    cout << maxx << endl;

    return 0;
}
