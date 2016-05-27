#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <utility>

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

        bool same_set(int x, int y){
            return find_set(x) == find_set(y);
        }
};

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
priority_queue< iii, vector<iii>, greater<iii> > Q;
int n, m;

void kruskal(){
    while(not Q.empty()){
        iii q = Q.top(); Q.pop();
        int u = q.second.first, v = q.second.second;
        if(not same_set(u, v))
            union_set(u, v);
    }
}


int main(){
    
    scanf("%d %d", &n, &m);
    for(int u, v, w, i = 0; i < m; ++i){
        scanf("%d %d %d", &u, &v, &w);
        Q.push(iii(w, ii(u, v)));
    }

    return 0;
}



