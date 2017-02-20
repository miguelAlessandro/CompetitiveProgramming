#include <bits/stdc++.h>
using namespace std;

const int N = 500005;
int n, xr, yr;
vector< pair<int, int> > R, B, Q;  
int minN, maxS, minE, maxO;
bool a01, a02, a11, a12, a2, a3;
vector<pair<int, char> > D1, D2;


int main(){

	scanf("%d%*c", &n);
	scanf("%d %d%*c", &xr, &yr);
	for(int c, x, y, i = 0; i < n; ++i){
		c = getchar();
		scanf("%d %d%*c", &x, &y);
		//cout << char(c) << " " << x  << " " << y << endl;
		if(c == 'R') R.push_back({x, y});
		if(c == 'B') B.push_back({x, y});
		if(c == 'Q') Q.push_back({x, y});
	}

	minN = INT_MAX;
	maxS = INT_MIN;
	minE = INT_MAX;
	maxO = INT_MIN;
	for(int i = 0; i < R.size(); ++i)
		if(R[i].first == xr){
			if(R[i].second > yr) minN = min(minN, R[i].second), a01 = true;
			if(R[i].second < yr) maxS =	max(maxS, R[i].second), a02 = true;
		} 
		else if(R[i].second == yr){
			if(R[i].first > xr) minE = min(minE, R[i].first), a11 = true;
			if(R[i].first < xr) maxO = max(maxO, R[i].first), a12 = true;
		}

	for(int i = 0; i < Q.size(); ++i)
		if(Q[i].first == xr){
			if(Q[i].second > yr) minN = min(minN, Q[i].second), a01 = true;
			if(Q[i].second < yr) maxS =	max(maxS, Q[i].second), a02 = true;
		} 
		else if(Q[i].second == yr){
			if(Q[i].first > xr) minE = min(minE, Q[i].first), a11 = true;
			if(Q[i].first < xr) maxO = max(maxO, Q[i].first), a12 = true;
		}

	
	for(int i = 0; i < B.size(); ++i)
		if(B[i].first == xr){
			if(B[i].second > yr and minN > B[i].second) a01 = false;
			if(B[i].second < yr and maxS < B[i].second) a02 = false;
		} 
		else if(B[i].second == yr){
			if(B[i].first > xr and minE > B[i].first) a11 = false;
			if(B[i].first < xr and maxO < B[i].first) a12 = false;
		}

	
	for(int i = 0; i < B.size(); ++i)
		if(B[i].first + B[i].second == xr + yr) D1.push_back({B[i].second, 'B'});
		else if(B[i].first - B[i].second == xr - yr) D2.push_back({B[i].first, 'B'});

	for(int i = 0; i < Q.size(); ++i)
		if(Q[i].first + Q[i].second == xr + yr) D1.push_back({Q[i].second, 'Q'});
		else if(Q[i].first - Q[i].second == xr - yr) D2.push_back({Q[i].first, 'Q'});


	for(int i = 0; i < R.size(); ++i)
		if(R[i].first + R[i].second == xr + yr) D1.push_back({R[i].second, 'R'});
		else if(R[i].first - R[i].second == xr - yr) D2.push_back({R[i].first, 'R'});


	sort(D1.begin(), D1.end());
	sort(D2.begin(), D2.end());

	if(not D1.empty() and D1[0].first > yr) a2 = D1[0].second != 'R'; 
	if(not D1.empty() and D1[D1.size() - 1].first < yr) a2 = D1[D1.size() - 1].second != 'R';

	for(int i = 0; i+1 < D1.size(); ++i)
		if(D1[i].first < yr and D1[i+1].first > yr){
			if(D1[i].second == 'R' and D1[i+1].second == 'R') a2 = false;
			else a2 = true;
			break;
		}

	if(not D2.empty() and D2[0].first > xr) a3 = D2[0].second != 'R'; 
	if(not D2.empty() and D2[D2.size() - 1].first < xr) a3 = D2[D2.size() - 1].second != 'R';
	
	for(int i = 0; i+1 < D2.size(); ++i)
		if(D2[i].first < xr and D2[i+1].first > xr){
			if(D2[i].second == 'R' and D2[i+1].second == 'R') a3 = false;
			else a3 = true;
			break;
		}	

	puts((a01 or a02 or a11 or a12 or a2 or a3 )? "YES" : "NO");

	return 0;
}
