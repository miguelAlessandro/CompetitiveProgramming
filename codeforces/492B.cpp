#include <bits/stdc++.h>

using namespace std;

int n, l;
int v[1005];

int main(){

    scanf("%d %d", &n, &l);
    for(int i = 0; i < n; ++i)
        scanf("%d", v + i);

    sort(v, v +  n);
    int d = max(2*v[0], 2*(l - v[n-1]));
    
    for(int i = 1; i < n; ++i) 
        d = max(d, v[i] - v[i-1]);
    
    
    printf("%.10f\n", double(d)/2);;

    return 0;
}
