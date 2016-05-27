#include <bits/stdc++.h>
#define N 100010


using namespace::std;

int n, m;
char S[N];

int main(){
    
    scanf("%d%*c%d%*c", &n, &m);
    scanf("%[^\n]s", S);
    int good_sum = 0;
    for(int i = 0; S[i] != '\0'; ++i)
        good_sum += max(S[i] - 'a', 'z' - S[i]);

    //puts(S);
    if(good_sum >= m){
        for(int i = 0, k = 0; S[i] != '\0'; ++i){ 
            if(S[i] - 'a' > 'z' - S[i]){
                k = min(S[i] - 'a', m);
                S[i] -= k;
                m -= k;
            }
            else{
                k = min('z' - S[i], m);
                S[i] += k;
                m -= k;
            }
        }
        puts(S);
    }
    else
        puts("-1");

    return 0;
}
