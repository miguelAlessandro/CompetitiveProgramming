#include <bits/stdc++.h>
using namespace std;
double eps = 1e-16;

const int N = 200000;
int n;
int X[N], Y[N];
int P[N], l, r, mmm = 0, mini, A;
int area(int L, int R){
    int sup = 0, inf = 0;
    for(int i = L; i < R; ++i){
        sup += X[i]*Y[i+1];
        inf += Y[i]*X[i+1];
    }
    sup += X[R]*Y[L];
    inf += Y[R]*X[L];
    return sup - inf;
}

int f(int a, int b){
    int M = area(a, b);
    return abs(A - 2*M);
}

void check(int L, int R){
    for(int i = L; i <= R; ++i){
        P[n + i%n]++;
        P[i%n]++;
        if(P[i%n] > mmm){
            mmm = P[i];
            l = i%n;
        }
        if(P[i%n] == mmm)
            r = i%n;
    }
}

int main(){

    while(scanf("%d", &n) != EOF){
        for(int i = 0; i < n; ++i){
            scanf("%d %d", X+i, Y+i);
            X[n+i] = X[i];
            Y[n+i] = Y[i];
        }
        mmm = 0;        
        A = area(0, n-1);
        mini = 0;
        int L = 2, R = n-2;
        for(int i = 0; i < n; ++i){
            if(not P[i]){
                int lo = L, hi = R;
                if((i+1)%n == L%n)
                    lo = (lo+1)%n;
                if((R+1)%n == i%n)
                    hi = (n+R-1)%n;
                while(lo < hi){
                    int mid = (lo+hi)>>1;
                    if(f(i, mid) < f(i, mid+1)) hi = mid;
                    else lo = mid+1;
                }

                printf("%d %d\n", lo, hi);
                int mm = (lo+hi)>>1;
                int M = area(i, mm);
                printf("%d: ", i);
                printf("%d %d\n", M, A-M);
                getchar();

                mini = max(mini, max(M, A-M));
                check(mm, n+i);               
            }
            L = l; R = r;
        }
        for(int i = 0; i < 2*n; ++i) P[i] = 0;
        printf("r: %d %d\n", A-mini, mini);
    }

    return 0;
}
