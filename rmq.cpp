sqrt descompotition:

const int N = 1000005;
int block[1005]; // sqrt N = 1000
int a[N]

void init(int n){
	int len = bi_sqrt(n) + 1; //mantener como variable global y hallar solo una vez

	for(int i = 0; i*len < n; ++i)
		block[i] = INT_MAX;//elemento neutro para el minimo

	for(int i = 0; i < n; ++i)
		block[i/len] = min(block[i/len], a[i]);//inicializacion por bloques sqrt
}

int query(int l, int r){ //slow query
	int mini = INT_MAX; //elemento neutro para el minimo
	while(l <= r)
		if(l%len == 0 and l + len - 1 <= r)
			mini = min(mini, b[l/len]), l+=len;//interior
		else 
			mini = min(mini, a[l]), l+=1;//lado restante izquierda y derecha
}

int query2(int l, int r){ //fast query
	int len = bi_sqrt(n)+1;//hallarlo solo una vez
	int bl = l/len, br = r/len;
	int ans = INT_MAX;
	if(bl == br)
		while(l <= r) 
			ans = min(ans, a[l++]); //caso especial (solo cuando el elemento neutro no es el mismo segmento (sum, producto, promedio, etc.))
	else{
		for(int i = l; i <= (bl+1)*len-1; ++i)//lado restante izquiero
			ans = min(ans, a[i]);	
		for(int i = bl+1; i <= br-1; ++i)//interior
			ans = min(ans, b[i]);
		for(int i = br*len; i <= r; ++i)//lado restante derecho
			ans = min(ans, a[i]);
	}
}



int bi_sqrt(int n){// ||sqrt n|| == int(sqrt(n) + eps)
	int lo = 0, hi = n;
	while(lo < hi){
		int mid = lo + (hi-lo+1)/2;
		if(mid*mid <= n) lo = mid;
		else hi = mid-1;
	}
	return lo;
}



