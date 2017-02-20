#include <iostream>
#include <cstdio>
#include <algorithm>
#include <climits>
#include <vector>
#include <cstring>
#include <string>
#include <map>
#include <queue>
#include <set>
using namespace std;

const int N = 200005;
int a[N];
int n, k;
vector<int> vv, p;

int main(){

	scanf("%d %d", &n, &k);	

	int len = 0;
	for(int i = 0; i < n; ++i){
		scanf("%d", a+i);
		if(a[i] < 0){
			vv.push_back(i);
			len += 2;
			k -= 1;
		}
		
	}

//	cout << len << endl;

	int z = -1;
	if(vv.size() >= 1)
		z = n - 1 - vv.back();
 
	for(int i = 1; i < vv.size(); ++i)
		p.push_back(vv[i] - vv[i-1] - 1);

	sort(p.begin(), p.end());	

	int i = 0;
	while(i < p.size()){
		if(p[i] > k) break;
		
		k -= p[i];
		len -= 2;
		i++;
	}
	
	if(z != -1 and k >= z)
		len -= 1;

	if(k < 0) puts("-1");
	else printf("%d\n", len);

	return 0;
}
