#include <bits/stdc++.h>
#define N 10005

int c, n;
int D[N];
bool bandera;

int main( void ){

    while(scanf("%d: ", &n) != EOF && n != 0){


        for(int i = 0; i < n; i++)
        {
            scanf("%d", &c);
            D[c] = i;
        }

        bandera = true;

        for(int i = 1; i < (n + 2)/3; i++)
            for(int j = 0; j < n - 2*i; j++)
                if(D[j] < D[j+i] && D[j+i] < D[j+2*i]){

                    bandera = false;
                    goto fin;
                }

        fin:
        if(bandera)
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}
