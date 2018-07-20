nclude <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 5;
int n, m, u, sq, nb;
long long A[N];
vector<long long> block[300];


void build(){
	sq = sqrt(n * log2(n)) + 1;
	nb = (n - 1)/sq + 1;

	for(int i = 0; i < nb; ++i)
		block[i].clear();

	for(int i = 0; i < n; ++i)
		block[i/sq].push_back(A[i]);

	for(int i = 0; i < nb; ++i)
		sort(block[i].begin(), block[i].end());
}

int query(int l, int r, int v){

	l -= 1;
	r -= 1;

	int nbl = l / sq;
	int nbr = r / sq;

	int ans = 0;
	if(nbl == nbr)
		for(int i = l; i <= r; ++i)
			ans += (A[i] < v);
	else{
		for(int i = l; i < (nbl+1)*sq; ++i)
			ans += (A[i] < v);

		for(int i = nbl+1; i < nbr; ++i){
			int lo = 0, hi = (int)block[i].size() - 1;
			while(lo < hi){
				int mid = lo + (hi-lo+1)/2;
				if(block[i][mid] < v) lo = mid;
				else hi = mid-1;
			}

			if(block[i][lo] < v)
				ans += lo + 1;
		}

		for(int i = nbr*sq; i <= r; ++i)
			ans += (A[i] < v);
	}
	return ans;
}


void update(int p, long long v){

	p -= 1;

	vector<long long> B;
	B.push_back(v);
	int bi = p / sq;

	for(int i = 0; i < block[bi].size(); ++i)
		if(block[bi][i] == A[p]){
			block[bi].erase(block[bi].begin() + i);
			break;
		}

	vector<long long> aux = block[bi];
	block[bi].push_back(0);
	merge(B.begin(), B.end(), aux.begin(), aux.end(), block[bi].begin());
	A[p] = v;
}


void solve(){

	scanf("%d %d %d", &n, &m, &u);
	for(int i = 0; i < n; ++i)
		scanf("%lld", A+i);

	build();

	for(int i = 0; i < m; ++i){
		int l, r, v, p;
		scanf("%d %d %d %d", &l, &r, &v, &p);

		update(p, 1ll*u*query(l, r, v) / (r - l + 1));
	}

	for(int i = 0; i < n; ++i)
		printf("%lld\n", A[i]);
}


int main(){

	solve();

	return 0;
}
