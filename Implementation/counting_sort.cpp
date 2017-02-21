#include <iostream>
using namespace std;

const int N = 1000005;
int c[N], a[N], b[N];

void counting_sort(int* a, int n, int k){
	//memset(c, 0, sizeof c);
	for(int i = 0; i < n; ++i) c[a[i]]++;
	for(int i = 1; i <= k; ++i) c[i] += c[i-1];
	for(int i = n-1; i >= 0; --i) b[c[a[i]]--] = a[i];
	for(int i = 0; i < n; ++i) a[i] = b[i];
}

int main(){

	return 0;
}
