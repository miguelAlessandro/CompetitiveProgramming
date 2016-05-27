#include <bits/stdc++.h>
using namespace std;

int t;
double a[3], b[3];
double eps = 1e-6;

double proof(double x){
    return hypot(a[0]-b[0], a[1]-b[1]) + hypot(a[0]-x, a[1]) + hypot(x, a[1]*x/(a[0]-x)) + hypot(b[0], b[1]-a[1]*x/(a[0]-x));
}


int main(){
    
    scanf("%d", &t);
    while(t--){
        scanf("%lf %lf", a, a+1);
        scanf("%lf %lf", b, b+1);
        
        if(a[0] < b[0]){
            swap(a[0], b[0]);
            swap(a[1], b[1]);
        }

        double lo = eps, hi = a[0];
        for(int i = 0; i < 100; ++i){
            double m1 = lo + (hi-lo)/3,
                   m2 = hi - (hi-lo)/3;
            if(proof(m1) > proof(m2)) lo = m1;
            else hi = m2;
        }
        printf("%.3lf\n", proof((lo+hi)/2));
    }

    return 0;
}
