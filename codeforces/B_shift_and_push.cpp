#include <iostream>
#include <cstdio>
#include <vector>
#include <climits>
using namespace std;

const int N = 100005;
vector<int> graph[N];
int n;

int main(){

	scanf("%d", &n);
	for(int x, i = 0; i < n; ++i){
		scanf("%d", &x);
		graph[x].push_back(i);
	}

	int max_r = INT_MAX;
	for(int dis, len, r, i = 1; i <= 100000; ++i){

		r = len = graph[i].size();
		if(len == 0) continue;

		dis = 0;
		for(int temp, j = 0; j < len-1; ++j){
			temp = graph[i][(j+1)%len]-graph[i][j]-1;			
			r += temp;
			dis = max(dis, temp);			
		}

		r += n - graph[i][len-1] - 1 + graph[i][0];
		dis = max(dis, n - graph[i][len-1] - 1 + graph[i][0]);
		

		max_r = min(max_r, dis+r);
	}	

	printf("%d\n", max_r);

	return 0;
}
