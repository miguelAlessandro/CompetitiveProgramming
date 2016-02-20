#include <iostream>
#include <cstdio>

using namespace::std;

int ABC[] = {
    0, 1, 2, 3, 0, 1, 2, 0,
    0, 2, 2, 4, 5, 5, 0, 1,
    2, 6, 2, 3, 0, 1, 0, 2, 
    0, 2
};
int c;

int main( void ){

    int anterior = 0; 
    while((c = getchar()) != EOF)
    {
        if(c == '\n') puts("");
        else
            if(ABC[c - 'A'] != 0 && ABC[c - 'A'] != anterior) printf("%d", ABC[c - 'A']);
        anterior = ABC[c - 'A'];
    }

    return 0;
}
