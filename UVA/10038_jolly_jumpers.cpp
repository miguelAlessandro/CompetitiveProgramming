#include <bits/stdc++.h>
#define N 3005

using namespace::std;

int V[N],
    n;
bool jolly, B[N];

int main( void ){
 
    while(cin >> n)
    {
        for(int i = 0; i < n; i++) cin >> V[i];

        memset(B, false, sizeof B);
        jolly = true;

        for(int i = 1; i < n; i++) 
        {
            int a = fabs(V[i] - V[i-1]) - 1;
            if(a >= 0 && a < n-1 && !B[a]) B[a] = true;
            else{
                jolly = false;
                break;
            }
        }
        if(jolly)
            cout << "Jolly" << endl;
        else
            cout << "Not jolly" << endl;
    }

    return 0;
}



