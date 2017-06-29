#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;
int n, b, k, x;
int c[12];

int mul(long long a, long long b){
   return a*b%mod;
}

struct matrix{

   vector<vector<int> > at;
   int n;
   

   void Init(int nn){
      n = nn;
      at.resize(n, vector<int>(n, 0));
   }

   void Id(){
      for(int i = 0; i < n; ++i)
         for(int j = 0; j < n; ++j)
            at[i][j] = i==j;
   }

   matrix operator*(const matrix& X){
      matrix ans; ans.Init(n);
      for(int i = 0; i < n; ++i)   
         for(int j = 0; j < n; ++j){
            ans.at[i][j] = 0;
            for(int k = 0; k < n; ++k)
               ans.at[i][j] = (ans.at[i][j] + mul(at[i][k], X.at[k][j]))%mod; 
         }
      return ans;
   }
} dp;


matrix expf(matrix A, int T){
   matrix R; R.Init(A.n); R.Id();
   while(T){
      if(T&1) R = R*A;
      A = A*A;
      T >>= 1;
   }
   return R;
}  


int main(){

   scanf("%d %d %d %d", &n, &b, &k, &x);   

   for(int i = 0; i < n; ++i){
      int x;
      scanf("%d", &x);
      c[x] += 1;
   }

   dp.Init(x);

   for(int i = 0; i < x; ++i)
      for(int j = 0; j < x; ++j)
         for(int l = 1; l <= 9; ++l)
            if((10*j + l)%x == i) 
               dp.at[i][j] += c[l];
   
   dp = expf(dp, b);
   printf("%d\n", dp.at[k][0]);   

   return 0;
}
