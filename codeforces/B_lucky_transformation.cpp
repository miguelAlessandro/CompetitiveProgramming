#include <bits/stdc++.h>
using namespace std;

int n, k;
string s;

int main(){

   cin >> n >> k >> s;

   for(int i = 0; i+1 < n; ++i){
      if(k == 0) break;
      if(s[i] == '4' and s[i+1] == '7'){
         if(i&1){
            if(s[i-1] == '4'){
               if(k&1) s[i] = '7';
               k = 0;
            }
            else{
               k -= 1;
               s[i] = '7';
            }
         }     
         else{
            k -= 1;
            s[i+1] = '4';
         }
      }
    }


   cout << s << endl;

   return 0;
}
