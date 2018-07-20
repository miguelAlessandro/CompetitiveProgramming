#include <iostream>
#include <cstdio>

using namespace::std;

int t;
bool l;

int recursive(){

    l = true;
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);

    if(!a) a = recursive();
    if(!c) c = recursive();
    if(a*b != c*d) l = false;

    return a + c;
}




int main(){

    scanf("%d", &t);
    while(t--){
        recursive();
        puts(l ? "YES" : "NO");
        if(t) puts("");
    }

    return 0;
}
