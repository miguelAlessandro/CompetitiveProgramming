#include<bits/stdc++.h>
using namespace std;
long long n,m,s;
int ans;
int q;

long long C(long long x){
	return x*(x-1)/2;
}

int main(){
	
	scanf("%d", &q);
	for(int i = 0; i < q; ++i){
		scanf("%lld %lld %lld", &n, &m, &s);
		long long ans = LLONG_MAX;
		if(n-1 == m) ans = s;
		else{
            for(long long x=1, Cm, y, v, u, a; x<n-1; ++x){
			    for(long long b=1; b <= s/(n-1)+1; ++b){
				    v = x+1;
                    a = (s - x*b)/(n-1-x);
                    if(a>=b and (s-x*b)%(n-1-x)==0)
						if(m-n+1+x <= C(v)) ans = min(ans, (n-1-x)*a + (m-n+1+x)*b);
				    	else ans = min(ans, m*a + C(v)*(b-a));
					
			    }
            }
		}

		printf("%lld\n", ans);
	}
	return 0;
}
