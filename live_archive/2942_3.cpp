#include <bits/stdc++.h>   
using namespace std;

const int N = 3003;
int  nc = 0, n, lo, hi, mid, x;
struct point{
	int x, y, z;
};

vector<point> p(N);
vector<int> dp(N);

bool cmp(const point& p, const point& q){  
	return p.x < q.x;  
}  

int main(){
	  
	while(scanf("%d",&n) == 1){
		for(int i = 0; i < n; i++)
    		scanf("%*s %d %d %d", &p[i].x, &p[i].y, &p[i].z);  
          
    	sort(p.begin(), p.begin()+n, cmp);  
    	dp[n] = 0; 
    	for(int i = n-1; i >= 0; i--){   
        	lo = i+1, hi = n-1, mid = (lo+hi)>>1, x = p[i].x + p[i].y;  
        	while(lo < hi){ 
            	if(p[mid].x < x) lo = mid+1;  
            	else hi = mid;
				mid = (lo+hi)>>1; 
        	}    
			p[mid].x >= x ? lo = mid : lo = mid+1;
			dp[i] = max(dp[i+1], dp[lo] + p[i].z); 
    	}
		if(nc++) putchar('\n');  
        printf("%d\n", dp[0]);  
   	}
    return 0;  
}  
