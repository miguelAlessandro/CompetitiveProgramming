#include <iostream>

using namespace::std;

int n;
int h[5][5], g[5][5];
int di[4] = {0, -1, 0, 1},
    dj[4] = {1, 0, -1, 0};
int cont, c;
string F;
bool diff = true;

int main( void ){

    cin >> n;
    getline(cin, F);
    
    while(n--){

        getline(cin, F);
        for(int i = 0; i < 3; i++){

            getline(cin, F);
            for(int j = 0; j < 3; j++)
                g[i][j] = F[j] - '0';
        }

        diff = true;
        cont = 0;
        while(diff){
            
            c = 0;
            for(int i = 0; i < 3; i++)
                for(int j = 0; j < 3; j++){

                    h[i][j] = 0;
                    for(int k = 0; k < 4; k++)
                    {
                        int a = i + di[k], b = j + dj[k];
                        if(a >= 0 && b >= 0 && a < 3 && b < 3)
                            h[i][j] += g[a][b];
                    }
                    h[i][j] %= 2;
                    if(g[i][j] == h[i][j])
                        c++;
                }

           if(c == 9)
                diff = false;
           
           cont++;

           for(int i = 0; i < 3; i++)
                for(int j = 0; j < 3; j++)
                    g[i][j] = h[i][j];
        }

        cout << cont - 2 << endl;
    }


    return 0;
}
