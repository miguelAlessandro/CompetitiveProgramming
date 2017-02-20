#include <stdio.h>
#include <string.h> 
//#include <algorithm>
//using namespace std;

const int N = 50002;
const int LN = 20;
const int K = 11;
int P[LN][N], t, T[N], cc, temp, l, r, i, j, f, len, var, inv[N], C[K];
long long n, ans, rev;

struct tup{
  int x, y, p;
  bool operator!=(const tup& p){return x != p.x or y != p.y;}
} L[N], out[N];


int lcp(int x, int y){
	//if(x == y) return n-x; 
	r = 0;
    for(f = len; f >= 0; --f)
        if(x >= n or y >= n) break;
        else if(P[f][x] == P[f][y]){
			temp = (1<<f);
            x += temp;
            y += temp;
            r += temp;
        }
    
    return r;
} 

void countSortX(){
	memset(C, 0, sizeof C);
	for(f = 0; f < n; ++f) T[f] = ((L[f].x+1)/l)%10;
	for(f = 0; f < n; ++f) C[T[f]]++;
	for(f = 1; f < K; ++f) C[f] += C[f-1];
	for(f = n-1; f >= 0; --f){
		out[C[T[f]] - 1] = L[f];
		C[T[f]]--;
	}
	//for(i = 0; i < n; ++i) L[i] = out[i];
	memcpy(L, out, sizeof(tup) * n);
}

void countSortY(){
	int i;
	memset(C, 0, sizeof C);	
	for(f = 0; f < n; ++f) T[f] = ((L[f].y+1)/l)%10;
	for(f = 0; f < n; ++f) C[T[f]]++;
	for(f = 1; f < K; ++f) C[f] += C[f-1];
	for(f = n-1; f >= 0; --f){
		out[C[T[f]] - 1] = L[f];
		C[T[f]]--;
	}
	//for(i = 0; i < n; ++i) L[i] = out[i];
	memcpy(L, out, sizeof(tup) * n);
}


void radixsort(){
	for(l = 1; l <= n; l *= 10) countSortY();
	for(l = 1; l <= n; l *= 10) countSortX();
}


//inline int ini(){
	//int number = 0;
void ini(){
	t = 0;
	var = getchar();
	while(var<48) var = getchar();
	while(var>47 and var<58){
    	//number = (number<<3)+(number<<1)+c-'0';
    	t = (t<<3) + (t<<1) + var - 48;
		var = getchar();
	}
	//return number;
}

void wrll(long long N)
{
	cc = 0;
    rev = N;
    if(N == 0){ 
		putchar(48);
		putchar('\n'); 
		return;
	}
    while(rev%10==0){ 
		cc++; 
		rev /= 10;
	}

    rev = 0;
    while(N){ 
		rev = (rev<<3) + (rev<<1) + N%10; 
		N /= 10;
	}
    while(rev){ 
		putchar(rev%10 + 48); 
		rev /= 10;
	}
    while(cc--) putchar(48);
    putchar('\n');
}


int main(){

	ini();
	while(t--){

		n = 0;		
		while(var = getchar(), var != '\n')
 			P[0][n++] = var; 
         
    	for(i = 0; (1<<i) < (n<<1); ++i){
        	for(j = 0; j < n; ++j){
            	L[j].x = P[i][j];
            	L[j].y = j+(1<<i) < n ? P[i][j+(1<<i)] : -1;
            	L[j].p = j; 
        	}
        	//sort(L, L+n);
			radixsort();      
        	P[i+1][L[0].p] = 0;
        	for(j = 1; j < n; ++j)
            	P[i+1][L[j].p] = L[j] != L[j-1] ? j : P[i+1][L[j-1].p];
     	}

		len = 0; while((1<<len) < n) len++;

		for(i = 0; i < n; ++i)
			inv[P[len][i]] = i;
		
		ans = 0;
		for(i = 1; i < n; ++i) ans += lcp(inv[i], inv[i-1]);

		wrll(n*(n+1)/2 - ans);
     }
     return 0;
}
