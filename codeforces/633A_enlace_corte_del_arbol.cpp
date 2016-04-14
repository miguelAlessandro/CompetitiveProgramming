#include <bits/stdc++.h>

using namespace::std;
unsigned long long l, r;
int k;
vector<unsigned long long> v;
int main(){
                     
        cin >> l >> r >> k;
        unsigned long long m = 1LL;
        while(m <= r){
            if(m >= l)
                v.push_back(m);
            m *= k;
            if(m%k != 0) break;
        }
                              
                               if(int(v.size()) == 0)
                                    cout << -1 << endl;
                                 else
                                      for(int i = 0; i < int(v.size()); ++i)
                                           cout << v[i] << char((i == v.size() - 1) ? '\n' : ' ');
                                    
                                     
                                      return 0;
                             }

