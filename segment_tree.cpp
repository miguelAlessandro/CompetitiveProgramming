#include <bits/stdc++.h>
using namespace std;

class segment_tree{

	private:
		static const int N = 100000;
		int n, st[1<<N];
	public:
		void build(int n){
			for(int i = n-1; i>0; --i) 
				st[i] = st[i<<1] + st[i<<1|1];
		}

		void modify(int p, const int v){
			for(st[p+=n] = value; p > 1; p>>=1) 
				st[p>>1] = st[p] + st[p^1];
		}

};


int main(){

	return 0;
}
