#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

using namespace::std;

int main(){

    int n, x;
    vector<int> v;
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    for(int i = 0; i + 2 < int(v.size()); ++i)
        if(v[i] + 1 == v[i+1] && v[i] + 2 == v[i + 2]){
            cout << "YES" << endl;
            return 0;
        }
    cout << "NO" << endl;

    return 0;
}
