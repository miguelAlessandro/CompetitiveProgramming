#include <bits/stdc++.h>
using namespace::std;
#define N 100010

int n;
int v[N];

int main( void ){

    scanf("%d", &n);

    for(int i = 1; i <= n; i++)
        scanf("%d", &v[i]);
	
    v[n+1] = 1000000001; v[0] = 0;
    bool bandera = true, bandera2 = true;
    int a, b, c, d, ic, ib;
    for(int i = 1; i <= n; i++)
    {
        if(v[i] < v[i+1]);
        else if(bandera2)
        {
            a = v[i-1], b = v[i], c = v[i+1], ib = i;
            for(;i <= n; i++)
                if(v[i] > v[i + 1])
                    c = v[i + 1], ic = i+1;
                else
                    break;
            if(!(a < c && b < v[i+1]))
                bandera = false;
            bandera2 = false;
        }
        else
            bandera = false;       
    }

    if(bandera){
        cout << "yes" << endl;
        if(bandera2 == true)
        	cout << "1 1" << endl;
       	else
        	cout << ib << " "<< ic << endl;
    }
    else
        cout << "no" << endl;
    return 0;
}
