#include <bits/stdc++.h>
using namespace std;

const int N = 54;
long long X[N], Y[N], Z[N];
int n;

bool same(int l, int r){
	return X[l] == X[r] and Y[l] == Y[r] and Z[l] == Z[r];
}

bool proof(int i, int j, int k, int l){
	return ((Y[j]-Y[i])*(Z[k]-Z[i]) - (Y[k]-Y[i])*(Z[j]-Z[i]))*(X[l]-X[i]) +
		   ((Z[j]-Z[i])*(X[k]-X[i]) - (X[j]-X[i])*(Z[k]-Z[i]))*(Y[l]-Y[i]) +
		   ((X[j]-X[i])*(Y[k]-Y[i]) - (Y[j]-Y[i])*(X[k]-X[i]))*(Z[l]-Z[i]) == 0;
}

bool line(int i, int j, int k){
	return (X[j]-X[i])*(Y[k]-Y[i]) == (Y[j]-Y[i])*(X[k]-X[i]) and
		   (X[j]-X[i])*(Z[k]-Z[i]) == (Z[j]-Z[i])*(X[k]-X[i]) and
		   (Y[j]-Y[i])*(Z[k]-Z[i]) == (Z[j]-Z[i])*(Y[k]-Y[i]);
}

int main(){

	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
		scanf("%I64d %I64d %I64d", X+i, Y+i, Z+i);

	
	int r = 0;
	for(int i = 0; i < n; ++i){
		long long mask = 0;
		int ans = 0;
		for(int j = 0; j < n; ++j)	
			if(same(i, j)){
				ans += 1;
				mask |= (1LL<<j);
			}			

		r = max(r, ans);
		int ans2 = ans;
		long long mask2 = mask;
		for(int j = 0; j < n; ++j)
			if(not(mask&(1LL<<j))){
				ans++;
				mask |= (1LL<<j);
				for(int k = 0; k < n; ++k)
					if(not(mask&(1LL<<k)) and line(i, j, k)){
						ans += 1;
						mask |= (1LL<<k);
					}	
				int ans3 = ans;	
				for(int k = 0; k < n; ++k)
					if(not(mask&(1LL<<k))){
						ans += 1;
						for(int l = 0; l < n; ++l)
							if(l != k and not(mask&(1LL<<l)) and proof(i, j, k, l))
								ans+=1;
						r = max(r, ans);	
						ans = ans3;		
					}
				r = max(r, ans);
				mask = mask2;
				ans = ans2;
			}
	}

	printf("%d\n", r);

	return 0;
}
