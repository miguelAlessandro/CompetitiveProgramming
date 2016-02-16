#include <iostream>
#define N 100010

using namespace::std;

string A;
int v[12][N],
    n, k, w;

int main( void ){

    cin >> n >> k >> w;
    getline(cin, A);
    getline(cin, A);

    for(int i = 0; i < k; i++){
        v[i][0] = (A[i] != '0');
        for(int j = 1 ; j < n; j++)
             v[i][j] = v[i][j-1] + (A[j] != ((j%k == i) + '0'));
    }

    while(w--){

        int a, b, cont;

        cin >> a >> b;
        a--; b--;
        cont = 0;
        for(int i = a; i < a + k - 1; i++ )
            cont += (A[i] != '0');
    
        if(b >= a + k - 1){
            cont += (A[a + k - 1] == '0');
            cont += v[(a + k - 1)%k][b] - v[(a + k - 1)%k][a + k - 1];
        }

        cout << cont << endl;
    }

    return 0;
}
