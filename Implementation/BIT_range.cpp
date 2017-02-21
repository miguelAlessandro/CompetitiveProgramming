#include <iostream>
#include <cstdio>
using namespace std;

class bit{
    
    private:
        const int N = 1000;
        long long ft_sum[N], ft_mul[N];
    public:
        void init(int n){
            memset(ft_sum, 0, sizeof ft_sum);
            memset(ft_add, 0, sizeof ft_add);
        }
        void update(int lo, int hi, long long v){
            update_range(lo, v, -v*(lo-1));
            update_range(hi, -v, v*hi);
        }
        void update_range(int x, long long mul, long long add){
            while(x <= N){
                ft_sum[x] += add;
                ft_mul[x] += mul;
                x -= x&-x;
            }
        }
        long long query(int x){
            long long mul = 0;
            long long add = 0;
            long long st = x;
            while(x){
                mul += ft_mul[x];
                add += ft_add[x];
                x -= x&-x;
            }
            return mul*st + add;
        }
};


int main(){

    

    return 0;
}
