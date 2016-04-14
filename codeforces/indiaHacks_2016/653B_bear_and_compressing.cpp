#include <iostream>
#include <cstdio>
#include <vector>

using namespace::std;

const int N  = 1000000;

int n, q;
bool visit[N];
vector<int> graph[10];
char a, b, c;


void dfs(vector<int> v, int& times){
    if(int(v.size()) == n){
        int numero = 0;
        for(int i = 0, d = 1; i < int(v.size()); ++i){
            numero += v[i]*d;
            d *= 10;
        }
        if(not visit[numero]){
            ++times;
            visit[numero] = true;
        }
        return;
    }

    int father = v[int(v.size()) - 1];
    v.pop_back();
    for(int i = 0; i < int(graph[father].size()); ++i){  
        int s = graph[father][i];
        v.push_back(s%10);
        v.push_back(s/10);
        dfs(v, times);
        v.pop_back();
        v.pop_back();
    }
}


int main(){
    
    scanf("%d %d%*c", &n, &q);
    for(int i = 0; i < q; ++i){
        scanf("%c%c%*c%c", &a, &b, &c);
        graph[c - 'a' + 1].push_back(10*(a - 'a' + 1) + (b - 'a' + 1));
        getchar();
    }   
    vector<int> v;
    v.push_back(1);
    int solve = 0;
    dfs(v, solve);
    printf("%d\n", solve);

    return 0;
}
