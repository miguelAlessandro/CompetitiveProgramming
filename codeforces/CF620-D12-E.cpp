/**
 *  CODEFORCES 620 D12 E
 *  @overview update and query in subtree 
 *  - flatten the tree.
 *  - lazy propagation with set of 60 elements (eazy using long long).
 */


#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 4e5 + 5;
int lo[MAX_N], hi[MAX_N];
int t=1, n, m;
long long diff[MAX_N<<2];
long long lazy[MAX_N<<2];
int a[MAX_N];
int inv[MAX_N];
vector<int> adj[MAX_N];

void dfs (int x, int p) {
    inv[t] = x;
    lo[x] = t++;
    for (int v : adj[x])
        if (v != p)
            dfs(v, x);
    hi[x] = t-1;
}

void upd (int nx, long long s) {
    diff[nx] = s;
    lazy[nx] = s;
}

void push(int nx) {
    if (lazy[nx]) {
        upd(nx<<1, lazy[nx]);
        upd(nx<<1|1, lazy[nx]);
        lazy[nx] = 0;
    } 
}

void build (int nx = 1, int l = 1, int r = n) {
    if (l == r) {
        diff[nx] = (1ll<<a[inv[r]]);
        return;
    }
    int mid = (l+r)/2;
    build(nx<<1, l, mid);
    build(nx<<1|1, mid+1, r);
    diff[nx] = diff[nx<<1] | diff[nx<<1|1];
}


void update(int a, int b, long long s, int nx = 1, int l = 1, int r = n) {
    if (b < l or a > r) return;
    if (a <= l and r <= b) {
        upd(nx, s);
        return;
    }
    int mid = (l+r)/2;
    push(nx);
    update(a, b, s, nx<<1, l, mid);
    update(a, b, s, nx<<1|1, mid+1, r);
    diff[nx] = diff[nx<<1] | diff[nx<<1|1];
}

long long query(int a, int b, int nx = 1, int l = 1, int r = n) {
    if (b < l or a > r) return 0;    
    if (a <= l and r <= b) return diff[nx];
    int mid = (l+r)/2;
    push(nx);
    return query(a, b, nx<<1, l, mid) | query(a, b, nx<<1|1, mid+1, r);
    
}

int main () {

    scanf ("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf ("%d", a+i);
    for (int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    dfs(1, 0);
    build();
    
    for (int i = 1; i <= m; ++i) {
        int type;
        int v, c;
        scanf("%d %d", &type, &v);
        if (type == 1) {
            scanf ("%d", &c);
            update(lo[v], hi[v], 1ll<<c);
        } else {
            printf("%d\n", (int)__builtin_popcountll(query(lo[v], hi[v])));
        }
    }
    
    return 0;
}
