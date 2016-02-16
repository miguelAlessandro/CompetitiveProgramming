#include <iostream>
#include <climits>
using namespace::std;

int n;
int V[105];

int main(){

    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> V[i];
    
    int r = INT_MAX;
    for(int i = 0; i < n; ++i){
        int d = V[i]*15, x;
        for(int j = 0; j < V[i]; ++j)
        {
            cin >> x;
            d += 5*x;
        }
        r = min(r, d);
    }
    cout << r << endl;
    return 0;
}
