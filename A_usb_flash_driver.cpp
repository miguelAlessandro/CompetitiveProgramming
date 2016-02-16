#include <bits/stdc++.h>

using namespace::std;

int n, m;
priority_queue<int> Q;

int main( void ){

    cin >> n >> m;

    while(n--){
        int a;
        cin >> a;
        Q.push(a);
    }

    int i = 0;
    while(m > 0){
        m -= Q.top(); Q.pop();
        i++;
    }

    cout << i << endl;

    return 0;
}
