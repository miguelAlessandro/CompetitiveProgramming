#include <iostream>

using namespace::std;

int a, b;

int main(){

    bool triangulo = false;
    cin >> a >> b;

    int m, n;
    for(int i = 1; i <= b; ++i)
        for(int j = 1; j <= b; ++j)
            if(i*i + j*j == b*b && (i*a)%b == 0 && (j*a)%b == 0 && ((i + (j*a)/b)*(i + (j*a)/b) < a*a + b*b) && (j != (i*a)/b))
            {
                m = i, n = j, triangulo = true;
                goto fin;
            }
    fin:
    if(triangulo)
    {
        cout << "YES" << endl;
        cout << "0 0" << endl;
        cout << m << " " << n << endl;
        cout << (-1*n*a/b) << " " << (m*a/b) << endl;
    }
    else
        cout << "NO" << endl;
    return 0;
}
