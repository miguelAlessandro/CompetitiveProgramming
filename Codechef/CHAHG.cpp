#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
const int N = 15;
const int Inf = 1000000005;
int a[N], m[N], temp;
int t, n;
ii U[N], L[N];
ii r[4];
int h;

int main(){

	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 0; i < n; ++i)
			scanf("%d %d", a+i, m+i);	

		for(int i = 0; i+1 < n; ++i)
			L[i] = U[i] = ii(Inf, 0);
		
		for(int i = 0; i+1<n; ++i){
			if(a[i]==a[i+1]){
				if(m[i]>m[i+1]) L[i] = ii(1, Inf);
				if(m[i]<m[i+1]) U[i] = ii(1, Inf);
			}
			if(a[i] > a[i+1]){
				if(m[i]>=m[i+1]) L[i] = ii(0, Inf);			
				else{
					temp = (a[i]-a[i+1])/(m[i+1]-m[i]);
					if((a[i]-a[i+1])%(m[i+1]-m[i]) == 0){
						L[i] = ii(0, temp-1);
						U[i] = ii(temp+1, Inf);
					}
					else{
						L[i] = ii(0, temp);
						U[i] = ii(temp+1, Inf);
					}
				}
			}	
			if(a[i] < a[i+1]){
				if(m[i]<=m[i+1]) U[i] = ii(0, Inf);			
				else{
					temp = (a[i+1]-a[i])/(m[i]-m[i+1]);
					if((a[i+1]-a[i])%(m[i]-m[i+1]) == 0){
						U[i] = ii(0, temp-1);
						L[i] = ii(temp+1, Inf);
					}
					else{
						U[i] = ii(0, temp);
						L[i] = ii(temp+1, Inf);	
					}
				}
			}			
		}	
		ii s1(0, Inf);
		for(int i = 0; i+1<n; ++i)
			if(i%2==0) s1 = ii(max(s1.first, U[i].first), min(s1.second, U[i].second));
			else s1 = ii(max(s1.first, L[i].first), min(s1.second, L[i].second));
		ii s2(0, Inf);
		for(int i = 0; i+1<n; ++i)
			if(i%2==0) s2 = ii(max(s2.first, L[i].first), min(s2.second, L[i].second));
			else s2 = ii(max(s2.first, U[i].first), min(s2.second, U[i].second));
	
		h = 0;	
		if(s1.first <= s1.second) r[h++] = s1;
		if(s2.first <= s2.second) r[h++] = s2;
		if(h==2){
			sort(r, r+h);		
			if(r[0].second+1 == r[1].second.first){
				r[0].second = r[1].second;
				h = 1;
			}
		}

		printf("%d\n", h);
		for(int i = 0; i < h; ++i)
			if(r[i].second == Inf) printf("%d Inf\n", r[i].first);	
			else printf("%d %d\n", r[i].first, r[i].second);
	}

	return 0;
}
