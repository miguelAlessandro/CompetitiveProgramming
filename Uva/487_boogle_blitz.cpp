#include <bits/stdc++.h>
#define f(x, y, z) for(int x = y; x < z; ++x)
using namespace::std;

const int N = 22;
int t, n,
    di[8] = {0, -1, -1, -1, 0, 1, 1, 1},
    dj[8] = {1, 1, 0, -1, -1, -1, 0, 1};
char T[N][N];
vector<string> solve;

bool compare(const string& a, const string& b){
    return a.size() < b .size() || a.size() == b.size() && a < b;
}

int dfs(string& set, int s1, int s2){

    if(set.size() >= 3) solve.push_back(set);

    f(i, 0, 8){
        int a = s1 + di[i], b = s2 + dj[i];
        if(a >= 0 && b >= 0 && a < n && b < n && set.back() < T[a][b]){
            set.push_back(T[a][b]);
            dfs(set, a, b);
            set.pop_back();
        }
    }
}

int main(){

    scanf("%d", &t);
    while(t--){
        solve.clear();

        scanf("%d", &n);
        f(i, 0, n) scanf("%s", T[i]);
        
        string S("");
        f(i, 0, n)
            f(j, 0, n){
                S.push_back(T[i][j]);
                dfs(S, i, j);
                S.pop_back();
            }

        sort(solve.begin(), solve.end(), compare);        
        solve.resize(unique(solve.begin(), solve.end()) - solve.begin());
        
        f(i, 0, int(solve.size())) puts(solve[i].c_str());   
        if(t) putchar('\n');
    }

    return 0;
}
