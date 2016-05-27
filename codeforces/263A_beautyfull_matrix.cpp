#include <iostream>
#include <cstdio>
#define ABS(X) (((X) >= 0) ? (X) : (-X))

using namespace::std;

int main(){

    for(int i = 0; i < 5; ++i)
        for(int j = 0; j < 5; ++j){
            if(getchar() == '1'){
                printf("%d\n", ABS(2 - i) + ABS(2 - j));
                return 0;
            }
            getchar();
        }
    
    return 0;
}
