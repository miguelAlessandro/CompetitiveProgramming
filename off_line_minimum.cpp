#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

class dsu{
    private:
        const int N = 10000;
        int rank[N];
        int in[N];
        int n;
    public: 
        dsu(){}
        void init(int n){
            this->n = n;
            for(int i = 1; i <= n; ++i)
                rank[i] = 0, in[i] = i;
        }
        int find_set(int v){
            return v == in[v] ? v : in[v] = find_set(in[v]);
        }
        void union_set(int x, int y){
            int u = find_set(x), v = find_set(y);
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
