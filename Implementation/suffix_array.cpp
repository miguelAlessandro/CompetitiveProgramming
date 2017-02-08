#include <bits/stdc++.h> 
using namespace std;

const int N = (1<<20)+1;
const int LN = 20;
int P[LN][N], n;
string A;

struct Point{
  int x, y, p;
  bool operator<(const Point& p){return x < p.x or x == p.x and y < p.y;}
  bool operator==(const Point& p){return x == p.x and y == p.y;}
} L[N];

int main(){
 
    cin >> A;
  
    n = A.size();
    for(int i = 0; i < n; ++i) 
        P[0][i] = A[i] - 'a';
        
    for(int i = 0; (1<<i) < 2*n; ++i){
        for (int j = 0; i < n; ++j){
            L[j].x = P[i-1][j];
            L[j].y = j+(1<<i) < n ? P[i-1][j+(1<<i)] : -1;
            L[j].p = j; 
        }
        sort(L, L+n);      
        P[i][L[0].p] = 0;
        for(int j = 1; j < n; ++j) 
            P[i][L[j].p] = L[j] == L[j-1] ? P[i][L[j-1].p] : j;
     } 
      
     return 0;
}
