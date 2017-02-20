#include <iostream>
using namespace std;

int n;
string s;

int main(){

	cin >> n;
	cin >> s;
	for(int i = 0; i < n; ++i){
		if(i+2 < n and s[i] == 'o' and s[i+1] == 'g' and s[i+2] == 'o'){
			int j = i+3;
			while(j+1 < n and s[j] == 'g' and s[j+1] == 'o') j += 2;
			i = j-1;
			cout << "***"; 
		}
		else cout << s[i];
	}
	cout << endl;

	return 0;
}
