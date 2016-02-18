#include <iostream>
#include <cstdio>
#define N 1010
using namespace::std;

string A;

int degree(int n, int times){
    int t = 0;
    if(n == 9) return times;
    if(n < 9) return -1;

    while(n > 0){
        t += n%10;
        n /= 10;
    }
    degree(t, times+1);
}



int main(){

    int t, d;
    while(getline(cin, A)){
        t = 0;
        for(string::const_iterator it = A.cbegin(); it != A.cend(); ++it)
            t += *it - '0';
        if(t == 0) break;
        
        d = degree(t, 1);
        if(d == -1) cout << A << " is not a multiple of 9." << '\n';
        else cout << A << " is a multiple of 9 and has 9-degree " << d << "." << '\n';
    }

    return 0;
}
