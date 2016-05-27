#include <bits/stdc++.h>

using namespace std;

const int N = 105;
int n, m, d;
int a[N*N];

int proof(int mid){
    int sum = 0;
    for(int i = 0; i < n*m; ++i)
        sum += abs(a[i]-mid);
    return sum;
}

int main(){

    scanf("%d %d %d", &n, &m, &d);
    for(int i = 0; i < n*m; ++i)
            scanf("%d", &a[i]);
    
    int r = a[0]%d;
    a[0] /= d;
    for(int i = 1; i < n*m; ++i)
        if(a[i]%d != r){
            printf("-1\n");
            return 0;
        }
        else
            a[i] /= d;

    int lo = 0, hi = 10000;
    while(lo < hi){
        int mid = (lo+hi)>>1;
        if(proof(mid) <= proof(mid+1))
            hi = mid;
        else
            lo = mid+1;
    }
    
    printf("%d\n", proof((lo+hi)>>1));

    return 0;
}




