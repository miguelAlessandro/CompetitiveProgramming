#include <bits/stdc++.h>
using namespace std;


const long double PI = 3.1415926535897932384626F;
int t, p, x, y;


int main(){

	scanf("%d", &t);
	for(int i = 1; i <= t; ++i){
		scanf("%d %d %d", &p, &y, &x);
		
		x -= 50;
		y -= 50;

		printf("Case #%d: ", i);

		if(p == 0) puts("white");
		else if(x*x + y*y > 2500) puts("white");
		else if(x == 0){
			if(y == 0){
				if(p == 0) puts("white");
				else puts("black");
			} 
			else if(y > 0){
				if(p < 25) puts("white");
				else puts("black");
			}
			else{
				if(p < 75) puts("white");
				else puts("black");
			}
		}
		else{
			if(y == 0){
				if(x > 0){
					if(p == 0) puts("white");
					else puts("black");
				}
				else{
					if(p < 50) puts("white");
					else puts("black");
				}
			}
			else if(x > 0){

				if(y > 0){
					if(p >= 25) puts("black");
					else{
						if(y <= x*tan(p*PI/50)) puts("black");
						else puts("white"); 
					}
				}
				else{
					if(p <= 75) puts("white");
					else{
						if(x*abs(tan((p - 50)*PI/50)) <= abs(y)) puts("black");
						else puts("white");
					}
				}
			}
			else{
				if(y > 0){
					if(p <= 25) puts("white");
					else if(p >= 50) puts("black");
					else{
						if(abs(x*tan(p*PI/50)) <= y) puts("black");
						else puts("white");
					}
				}
				else{
					if(p <= 50) puts("white");					
					else if(p >= 75) puts("black");
					else{
						if(abs(x)*tan((p-50)*PI/50) >= abs(y)) puts("black");
						else puts("white");
					}
				}
			}
		}
	}


	return 0;
}	
