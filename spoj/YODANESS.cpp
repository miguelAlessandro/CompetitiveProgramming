#include <bits/stdc++.h>
using namespace std;
const int N = 30005;
int n, t;
map<string, int> m;
string x;

class BIT{
	private:
		int ft[N];
		int n;
	public:
		void init(const int m){
			this->n = m;
			memset(ft, 0, sizeof ft);
		}
		
		void update(int x, const int v = 1){
			while(x <= n){
				ft[x] += v;
				x += x&(-x);
			}
		}
			
		int query(int x){
			int sum = 0;
			while(x > 0){
				sum += ft[x];
				x -= x&(-x);		
			}
			return sum;
		}		
} bit;


int main(){

	cin >> t;
	while(t--){
		m.clear();
		cin >> n;
		bit.init(n);
		for(int i = 1; i <= n; ++i){
			cin >> x;	
			m[x] = i;
		}
		
		long long ninv = n*1LL*(n-1)/2;
		for(int i = 1; i <= n; ++i){
			cin >> x;
			int k = m[x];
			ninv -= bit.query(k);
			bit.update(k);
		}
		cout << ninv << endl;
	}	

	return 0;
}
