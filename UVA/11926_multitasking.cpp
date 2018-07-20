#include <iostream>
#include <cstdio>
#include <cstring>
#include <bitset>

const int N = 1000010;
using namespace::std;

bool v[N];
int t, n, m, a, b, c, d;

int main(){
    while(scanf("%d %d", &n, &m), n+m){
        bool ok = true;
        memset(v, false, sizeof v);
        while(n--){
            scanf("%d %d", &a, &b);
            if(ok){
                for(int i = a; i < b; ++i)
                    if(v[i]){
                        ok = false;
                        break;
                    }
                    else
                        v[i] = true;
            }
        }
        while(m--){
            scanf("%d %d %d", &a, &b, &c);
            if(ok){
                for(int j = a; j <= 1000000; j += c){
                    for(int i = j; i < j + b - a && i <= 1000000; ++i)
                        if(v[i]){
                            ok = false;
                            goto fin;
                        }
                        else v[i] = true;
                }
                fin:
                    ;
            }
        }
        if(ok)
            puts("NO CONFLICT");
        else
            puts("CONFLICT");
    }

    return 0;
}
