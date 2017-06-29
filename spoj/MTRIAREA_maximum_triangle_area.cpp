#include <bits/stdc++.h>
using namespace std;

const int N = 50005;
int n, t;
struct data{
   long long x, y;
} P[N], H[N<<2];


long long cross(const data& O, const data& A, const data& B){
   return (A.x - O.x)*(B.y - O.y) - (A.y - O.y)*(B.x - O.x);
}

long long Area(const data& A, const data& B, const data& C){
   return abs(cross(A, B, C));
}

bool cmp(const data& A, const data& B){
   return A.x < B.x or A.x == B.x and A.y < B.y;
}

long long p(int a, int b){
   int lo = b+1, hi = t+a-1; 
   while(lo < hi){
      int mid = lo + (hi-lo)/2;
      if(Area(H[a], H[b], H[mid]) <= Area(H[a], H[b], H[mid+1])) lo = mid+1;
      else hi = mid;
   }
  
   int lo2 = a+1, hi2 = b-1;
   while(lo2 < hi2){
      int mid = lo2 + (hi2-lo2)/2;
      if(Area(H[a], H[b], H[mid]) <= Area(H[a], H[b], H[mid+1])) lo2 = mid+1;
      else hi2 = mid;
   }

   return max(Area(H[a], H[b], H[lo]), Area(H[a], H[b], H[lo2]));
}


int main(){

   while(scanf("%d", &n), ~n){
      for(int i = 0; i < n; ++i)   
         scanf("%lld %lld", &P[i].x, &P[i].y);

      sort(P, P+n, cmp);

      int t = 0;
      for(int i = 0; i < n; ++i){
         while(t >= 2 and cross(H[t-2], H[t-1], P[i]) <= 0) t--; 
         H[t++] = P[i];
      }

      int f = t+1;
      for(int i = n-2; i >= 0; --i){
         while(t >= f and cross(H[t-2], H[t-1], P[i]) <= 0) t--; 
         H[t++] = P[i];
      }

      if(H[0].x == H[t-1].x and H[0].y == H[t-1].y) t--;

      for(int i = 0; i < t; ++i)
         H[i+t] = H[i];

      long long ans = 0;
      for(int i = 0; i < t; ++i)
         for(int j = i+1; j < t; ++j)
            ans = max(ans, p(i, j));

      if(ans&1) printf("%lld.50\n", ans/2);
      else printf("%lld.00\n", ans/2);
   }

   return 0;
}
