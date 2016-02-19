#include <bits/stdc++.h>
#define f(x, y, z) for(int x = y; x < z; x++)

using namespace::std;

int n;
vector <int> V(3);

int prueba(int a, int b, int c)
{
    int m = c/a*a, cont = c/a;
    while(m >= 0)
    {
        if((c-m) >= b && (c - m)%b == 0)
            return cont + (c-m)/b;
        m -= a;
        cont--;
    }
    return -1;
}





int main( void )
{
    cin >> n;
    f(i, 0, 3)
        cin >> V[i];

    sort(V.begin(), V.end());
    
    if(n >= V[0] && n%V[0] == 0)
        cout << n/V[0] << endl;
    else{
        int l = prueba(V[0], V[1], n);
        int m = -1;
        int k = n/V[0]*V[0], cont = n/V[0]; 
        while(k >= 0)
        {
            int t = prueba(V[1], V[2], n - k);
            if(t != -1)
                m = max(m, cont + t);
            cont--;
            k -= V[0];
        }
        cout << max(m, l) << endl;
    }
    
    return 0;
}



