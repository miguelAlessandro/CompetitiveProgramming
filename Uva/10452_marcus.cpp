#include <bits/stdc++.h>
#define N 10

using namespace::std;

typedef pair<int, int> ii;

const string S = "IEHOVA#";
int di[8] = {0, -1, 0},
    dj[8] = {1, 0, -1},
    n, m, t, s1, s2, f1, f2;
char M[N][N];
string line;
vector<ii> path;
ii padre[N][N];
bool visit[N][N];


void dfs(int s1, int s2, int times){

    visit[s1][s2] = true;
    if(times == 7)
        {f1 = s1; f2 = s2; return;}

    for(int i = 0; i < 3; ++i){
        int a = s1 + di[i], b = s2 + dj[i];
        if(a >= 0 && a < n && b >= 0 && b < m && !visit[a][b] && M[a][b] == S[times]){
            padre[a][b] = ii(s1, s2);  
            dfs(a, b, times + 1);
        }
    }
}

int main(){

    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &m);
        getline(cin, line);
        memset(visit, false, sizeof visit);       
        for(int i = 0; i < n; ++i){
            getline(cin, line);
            //cout << line << endl;
            for(int j = 0; j < m; ++j)
                if((M[i][j] = line[j]) == '@')
                    s1 = i, s2 = j;                   
            //getchar();
        }
        dfs(s1, s2, 0);
        
        ii s(s1, s2), v(f1, f2);
        while(s != v){
            path.push_back(v);
            v = padre[v.first][v.second];
        }
        for(vector<ii>::reverse_iterator it = path.rbegin(); it != path.rend(); ++it){
            if(s.first != it->first)
                printf("forth");
            else if(s.second == it->second + 1)
                printf("left");
            else
                printf("right");

            putchar((M[it->first][it->second] == '#' ? '\n' : ' '));
            s = *it;
        }
        path.clear();
    }

    return 0;
}
