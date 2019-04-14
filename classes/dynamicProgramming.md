# Programacion dinamica 

### concepto

se refiere al guardado dinamico de informacion para ser usado apenas se necesite.

#### ejemplo:

Supongamos que necesitamos calcular fibonacci de n. esto lo podemos hacer asi:

```cpp
int fibonacci(int n) {
	if (n <= 1) return 1;	
	return fibonacci(n-1) + fibonacci(n-2);
}
```

como habiamos visto en recursividad, este algoritmo puede ser costoso! que tanto?

denotemos el tiempo de ejecucion asi:
```cpp
  T[0] = T[1] = 1 //complejidad del caso base
  T[n] = T[n-1] + T[n-2] + 1 //complejidad de los demas casos

  //sea la funcion generadora
  F(x) = T[0] + T[1] x + T[2] x^2 + T[3] x^3 + ...
  //luego reduzcamos un poco...
  F(x) - x F(x) - x^2 F(x) = T[0] + T[1] x + (T[2] - T[1] - T[0]) x^2 + ... + (T[n] - T[n-1] - T[n-2]) x^n + ...
  //lo cual es:
  F(x) (1 - x - x^2) = 1 + x + x^2 + x^3 + ...
  //teniendo:
  F(x) (1 - x - x^2) = 1 / (1 - x)
  //que es lo mismo a 
  F(x) = 1 / [(1 - x) (r1 - x) (r2 - x)]
  //pero sabemos que esto puede verse asi!:
  F(x) = A / (1 - x) + B / (r1 - x) + C / (r2 - x)
  //lo que nos quieres decir que 
  T[n] = A + (B * r2) * r2 ^ n + (C * r1) * r1 ^ n
  //en resumen T[n] es una funcion exponencial!
  //(usando conceptos de series de tiempo se puede llegar mas rapido con simple inspeccion)
  // Una respuesta mas concreta es que T[n] = fibonacci(n + 2) - 1 (>:) trate de probarlo)
```

Pero se puede hacer menos costoso? y sobretodo... sin perder precision?

### Memoization, la clave de programacion dinamica.

El corazon de programacion dinamica se basa en guardar todo lo que puedas necesitar, a esto
se le llama memoization (es un tipo de caching). Como luce un algoritmo de programacion 
dinamica usando nuestro ejemplo anterior?

```cpp
const int maxN = 1e6;
int memo[maxN];
bool check[maxN];
int fibonacci(int n) {
	if (n <= 1) return 1;
	if (check[n]) return memo[n];
	check[n] = 1;
	return memo[n] = fibonacci(n-1) + fibonacci(n-2);
}
```

- note que para este caso solo puedo guardar hasta 1e6... (que es muchisimo mas de lo que podria usando solo recursion).
- note tambien que esto necesariamente nos dara overflow... y es por eso que generalmente nos pediran respuestas modulares.

#### como es que esto funciona?

Tenemos que en nuestro primer algoritmo de fibonacci, al calcular f(n) necesito f(n-1) y f(n-2) y para calcular f(n-1) uso f(n-2) 
tambien... Planteatelo asi, f(n-2) es un amigo de f(n) y f(n-1), donde f(n) y f(n-1) le piden que haga una misma tarea... 
la pregunta es: f(n-2) tiene que hacer dos veces esa tarea? claramente, no!

Que tan importante es que f(n-2) no haga una tarea 2 veces o mas...?

sumamente importante, eso quiere decir que calcular f(n) = es igual a la cantidad de estados que se visita..., por tanto, como
para calcular f(n) solo necesito calcular f(n-1), f(n-2), ... y f(0) y cada uno se calcula una vez... entonces, la complejidad
de calcular f(n) es O(n)... 

#### uso practico:

[10229 - Modular Fibonacci](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1170)

vemos los pasos que debemos seguir para darle solucion:

##### observacion del problema:

En este problema nos piden hallar fibonacci de n modulo 2^m, nos van a dar varias queries y n es un numero relativamente grande...

##### observacion de detalles:

2^m no es tan grande! (sacar modulo es sencillo esto se puede hacer sacando ampersand con 2^m - 1, llegue a esto usted mismo!) 

##### usando conocimientos que ya conozco:

este tipo de funciones lineales generalmente tienen un ciclo proporcional al modulo. hallemos con un simple programa (optimista)

```cpp
const int maxN = 1e9;
cout << 0 << " " << 1 << endl; //para modulo 2^0, siempre es 0 la respuesta
for (int k = 1; k <= 20; ++k) { //reviso para cada potencia
	//solo llevo 4 numeros
	int a[4] = {0, 1}; //inicializo los primeros dos 
	for (int i = 2; i <= maxN; ++i) {
		a[i&3] = a[(i+3)&3] + a[(i+2)&3]; //esta es una forma de usar solo 4 slots de memoria tenga en cuenta que &3 es modulo 4
		a[i&3] &= (1<<k)-1; //saco modulo 2^k
		if (a[i&3] == 1 and a[(i+3)&3] == 0) { //veo si los dos ultimos son 0, 1 (de ahi se repetira)
			cout << k << " " << i-1 << endl; //encontre un ciclo!
			break;	
		}
	}
}
```

tuvimos suerte, y tenemos que los ciclos son:

```cpp
m, longitud del ciclo
0 1
1 3
2 6
3 12
4 24
5 48
6 96
7 192
8 384
9 768
10 1536
11 3072
12 6144
13 12288
14 24576
15 49152
16 98304
17 196608
18 393216
19 786432
20 1572864
```

todos son menores a 1600000... Veamos el algoritmo modificando un poco nuestro codigo anterior

```cpp
#include <bits/stdc++.h>
using namespace std;
const int maxN = 1.6e6;
int cycle[21] = 
{1, 3, 6, 12, 24, 48, 96, 192, 384, 768, 1536,
3072, 6144, 12288, 24576, 49152, 98304, 196608,
393216, 786432, 1572864};

int memo[21][maxN];
bool check[21][maxN];
int fibonacci(int m, int n) {
	if (n == 0) return 0;
	if (n == 1) return m!=0;
	if (check[m][n]) return memo[m][n];
	check[m][n] = 1;
	return memo[m][n] = (fibonacci(m, n-1) + fibonacci(m, n-2)) & ((1<<m)-1);
}

int main() {
	int n, m;
	while (cin>>n>>m) {
		cout << fibonacci(m, n % cycle[m]) << endl;
	}
	return 0;
}
```
