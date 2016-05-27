#include <iostream>
#include <cstdio>
#define N 300010

using namespace::std;

char S[N];
long long int suma = 0ll;

int main(){
    
    scanf("%[^\n]s", S);
    if(S[0]%4 == 0) suma++;
    for(int i = 1; S[i] != '\0'; ++i){
        if(((S[i-1] - '0')*10 + (S[i] - '0'))%4 == 0)
           suma += i;
        if((S[i])%4 == 0)
            suma++;
    }

    printf("%I64d\n", suma);

    return 0;
}
