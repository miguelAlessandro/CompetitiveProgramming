#include <iostream>

using namespace::std;

int a, b, c;
string m;
bool prueba = false;;

int main(){

    cin >> a >> b >> c;
    cin >> m;

    int h, k;
    for(int i = 0; i*b <= a; ++i)
        if((a - b*i)%c == 0)
            h = i, k = (a - b*i)/c, prueba = true;
    if(not prueba) {cout << -1 << endl; return 0;}

    cout << h + k << endl;
    int t = 0;
    for(int i = 0; i < h; ++i){
        for(int j = t; j < t + b; ++j)
            cout << m[j];
        cout << endl;
        t += b;
    }
    for(int i = 0; i < k; ++i){
        for(int j = t; j < t + c; ++j)
            cout << m[j];
        cout << endl;
        t += c;
    }
    
    return 0;
}
