#include <iostream>

using namespace::std;

int a, b, c;
bool ok;

int main(){
    
    cin >> a >> b >> c;
    for(int i = 0; i*a <= c; ++i)
        if((c - i*a)%b == 0){
            ok = true;        
            break;
        }
    
    if(ok) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
