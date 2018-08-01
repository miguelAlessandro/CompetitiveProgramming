/**
 *  LIVE ARCHIVE 4976
 *  @overview maximum subarray problem, I can delete a range.
 *  - calculate without eliminate a range for right
 *  - calculate without eliminate a range for left and save in fenwick tree 
 */

#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
const int MAX_N = 2e5 + 5;
int a[MAX_N], dpL[MAX_N], dpR[MAX_N];
int t, n;
int ft[MAX_N];

void upd(int x, int v) {
    while (x < MAX_N) {
        ft[x] = max(ft[x], v);
        x += x&-x;
    }
}

int query(int x) {
    int ans = 0;
    while (x > 0) {
        ans = max(ans, ft[x]);
        x -= x&-x;
    }
    return ans;
}


int main() {
    
    scanf ("%d", &t);
    while (t --) {
        scanf ("%d", &n);   
        for (int i = 1; i <= n; ++i) 
            scanf ("%d", a+i);
        
        map<int, int> id;
        for (int i = 1; i <= n; ++i)
            id[a[i]];
        
        int m = 1;
        for (auto& v : id)
            v.second = m++;
        
        memset(ft, 0, sizeof ft);
        int ans = 1;
        dpR[n] = 1;
        for (int i = n-1; i >= 1; --i) {
            dpR[i] = 1 + (a[i] < a[i+1] ? dpR[i+1] : 0);
            ans = max(ans, dpR[i]);
        }
    
        dpL[1] = 1;
        upd(id[a[1]], 1);
        for (int i = 2; i <= n; ++i) {
            
            dpL[i] = 1 + (a[i-1] < a[i] ? dpL[i-1] : 0);
            int Id = id[a[i]];
            upd(Id, dpL[i]);
            ans = max(ans, query(Id-1) + dpR[i]);
        }
        ans = max(ans, query(m));
        printf("%d\n", ans);
    }
    return 0;
}
