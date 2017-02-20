#include <bits/stdc++.h>
using namespace std;

const int N = 1000000;
class knuth{
	private:
		int L[N], R[N], 
			U[N], D[N],
			C[N], S[N], 
			O[N], Ch[N], Rh[N];		
		int h, size; 		
	public:
		void init(const int m){
			size = 0;
			h = new_node(0, 0, 0, 0);
			for(int i = 1; i <= m; ++i)
				new_node(i, i, L[h], h),
				Ch[i] = i, s[i] = 0; 
		}
		int new_node(int up, int dow, int left, int right){
			U[size] = up; D[size] = down;
			L[size] = left; R[size] = right;
			D[up] = U[down] = R[left] = L[right] = size; 
			return size++;
		}
		void new_row(int n, int a[], int rh, int set){
			int r = a[0];
			int row = new_node(U[Ch[r]], Ch[r], size, size);
			Rh[row] = rh;
			for(int i = 1; i < n; ++i){ r = a[i];
				Ch[size] = r; C[size] = set; S[r]++;
				Rh[new_node(U[Ch[r]], Ch[r], L[row], row)] = rh;
			}			
		}
		void dfs(int k){
			if(R[h] == h) return;

			int t = INT_MAX, c; //heuristic
			for(int i = R[h]; i != h; i = R[i])
				if(s[i] < t) t = s[i], c = i;
			
			uncover(c);
			for(int i = D[c]; i != c; i = D[i]){
				O[k] = i;
				for(int j = R[i]; j != i; j = R[j]) uncover(Ch[j]);
				dfs(k+1);
				for(int j = L[i]; j != i; j = L[j]) cover(Ch[j]);
			}
			cover(c);
		}
		void uncover(const int x){
			L[R[x]] = L[x];
			R[L[x]] = R[x];
			for(int i = 0; D[x]; i != x; i = D[i])
				for(int j = R[i]; j != i; j = R[j])
					U[D[j]] = U[j],
					D[U[j]] = D[j],
					S[Ch[j]] -= 1;
		}
		void cover(const int x){
			for(int i = D[x]; i != x; i = D[i])
				for(int j = L[i]; j != i; j = L[j])	
					U[D[j]] = j,
					D[U[j]] = j,
					S[Ch[j]] += 1;
			L[R[x]] = x;
			R[L[x]] = x;
		}
		void print(int k){
			static int set[512];
			for(int i = 0; i < k; ++i)
				set[C[O[i]]] = Rh[O[i]]+1;
			for(int i = 0; i < n; ++i)
				for(int j = 0; j < n; ++j)
					putchar(set[a*16+b]+'A'-1);
			putchar('\n');
		}
};


int main(){

	char g[20][20];
	int map[20][20], r[256];
	while(scanf("%s", g[0]) == 1){
		

	}


	return 0;
}
