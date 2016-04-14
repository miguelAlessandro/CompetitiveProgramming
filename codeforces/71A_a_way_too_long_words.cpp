#include <iostream>
#include <cstdio>
#include <vector>

using namespace::std;

int main(){

    int t;
    string line;
    cin >> t;
    getchar();
    while(t--){
        getline(cin, line);
        if(line.size() <= 10) cout << line << endl;
        else cout << *line.begin() << line.size() - 2 << *line.rbegin() << endl;
    }

    return 0;
}
