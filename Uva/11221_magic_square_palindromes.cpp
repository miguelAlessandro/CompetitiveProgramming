#include <iostream>
#include <cstdio>

using namespace::std;

int t, m[10005], l;
char c;

int main(){
    
    scanf("%d%*c", &t);
    for(int i = 1; i <= t; ++i){
        l = 0;
        while((c = getchar()) != '\n') if(c >= 'a' && c <= 'z') m[l++] = c - 'a';
        int sqrtl = 1;
        bool ok = true;
        for(; sqrtl*sqrtl < l; ++sqrtl);
        for(int j = 0; j < sqrtl && ok; ++j)
            for(int k = 0; k < sqrtl && ok; ++k){
                if(m[j*sqrtl + k] != m[(sqrtl - j)*sqrtl - 1 - k])           
                    ok = false;
                if(m[k*sqrtl + j] != m[(sqrtl - k)*sqrtl - 1 - j])
                    ok = false;
            }
        if(ok && sqrtl*sqrtl == l)
            printf("Case #%d:\n%d\n", i, sqrtl);
        else
            printf("Case #%d:\nNo magic :(\n", i);
    }

    return 0;
}
