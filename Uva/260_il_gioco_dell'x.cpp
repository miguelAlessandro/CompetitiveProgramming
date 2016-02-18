#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <map>
#include <complex>
#include <utility>
#include <iterator>
#include <sstream>
#include <string>
#include <cstring>
#include <cctype>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <bitset>
#include <unordered_map> //c++11
#include <unordered_set> //c++11
#define f(x, y, z)              for(int x = y; x < (int)z; ++x)
#define fd(x, y, z)             for(int x = y; x >= (int)z; --x)
#define fa(X, it)				for(auto& it : X) //c++11
#define fe(x, y, z)             for(int x = y; x <= (int)z; ++x)
#define FOR(A, it)              for(typename A.begin() it = A.begin(); it != A.end(); ++it)
#define CFOR(A, it)		for(typename A.cbegin() it = A.cbegin(); it != A.cend(); ++it) //c++11
#define RFOR(A, it)             for(typename A.rbegin(); it = A.rbegin(); it != A.rend(); ++it)
#define CRFOR(A, it)		for(typename A.crbegin() it = A.crbegin(); it != A.crend(); ++it) //c++11
#define all(V)                  V.begin(), V.end()
#define rall(V)                 V.rbegin(), V.rend()
#define UNIQUE(V)               (V).resize(unique(all(V)) - (V).begin()) 
#define sz(A)                   int((A).size())
#define present(A, x)           ((A).find(x) != (A).end())
#define cpresent(A, x)          (find(all(A), x) != (A).end())
#define pb                      push_back
#define pf						push_front
#define mp                      make_pair
#define fst                     first
#define snd                     second

//to memset
#define MAX_INFINITE            0x7f
#define MINUS_INFINITE          0x80
#define HALF_INFINITE           0x3f
#define INFINITE                0x2d
#define FAST_INFINITE           0x01
		
#define ones(X)                 __builtin_popcount(X)
#define NOsync                  ios_base::sync_with_stdio(0)
#define cua(X)                  ((X)*(X))
#define debug(X)                cout << #X << " = " << X << endl;
#define Adebug(X, n)            cout << #X << endl; f(i, 0, n) cout << X[i] << " \n"[i+1==n] //c++11
#define Mdebug(X, m, n)         cout << #X << endl; f(i, 0, m) f(j, 0, n) cout << X[i][j] << " \n"[j+1==n] //c++11
#define clr(A, x)               memset(A, x, sizeof A)
#define citor                   const_iterator //c++11
#define critor                  const_reverse_iterator //c++11
#define ritor                   reverse_iterator
    
using namespace::std;
    
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef map<int, int> mii;
typedef unordered_map<int, int> umii;
typedef map<string, int> msi;
typedef unordered_map<string, int> umsi;
typedef vector<ii> vii;
typedef pair<int, ii> iii;
typedef priority_queue<iii> pqiii;
typedef complex<double> point;

const int N = 205;
const double eps = (1e-9);
const double pi = 2.0f*acos(0.0f);
const int oo = (1 << 30);
const ll OO = (1LL << 60);

template<typename T> inline void MAXI(T& a, T b){if(a > b) a=b;}
template<typename T> inline void MINI(T& a, T b){if(a < b) a=b;}


int n, cn = 1,
    dx[6] = {0, -1, -1, 0, 1, 1}, 
    dy[6] = {-1, -1, 0, 1, 1, 0};
bool M[N][N], 
     visit[N][N], ok;
char A[N];

void dfs(int s1, int s2){
    visit[s1][s2] = true;
    f(i, 0, 6)
    {
        int a = s1 + dy[i], b = s2 + dx[i];
        if(a >= 0 && a < n && b >= 0 && b < n && M[a][b] && !visit[a][b])
            dfs(a, b);
    }
}


int main(){

    while(scanf("%d%*c", &n), n)
    {
        f(i, 0, n){
            fgets(A, N, stdin);       
            for(int j = 0; A[j] != '\0' && A[j] != ' '; ++j)
                M[i][j] = bool(A[j] == 'w');
        }
        
        clr(visit, 0x0);
        f(i, 0, n) if(M[i][0] && !visit[i][0]) dfs(i, 0);
    
        ok = false;
        f(i, 0, n)
            if(visit[i][n-1]){
                printf("%d W\n", cn++), ok = true;
                break;
            }
        if(!ok) printf("%d B\n", cn++); 
    }
   
    return 0;
}

