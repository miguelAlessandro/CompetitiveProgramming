#include <iostream>
#define N 105

using namespace::std;

int M[N][N], n;
int fila, columna;
int cont, cont2;
int cf, cc;

int main( void ){
    
    while(cin >> n && n != 0){

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
                cin >> M[i][j];

        }

        cc = cf = 0;
        for(int i = 0; i < n; i++)
        {
            cont2 = cont = 0;
            for(int j = 0; j < n; j++){

                cont += M[i][j];
                cont2 += M[j][i];
            
            }
            if(cont & 1){
                fila = i + 1;
                cf++;
            }
            if(cont2 & 1){
                columna = i + 1;
                cc++;
            }
        }
        
        if(cc == 0 && cf == 0)
            cout << "OK" << endl;
        else if(cc == 1 && cf == 1)
            cout << "Change bit (" << fila << "," << columna << ")" << endl;
        else
            cout << "Corrupt" << endl;
    }


    return 0;
}
