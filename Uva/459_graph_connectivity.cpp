#include <cstdio>
#include <cstring>
#define debug(x) printf("%d\n", x)

using namespace::std;

bool visit[30], graph[30][30];
int t, n, cont;
char A[10];

void dfs(int source){

    visit[source] = true;
    for(int i = 0; i < n; ++i)
        if(graph[source][i] && !visit[i])
            dfs(i);

}


int main(){

    scanf("%d%*c%*c", &t);
    
    while(t--){
    
        fgets(A, 10, stdin);
        n = A[0] - 'A' + 1;

        while(fgets(A, 10, stdin) != NULL && strlen(A) == 3)
            graph[A[0] - 'A'][A[1] - 'A'] = graph[A[1] - 'A'][A[0] - 'A'] = true;
       
        for(int i = 0; i < n; ++i)   
            if(!visit[i])
                dfs(i), ++cont;

        printf("%d\n", cont);
        if(t) puts("");

        cont = 0;
        memset(graph, 0, sizeof graph);
        memset(visit, 0, sizeof visit);
    }

    return 0;
}
