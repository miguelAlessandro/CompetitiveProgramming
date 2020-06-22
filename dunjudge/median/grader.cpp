#include <cstdio>
#include <utility>
#include <algorithm>
#include "device.h"
using namespace std;
static const int MAXN = 1500;
static const int MAXQ = 7777;
static int N, q, str[MAXN], ans;

void bad() {
    printf("1\n");
    exit(0);
}

int Med3(int a, int b, int c){
    if (a == b || b == c || a == c) bad();
    if (a < 1 || a > N) bad();
    if (b < 1 || b > N) bad();
    if (c < 1 || c > N) bad();
    q++;
    pair<int,int> x(make_pair(str[a-1],a)), y(make_pair(str[b-1],b)), z(make_pair(str[c-1],c));
    return (max(min(x,y),min(max(x,y),z))).second;
}

int main(){
    scanf("%d%d",&ans,&N);
    for (int i=0; i<N; i++) scanf("%d",&str[i]);
    int ret = Median(N);   
	printf("%d\n", ret);
    if (ans==ret) printf("0\n");
    else printf("1\n");
    if (q>MAXQ) printf("1\n");
}
