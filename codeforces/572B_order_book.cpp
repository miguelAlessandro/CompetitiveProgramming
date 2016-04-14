#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <utility>
#define FOR(A, it) for(typeof A.begin() it = A.begin(); it != A.end(); ++it)

using namespace::std;

map<int, int , greater<int> > S, B;
vector<pair<int, int> > Sell, Buy;
char c;
int a, b;
int n, m;

int main(){
    
    scanf("%d %d%*c", &n, &m);
    for(int i = 0; i < n; ++i){
        scanf("%c %d %d%*c", &c, &a, &b);
        if(c == 'B')
            B[a] += b;
        else
            S[a] += b;
    }   
    Buy.resize(B.size());
    int i = 0;
    FOR(B, it)  Buy[i++] = *it;
    
    Sell.resize(S.size());
    i = 0;
    FOR(S, it) Sell[i++] = *it;
        
    partial_sort(Buy.begin(), Buy.begin() + min(m, (int)Buy.size()), Buy.end(), greater<pair<int, int> >());
    partial_sort(Sell.begin(), Sell.begin() + min(m, (int)Sell.size()), Sell.end(), less<pair<int, int> >());

    for(int i = min(m, (int)Sell.size()) - 1; i >= 0; --i)
        printf("S %d %d\n", Sell[i].first, Sell[i].second);
    for(int i = 0; i < min(m, (int)Buy.size()); ++i)
        printf("B %d %d\n", Buy[i].first, Buy[i].second);

    return 0;
}
