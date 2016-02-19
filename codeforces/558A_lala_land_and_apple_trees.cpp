#include <bits/stdc++.h>
#define f(x, y, z) for(int x = y; x < z; x++)
#define FOR(A, i) for(typeof(A.begin()) it = A.begin(); it != A.end(); it++) 
#define N 100005
using namespace::std;

struct nodo{
    int v;
    unsigned int w;
    nodo() {}
    nodo(int vv, unsigned int ww): v(vv), w(ww) {}
};

unsigned short int n;
vector<nodo> A, B;
unsigned long long suma;

bool compare1(nodo p, nodo q)
{
    return p.v < q.v;
}

bool compare2(nodo p, nodo q)
{
    return p.v > q.v;
}

int main( void )
{
    scanf("%hu", &n);
    int a, b;
    f(i, 0, n)
    {
        scanf("%d %d", &a, &b);
        if(a > 0)
            A.push_back(nodo(a, b));
        else
            B.push_back(nodo(a, b));
    }
    sort(A.begin(), A.end(), compare1);
    sort(B.begin(), B.end(), compare2);
      
    if(A.size() > B.size())
    {
        for(vector<nodo>::iterator it = A.begin(); it != A.begin() + B.size() + 1; it++)
            suma += it->w;
        FOR(B, it)
            suma += it->w;
    }
    else if(B.size() > A.size())
    {
        for(vector<nodo>::iterator it = B.begin(); it != B.begin() + A.size() + 1; it++)
            suma += it->w;
        FOR(A, it)
            suma += it->w;
    }
    else
    {
        FOR(A, it) suma += it->w;
        FOR(B, it) suma += it->w;
    }

    cout << suma << endl;
    return 0;
}
