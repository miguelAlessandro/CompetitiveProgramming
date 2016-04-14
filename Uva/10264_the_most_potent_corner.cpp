#include <iostream>
#include <cstdio>

using namespace::std;

int n, e,
    edge[1<<15],
    sum[1<<15], max_sum;

int main(){
    while(scanf("%d", &n) != EOF){
        e = 1<<n;
        for(int i = 0; i < e; ++i) 
            scanf("%d", edge + i);

        for(int i = 0; i < e; ++i){
            sum[i] = 0;
            for(int j = 0; j < n; ++j)
                sum[i] += edge[i ^ (1 << j)];
        }

        max_sum = 0;
        for(int i = 0; i < e; ++i)
            for(int j = 0; j < n; ++j)
                max_sum = max(max_sum, sum[i] + sum[i ^ (1 << j)]); 

        printf("%d\n", max_sum);
    }

    return 0;
}
