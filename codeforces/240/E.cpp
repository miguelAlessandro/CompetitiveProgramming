#include <iostream>
using namespace std;

const int N = 21;
int a[1<<N];
int b[1<<N];
int ft[1<<N];
int in[N], ex[N];
int n, m;

void merge(int l, int r, int floor){
	
	int mid = (l+r>>1)
	int inv = 0;

	for(int i = l; i <= r; ++i) b[i] = a[i];

	int lo = l, hi = mid+1;
	for(int i = l; i <= r; ++i)
		if(lo <= mid and hi <= r) 
			if(b[lo] <= b[hi]) a[i] = b[lo++];
			else a[i] = b[hi++], inv += mid - lo + 1; 
		else if(lo <= mid) a[i] = b[lo++];
		else a[i] = b[hi++];
}

void merge_sort(int l, int r, int floor){
	if(l >= r) return;

	int mid = (r+l>>1);
	merge_sort(l, mid, floor - 1);
	merge_sort(mid+1, r, floor - 1);	
	merge(l, r, floor);
}


int main(){

	scanf("%d", &n);	
	m = (1<<n);
	for(int i = 0; i < m; ++i)
		scanf("%d", a+i);

	

	for()	



	return 0;
}
