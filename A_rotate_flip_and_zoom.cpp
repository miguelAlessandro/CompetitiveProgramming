#include <iostream>

using namespace::std;

int n, m;
char M[105][105];
string A;

int main(void){
    
    cin >> n >> m;
    getline(cin, A);
    for(int i = m-1; i >= 0; --i)
    {
        getline(cin, A);
        for(int j = 0; j < A.length(); ++j)
            M[j][i] = A[j];
    }

    for(int i = 0; i < 2*n; i++)
    {
        for(int j = 2*m-1; j >= 0; --j)
            cout << M[i/2][j/2];
        cout << endl;
    }

    return 0;
}
