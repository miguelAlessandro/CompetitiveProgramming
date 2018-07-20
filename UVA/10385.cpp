#include <bits/stdc++.h>
using namespace std;

const int N = 22;
int t, n;
double X[N], Y[N];

double f(double m){
    
    double time = 1000000000.0;
    for(int i = 1; i < n; ++i)
        time = min(time, m/X[i] + (t-m)/Y[i]);
    return (time - m/X[n] - (t-m)/Y[n])*3600;
}

int main(){

    while(scanf("%d", &t) != EOF){
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i)
            scanf("%lf %lf", X+i, Y+i);

        double lo = 0.0, hi = double(t);
        for(int i = 0; i <= 50; ++i){
            double m1 = lo + (hi-lo)/3,
                   m2 = hi - (hi-lo)/3;
            if(f(m1) < f(m2)) lo = m1;
            else hi = m2;
        }
        double r = (lo+hi)/2; 
        if(f(r) < -1e-9)
            printf("The cheater cannot win.\n");
        else
            printf("The cheater can win by %.0lf seconds with r = %.2lfkm and k = %.2fkm.\n", f(r), r, t-r);
    }

    return 0;
}
