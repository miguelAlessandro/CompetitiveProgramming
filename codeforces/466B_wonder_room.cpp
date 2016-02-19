#include <iostream>
#include <climits>
using namespace::std;

unsigned long long n, a, b;


int main( void ){

    cin >> n >> a >> b;

    unsigned long long c = min(a, b), d, cr = LLONG_MAX, dr = 1;

    if(a*b >= 6*n)
        cout << a*b << "\n" << a << " " << b << endl;
    else
    {
        n *= 6;
        while(c*c <= n)
        {   
            d = (n + c - 1)/c;    

            if(d >= max(a, b) && cr*dr > c*d) 
                cr = c, dr = d;
            c++;
        }
        cout << cr*dr << endl;
        if(a > b)
            cout  << dr << " " << cr << endl;
        else
            cout <<  cr << " " << dr << endl;
    }

    return 0;
}
