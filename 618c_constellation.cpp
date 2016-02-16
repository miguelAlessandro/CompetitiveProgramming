#include <bits/stdc++.h>
#define N 100005

using namespace::std;

int n;
long long a, b;
vector<complex<long long> > G;
int v[N];

bool compare(int a, int b){
    return G[a].real() < G[b].real() || G[a].real() == G[b].real() && G[a].imag() < G[b].imag();
}


int main(){

    ios_base::sync_with_stdio(0);

    cin >> n;

    for(int i = 0; i < n; ++i)
    {
        cin >> a >> b;
        G.push_back(complex<long long>(a, b));
        v[i] = i;
    }

    sort(v, v + n, compare);

    int i = 2;
    for(; i < n; ++i)
        if( (conj(G[v[i]] - G[v[0]])*(G[v[1]] - G[v[0]])).imag() != 0)
            break;        
 
    printf("%d %d %d\n",v[0]+1, v[1]+1, v[i]+1);

    return 0;
}
