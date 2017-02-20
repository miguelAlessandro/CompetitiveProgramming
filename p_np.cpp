#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int t, p, n;
bool P[N], NP[N];
int cp, cnp;
vector<int> v;
string x;

int main(){

	cin >> t >> n >> p;
	cin >> x;
	for(int i = 0; i < p; ++i){
		cin >> x;
		if(x == "?") cp++;
		else P[atoi(x.c_str())] = true;
	}
	cin >> x;
	for(int i = 0; i < n; ++i){
		cin >> x;
		if(x == "?") cnp++;
		else NP[atoi(x.c_str())] = true;
	}
	
	for(int i = 1; i <= t; ++i)
		if(not NP[i] and not P[i]) 
			v.push_back(i);

	sort(v.begin(), v.end());
	long long lop = 0, lonp = 0, hip = 0, hinp = 0;
	for(int i = 0; i < v.size(); ++i){
		if(i < cp) lop += v[i];
		if(i < cnp) lonp += v[i];
		if(int(v.size()) - 1 - cp) hip += v[i];
		if(int(v.size()) - 1 - cnp) hinp += v[i];
	}
	

	for(int i = 1; i <= t; ++i){
		if(P[i]){
			lop += i;
			hip += i;
		}
		else{
			hinp += i;
			lonp += i;
		} 
	}

	cout << lop << " " << hip << endl;
	cout << lonp << " " << hinp << endl;

	return 0;
}
