#include <iostream>

using namespace::std;

int main(){
    bool prueba = false;
    long long l, r;
    int k;
    unsigned long long m = 1LL;
    cin >> l >> r >> k;
    while(m <= r){
        if(m >= l)
           {prueba = true; cout << m << " ";}        
        m *= k;
        if(m%k != 0) break;
    }
    
    if(not prueba) cout << -1 << endl;
    else cout << endl;

    return 0;
}
