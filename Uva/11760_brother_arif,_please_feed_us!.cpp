#include <iostream>
#include <cstdio>
#include <cstring>

using namespace::std;

const short N = 10005;

bool row[N], col[N], ok;
short r, c, n, x, y;
const short di[5] = {0, -1, 0, 1, 0},
            dj[5] = {1, 0, -1, 0, 0};
int TC = 1;


int main(){

    while(scanf("%hd %hd %hd", &r, &c, &n), r+c+n){
        for(short i = 0; i < r; ++i) row[i] = false;
        for(short i = 0; i < c; ++i) col[i] = false;
        for(short i = 0; i < n; ++i){
            scanf("%hd %hd", &x, &y); 
            row[x] = col[y] = true;
        }
        scanf("%hd %hd", &x, &y);
        ok = false;
        for(short i = 0; i < 5; ++i){
            short a = x + di[i], b = y + dj[i];
            if(a >= 0 && a < r && b >= 0 && b < c && 
               !row[a] && !col[b])
                ok = true;
        }
        
        printf("Case %d: ", TC++);
        if(ok) puts("Escaped again! More 2D grid problems!"); 
        else puts("Party time! Let's find a restaurant!");
    }

    return 0;
}
