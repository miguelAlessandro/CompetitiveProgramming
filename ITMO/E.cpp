#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
using namespace std;

int a[4][4];
double r;

int main(){

	ifstream In("team.in");
	ofstream Out("team.out");
	Out.precision(10);

	for(int i = 0; i < 3; ++i)
		for(int j = 0; j < 3; ++j)
			In >> a[i][j];

	for(int i = 0; i < 3; ++i)
		for(int j = 0; j < 3; ++j)
			for(int k = 0; k < 3; ++k)
				if(i == j or j == k or i == k) continue;
				else r = max(r, sqrt(a[0][i]*a[0][i] + a[1][j]*a[1][j] + a[2][k]*a[2][k]));
	Out << fixed << r << endl;			

	return 0;
}
