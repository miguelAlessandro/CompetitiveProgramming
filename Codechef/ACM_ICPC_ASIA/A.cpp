#include <iostream>
#include <cstdio>
using namespace std;

int t, n, k;

int main(){

	cin >> t;
	while(t--){
		cin >> n >> k;
		puts(k%3 ? "yes" : "no");
	}

	return 0;
}
