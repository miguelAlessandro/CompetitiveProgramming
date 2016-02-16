#include <iostream>

using namespace::std;

int a, b, c;

int main( void )
{
    cin >> a >> b >> c;   
    cout << max(a+b+c, max(a + b*c, max(a*b*c, max(a*b + c, max((a+b)*c, a*(b+c)))))) << endl;

    return 0;
}
