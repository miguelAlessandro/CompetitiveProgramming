#include <iostream>
#include <unordered_map>
#include <cstdio>

using namespace::std;

unordered_map<char, int> M;
char c;

int main(){

    while((c = getchar()) != '\n')
        if(c != ' ')
           M[c]++; 

    while((c = getchar()) != '\n')
        if(c != ' ')
            if(M[c] != 0)
                M[c]--;
            else
                {puts("NO"); return 0;}

    puts("YES");

    return 0;
}
