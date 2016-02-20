#include <cstdio>

int t;


int phi(int n)
{
    int result = n;
    
    for (int i=2; i*i <= n; ++i)
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    
    if (n > 1)
        result -= result / n;
    
    return result;
}

int main( void )
{
    while(scanf("%d", &t) != EOF && t != 0)
        printf("%d\n", phi(t));


    return 0;
}
