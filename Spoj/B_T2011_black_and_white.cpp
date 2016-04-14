#include <iostream>

using namespace::std;

string A, B;


int main(){
    while(cin >> A >> B, A != "*"){
        int size = A.size();
        int r = 0;
        bool d = A[0] == B[0];
        if(size == 1) r = (d ? 0 : 1);
        for(int i = 1; i < size; ++i){
            if((A[i] == B[i] or i == size-1) and not d) ++r;
            if(A[i] !=  B[i] and i == size-1 and d) ++r;
            d = A[i] ==  B[i];
        }
        cout << r << endl;
    }


    return 0;
}
