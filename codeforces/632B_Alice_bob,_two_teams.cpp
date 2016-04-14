#include <iostream>
#include <cstdio>

using namespace::std;

const int N = 500005;
int p[N], n;
long long suma, max_left, max_right, sum_left, sum_right;
bool s[N];

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
        scanf("%d%*c", p + i);
    for(int i = 0; i < n; ++i)
        s[i] = (getchar() == 'B');
    
    for(int i = 0; i < n; ++i)
        if(s[i]) suma += p[i];
    
    sum_left = max_left = suma;
    for(int i = 0; i < n; ++i){
        if(s[i]) sum_left -= p[i];
        else sum_left += p[i];
        max_left = max(max_left, sum_left);
    }

    sum_right = max_right = suma;
    for(int i = n-1; i >= 0; --i){
        if(s[i]) sum_right -= p[i];
        else sum_right += p[i];
        max_right = max(max_right, sum_right);
    }

    printf("%I64d\n", max(max_right, max_left));

    return 0;
}









