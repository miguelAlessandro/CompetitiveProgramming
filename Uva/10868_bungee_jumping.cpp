#include <bits/stdc++.h>
using namespace std;

double k, l, s, w;

int main(){

   while(scanf("%lf %lf %lf %lf", &k, &l, &s, &w), k+l+s+w > 1e-8){

      if(s <= l){
         if(sqrt(2.0l*9.81l*s) > 10.0l) puts("Killed by the impact.");
         else puts("James Bond survives.");
      }
      else{
         double Et = w*9.81l*s;
         double Eemax = 0.5*k*(s-l)*(s-l);         
         
         if(Et < Eemax) puts("Stuck in the air.");
         else{
            if(sqrt(2.0l*(Et-Eemax)/w) > 10.0l) puts("Killed by the impact.");
            else puts("James Bond survives.");
         }
      }
   }

   return 0;
}
