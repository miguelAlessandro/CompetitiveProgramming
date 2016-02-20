#include <bits/stdc++.h>
#define f(x, y, z) for(int x = y; x < z; x++)
#define fd(x, y, z) for(int x = y; x >= z; x--)
#define FOR(A, X) for(typeof A.begin() X = A.begin(); X != A.end(); X++)
#define all(A) A.begin(), A.end()
#define pb push_back


using namespace::std;

struct nodo{
    int v, w;

    nodo() {}
    nodo(int vv, int ww): v(vv), w(ww) {}
};

int n;
vector<int> V;
multimap<int, nodo> M;
multimap<int, nodo>::iterator it, l, u;


int main( void )
{
    while( scanf("%d", &n) != EOF && n != 0)
    {
        V.reserve(n);
        f(i, 0, n)
            scanf("%d", &V[i]);
     
        sort(all(V));

        f(i, 0, n)
            f(j, i + 1, n)
                if(V[i] != V[j])
                    M.insert(make_pair(V[i] + V[j], nodo(V[i], V[j])));

        int minimum = INT_MIN;
        fd(i, n-1, 0)
            fd(j, i - 1, 0)
                if(V[i] > minimum && M.find(V[i] - V[j]) != M.end() && V[i] != V[j])
                {
                    l = M.lower_bound(V[i] - V[j]);                        
                    u = M.upper_bound(V[i] - V[j]);
                    while(l != u)
                    {
                        if(l->second.v != V[i] && l->second.v != V[j] &&
                           l->second.w != V[i] && l->second.w != V[j]) 
                            minimum = V[i];
                        l++;
                    }

                }

        
        if(minimum != INT_MIN)
            printf("%d\n", minimum);
        else
            printf("no solution\n");
        
        V.clear();
        M.clear();
    }

    return 0;
}
