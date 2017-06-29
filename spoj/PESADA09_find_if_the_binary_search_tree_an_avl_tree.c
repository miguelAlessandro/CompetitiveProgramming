#include <stdio.h>
#include <string.h>
#define N 205

int a[N], t, n;
int avl;

int dfs(int x){
   if(a[x] == -1) return 0;

   int L = dfs(2*x+1);
   int R = dfs(2*x+2);

   
   if((R-L >= 0 ? R-L : L-R) > 1) avl = 0;
      
   return (L > R ? L : R) +1;
}

int main(){

   scanf("%d", &t);
   while(t--){
      scanf("%d", &n);

      memset(a, -1, sizeof a);
      for(int i = 0; i < n; ++i)
         scanf("%d", a+i);      
      
      avl = 1;
      dfs(0);
      
      puts(avl ? "T" : "F");
   }

   return 0;
}
