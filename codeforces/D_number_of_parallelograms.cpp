#include <iostream>
#include <cstdio>
#include <utility>
#include <vector>
#include <map>
#define mp make_pair
using namespace std;

typedef pair<int, int> ii;
map<ii, int> MP;
vector<ii> P;
int n;

int main(){

    scanf("%d", &n);
    for(int x, y, i = 1; i <= n; ++i){
        scanf("%d %d", &x, &y);
        P.push_back(mp(x, y));
    }
    
    for(int i = 0; i < n; ++i)
        for(int j = i + 1; j < n; ++j)
            MP[mp(P[i].first + P[j].first, P[i].second + P[j].second)]++;

    int sum = 0;
    for(auto it : MP)
       sum += it.second*(it.second - 1)/2; 

    printf("%d\n", sum);

    return 0;
}
