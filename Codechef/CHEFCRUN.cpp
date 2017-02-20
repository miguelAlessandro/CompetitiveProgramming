#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
long long a[N], dp1[N], dp2[N], dp3[N], dp4[N];
int t, x, y, n;
long long sum;

long long dis(int x, int y){
	x = (n+x)%n;
	y = (n+y)%n;
	if(x==(y+1)%n) return a[y];
	return a[x];
}

int left(int x){
	return (n+x-1)%n;
} 

int right(int x){
	return (x+1)%n;
}

int main(){

	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 0; i < n; ++i)
			scanf("%lld", a+i);
		scanf("%d %d", &x, &y);
		if(n==1){
			printf("%lld\n", min(2*a[0], 0ll));
			continue;
		}

		x--; y--;
		
		dp1[y] = 0;
		sum = 0;
		for(int z = y; z != left(y); z=right(z)){
			sum += dis(z, right(z));
			dp1[right(z)] = min(dp1[z], sum);
		}
		dp2[y] = 0;
		sum = 0;	
		for(int z = y; z != right(y); z = left(z)){
			sum += dis(z, left(z));
			dp2[left(z)] = min(dp2[z], sum);
		}	
		dp3[x] = 0;
		sum = 0;
		for(int z = x; z != left(x); z=right(z)){
			sum += dis(z, right(z));
			dp3[right(z)] = min(dp3[z], sum);
			//cout << dp3[right(z)] << " ";
		}	
		dp4[x] = 0;
		sum = 0;
		for(int z = x; z != right(x); z=left(z)){
			sum += dis(z, left(z));
			dp4[left(z)] = min(dp4[z], sum);
		}
		
		long long pathxy=0, pathyx=0;
		for(int i = x; i != y; i = right(i))
			pathxy+=dis(i, right(i));

		for(int i = y; i != x; i = right(i))
			pathyx+=dis(i, right(i));

		long long minhi = 0, minlo = 0;
		for(int i = x; i != y; i=right(i)){	
			minhi = min(minhi, dp2[i]+dp3[i]);	
		}		
		minhi = min(minhi, dp2[y]+dp3[y]);
		for(int i = y; i != x; i=right(i))
			minlo = min(minlo, dp1[i]+dp4[i]);
		minlo = min(minlo, dp1[x]+dp4[x]);		


		printf("%lld\n", min(2*minlo+pathxy, 2*minhi+pathyx));
	}

	return 0;
}
