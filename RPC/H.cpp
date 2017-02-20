#include <bits/stdc++.h>
using namespace std;

char s[20];
int v, n, W, w, ac;
long double p, P = 1.0, E, aux;

int main(){

	scanf("%d %d%*c", &n, &W);
	printf("%lF\n", log(1.0 + 2316.82/W));

	w = W;
	for(int i = 0; i < n; ++i){
		scanf("%s %Lf %d%*c", s, &p, &v);

		E += P*p*log(1.0 + 1.0*v/w) + P*(1.0-p)*log(1.0 - 1.0*ac/w);
		P *= p;
		ac += v;
		w += v;
		if(s[0] == 's') ac = 0.0;
	}
	
	printf("%Lf\n", E);
	printf("$%.2Lf\n", W*exp(E) - W);


	return 0;
}
