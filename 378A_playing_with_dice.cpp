#include <bits/stdc++.h>

using namespace::std;

int a, b;
int c1, c2, c3;

int main( void ){

    cin >> a >> b;


    for(int i = 1; i <= 6; i++)
        if(fabs(a - i) < fabs(b - i))
            c1++;
        else if(fabs(a - i) > fabs(b - i))
            c2++;
        else
            c3++;

    cout << c1 << " " << c3 << " " << c2 << endl;

    return 0;
}
