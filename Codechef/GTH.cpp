#include <bits/stdc++.h>
using namespace std;


string name, pos;
int t, gn[30], r;


int main(){
	
	cin >> t;
	while(t--){
		memset(gn, 0, sizeof gn);		

		cin >> name >> pos;
		for(char it : pos)
			gn[it-'a'] += 1;
		
		r = 0;
		for(int i = 0; i < 26; ++i)
			r ^= gn[i];

		if(not r) 
			if(name[0] == 'V') name[0] = 'T'; 
			else name[0] = 'V';

		cout << name << endl;
	}	


	return 0;
}
