#include <iostream>
using namespace std;


bool comp(const string& p, const string& q){
	return p.size() < q.size() or p.size() == q.size() and p < q;
}

const int N  = 105;
int n, k;
string s;
int len[N], psw;

int main(){

	cin >> n >> k;	
	for(int i = 0; i < n; ++i){
		cin >> s;
		len[s.size()] += 1;
	}

	
	cin >> s;
	psw = s.size();

	int acum1 = 0, acum2 = 0;
	int lo = 0;
	while(lo < psw)
		acum1 += len[lo++];

	acum2 = acum1 + len[psw] - 1;
	acum1 += acum1/k*5;
	acum2 += acum2/k*5;
	
	cout << acum1 + 1 << " " << acum2 + 1 << endl;

	return 0;
}
