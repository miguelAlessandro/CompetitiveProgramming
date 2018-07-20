#include <iostream>
using namespace std;

const int N = 200005;
int n, m;
int A[N];

class bit{
    
    private:
        int ft[N];
        int n;
    public:
        void init(int n){
            this->n = n;
            for(int i = 1; i <= n; ++i) ft[i] = 0;
        }
        void update(int x, int v){
            while(x <= n){
                ft[x] += v;
                x += x&-x;
            }
        }
        long long query(int x){
            long long sum = 0;
            while(x > 0){
                       
            }
        }
};

int main(){

    while(scanf("%d %d", &n, &m) == 2){
        for(int i = 0; i < n; ++i)
            scanf("%d", A+i);

    }

    return 0;
}
