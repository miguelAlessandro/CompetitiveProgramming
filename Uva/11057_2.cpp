#include <iostream>
#include <unordered_set>

using namespace std;

int n, m, diff;
unordered_multiset<int> S;
int r;

bool proof(int mid){
    if(S.find(mid) != S.end() and S.find(m - mid) != S.end() and m - 2*mid > diff)
        return true;
    return false;
}


int main(){

    while(scanf("%d", &n) == 1){
        for(int x, i = 1; i <= n; ++i){
            scanf("%d", &x);
            S.insert(x);
        }
        scanf("%d", &m);
        diff = m;
        if(!(m&1) and S.count(m/2) > 1)
            printf("Peter should buy books whose prices are %d and %d.\n\n", m>>1, m>>1);
        else{
            int low = m/2 + 1, upper = m;
            while(low < upper){
                int mid = low + (upper - low + 1)/2;
                if(proof(mid)) low = mid;
                else upper = mid - 1;
            }
            printf("Peter should buy books whose prices are %d and %d.\n\n", m-low, low);
        }
        S.clear();
    }

    return 0;
}
