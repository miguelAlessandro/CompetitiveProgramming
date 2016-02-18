#include <iostream>
#include <cstdio>
#define f(x, y, z) for(int x = y; x < z; ++x)

using namespace::std;

int n, k;

void recursive(int n, int floor){

    if( n == 1 && floor == 1)
        printf(" /\\");
    else if( n == 1 && floor == 2 )
        printf("/__\\");
    else{

        int t = 1<<(n-1);
        if(floor <= t)
        { 
            while(t--) putchar(' ');
            recursive(n-1, floor); 
        }
        else
        {
            recursive(n-1, floor - t);
            f(i, 0, 2*t - floor) putchar(' ');   
            recursive(n-1, floor - t);
        }
    }
}


int main(){
    
    while(scanf("%d", &n), n)
    {
        k = (1<<n);
        for(int i = 1; i <= k; ++i)
        {
            recursive(n, i);   
            puts("");
        }
        puts("");
    }

    return 0;
}
