#include <bits/stdc++.h>
using namespace std;

int c;
set<int> s;

int main(){

	while((c = getchar()) != '\n')
		s.insert(c);

	
	puts(int(s.size())&1 ? "IGNORE HIM!" : "CHAT WITH HER!"); 


	return 0;
}
