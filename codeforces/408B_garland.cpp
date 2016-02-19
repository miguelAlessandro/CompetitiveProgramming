#include <iostream>
#define FOR(A, it) for(typeof A.begin() it = A.begin(); it != A.end(); ++it)

using namespace::std;

int A[30], B[30];

int main( void ){

    string C;
    getline(cin, C); FOR(C, it) A[*it - 'a']++;
    getline(cin, C); FOR(C, it) B[*it - 'a']++;

    int cont = 0;
    for(int i = 0; i < 26; i++)
        if(A[i] == 0 && B[i] > 0){
            cout << "-1" << endl;
            return 0;
        }
        else if(A[i] > 0 && B[i] > 0)
            cont += min(A[i], B[i]);
    
    cout << cont << endl;

    return 0;
}
