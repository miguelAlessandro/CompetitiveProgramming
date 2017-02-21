#include <iostream>
using namespace std;


int lower_bound(int lo, int hi){

	while(lo < hi){
		int mid = lo + (hi-lo)/2; 
		if(p(mi)) lo = mid+1;
		else hi = mid;
	}

	return lo;
}

int upper_bound(int lo, int hi){

	while(lo < hi){
		int mid = lo + (hi - lo + 1)/2;
		if(p(mid)) lo = mid;
		else hi = mid-1;
	}

	return lo;
}

double real_binary_search(double lo, double hi){

	for(int i = 0; i < 50; ++i){
		double mid = (lo + hi)/2.0;
		if(p(mid)) lo = mid;
		else hi = mid;
	}

	return lo;
}


int main(){

	return 0;
}
