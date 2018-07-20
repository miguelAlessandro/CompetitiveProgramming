#include <bits/stdc++.h>
using namespace::std;

const int N = 22,
    di[8] = {0, -1, -1, -1, 0, 1, 1, 1},
    dj[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int t, n;
char T[N][N];
string S;
vector<string> solve;

bool compare(const string& a, const string& b){
    return a.size() < b .size() || a.size() == b.size() && a < b;
}

int dfs(string& set, int s1, int s2){

    if(set.size() >= 3) solve.push_back(set);

    for(int i = 0; i < 8; ++i){
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
        for(int i = 0; i < n; ++i) scanf("%s", T[i]);
        
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j){
                S.push_back(T[i][j]);
                dfs(S, i, j);
                S.pop_back();
            }

        sort(solve.begin(), solve.end(), compare);        
        solve.resize(unique(solve.begin(), solve.end()) - solve.begin());
        
        for(int i = 0; i < solve.size(); ++i) puts(solve[i].c_str());   
        if(t) putchar('\n');
    }

    return 0;
}
