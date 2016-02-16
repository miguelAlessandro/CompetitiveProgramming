#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
#define pii pair<int, int>

using namespace::std;

int n;

int main( void ){

    vector<pii> V;
    vector<int> W;    

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        V.push_back(make_pair(y, x));
    }

    W.resize(n);
    for(int i = 0; i < n; i++)
        cin >> W[i];

    sort(V.begin(), V.end());

    bool yes = true;
    for(int i = 0; i < n; i++)
        if(W[i] != V[i].first - V[i].second)
            yes = false;

    if(yes)
    {
        cout << "YES" << endl;
        for(int i = 0; i < n; i++)
            cout << V[i].second << " " << V[i].first << endl;
    }
    else
        cout << "NO" << endl;

    return 0;
}
