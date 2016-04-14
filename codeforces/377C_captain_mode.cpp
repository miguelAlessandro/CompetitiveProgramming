#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace::std;

int query[25], q, x,
    heroes[105], n;

int main(){

    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
        scanf("%d", heroes + i);

    scanf("%d%*c", &q);
    for(int i = 0; i < q; ++i)
        if(getchar() == 'p'){
            scanf("%d%*c", &x);
            query[i] = (1<<x) - 1;
        }
        else{
            scanf("%d%*c", &x);
            query[i] = (1<<x);
        }
    
    bool condicion = (query[0] <= 2);
    int inicio = 0, fin = 1;
    for(int i = 1; i < q; ++i){
        if((query[i] <= 2) != condicion){
            sort(query + inicio, query + fin);        
            condicion ^= true; 
            inicio = fin;
        }
        ++fin;
    }
    sort(query + inicio, query + fin);

    sort(heroes, heroes + n, greater<int>());
    int teamA = 0, teamB = 0;   
    for(int i = 0; i < q; ++i)
        if(query[i] == 1)
            teamA += heroes[i];
        else if(query[i] == 3)
            teamB += heroes[i];

    printf("%d\n", teamA - teamB);

    return 0;
}
