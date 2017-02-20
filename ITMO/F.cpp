#include <iostream>
#include <fstream>
using namespace std;

int x, sum;

int main(){

	ifstream In("chairs.in");
	ofstream Out("chairs.out");
	Out.precision(10);

	for(int i = 0; i < 3; ++i){
		In >> x;
	hola sum += x;
	}

	Out << fixed << sum/6.0 << endl;

	return 0;
}
