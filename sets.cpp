#include <iostream>
#include <cstdio>

using namespace std;

class dsu{    
    private:
        const int maxV = 100000;
        int in[N];
        int rank[N];
        int n;
        
        void init_set(const int n){
            for(int i = 0; i < n; ++i){
                in[i] = i;
                rank[i] = 0;
            }
        }

    public:
        dsu(int n){
            this->n = n;
            init_set(n);   
        }
        int find_set(int x){
            if(in[x] != x)
                in[x] = find_set(in[x]);
            return in[x];
        }

        void union_set(int x, int y){
            int u = find_set(x);
            int v = find_set(y);

            if(rank[u] > rank[v])
                in[v] = u;
            else{
                in[u] = v;
                if(rank[u] == rank[v])
                    rank[v] = rank[v] + 1;
            }       
        }
};


int main(){

    return 0;
}
