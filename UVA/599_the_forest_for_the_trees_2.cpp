#include <iostream>
#include <cstdio>
#define N 27

using namespace::std;


bool in[N], edge[N]; 
int szin, szedge, Nedge, Nacorn, Ntree, t, c;

int main(){

    scanf("%d", &t);
    while(t--){
        szin = szedge = Nacorn = Ntree = Nedge = 0;
        for(int i = 0; i < 26; ++i) in[i] = edge[i] = false;

        while((c = getchar()) != '*') 
            if(isupper(c)) ++Nedge, edge[c - 'A'] = true;
        
        while(getchar() != '\n');
        while((c = getchar()) != '\n') 
            if(isupper(c)) in[c - 'A'] = true; 
    
        for(int i = 0; i < 26; ++i){
            if(in[i]) ++szin;
            if(edge[i]) ++szedge;
        }

        Nacorn = szin - szedge;
        Ntree = szedge - (Nedge>>1);
        printf("There are %d tree(s) and %d acorn(s).\n", Ntree, Nacorn);
    }

    return 0;
}
