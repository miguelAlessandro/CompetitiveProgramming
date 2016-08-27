#include <cstdio>
const int N = 1000002;

int p[N], solve[N];
int n, a, b, term = 1, nc = 1, nd, f, c, i, j;
short v[N];

#define getcx getchar_unlocked
inline void inp( int &n )//fast input function
{
   n=0;
   int ch=getcx();int sign=1;
   while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}
 
   while(  ch >= '0' && ch <= '9' )
           n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
   n=n*sign;
}

void criba(){
    for(i = 4; i < N; i += 2) p[i] = 2;
    for(i = 3; i*i < N; i += 2)
        if(!p[i]) for(j = i*i; j < N; j += 2*i) 
                p[j] = i;
}

int fact(int n){
    nd = 1;
    while(p[n]){
        f = p[n]; c = 1;
        while(n%f == 0){
            c++;
            n /= f;
        }
        nd *= c;
    }
    if(n > 1) nd <<= 1;

    return nd;
}




int main(){
    
    criba();
    while(term < N){
        v[term] = 1;
        term += fact(term);
    }
    
    for(i = 1; i < N; ++i)
        solve[i] = solve[i-1] + v[i];       

    inp(n);
    while(n--){
        inp(a); inp(b);
        printf("Case %d: %d\n", nc++, solve[b] - solve[a-1]);
    }

    return 0;
}
