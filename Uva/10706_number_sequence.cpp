#include <bits/stdc++.h>
using namespace std;

const int N = 31270;

long long sum[N];
string pos;
int t, n;

string toString(int n, long long& c){

    string r("");
    while(n) r += n%10 + 48, n /= 10, c += 1;
    reverse(r.begin(), r.end());
    return r;
}

bool proof(int mid){
    return sum[mid] < n;
}


int main(){

    long long aux = 0LL;
    for(int i = 1; i < N; ++i){
        pos.append(toString(i, aux));
        sum[i] = sum[i-1] + aux;
    }
        

    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        int low = 0, upper = N-1;
        while(low < upper){
            int mid = low + (upper - low +1)/2;
            if(proof(mid)) low = mid;
            else upper = mid-1;
        }
        printf("%c\n", pos[n - sum[low] -1]);   
    }

    return 0;
}
