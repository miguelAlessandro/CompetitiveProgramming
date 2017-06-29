#include <bits/stdc++.h>
using namespace std;

const int N = 10005;
int i, l;
bool vis[N];
vector<int> v;

bool bs(int n, int x, int l){

   int lo = 0, hi = n-1;
   int ans = 0;
   while(lo <= hi){
      int mid = (lo+hi)/2;
      ans += 1;   
      if(x == mid) return l == ans;
      if(x < mid) hi = mid-1;      
      else lo = mid+1;
   }
}


int main(){

   scanf("%d %d", &i, &l);
   for(int k = i+1; k <= 10000; ++k)
      vis[k] = bs(k, i, l);      

   for(int i = 1; i <= 10000; ++i)   
      if(vis[i]){
         if(vis[i-1])
            v.back() += 1;
         else{
            v.push_back(i);
            v.push_back(i);
         }
      }
      
   printf("%d\n", (int)v.size()/2);
   for(int i = 0; i < v.size(); i += 2)
      printf("%d %d\n", v[i], v[i+1]);
   

   return 0;
}
