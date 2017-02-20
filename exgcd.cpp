#include <iostream>
using namespace std;

struct point{
	int x, y, z;
};

point gcdex(int a, int b){
	if(b == 0) return {a, 1, 0};
	point q = gcdex(b, a%b);
	return {q.x, q.z, q.y - a/b*q.z};
}

int main(){

	cout << gcdex(4, 10).z << endl;

	return 0;
}
