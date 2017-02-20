#include <bits/stdc++.h>
using namespace std;
	
vector< vector<int> > solve;
vector<int> v;
int n;
	
void backtrack(int pos, vector<int>& p, int mask, int pf){

	if(pos == n){
		if(pf == 2) solve.push_back(p);		
		return;
	}
			
	for(int i = 0; i < n; ++i)
		if(((~mask)&(1<<i)) and pf+(pos==i) <= 2){
			p.push_back(i+1);
			backtrack(pos+1, p, mask|(1<<i), pf + (pos==i));
			p.pop_back();
		}
}

double ex2(double a){
	return a*a;
}

double dis(int x, int y){
	double r = 0;
	for(int i = 0; i < n; ++i)
		r += ex2(solve[x][i]-solve[y][i]);

	return sqrt(r);
}

int main(){

	scanf("%d", &n);
	backtrack(0, v, 0, 0);			

	double ans = 0;
	for(int i = 0; i < solve.size(); ++i)
		for(int j = i+1; j < solve.size(); ++j)
			ans += dis(i, j);

	printf("%.2lf\n", 2.0*ans);

	return 0;
}


