#include <iostream>
#include <cstdio>
using namespace::std;

long long a, b, c;

int main(){
    
    scanf("%I64d %I64d %I64d", &a, &b, &c);
    printf("%I64d\n", min((a+b+c)/3, min(a+b, min(b+c, a+c))));
    return 0;
}
