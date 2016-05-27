#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
int n;
vector<long long> a, b;

class bit{
    private:
        long long ft[N];
    public:
        bit(){
            for(int i = 0; i < N; ++i) ft[i] = 0;
        }
        void update(int x, long long v){
            while(x < N){
                ft[x] += v;
                x += x&-x;
            }
        }
        long long query(int x){
            long long sum = 0;
            while(x>0){
                sum += ft[x];
                x -= x&-x;
            }
            return sum-1;
        }
};

int main(){

    bit inv;
    while(scanf("%d", &n) == 1){
        a.resize(n);
        for(int i = 0; i < n; ++i)
            scanf("%lld", &a[i]), scanf("%*[^\n ]s"); 
        b = a;
        sort(b.begin(), b.end());
        for(int i = 1; i <= n; ++i) inv.update(i, 1);
        long long r = 0;
        for(int i = 0; i < n; ++i){
            int lo = 0, hi = n-1;
            while(lo < hi){
                int mid = lo + (hi-lo+1)/2;
                if(b[mid] <= a[i]) lo = mid;
                else hi = mid-1;
            }
            r += inv.query(lo+1);
            inv.update(lo+1, -1);
        }

        printf("%lld\n", r);
    }

    return 0;
}
