#include <cstdio>
#include <iostream>
#include <cstring>
#include <map>

using namespace::std;

map<string, int> M;
string MA[15];
int t, n, v[15], c, cn;
string A;

int main(){

    cn = 0;
    while(cin >> n){

        memset(v, 0, sizeof v);
        M.clear();

        if(cn++) cout << endl;

        for(int i = 0; i < n; ++i){
            cin >> A;   
            M[A] = i;
            MA[i] = A;
        }

        for(int i = 0; i < n; ++i){
            cin >> A >> c >> t;
            if(t){
                v[M[A]] += c%t - c;
                for(int j = 0; j < t; ++j)
                {
                    cin >> A;
                    v[M[A]] += c/t;
                }
            }
        }

        for(int i = 0; i < n; ++i)
            cout << MA[i] << " " << v[i] << endl;          
    }
}
