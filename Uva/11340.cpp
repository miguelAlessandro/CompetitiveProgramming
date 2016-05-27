#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 260;
int t, n, m;
int cost[N];


int main(){

    scanf("%d", &t);
    while(t--){
        memset(cost, 0, sizeof cost);
        scanf("%d%*c", &n);
        char a;
        for(int b, i = 0; i < n; ++i){
            scanf("%c%*c%d%*c", &a, &b);   
            cost[a] = b;
        }
        scanf("%d%*c", &m);
        int sum = 0;
        for(int c, i = 0, nl = 0; nl < m; ++i)
            if((c = getchar()) != '\n')
                sum += cost[c];
            else ++nl;
        printf("%.2f$\n", float(sum)/100);
    }

    return 0;
}
