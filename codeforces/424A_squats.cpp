#include <bits/stdc++.h>

using namespace::std;



int main(void){

    int n, pa = 0, pi = 0;
    vector<char> v;
    char a;
    int k;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a;
        v.push_back(a);   
        if(a == 'X')
            pi++;
    }

    if(pi == n - pi){
        cout << 0 << endl;

        for(int i = 0; i < n; i++)
           cout << v[i];
    }
    else if(pi > n - pi)
    {
        k = abs(pi - n/2);
        cout << k << endl;
        for(int i = 0; i < n; i++)
            if(v[i] == 'X' && k > 0)
                    cout << 'x', k--;
            else
                cout << v[i];
    }
    else
    {
        k = abs( n/2 - pi);
        cout << k << endl;
        for(int i = 0; i < n; i++)
            if(v[i] == 'x' && k > 0)
                cout << 'X', k--;
            else
                cout << v[i];
    }
    cout << endl;

    return 0;
}
