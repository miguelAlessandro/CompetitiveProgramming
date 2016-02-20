#include <bits/stdc++.h>
#define N 25
#define f(x, y, z) for(int x = y; x < z; ++x)

using namespace::std;

int t, n,
    di[8] = {0, -1, -1, -1, 0, 1, 1, 1},
    dj[8] = {1, 1, 0, -1, -1, -1, 0, 1};
string T[N];
vector<string> solve;

bool compare(const string& a, const string& b){
    return a.size() < b .size() || a.size() == b.size() && a < b;
}

int dfs(string& set, int s1, int s2, int times){

    if(times >= 3) solve.push_back(set);

    f(i, 0, 8){
        int a = s1 + di[i], b = s2 + dj[i];
        if(a >= 0 && b >= 0 && a < n && b < n && set[times-1] < T[a][b]){
            set.push_back(T[a][b]);
            dfs(set, a, b, times + 1);
            set.pop_back();
        }
    }
}

int main(){

    ios_base::sync_with_stdio(0);

    cin >> t;
    while(t--){
        solve.clear();

        cin >> n;
        f(i, 0, n) cin >> T[i];
        
        string S("");
        f(i, 0, n)
            f(j, 0, n){
                S.push_back(T[i][j]);
                dfs(S, i, j, 1);
                S.pop_back();
            }

        sort(solve.begin(), solve.end(), compare);        
        solve.resize(unique(solve.begin(), solve.end()) - solve.begin());
        
        f(i, 0, int(solve.size())) cout << solve[i] << '\n';   
        if(t) cout << '\n';
    }

    return 0;
}
