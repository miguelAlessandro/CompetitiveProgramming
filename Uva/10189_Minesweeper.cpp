#include <bits/stdc++.h>
#define N 105

using namespace::std;

int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1},
    dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};

vector<string> V;
int M[N][N];
string A;
int n, m, t;


int main( void )
{
    while(cin >> n >> m && m + n != 0)
    {
        if(t != 0) cout << endl;

        V.resize(n);
        for(int i = 0; i < n; i++)
            cin >> V[i]; 

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(V[i][j] == '*')
                    for(int k = 0; k < 8; k++)
                    {
                        int a = i + dy[k],
                            b = j + dx[k];
                        if(a >= 0 && a < n && b >= 0 && b < m && V[a][b] != '*')
                            M[a][b]++;
                    }   
        t++;
        cout << "Field #" << t << ":" << endl; 
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
                if(V[i][j] != '*')
                    cout << M[i][j];
                else
                    cout << '*';
            cout << endl;
        }
    
        memset(M, 0, sizeof M);
    }
    return 0;
}



