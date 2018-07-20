#include <iostream>
#include <cstdio>

using namespace std;

int n;
string A;

int main(){
    
    
    while(getline(cin, A), A != "0"){
        n = A.size();
        //printf("%d\n", n);
        int number, dec;
        //cout << A << endl;
        if(n&1){
            number = A[0] - '0';
            dec = (n-1)/2;
        }
        else{
            number = (A[0] - '0')*10 + A[1] - '0';
            dec = (n-2)/2;
        }
        //printf("%d\n", number);
        int i = 1;
        for(; i*i <= number; ++i); --i;
        printf("%d", i);
        for(int i = 0; i < dec; ++i)
            printf("0");
        puts("");
    }

    return 0;
}
