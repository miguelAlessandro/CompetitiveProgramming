#include <iostream>
#include <string>
#include <algorithm>

using namespace::std;


string operator+(string& a, string& b){

	if(b == "No") return a;

	if(a == "+x") return b;
	
	if(a == "-x"){
		if(b[0] == '+') b[0] = '-'; 
		else b[0] = '+';
		return b;
	}

	if(a == "+y"){
		if(b[1] == 'z') return a;
		if(b[0] == '+') return "-x";
		else return "+x";
	}

	if(a == "-y"){
		if(b[1] == 'z') return a;
		if(b[0] == '+') return "+x";
		else return "-x";
	}
	
	if(a == "+z"){
		if(b[1] == 'y') return a;
		if(b[0] == '+') return "-x";
		else return "+x";
	}

	if(a == "-z"){
		if(b[1] == 'y') return a;
		if(b[0] == '+') return "+x";
		else return "-x";
	}
}


int main(){

	int n;		
	string r, A; 


	while(cin >> n, n){
	
		r = "+x";
		for(int i = 1; i < n; ++i){
			cin >> A;
			r = r + A;
		}
		
		cout << r << endl;
	}

	return 0;
}
