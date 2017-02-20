#include <bits/stdc++.h>
using namespace std;

const int N = 55;
int n;
int t;
string s;


int main(){

	cin >> n;
	int hi = 20000;
	bool ok = true;
	for(int i = 0; i < n; ++i){
		cin >> t >> s;
		
		if(s == "East" or s == "West"){
			 if(hi == 20000 or hi == 0){
				ok = false;
				break;
				}

			 continue;
		}

		if(s == "South"){
			if(hi - t < 0){
				ok = false;
				break;
			}
			hi -= t;
		} 
		else{
			if(hi + t > 20000){
				ok = false;
				break;
			}
			hi += t;
		}	
	}

	if(hi == 20000 and ok) puts("YES");
	else puts("NO");

	return 0;
}
