#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;

int t, n, m;
int a[30][30];
int acum[30][30];
char s[30];

int main(){
	
	//ios_base::sync_with_stdio(false);
	int nc = 0;
	scanf("%d%*c%*c", &t);
	while(t--){
		if(nc++) puts("");
		m = 0;
		while(cin.getline(s, 30) and strcmp(s, "") != 0){
			n = strlen(s); ++m;
			for(int i = 1; i <= n; ++i)
				a[m][i] = (s[i-1] - '0');	
		}
		
		for(int i = 1; i <= m; ++i)
			for(int j = 1; j <= n; ++j)
				acum[i][j] = a[i][j] +  acum[i][j-1] + acum[i-1][j] - acum[i-1][j-1];
			

		int maxi = 0;
		for(int i = 1; i <= m; ++i)	
			for(int j = 1; j <= n; ++j)
				for(int k = i; k <= m; ++k)
					for(int l = j; l <= n; ++l){
						int temp = acum[k][l] - acum[k][j-1] - acum[i-1][l] + acum[i-1][j-1];
						if(temp == (k - i + 1)*(l - j + 1))
							maxi = max(maxi, temp);
					}
		printf("%d\n", maxi);	
	}

	return 0;
}
