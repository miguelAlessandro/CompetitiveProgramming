#include <iostream>
using namespace std;


int main(){

	int lo = 0; hi = 1000000000;
	while(lo < hi){
		int mid = lo + (hi-lo+1)/2;
		if(proof(mid)) lo = mid;
		else lo = mid-1;
	}

	return 0;
}
