#include <iostream>
#include <cstdio>
using namespace std;

int h, m, s,
    h1, m1, s1, v, v1;
bool first = true;

int main(){

    float dis = 0.0f; 
    while(scanf("%d:%d:%d", &h, &m, &s) == 3){
        bool query = true;
        if(getchar() != '\n')
            scanf("%d", &v), query = false;
        
        if(not first)
            dis += (h-h1)*v1 + (m-m1)*v1/60.0f + (s-s1)*v1/3600.0f;
        h1 = h, m1 = m, s1 = s, v1 = v;

        if(query == true)
            printf("%02d:%02d:%02d %.2f km\n", h, m, s, dis);
        first = false;
    }
    

    return 0;
}
