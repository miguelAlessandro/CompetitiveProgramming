#include <iostream>

using namespace::std;

string A, B;

int main(){
    
    cin >> A >> B;
    int t = 0, sz = A.size();
    for(int i = 0; i < sz; ++i){
        int a = tolower(A[i]), 
            b = tolower(B[i]);
        if(a > b){
            t = 1;
            break;
        }
        else if(a < b){
            t = -1;
            break;
        }
    }

    cout << t << endl;

    return 0;
}
