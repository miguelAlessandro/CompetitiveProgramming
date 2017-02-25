///Soluciones

1. hacer una función que bote -1 en caso que un entero sea negativo y 0 en otro caso.
rpta:

int neg(int x){return -(x < 0);}

2. intercambie dos enteros x e y, se entiende que ahora x sera y e y tendra el valor inicial de x. 
rpta:

void swap(int& x, int& y){
	x ^= y; y ^= x; x ^= y;
}

3. hacer una función que reciba dos enteros que te evalue la siguiente sentencia: "x e y tienen el mismo signo".
rpta: 
 
bool samesign(int x, int y){
	return (x^y) >= 0;
}
 
4. Encuentra el minimo de dos enteros.
rpta:
 
int min(int x, int y){
   return y ^ ((x ^ y) & -(x < y));
}
 
5. Encuentra el máximo de dos enteros.
rpta:

int max(int x, int y){
	return x ^ ((x ^ y) & -(x < y));
}
 
6. Haga una función que determine si un número es una potencia de 2:

int twopot(int n){
	return n and not (n&(n-1));
} 
