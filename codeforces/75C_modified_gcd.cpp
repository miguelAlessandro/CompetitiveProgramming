#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>

using namespace::std;

vector< pair<int, int> > euclid(int n){
    vector< pair<int, int> > f;
    for(int r = 1, i = 2; i*i <= n; i += r, r = 2)
        if(n%i == 0){
            f.push_back(make_pair(i, 0));
            while(n%i == 0){
                n /= i;
                f.back().second++;
            }
        }
    if(n != 1) f.push_back(make_pair(n, 1));
    
    return f;
}

void backtracking(vector<int>& solve, vector< pair<int, int> >& f, int in, int prod){
    if(in == f.size()){ solve.push_back(prod); return;}
    for(int i = 0; i <= f[in].second; ++i){
        backtracking(solve, f, in + 1, prod);
        prod *= f[in].first;
    }
}

int a, b, n;

int main(){

    scanf("%d %d", &a, &b);
    vector< pair<int, int> > Fa = euclid(a), 
                             Fb = euclid(b);

    vector<int> Sa, Sb;
    backtracking(Sa, Fa, 0, 1);
    backtracking(Sb, Fb, 0, 1);

    sort(Sb.begin(), Sb.end());

    vector<int> SaAndSb;
    for(auto it : Sa)
        if(binary_search(Sb.begin(), Sb.end(), it))
            SaAndSb.push_back(it);
                
    sort(SaAndSb.begin(), SaAndSb.end());

    scanf("%d", &n);
    for(int high, low, i = 1; i <= n; ++i){
        scanf("%d %d", &low, &high);
        int pos = (upper_bound(SaAndSb.begin(), SaAndSb.end(), high) - SaAndSb.begin()) - 1;
        
        if(SaAndSb[pos] < low) puts("-1");
        else printf("%d\n", SaAndSb[pos]);
    }

    return 0;
}


