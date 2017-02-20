#include <bits/stdc++.h>
using namespace std;

const int N = 55;
int t, k;
long long c[N], n;
int In[N];

int main(){

	scanf("%d", &t);
	while(t--){
		scanf("%lld %d", &n, &k);
		for(int x,  i = 0; i < k; ++i){
			scanf("%d", &x);
			if(i) c[i] = 2*c[i-1] + x;
			else c[i] = x;		
		}	
	
		int t = 0;
		for(int i = k-1; i >= 0; --i)
			if(c[i] <= n){
				n -= c[i];
				In[t++] = i;
			} 

		if(n == 0)
			for(int i = t-1; i >= 0; --i)
				printf("%d%c", In[i]+1, i==0 ? '\n' : ' ');
		else
			puts("-1");
	}
	

	return 0;
}
