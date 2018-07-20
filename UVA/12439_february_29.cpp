#include <iostream>
#include <cstring>
#include <cstdio>

using namespace::std;

int t, r, nc = 1; 
char month[15];
int day, year;

int main(){
    
    scanf("%d", &t);
    while(t--){
        scanf("%s %d%*c %d", month, &day, &year);
        if(((year%4 == 0 && year%100 != 0) || year%400 == 0) && (strcmp(month, "January") == 0 || (strcmp(month, "February") == 0 && day <= 29)))
            r = (year-1)/4 - (year-1)/100 + (year-1)/400;
        else
            r = year/4 - year/100 + year/400;

        scanf("%s %d%*c %d", month, &day, &year);
        if(((year%4 == 0 && year%100 != 0) || year%400 == 0) && (strcmp(month, "January") == 0 || (strcmp(month, "February") == 0 && day < 29)))
            r = (year-1)/4 - (year-1)/100 + (year-1)/400 - r;
        else
            r = year/4 - year/100 + year/400 - r;
        printf("Case %d: %d\n", nc++, r);
    }

    return 0;
}
