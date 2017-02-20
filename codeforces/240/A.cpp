#include <iostream>
#include <cstring>
using namespace std;

const int N = 105;
bool light[N];
int var[N];
int n, m;

int main(){

	cin >> n >> m;

	memset(light, true, sizeof light);

	for(int x, i = 1; i <= m; ++i){
		cin >> x;
		
		for(int j = x; j <= n; ++j)	
			if(light[j]){
				light[j] = false;
				var[j] = x;
			}		
	}

	for(int i = 1; i <= n; ++i)
		cout << var[i] << " ";
	cout << endl;

	return 0;
}
