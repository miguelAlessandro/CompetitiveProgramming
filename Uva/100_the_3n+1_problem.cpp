#include <iostream>
using namespace std;

int li, ri, l, r;
int max_cycle, n;

int main() {

    while(cin >> li >> ri){
        l = min(li, ri);
        r = max(li, ri);
        max_cycle = 0;
        for(int len, i = l; i <= r; ++i){
            len = 1;
            n = i;
            
            while(n != 1){
                if(n&1) n = 3*n+1;  
                else n /= 2;
                
                len++;
            }
            
            max_cycle = max(max_cycle, len);
        }
        
        cout << li << " " << ri << " " << max_cycle << endl;
    }

	return 0;
}
