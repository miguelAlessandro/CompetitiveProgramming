#include <iostream>
#include <cstdio>
using namespace std;

const int N = 10000;
int T, n;
int a[N], b[N], c[N];

double f(double x){

    double maxi = -100000.0;
    for(int i = 0; i < n; ++i)
        maxi = max(maxi, a[i]*x*x + b[i]*x + c[i]); 
    return maxi;
}

int main(){

    scanf("%d", &T);
    while(T--){
        scanf("%d", &n);
        for(int i = 0; i < n; ++i)
            scanf("%d %d %d", a+i, b+i, c+i);
        
        double lo = 0.0f, hi = 1.0f;
        for(int i = 0; i < 48; ++i){
            double m1 = lo + (hi-lo)/3,
                   m2 = hi - (hi-lo)/3;
            if(f(m1) > f(m2)) lo = m1;
            else hi = m2;
        }
        printf("%.4lf\n", f((lo+hi)/2));     
    }

    return 0;
}
