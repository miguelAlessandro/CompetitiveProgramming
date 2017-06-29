#include <iostream>
#include <cstdio>
#include <climits>
#include <cstring>
using namespace std;

const int N = 32780;
int ft[N], x;

void update(int x, int v){
   while(x < N){
      ft[x] = max(ft[x], v);
      x += x&-x;
   }
}

int query(int x){
   int ans = INT_MIN;
   while(x > 0){
      ans = max(ans, ft[x]);
      x -= x&-x;
   }
   return ans;
}


int main(){

   int nc = 1;
   while(scanf("%d", &x), ~x){
      memset(ft, 0, sizeof ft);
      
      update(32779 - x, 1);
      
      while(scanf("%d", &x), ~x)
         update(32779 - x, query(32779 - x) + 1);            
      
      if(nc-1) puts("");

      printf("Test #%d:\n  maximum possible interceptions: %d\n", nc++, query(N-1));
   }

   return 0;
}
