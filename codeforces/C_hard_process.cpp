#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#define all(V) V.begin(), V.end()
using namespace std;


int n, k;
vector<int> r, s;
int main(){
    
    scanf("%d %d", &n, &k);
    r.resize(n+1); 
    
    for(int i = 1; i <= n; ++i)
        scanf("%d", &r[i]);
    s = r;

    r[0] = 1;
    for(int i = 1; i <= n; ++i)
        r[i] = r[i-1] + (s[i] == 0);

    
    vector<int>::iterator le, ri, lf, rf;
    int m = 2, mp, dis = 0, maxd = 0;
    while(true){
        le = lower_bound(all(r), m-1);
        ri = lower_bound(all(r), m+k);
        dis = (ri-le) - 1;
        if(maxd < dis){
            maxd = dis;
            mp = m;
        }
        if(ri == r.end()) break;
        m = m + 1;
    }

    printf("%d\n", maxd);
    for(int i = 1; i <= n; ++i)
        if(r[i] >= mp && r[i] <= mp + k - 1) printf("1 ");
        else printf("%d ", s[i]);
    printf("\n");

    return 0;
}
