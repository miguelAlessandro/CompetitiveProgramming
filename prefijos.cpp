prefix function:

Sea un string s, decimos que un substring propio a de s es un borde
si es un prefijo y un sufijo a la vez.

propiedades:

1. sean a y b dos bordes diferentes, si len(a) < len(b) entonces
a es borde de b.
2. sea c el borde de mayor tama;o de un string s, entonces el
borde del string s+{character} es de tama;o a lo mas len(c)+1.

se define la funcion pi con dominio {0, ..., len(s) - 1} hacia los
enteros, como el maximo tama;o de los bordes para el 
prefijo {s_0, ... s_i}. 


O(n) algorithm.

const int N = 100005;
int pi[N];

void prefix(string s){
	int lo = 1;
	while(lo < n){
		int j = pi[lo-1];		
		while(j >= 0 and s[i] != s[j]) j = pi[j-1];
		pi[lo++] = ++j;
	}
}

applications:

KMP algorithm.

//antes llamar a prefix-function sobre P

void kmp(){
	int lo = 0, j = 0;
	while(lo < n){
		while(j >= 0 and T[lo] != P[j]) j = b[j];
		lo += 1; j += 1;
		if(j == m){
			printf("P is found at index %d in T\n", lo-j);
			j = b[j];
		}
	}	
}
