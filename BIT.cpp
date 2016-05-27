#include <iostream>
using namespace std;

class bit{
    
    private:
        const int N = 100001;
        int ft[2*N], n;
    public:
        bit(){}
        void init(int n){
            this->n = n;
            memset(ft, 0, sizeof f);
        }
        int query(int p){
            int sum = 0;
            while(p > 0){
                sum += ft[p];
                p -= p&~p;
            }
            return sum;
        }
        void update(int i, int x){
            while(i <= n){
                ft[i] += v;
                i += i&~i;
            }
        }
};


int main(){


    return 0;
}
