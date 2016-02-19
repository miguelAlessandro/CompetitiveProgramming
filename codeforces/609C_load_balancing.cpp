#include <bits/stdc++.h>

using namespace::std;

int n, suma = 0, result = 0;
vector<int> V;

int main( void ){
    
    cin >> n;

    V.resize(n);
    for(int i = 0; i < n; i++){
        cin >> V[i];
        suma += V[i];
    }

    sort(V.begin(), V.end());

    int medium = suma/n;
        
    int i;
    for( i = 0; i < n - suma%n && V[i] <= medium; i++)
        result += medium - V[i];
    medium++;
    for(; i < n && V[i] < medium; i++)
        result += medium - V[i];


    cout << result << endl;

    return 0;
}
