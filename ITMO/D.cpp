#include <iostream>
#include <fstream>
using namespace std;  

const int N = 103;
int a[N], b[N], c[N], n;
int sum, r;

int main() {

	ifstream In("prepare.in");
	ofstream Out("prepare.out");

    In >> n;
    for(int i = 0; i < n; ++i) In >> a[i];
	for(int i = 0; i < n; ++i) In >> b[i]; 
	for(int i = 0; i < n; ++i) c[i] = max(a[i], b[i]);
	for(int i = 0; i < n; ++i) sum += c[i];
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j){
			if(i == j) continue;
			r = max(r, sum - c[i] + a[i] - c[j] + b[j]);	
		}

	Out << r << endl;

    return 0;
}
