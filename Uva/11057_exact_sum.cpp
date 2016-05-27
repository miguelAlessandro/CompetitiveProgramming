#include <bits/stdc++.h>

using namespace std;

int n, m;
int v[10000 + 5];

int main(){

    while(scanf("%d", &n) != EOF){
        for(int i = 0; i < n; ++i)
            scanf("%d", v + i);
        scanf("%d", &m);
        sort(v, v + n);
        
        int diff = v[n-1] - v[0] + 1, a, b;
        for(int i = n-1; i >= 0; --i){
            int lo = 0, hi = i-1;
            while(lo < hi){
                int mid = lo + (hi-lo+1)/2;
                if(v[mid] <= m - v[i]) lo = mid;
                else hi = mid - 1;
            }
            if(v[lo] + v[i] == m and v[i] - v[lo] < diff){ 
                diff = v[i] - v[lo];
                a = v[lo];
                b = v[i];
            }
        }   
        printf("Peter should buy books whose prices are %d and %d.\n\n", a, b);
    }

    return 0;
}
