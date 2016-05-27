#include <bits/stdc++.h>

using namespace std;

vector<int> a, b;
int n, m;

int main(){

    scanf("%d %d", &n, &m);
    a.resize(n); b.resize(m);
    for(int i = 0; i < n; ++i) scanf("%d", &a[i]);
    for(int j = 0; j < m; ++j) scanf("%d", &b[j]);

    sort(a.begin(), a.end());

    for(int i = 0; i < int(b.size()); ++i){
        int low = 0, upper = n-1;
        while(low < upper){
            int mid = low + (upper - low + 1)/2;
            if(a[mid] <= b[i]) low = mid;
            else upper = mid - 1;
        }
        a[low] <= b[i] ? printf("%d ", low + 1) : printf("0 ");
    }
    puts("");

    return 0;
}
