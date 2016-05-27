#include <bits/stdc++.h>
using namespace std;

const int N = 200010;
int n;
long long X[N], Y[N], A;
long long acum[N];

long long area(int L, int R){
    return acum[R-1] - acum[L-1] + X[R]*Y[L] - Y[R]*X[L];
}
long long f(int l, int m){
    return abs(A - 2*area(l, m)); 
}

int main(){

    while(scanf("%d", &n) != EOF){
        X[0] = Y[0] = 0;
        for(int i = 1; i <= n; ++i){
            scanf("%lld %lld", X+i, Y+i);
            X[n+i] = X[i];
            Y[n+i] = Y[i];
        }
        acum[0] = 0;
        for(int i = 1; i < 2*n; ++i)
            acum[i] = acum[i-1] + X[i]*Y[i+1] - Y[i]*X[i+1];
        A = acum[n-1] + X[n]*Y[1] - Y[n]*X[1];

        long long r = A;
        for(int i = 1; i <= n; ++i){
            int lo = i+2, hi = n+i-2;
            while(lo < hi){
                int mid = (lo+hi)>>1;
                if(f(i, mid) < f(i, mid+1)) hi = mid;
                else lo = mid+1;
            }
            long long m = area(i, (lo+hi)>>1);
            m = min(A-m, m);
            if(A-2*m > A-2*r)
                r = m;
        }
        printf("%lld %lld\n", A-r, r);
    }

    return 0;
}
