#include <iostream>

using namespace::std;

int h;
long long n;

long long busqueda(int, long long);
long long busqueda2(int, long long);

long long busqueda(int h, long long n){
    
    long long k = (1LL << h);
    if(h < 1) return 0;
    if(n > k/2)
        return k + busqueda(h-1, n - k/2);
    else
        return 1 + busqueda2(h-1, n);
}

long long busqueda2(int h, long long n){
    
    long long k = (1LL << h);
    
    if(h < 1) return 0;
    
    if(n > k/2)
        return 1 + busqueda(h-1, n - k/2);
    else
        return k + busqueda2(h-1, n);
}

int main( void ){

    cin >> h >> n;
    cout << busqueda(h, n) << endl;
    
    return 0;
}
