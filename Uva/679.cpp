#include <bits/stdc++.h>
using namespace std;

int n, D, I;


int main(){
    
    scanf("%d", &n);
    while(n--){
        scanf("%d %d", &D, &I);
        int r = 1;
        for(int i = 1; i < D; ++i, I = (I+1)/2){
            if(not (I&1)){
                r = r*2 + 1;
            }
            else{

                r = r*2;   
            }
        }
        printf("%d\n", r);
    }

    return 0;
}
