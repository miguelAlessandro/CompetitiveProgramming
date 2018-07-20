#include <cstdio>

long int t;


long int phi(long int n)
{
    if(n == 1) return 0;

    long int result = n;
    
    for (long int i=2; i*i <= n; ++i)
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
    while(scanf("%ld", &t) != EOF && t != 0)
        printf("%ld\n", phi(t));
	
    return 0;
}
