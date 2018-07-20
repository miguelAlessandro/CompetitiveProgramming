#include <cstdio>
#include <algorithm>
#define long long ll
 
using namespace std;
 
int main ( void )
{
    int  a,
		 b;
 
    while ( scanf ("%d %d", &a, &b) != EOF ) 
	{
 
        int tempa = a,
        	tempb = b;
 
        if ( a > b ) swap (a, b);
 
        int max_c = 0, c_l;
 
        while ( a <= b ) {
            unsigned n = a;
            c_l = 1;
 
            while ( n != 1 ) {
                if ( n % 2 == 1 ) n = 3 * n + 1;
                else n >>= 1;
                c_l++;
            }
 			
            if ( c_l > max_c )
                max_c = c_l;
 
            a++;
        }
 
        printf ("%d %d %d\n", tempa, tempb, max_c);
    }
 
    return 0;
}
