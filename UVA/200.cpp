#include <bits/stdc++.h>

using namespace::std;

const int N = 30;
const double eps = (1e-9);
const double pi = 2.0f*acos(0.0f);
const int oo = (1 << 30);

template<typename T> inline void MAXI(T& a, T b){if(a > b) a=b;}
template<typename T> inline void MINI(T& a, T b){if(a < b) a=b;}

char A[N], B[N];
vector<int> graph[N], ORD;
bool MAP[N], visit[N];


void dfs(int source){

	visit[source] = true;
	for(int i = 0; i < graph[source].size(); ++i)
		if(!visit[graph[source][i]]) dfs(graph[source][i]);
	
	ORD.push_back(source);	
}

void dag(){

	for(int i = 0; i < 26; ++i)
		if(MAP[i] && !visit[i]) dfs(i);
	reverse(ORD.begin(), ORD.end());
}


int main(){

    B[0] = '\0';
    
	while(fgets(A, N, stdin), A[0] != '#'){
	
		for(int i = 0; A[i] != '\0'; ++i)
			MAP[A[i] - 'A'] = true;
			
		for(int i = 0; isupper(A[i]) && isupper(B[i]); ++i)
			if(A[i] != B[i]){
				graph[B[i] - 'A'].push_back(A[i] - 'A');
				break;
			}
		
	}
	dag();
	
	for(vector<int>::const_iterator it = ORD.cbegin(); it != ORD.cend(); ++it)
		printf("%c", *it + 'A');
	puts("");

	return 0;
}

