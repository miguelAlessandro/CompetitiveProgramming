#include <bits/stdc++.h>
using namespace std;

typedef pair<long long, long long> ii;
typedef pair< char, ii > cii;
vector< cii > event;

bool proof(long long mid){
    long long acum_leak = 0ll, gas = mid, back = 0ll, fuel = 0ll;   
    
    for(auto v : event){
        long long t = v.second.first - back;
        gas -= t*(fuel + 100*acum_leak);
        if(gas <= 0) return true;
        if(v.first == 'L') acum_leak += 1ll;
        else if(v.first == 'F') fuel = v.second.second;
        else if(v.first == 'M') acum_leak = 0ll;
        else if(v.first == 's') gas = mid;
        else if(v.first == 'G') return gas <= 0ll;
        back = v.second.first;
    }
}


int main(){

    long long d, f;
    string A, B;
    while(cin >> d >> A >> B >> f && d + f){
        event.push_back(cii(A[0], ii(d, f)));
        while(cin >> d >> A, A != "Goal"){
            if(A[0] == 'F') cin >> B >> f;
            else if(A == "Gas") cin >> A;
            event.push_back(cii(A[0], ii(d, f)));
        }
        event.push_back(cii('G', ii(d, 0)));

        long long lo = 0, hi = 1000000000000000ll;
        while(lo < hi){
            long long mid = lo + (hi-lo+1ll)/2ll;
            if(proof(mid)) lo = mid;
            else hi = mid-1ll;
        }
        printf("%.3f\n", lo/100.0f);
        event.clear();
    }

    return 0;
}
