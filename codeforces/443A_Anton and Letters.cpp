#include <bits/stdc++.h>

using namespace::std;

int main(){
    char c;
    set<char> s;
    while((c = getchar()) != '}')
        if(c != ',' && c != ' ' && c != '{')
            s.insert(c);

    printf("%d\n", (int)s.size());

    return 0;
}
