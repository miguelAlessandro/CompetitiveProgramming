#include <iostream>
using namespace std;

string s;
int n;

int main(){

	cin >> s;
	n = s.size();

	if(n < 26){
		 cout << -1 << endl;
		return 0;
	}

	int l, r;
	int sum[30], sum27;
	bool ok = false;
	for(int i = 0; i+25 < n and not ok; ++i){
		for(int j = 0; j < 26; ++j)
			sum[j] = 0;
		sum27 = 0;
		for(int j = i; j < i+26; ++j)
			if(s[j] != '?') sum[s[j]-'A']+=1;
			else sum27 += 1;
		
		int sumt = 0;
		for(int j = 0; j < 26; ++j)
			if(sum[j] > 1);
			else sumt += sum[j];
	
		if(sumt + sum27 == 26){
			l = i; r = i + 25;
			ok = true;
			break;
		}
	}

	int h = 0, res[30];
	for(int i = 0; i < 26; ++i)
		if(not sum[i]) res[h++] = i;

	if(not ok){
		cout << -1 << endl;
		return 0;
	}

	for(int z = 0, i = 0; i < n; ++i)
		if(i >= l and i <= r and s[i] == '?')
			cout << char(res[z++] + 'A');			
		else if(s[i] == '?')
			cout << 'A';
		else
			cout << s[i];

	cout << endl;


	return 0;
}
