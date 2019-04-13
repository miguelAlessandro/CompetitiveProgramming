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

note que para este caso solo puedo guardar hasta 1e6... (que es muchisimo mas de lo que podria usando solo recursion).
note tambien que esto necesariamente nos dara overflow... y es por eso que generalmente nos pediran respuestas modulares.

# uso practico:

[10229 - Modular Fibonacci](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1170)

