#include <iostream>
#include <algorithm>
using namespace::std;

int t, n, m;

int main(){

    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i = 0; i < m; ++i)
        {
            if(i) cout << endl;
            for(int j = 1; j <= n; j++)
            {
                for(int k = 1; k <= j; k++)
                    cout << j;
                cout << endl;
            }
            for(int j = n-1; j >= 1; j--)
            {
                for(int k = 1; k <= j; k++)
                    cout << j;
                cout << endl;
            }
        }
        if(t) cout << endl;
        
    }

    return 0;
}
