#include <bits/stdc++.h>
using namespace std;

int t;
int x, y, z;

int main(){

   scanf("%d", &t);
   while(t--){
      scanf("%d %d %d", &x, &y, &z);
      if(2*x < y) puts("0");
      else if(x >= 2*y) printf("%d\n", z);
      else printf("%d\n", z*(2*x-y)/(x+y));
   }

   return 0;
}
