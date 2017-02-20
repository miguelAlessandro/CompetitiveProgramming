#include <iostream>
using namespace std;

string s;

bool vocal(char c){
	return (c == 'A' || c == 'E' || c == 'I' || c == 'O'  || c == 'U' || c == 'Y');
}

int main(){

	cin >> s;
	int len = 0;
	int prev = 0;
	for(int i = 0; i < s.size(); ++i)
		if(vocal(s[i])){
			len = max(len, i+1 - prev);
			prev = i+1;
		}	
	len = max(len, (int)s.size()+1 - prev);


	cout << len << endl;

	return 0;
}
