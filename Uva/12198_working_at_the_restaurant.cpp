#include <bits/stdc++.h>
using namespace std;

const int N = 30;
int n, x;
char s[N];

int main(){

   int nc = 0;   
   while(scanf("%d", &n), n){

      if(nc++) puts("");

      int p1=0, p2=0;
      while(n--){
         scanf("%s %d\n", s, &x);
         if(s[0] == 'D'){
            printf("DROP 2 %d\n", x);
            p2 += x;
         }
         else{
            if(p1 < x){
               if(p1){
                  printf("TAKE 1 %d\n", p1);
                  x -= p1;
                  p1 = 0;
               }
      
               printf("MOVE 2->1 %d\n", p2);
               p1 = p2;
               p2 = 0;
            }

            if(x){
               printf("TAKE 1 %d\n", x);
               p1 -= x;
            }
         }
      }
   }

   return 0;
}
