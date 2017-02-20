#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
char s[N];
int R[N], len;
long long r;
stack<int> low;

long long cuenta(int l){

	if(R[l]-l+1 == 2) return 0;	

	long long sum = 0;
	for(int x, i = l+1; i < R[l]; i = R[i] + 1){
		x = 1 + cuenta(i);
		r += (x*sum)*(R[l]-l+1);
		sum += x;
	}

	return sum;
}

int main(){

	scanf("%s", s);
	len = strlen(s);
	for(int i = 0; i < len; ++i)
		if(s[i] == '(') low.push(i);
		else{
			R[low.top()] = i;
			low.pop();
		}

	cuenta(0);	
	printf("%lld\n", r);

	return 0;
}
