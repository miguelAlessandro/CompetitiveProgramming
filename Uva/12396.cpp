#include <iostream>
#include <cstdio>
using namespace std;

const int N = 10000010;
const long long MOD = 1000000007;
long long p[N], d[N];
int n;
bool a[N];

void criba(int n){
    for(int i = 4; i<= n; i+=2) p[i] = 2;
    for(int i = 3; i*i <= n; i += 2) 
        if(not p[i])
            for(int j = i*i; j <= n; j += 2*i)
                if(not p[j]) p[j] = i;
}

long long fact(long long n){
    long long d = 1ll;
    while(p[n]){
        if(a[p[n]]) d = (((p[n]*p[n])%MOD)*d)%MOD;
        a[p[n]] ^= true;
        n /= p[n];
    }

    if(n > 1){
        if(a[n]) d = (((n*n)%MOD)*d)%MOD;
        a[n] ^= true;
    }
    return d;
}


int main(){

    criba(10000000);
    d[1] = 1ll;
    for(int i = 2; i <= 10000000; ++i)
        d[i] = (d[i-1]*fact(i))%MOD;

    while(scanf("%d", &n), n)
        printf("%lld\n", d[n]);

    return 0;
}
