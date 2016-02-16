#include <bits/stdc++.h>

using namespace::std;

vector<int> A;
map<int, int> M;
int n, m;

int main( void ){

    cin >> n >> m;
    
    A.resize(n);
    for(int i = 0; i < n; i++)
    {
        cin >> A[i];
        M[A[i]]++;
    }

    int suma = 0;
    for(int i = 0; i < n; i++)
    {
        M[A[i]]--;
        suma += n - i - 1 - M.find(A[i])->second;
    }
    cout << suma << endl;


    return 0;
}
