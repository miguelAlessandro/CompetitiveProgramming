#include <bits/stdc++.h>
#define f(x, y, z) for(int x = y; x < z; x++)
#define fd(x, y, z) for(int x = y; x >= z; x--)
#define pb push_back


using namespace::std;

int M[30];
deque<int> D;
int c;

string A;

int main( void ){

    cin >> A;

    f(i, 0, A.size()) M[A[i] - 'a']++;

    f(i, 0, 30)
        if(M[i] & 1)
            D.pb(i);
    

    while(D.size() > 1)
    {
        M[D.front()]++;   
        D.pop_back();
        D.pop_front();
    }


    f(i, 0, 30)
        f(j, 0, M[i]/2)
            cout << char(i + 'a');

    f(i, 0, D.size())
        cout << char(D.front() + 'a');

    fd(i, 29, 0)
        f(j, 0, M[i]/2)
            cout << char(i + 'a');

    cout << endl;

    return 0;
}
