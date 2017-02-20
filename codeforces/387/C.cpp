#include <iostream>
#include <cstdio>
#include <climits>
#include <vector>
#include <cstring>
#include <string>
#include <map>
#include <queue>
#include <set>
using namespace std;

const int N = 100005;
int n, q;
int v[N][3];
vector<bool> s;
vector<int> can;
int tf[N]; 

int main(){

	scanf("%d %d", &n, &q);
	
	s.resize(n);
	for(int i = 0; i < n; ++i)
		s[i] = false;
	

	for(int i = 0; i < q; ++i){
		for(int j = 0; j < 3; ++j)
			scanf("%d", &v[i][j]);

		int sum = 0;
		can.clear();
		for(int j = 0; j < n; ++j)
			if((not s[j]) or (s[j] and tf[j] < v[i][0])){
				can.push_back(j);
			}

		//for(auto v : can)
		//	cout << v << " ";
		//cout << endl;

		if(can.size() >= v[i][1]){
			//for(int j = 0; j < can.size(); ++j)
			 //	cout << can[j] << endl;

			for(int j = 0; j < v[i][1]; ++j){
				tf[can[j]] = v[i][0] + v[i][2] - 1;				
				sum += can[j]+1;
				//cout << can[j] + 1 << endl;
				s[can[j]] = true;
			}
			printf("%d\n", sum);
		}		
		else puts("-1");
	
	}


	return 0;
}
