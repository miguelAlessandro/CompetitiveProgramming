#include <iostream>
#include <cstdio>

using namespace::std;

int main(){

    int c;
    while((c = getchar()) != '\n')
        if(c != 'A' && c != 'a' && c != 'E' && c != 'e' && c != 'I' && c != 'i' &&
           c != 'O' && c != 'o' && c != 'U' && c != 'u' && c != 'Y' && c != 'y')
            printf(".%c", (c >= 'A' && c <= 'Z') ? c ^ ' ' : c);

    return 0;
}
