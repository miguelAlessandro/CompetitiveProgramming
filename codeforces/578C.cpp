#include <iostream>
#include <cstdio>
using namespace std;

const int N = 200005;
int n;
int a[N];


bool proof(double mid, double& max1, double& max2){
    
    double max1_1;
    max1_1 = max1 = 0.0F;
    for(int i = 1; i <= n; ++i){
        max1_1 = max(double(0), max1_1 + a[i] - mid);
        max1 = max(max1, max1_1);
    }

    max1_1 = max2 = 0.0F;
    for(int i = 1; i <= n; ++i){
        max1_1 = max(double(0), max1_1 + mid - a[i]);
        max2 = max(max2, max1_1);
    }
    
    return max1 > max2;
}

int main(){
    
    scanf("%d", &n);
    double lo = 10000.0F, hi = 1.0F;
    for(int i = 1; i <= n; ++i){
        scanf("%d", a + i);
        lo = min(lo, double(a[i]));
        hi = max(hi, double(a[i]));
    }
     
    double p, q;
    for(int i = 0; i < 80; ++i){
        double m = (hi+lo)/2;
        if(proof(m, p, q)) lo = m;
        else hi = m;
    }
    
    printf("%.15lf\n", max(p, q)); 

    return 0;
}
