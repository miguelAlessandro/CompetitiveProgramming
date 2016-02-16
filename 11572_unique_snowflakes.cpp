#include <iostream>
#include <cstdio>
#include <map>

using namespace::std;

map<int, int> M;
int t, n, a, la, r;


int main(){

    scanf("%d", &t);
    while(t--){

        scanf("%d", &n);
        int block = 0, cont = 0, r = 0; 
        for(int i = 1; i <= n; i++){
            
            scanf("%d", &a);
            
            la = M[a];
            M[a] = i;
            
            if(la != 0){
                block = max(block, la);
                cont = i - block - 1;
            }

            cont++;
            r = max(r, cont);       
        }
        printf("%d\n", r);
        
        M.clear();
    }

    return 0;
}   


