#include <bits/stdc++.h>

using namespace::std;

int t;
long long a, b;

int main(){
    scanf("%d", &t);
    for(int T = 1; T <= t; ++T){
        scanf("%lld%lld", &a, &b);
        long long And = b, Or = b;
        long long aux = b;
        //int lb = int(log2(b)) + 1, la = int(log2(a)) + 1;
        int lb = 0, la = 0;
        while(aux){aux>>=1; lb++;}
        aux = a;
        while(aux){aux>>=1; la++;}
        if(lb > la){
            Or = (1LL << lb) - 1;
            And = 0LL;
        }
        else{
            for(int i = lb - 1; i >= 0; --i)
                if((b&(1LL<<i)) != (a&(1LL<<i))){
                    long long unos = (1LL << (i+1)) - 1;
                    Or = b|unos;
                    And = b&~unos;
                    break;
                }
        }

        printf("Case %d: %lld %lld\n", T, Or, And);
    }
    return 0;
}
