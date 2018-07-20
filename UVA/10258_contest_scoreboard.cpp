#include <bits/stdc++.h>
#define N 105

using namespace::std;

string A;
int t, 
    a, b, c,
    pr[N], ta[N];

bool pra[N][20];

vector<pair<int, pair<int, int> > > Sorted;
bool participantes[N];
int pendiente[N][20];

char d;

int main( void ){

    cin >> t;
    getline(cin, A);
    getline(cin, A);
    while(t--)
    {
        getline(cin, A);
     
        while(A.length() > 0){
        
            stringstream(A) >> a >> b >> c >> d;
            a--;
            participantes[a] = true;
            if(d == 'I')
                pendiente[a][b]++;
            else if(d == 'C' && !pra[a][b])
            {
                pr[a]++;
                ta[a] += pendiente[a][b]*20 + c;
                pra[a][b] = true;
            }
            getline(cin, A);
        }
     
        for(int i = 0; i < N; i++)
            if(participantes[i] || pr[i] > 0)
            {
                pair<int, pair<int, int> > p(9-pr[i], pair<int, int>(ta[i], i));
                Sorted.push_back(p);
            }

        sort(Sorted.begin(), Sorted.end());

        for(int i = 0; i < Sorted.size(); i++)
            cout << Sorted[i].second.second + 1 << " " << 9 - Sorted[i].first << " " << Sorted[i].second.first << endl;

        if(t) cout << endl;
        Sorted.clear();
        memset(pr, 0, sizeof pr);
        memset(ta, 0, sizeof ta);
        memset(participantes, false, sizeof participantes);
        memset(pra, false, sizeof pra);
        memset(pendiente, 0, sizeof pendiente);
    }

    return 0;
}
