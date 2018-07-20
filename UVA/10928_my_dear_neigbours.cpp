#include <iostream>
#include <cstdio>

using namespace::std;


int t, m, neighbours[1005], min_deg, nmin;
char c;

int main(){

    scanf("%d", &t);
    while(t--){
        scanf("%d%*c", &m);
        min_deg = 2000;
        for(int i = 1; i <= m; ++i){
            neighbours[i] = 1;
            while((c = getchar()) != '\n')
                if(c == ' ') ++neighbours[i];           
            if(min_deg > neighbours[i]){
                min_deg = neighbours[i];
                nmin = 1;
            }
            else if(min_deg == neighbours[i])
                ++nmin;
        }
        for(int i = 1; i <= m; ++i)
            if(neighbours[i] == min_deg){
                --nmin;
                printf("%d%c", i, (nmin == 0) ? '\n' : ' ');
            }
            else if(nmin == 0)
                break;
    }       
    

    return 0;
}
