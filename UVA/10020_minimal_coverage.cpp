#include <bits/stdc++.h>
using namespace std;


const int N = 100005;
int t, n, m, x, y;
pair<int, int> S[N];
vector<int> H;


int main(){

	scanf("%d", &t);
	while(t--){
		scanf("%d", &m);
		n = 0;
		H.clear();
		while(scanf("%d %d", &x, &y), x + y){
			S[n].first = x;
			S[n].second = y;
			n++;
		}
		
		sort(S, S+n);
		
		int lo = 0, hi = 0, i = 0, in;
		while(hi < m){
			int maxhi = hi;
			while(i < n and S[i].first <= hi){
				if(S[i].second > maxhi){
					maxhi = S[i].second;
					in = i;
				}
				i++;
			}

			if(maxhi == hi) break;
			hi = maxhi;
			H.push_back(in);
		}
			
		if(hi < m) puts("0"); 
		else{
			printf("%d\n", (int)H.size());
			for(int i = 0; i < H.size(); ++i)
				printf("%d %d\n", S[H[i]].first, S[H[i]].second);
		}
		if(t) puts("");
	}
	

	return 0;
}
