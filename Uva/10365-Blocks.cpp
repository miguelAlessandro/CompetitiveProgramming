#include <bits/stdc++.h>
#define eps 1e-16

using namespace::std;

unsigned int t;
unsigned int n;
unsigned int suma;

int main( void )
{
    scanf("%u", &t);
    while(t--)
    {
        scanf("%u", &n);
        

        if(n == 0)
            printf("0\n");
        else
        {
            suma = (1<<30);
            for(int i = 1; i*i <= n; i++)
            {
                if(n%i == 0)
                    for(int j = 1; j*j <= (n/i); j++)
                        if((n/i)%j == 0)
                            suma = min(suma, i*j + n/(i*j)*j + n/(j*i)*i);
            }
            printf("%d\n", 2*suma);
        }
    }

    return 0;
}
