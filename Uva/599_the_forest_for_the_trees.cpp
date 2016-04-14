#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <sstream>

using namespace::std;

string line;
int degree[30], Nacorn, Nedge, Nvertex, t;
bool vertex[30];

int main(){

    ios_base::sync_with_stdio(0);

    getline(cin, line);
    istringstream(line) >> t;
    while(t--){
        memset(degree, 0, sizeof degree);
        memset(vertex, false, sizeof vertex);
        Nacorn = Nedge = Nvertex = 0;

        while(getline(cin, line), line[0] != '*'){
            for(string::const_iterator it = line.cbegin(); it != line.cend(); ++it)
                if(isupper(*it)) ++degree[*it - 'A'];
            ++Nedge;
        }

        getline(cin, line);
        for(string::const_iterator it = line.cbegin(); it != line.cend(); ++it)
            if(isupper(*it)) vertex[*it - 'A'] = true;

        for(int i = 0; i < 26; ++i)
            if(vertex[i]){
                if(degree[i] == 0) ++Nacorn;
                ++Nvertex;
            }

        printf("There are %d tree(s) and %d acorn(s).\n", Nvertex - Nedge - Nacorn, Nacorn);
    }

    return 0;
}
