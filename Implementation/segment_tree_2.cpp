#include <iostream>
using namespace std;


class segment_tree{
	public:
		static const int N = 1000000, M = 20;	
		int st[N][M];
		int n, m;

	private:
		void init(int nn, int mm){
			n = nn; m = mm;
			for(int i = 0;  i < n; ++i) st[i][0] = a[i];
			for(int j = 1; j <= m; ++j)
				for(int i = 0; i < n; ++i)
					st[i][j] = function(st[i][j-1], st[i+(1<<j-1)][j-1]);
		}

		void set(int i, const int v){
			st[i][0] = a[i] = v;
			for(int x, j = 1; j <= m; ++j){
				x = i-(i&((1<<j)-1));
				
			}	
		}

		
		int function(int x, int y){
			//...
			return x+y;
		}
};


int main(){

	return 0;
}
