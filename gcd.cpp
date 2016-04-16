#include <iostream>

using namespace::std;

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a%b);
}

int gcd_extended(int a, int b, int& x, int& y){
    if(b == 0){
        x = 1; y = 0;
        return a;
    }   
    int x1, x2;
    int g = gcd_extended(b, a%b, x1, y1);
    x = y1;
    y = x1 - (a/b)*y1;
    return g;
}


int main(){
    
    int a, b, c, xg, yg;
    cin >> a >> b >> c;
    int g = gcd_extended(a, b, xg, yg);
    // solucion general x = xg(c/g) + k(b/g), y = yg(c/g) - k(a/g). para todo k entero.


    return 0;
}
