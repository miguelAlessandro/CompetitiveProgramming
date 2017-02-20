#include<bits/stdc++.h>
using namespace::std;

long long n,m,s;

int main(){
	int q;
	cin >> q;
	while(q--){
		cin >> n >> m >> s;
		if(n == m+1) cout << s << endl;
		else{
			long long ans = LONG_LONG_MAX;
			long long faltan = m - n + 1;
			long long vm, vM, v, u, y, l2, x;
            for(long long x=1; x<n-1; x++){
			    for(long long l1=1; l1<=s/(n-1)+1; l1++){
				    y = n-1-x;
				    v = x+1;
				    u = y;
                    l2 = (s - x*l1)/y;
                    if(l2<l1 || (s-x*l1)%y!=0) continue;
				    vm = (v*(v-1))/2 - x;
				    vM = (u*(u-1))/2 - y;
				    if(faltan <= vm){
					   ans = min(ans,y*l2 + (m-y)*l1);
				    }
				    else{
					   ans = min(ans,x*l1+vm*l1+y*l2+(m-x-vm-y)*l2);
				    }
			    }
            }
			cout << ans << endl;
		}
	}
	return 0;
}
