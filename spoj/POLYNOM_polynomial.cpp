#include <bits/stdc++.h>
using namespace std;

const int N = 505;
int t, n;
int x[N];

double L(double X){
   return x[1]*((X-2)*(X-3)*(X-4))/((1-2)*(1-3)*(1-4)) + x[2]*((X-1)*(X-3)*(X-4))/((2-1)*(2-3)*(2-4)) + 
          x[3]*((X-1)*(X-2)*(X-4))/((3-1)*(3-2)*(3-4)) + x[4]*((X-1)*(X-2)*(X-3))/((4-1)*(4-2)*(4-3));
}


int main(){
   
   scanf("%d", &t);
   while(t--){
      scanf("%d", &n);
      for(int i = 1; i <= n; ++i)
         scanf("%d", x+i);

      if(n <= 4) puts("YES");
      else{
         bool ok = 1;
         for(int i = 5; i <= n; ++i)
            if(abs(L(i) - x[i]) > 1e-8) 
               ok = false;           
         puts(ok ? "YES" : "NO");
      }
   }
   
   return 0;
}
