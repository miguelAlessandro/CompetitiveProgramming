#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int n, nc = 1;
int p[N], p2[N], invp[N];
int sum, sumt, mini, lencycle, kst;
bool vis[N];

inline void read(int &x){

    x=0;
    register char c=fgetc_unlocked(stdin);
    for(;c<'0' || c>'9';c=fgetc_unlocked(stdin));
    for(;c>='0' && c<='9';c=fgetc_unlocked(stdin))
        x=(x<<3)+(x<<1)+(c-'0');
}

inline void write(int x){

    register char buffor[35];
    register int i=0;
    do{
        buffor[i++]=(x%10)+'0';
        x/=10;
    } while(x);
    i--;
    while(i>=0) putchar_unlocked(buffor[i--]);
}

int main() {
	
    while(read(n), n){
    
        for(int i = 0; i < n; ++i) read(p[i]);
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
        
        putchar_unlocked('C');
        putchar_unlocked('a');
        putchar_unlocked('s');
        putchar_unlocked('e');
        putchar_unlocked(' ');
        write(nc); nc++;
        putchar_unlocked(':');
        putchar_unlocked(' ');
        write(sum);
        putchar_unlocked('\n');
        putchar_unlocked('\n');
    }
	
	return 0;
}
