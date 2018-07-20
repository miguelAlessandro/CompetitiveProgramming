#include <iostream>
#include <cstdio>
#include <utility>
#include <vector>
#include <climits>
#define N 505

using namespace::std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;


int n, t;
char query;
vector<int> M[N];


class segmentTree{
    public:
        vi stmin, stmax, A;
        int n;
        int left(int p){return p << 1;}
        int right(int p){return (p << 1) + 1;}

    int rmqmin(int p, int L, int R, int i, int j){
        if(i > R || j < L) return -1;
        if(L >= i && R <= j) return stmin[p];
    
        int p1 = rmqmin(left(p) , L          , (L+R)/2, i, j);
        int p2 = rmqmin(right(p), (L+R)/2 + 1, R      , i, j);

        if(p1 == -1) return p2;
        if(p2 == -1) return p1;
        return (A[p1] <= A[p2]) ? p1 : p2;
    }

    int rmqmax(int p, int L, int R, int i, int j){
        if(i > R || j < L) return -1;
        if(L >= i && R <= j) return stmax[p];

        int p1 = rmqmax(left(p), L, (L+R)/2, i, j);
        int p2 = rmqmax(right(p), (L+R)/2 + 1, R, i, j);

        if(p1 == -1) return p2;
        if(p2 == -1) return p1;
        return (A[p1] >= A[p2]) ? p1 : p2;
    }
        
    void build(int p, int L, int R){
        if(L == R){
            stmin[p] = L;
            stmax[p] = L;
        }
        else{
            build(left(p) , L           , (L+R)/2   );
            build(right(p), (L+R)/2 + 1 , R         );
            int p1 = stmin[left(p)], p2 = stmin[right(p)];
            int p3 = stmax[left(p)], p4 = stmax[right(p)];
            stmin[p] = (A[p1] <= A[p2])? p1 : p2;
            stmax[p] = (A[p3] >= A[p4])? p3 : p4;
        }
    }
    segmentTree(){}
};

segmentTree S[N];

int main(){

    scanf("%d", &n);
    
    for(int i = 0; i < n; ++i){
        M[i].resize(n);
        for(int j = 0; j < n; ++j)
            scanf("%d", &M[i][j]);
        S[i].A = M[i]; S[i].n = n;
        S[i].stmax.assign(4*n, 0);
        S[i].stmin.assign(4*n, 0);
        S[i].build(1, 0, n-1);
    }
    
    scanf("%d%*c", &t);
    int a, b, c, d, minimum, maximum;
    while(t--){
        scanf("%c", &query);
        if(query == 'c'){
            scanf("%d %d %d%*c", &a, &b, &c);
            S[a-1].stmax.clear();
            S[a-1].stmin.clear();
            M[a-1][b-1] = c;
            S[a-1].A = M[a-1];
            S[a-1].stmax.assign(4*n, 0);
            S[a-1].stmin.assign(4*n, 0);
            S[a-1].build(1, 0, n-1);
        }
        else{
            minimum = INT_MAX; maximum = INT_MIN;
            scanf("%d %d %d %d%*c", &a, &b, &c, &d);
            for(int i = a - 1; i < c; ++i){
                minimum = min(minimum, M[i][S[i].rmqmin(1, 0, n-1, b-1, d-1)]);
                maximum = max(maximum, M[i][S[i].rmqmax(1, 0, n-1, b-1, d-1)]);
            }
            printf("%d %d\n", maximum, minimum);
        }
    }
    return 0;
}
