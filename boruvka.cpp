#include <iostream>
#include <cstdio>
using namespace std;

class dsu{
    private:
        const int N = 1000001;
        int in[N];
        int rank[N];
        int n, T;
    
    public:
        void init_set(int n){
            this->n = n; T = n;
            for(int i = 1; i <= n; ++i)
                in[i] = i, rank[i] = 0;
        }
        int find_set(int x){
            return x == in[x] ? x : in[x] = find_set(in[x]);
        }
        int union_set(int x, int y){
            int u = find_set(x), v = find_set(y);
            if(u != v){
                if(rank[u] > rank[v])
                    in[v] = u;
                else{
                    in[u] = v;
                    if(rank[u] == rank[v])
                        rank[v] = rank[v] + 1;
                }
                T = T - 1;
            }
            return T;
        }
};



int main(){

           

    return 0;
}
