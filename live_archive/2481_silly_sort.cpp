#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int n, nc = 1;
int p[N], p2[N], invp[N];
int sum, sumt, mini, lencycle, kst;
bool vis[N];

int main() {
	
    while(scanf("%d", &n), n){
    
        for(int i = 0; i < n; ++i) scanf("%d", p+i);
        for(int i = 0; i < n; ++i) p2[i] = p[i];
        
        sort(p2, p2+n);
        for(int i = 0; i < n; ++i) invp[p2[i]] = i;
        
        memset(vis, false, sizeof vis);
        sum = 0;
        for(int i = 0; i < n; ++i){
            if(invp[p[i]] == i or vis[i]) continue;
            sumt = 0; lencycle = 0, mini = N; kst = i;
            while(not vis[kst]){            
                sumt += p[kst];
                mini = min(mini, p[kst]);
                vis[kst] = true;
                lencycle += 1;
                
                kst = invp[p[kst]];
            }
            
            sum += sumt + min(mini*(lencycle-2), p2[0]*(lencycle+1) + mini);
        }
        
        printf("Case %d: %d\n\n", nc++, sum);
    }
	
	return 0;
}
