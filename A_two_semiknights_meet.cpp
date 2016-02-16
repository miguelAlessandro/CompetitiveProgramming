#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace::std;

int t, s1[5], s2[5], m;
string A;

int main(){

    scanf("%d%*c", &t);
    while(t--){
    
        m = 0;
        
        for(int i = 0; i < 8; ++i){
            cin >> A;
            for(int j = 0; j < 8; ++j)
                if(A[j] == 'K') {s1[m] = i; s2[m++] = j;}
        }
    
        if(abs(s1[0] - s1[1])%4 == 0 && abs(s2[0] - s2[1])%4 == 0) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}

