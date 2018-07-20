#include <bits/stdc++.h>

using namespace::std;

vector<int> V(3);

int main( void ){
    
    int a, b, c, n;
    bool solucion;

    cin >> n;
    while(n--)
    {
        solucion = false;
        cin >> a >> b >> c;
        
        if(b != 0)
        {
            for(int i = 1; i*i <= b; i++)
                if(b%i == 0)
                {
                    int x = b/i;
                    for(int j = 1; j <= x; j++)
                        if(x%j == 0)
                        {
                            int y = x/j;
                            if(i*i + j*j + y*y == c && i != j && i != y && y != j)
                            {
                                if(i + j + y == a)
                                    solucion = true, V[0] = i, V[1] = j, V[2] = y;
                                if(y -i - j == a)
                                    solucion = true, V[0] = -i, V[1] = -j, V[2] = y;
                                if(j + -i - y == a)
                                    solucion = true, V[0] = -i, V[1] = j, V[2] = -y;
                                if(i - j - y == a)
                                    solucion = true, V[0] = i, V[1] = -j, V[2] - y;                         
                            }
                        }    
                }
        }
        else
        {
            V[0] = 0;
            if(a != 0)
            {
                for(int i = 1; i <= a; i++)
                {
                    if((i*i + (a-i)*(a-i) == c) && i != 0 && (a-i != 0) && (a-i != i))
                    {
                        solucion = true;
                        V[1] = i, V[2] = a - i;
                    }
                    if((i*i + (a+i)*(a+i)) == c && i != 0 && (a+i) != 0 && (a+i) != i) 
                    {
                        solucion = true;
                        V[1] = min(-a-i, -i), V[2] = min(a + i, i);
                    }
                }
            }
            else
            {
                for(int i = 1; 2*i*i <= c; i++)
                    if(2*i*i == c && i != 0)
                    {
                        solucion = true;
                        V[1] = -i, V[2] = i;
                    }
            }
        }
    
        sort(V.begin(), V.end());
        
        if(solucion)
            cout << V[0] << " " << V[1] << " " << V[2] << endl;
        else
            cout << "No solution." << endl;
    }


    return 0;
}
