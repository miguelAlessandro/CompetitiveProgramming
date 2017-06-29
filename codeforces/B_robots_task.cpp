#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int n, a[N];
bool vis[N];

int main(){

   scanf("%d", &n);
   
   for(int i = 1; i <= n; ++i)
      scanf("%d", a+i);

   int ans = -1;
   int time = 1;
   int b = 0;
   while(b < n){
      ans += 1;

      if(time&1)
         for(int i = 1; i <= n; ++i){
            if(not vis[i] and a[i] <= b){
               b += 1;
               vis[i] = 1;
            }
         }
      else
         for(int i = n; i >= 1; --i)
            if(not vis[i] and a[i] <= b){
               b += 1;
               vis[i] = 1;
            }   
      time += 1;
   }

   printf("%d\n", ans);

   return 0;
}
