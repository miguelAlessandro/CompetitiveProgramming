#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace::std;

vector<int> O;
vector<string> V;
int n, t, x;
string line;

int main(){
    

    cin >> t;
    getline(cin, line);

    while(t--){

        getline(cin, line);
        getline(cin, line);
        istringstream cline(line);
        
        while(cline >> x)
            O.push_back(x-1);
    
        V.resize(O.size());
        for(int i = 0; i < O.size(); ++i)
            cin >> V[O[i]];
        
        getline(cin, line);

        for(int i = 0; i < O.size(); ++i)
            cout << V[i] << "\n";

        if(t) cout << "\n";

        O.clear();
        V.clear();
    }
    
    return 0;
}

