/**
 *  SPOJ BRICKS
 *  @overview minimum number of swap to transform a string in other one, swaps blocked
 *  - form string in order.
 *  - different elements of my position to the next letter should contain in possible swaps.
 *  - segment tree to calculate mask of diferents elements.
 */

#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5 + 5;
typedef pair<int, int> ii;
ii st[MAX_N<<2];
char I[MAX_N], F[MAX_N];
int m, t, n;
int cur[30], S[30];
int link[MAX_N][30];

ii merge(ii p, ii q) {
    return {p.first|q.first, p.second+q.second};
}

void build(int nx = 1, int l = 0, int r = n-1) {
    if (l == r) {
        st[nx] = {1<<I[r]-'a', 1};
        return;
    }
    int mid = (l+r)/2;
    build(nx<<1, l, mid);
    build(nx<<1|1, mid+1, r);
    st[nx] = merge(st[nx<<1], st[nx<<1|1]);
}

void erase(int pos, int nx = 1, int l=0, int r=n-1) {
    if (pos < l or pos > r) return;
    if (l == r) {
        st[nx] = {0, 0};
        return;
    }
    int mid = (l+r)/2;
    erase(pos, nx<<1, l, mid);
    erase(pos, nx<<1|1, mid+1, r);
    st[nx] = merge(st[nx<<1], st[nx<<1|1]);
}
ii query(int a, int b, int nx = 1, int l = 0, int r = n-1) {
    if (l>r or b < l or a > r) return {0, 0};
    if (a <= l and r <= b) return st[nx];
    int mid = (l+r)/2;
    return merge(
            query(a, b, 2*nx, l, mid),
            query(a, b, 2*nx+1, mid+1, r)
        );
}

int main() {
    scanf ("%d\n", &t);
    while (t--) {
        scanf ("%s", I); 
        scanf ("%s", F); 
        
        scanf ("%d\n", &m);
        for (int i = 0; i < 26; ++i) S[i] = 0;
        for (int i = 0; i < m; ++i) {
            char a, b;
            scanf ("%c%c\n", &a, &b);
            S[a-'a'] |= 1<<b-'a';
            S[b-'a'] |= 1<<a-'a';
        }
        n = strlen(I);
        memset(link, -1, sizeof link);
        for (int i = n-1; i >= 0; --i) {
            link[i][I[i] - 'a'] = i;
        }
        
        for (int i = n-1; i >= 0; --i) {
            for (int j = 0; j < 26; ++j) {
                if (link[i][j] != i) 
                    link[i][j] = link[i+1][j];
            }
        }
        
        build();
        bool ok = 1;
        unsigned ans = 0;
        memset(cur, -1, sizeof cur);
        
        for (int i = 0; i < n; ++i) {
            int ch = F[i] - 'a';
            cur[ch] = link[cur[ch]+1][ch];   
            
            if (cur[ch] == -1) {
                ok = 0;
                break;
            }
            
            ii node = query(0, cur[ch]-1);
            
            if ((node.first & S[ch]) != node.first) {
                ok = 0;
                break;
            }
            ans += node.second;
            erase(cur[ch]);
        }
        
        if(strlen(F) != n) ok = 0;
        
        if (ok) printf("%u\n", ans);
        else puts("-1");
    }
    return 0;
}
