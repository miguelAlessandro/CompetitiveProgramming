#include <bits/stdc++.h>

using namespace std;

const int N = 1000000 + 5;

int p[N]; 
int f[N];
int solve[N];
int n, a, b;
bool v[N];

void criba(){
    for(int i = 4; i < N; i += 2) p[i] = 2;
    for(int i = 3; i*i < N; i += 2)
        if(!p[i]) for(int j = i*i; j < N; j += 2*i) 
            if(!p[j])
                p[j] = i;
}

int fact(int n){
    if(n == 1) return 1;
    int F = 0;
    while(p[n]){
        f[F++] = p[n]; 
        n /= p[n];
    }
    if(n != 1)
        f[F++] = n;

    int nd = 1, t = 1;
    for(int i = 1; i < F; ++i){
        if(f[i] == f[i-1]) ++t;
        else{
            nd *= (t+1);
            t = 1;
        }
    }
    nd *= (t+1);

    return nd;
}




int main(){
    
    criba();
    long long term = 1;
    while(term <= 1000000){
        int t = term;
        v[t] = true;
        term = t + fact(t);
    }
    
    for(int i = 1; i <= 1000000; ++i)
        solve[i] = solve[i-1] + v[i];       

    scanf("%d", &n);
    for(int i = 1; i <= n; ++i){
        scanf("%d %d", &a, &b);
        printf("Case %d: %d\n", i, solve[b] - solve[a-1]);
    }

    return 0;
}













