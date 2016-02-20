#include <iostream>
#include <climits>
#include <cstdio>
#define N 200010

using namespace::std;

int t, n,
    p[N];
    

int main( void ){
    
    scanf("%d", &t);
    for(int j = 1; j <= t; j++){
        scanf("%d", &n);

        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &p[i]); 
            p[n + i] = p[i];
        }

        for(int i = 1; i <= n; i++)
        {   
            int a;
            scanf("%d", &a);
            p[i] -= a;
            p[n+i] -= a;
        }


        p[0] = 0;
        for(int i = 1; i <= 2*n; i++)
            p[i] += p[i-1];


        int k = 0, l = 1, r = 0;
        for(int i = 0; i <= 2*n; i++)
            if(p[i] >= l){
                if(++k > n) break;
            }
            else
            {
                l = p[i];
                r = i;
                k = 0;
                if(i >= n) break;
            }
        
        if(k > n)
            printf("Case %d: Possible from station %d\n", j, r + 1);
        else
            printf("Case %d: Not possible\n", j);
    }

    return 0;
}












