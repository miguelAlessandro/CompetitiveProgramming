#include<bits/stdc++.h>
using namespace::std;

int n;
string s;

bool beauty(int pos, long long back, int len){
	if(pos == int(s.size())) return len > 1;
	
	long long x = 0;
	for(int i = pos; i < s.size(); ++i){
		x = 10*x + s[i] - '0';
		if(back+1== x)
			return beauty(i+1, x, len+1);		
	}
	return false;
}

int main(){
	
	cin >> n;
	while(n--){
		cin >> s;
		if(s[0] == '0'){
			puts("NO");
			continue;
		}
		bool ok = false;
		long long x = 0;
		for(int i = 0; i < s.size(); ++i){
			x = 10*x + s[i]-'0';
			if(beauty(i+1, x, 1)){
				ok = true;
				break;
			}
		}
		if(ok) printf("YES %lld\n", x);
		else puts("NO");
	}

	return 0;
}
