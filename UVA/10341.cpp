#include <bits/stdc++.h>

using namespace std;

int p, q, r, s, t, u;
double eps = 1e-7;

double funct(double x){
    return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
}

bool proof(double x, double y){
    return funct(x)*funct(y) > 0;   
}

double binary_search(double lo, double hi){
    static double mid;
    while(lo+eps < hi){
        mid = (lo+hi)/2.0f;
        if(proof(lo, mid)) lo = mid;
        else hi = mid;
    }
    return (lo+hi)/2.0f;
}

int main(){

    while(scanf("%d %d %d %d %d %d", &p, &q, &r, &s, &t, &u) != EOF)
        proof(0.0000f, 1.0000f) ?
            puts("No solution") : printf("%.4lf\n", binary_search(0.0000f, 1.0000f));

    return 0;
}
