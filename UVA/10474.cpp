#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> v;

int main(){

    int nc = 1;
    while(scanf("%d %d", &n, &m), n + m){
        v.resize(n);
        for(int i = 0; i < n; ++i)
            scanf("%d", &v[i]);
        sort(v.begin(), v.end());
        
        printf("CASE# %d:\n", nc++);
        for(int q, i = 0; i < m; ++i){
            scanf("%d", &q);
            int lo = 0, hi = n-1;
            while(lo < hi){
                int mid = (hi+lo)>>1;
                if(v[mid] < q) lo = hi+1;
                else hi = mid;
            }
            v[lo] == q ?
                printf("%d found at %d\n", q, lo + 1):
                printf("%d not found\n", q);
        }
    }
    
    return 0;
}
