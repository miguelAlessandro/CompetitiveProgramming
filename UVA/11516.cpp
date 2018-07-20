#include <bits/stdc++.h>

using namespace std;

int t, n, m;
int v[100000 + 5];

bool proof(int a){
    int t = 1, p = v[1];
    for(int i = 2; i <= m; ++i) if(v[i] > p + a)  
        p = v[i], ++t;
    return t > n;
}

int main(){

    scanf("%d", &t);
    while(t--){
        scanf("%d%*c%d", &n, &m);
        for(int i = 1; i <= m; ++i)
            scanf("%d", v + i);
        sort(v+1, v + m+1);

        int low = 0, upper = 2*(v[m] - v[1] + 1);
        while(low < upper){
            int mid = (upper + low)/2;
            if(proof(mid)) low = mid + 1;
            else upper = mid;
        }
        printf("%.1f\n", low/2.0);
    }

    return 0;
}
