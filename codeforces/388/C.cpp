#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <map>
#include <cstring>
#include <string>
#include <algorithm>
#include <list>
#include <set>
#include <climits>
using namespace std;

const int N = 200005;
int n;
bool a[N];
list<int> d, r;
list<int>::iterator it, jt;

int main(){

	int len = 0;
	scanf("%d%*c", &n);
	for(int i = 0; i < n; ++i){
		a[i] = (getchar() == 'D');
		if(a[i]) d.push_back(i), len++;
		else r.push_back(i);
	}	

	
	it = d.begin();
	jt = r.begin();	
	
	//cout << r.size() << endl;
	int lend = len, lenr = n-len;	
	int carryd, carryr;
	int supd = 0, supr = 0;
	carryd = carryr = 0;	

	while((not r.empty()) and (not d.empty())){
			
		if(carryr + *jt < carryd + *it){
			supd++;
			++jt;
			if(jt == r.end()){
				carryr += lend + lenr; 
				lenr -= supr;
				lend -= supd;
				jt = r.begin();
			}
			it = d.erase(it);
		} 		
		else{
			supr++;
			++it;
			if(it == d.end()){
				carryd += lend + lenr; 
				lenr -= supr;
				lend -= supd;
				it = d.begin();
			}
			jt = r.erase(jt);
		}

		//cout << *jt << endl;
		//cout << *it << endl;
		//for(aux = r.begin(); aux != r.end(); ++aux)
		//	cout << *aux << " ";
		//cout << endl;

	}

	if(not r.empty()) puts("R");
	else puts("D");


	return 0;
}
