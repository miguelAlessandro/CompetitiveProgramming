# dynamic programming 2

## 0. expectativas:
	
	- identificar algunos de los problemas	
	clasicos de dynamic programming.
	
	- ver que todos estos problemas tienen 
	una solucion recursiva y otra iterativa,
	pero a veces se puede hacer mejores optimizaciones
	en una solucion iterativa.

## 1. Longest Common Subsequence

formulacion: 

dado dos strings S y T, hallar la subsecuencia
comun mas larga entre ellos.


solucion O(|S| x |T|):

```cpp
int LCS(int n, int m) {
	if (n == 0 or m == 0) return 0;
	if (vis[n][m]) return memo[n][m];
	int &ans = memo[n][m] = max(LCS(n-1, m), LCS(n, m-1));
	if (S[n-1] == T[m-1]) ans = max(ans, 1 + LCS(n-1, m-1));
	vis[n][m] = 1;
	return ans;
}
```

explicacion: 

- nuestro dp(n, m) lo que halla es la maxima subsecuencia
entre dos strings de tamaños n y m respectivamente. 

Es claro que si el tamaño de uno de ellos es 0 entonces la 
respuesta es 0. en otro caso el caracter S[n-1] o T[m-1] no
matchean con ninguno de los caracteres en el otro string y
por ultimo es posible que haya un match entre S[n-1] y T[m-1]
solo si los caracteres son iguales. 

ejercicio: pruebe que en caso de que n, m >= 1 y S[n-1] == T[m-1]
entonces, siempre conviene que haya un match entre esos dos 
caracteres.

nota: hoy en dia este problema se puede resolver en O(|S| x |T| / 32)
con manejo de bits y una reformulacion de la solucion a suma de 
matrices binarias.

existe una solucion iterativa a este problema???

```cpp
for (int i = 0; i <= n; ++i) dp[i][0] = 0;
for (int i = 1; i <= m; ++i) dp[0][i] = 0;
for (int i = 1; i <= n; ++i) {
	for (int j = 1; j <= m; ++j) {
		if (S[i-1] == T[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
		else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
	}
}
```

nota: tenga en cuenta que se recorre en el orden natural 
del problema, pero tambien podemos recorrer por T primero
y luego por S. ya que el problema es simetrico. Vea que
para preprocesar (i, j) necesito que esten preprocesados
(i-1, j), (i, j-1) y (i-1, j-1). 

ejercicio: vea que tambien un orden natural para resolver
el problema es recorrerlo en el orden creciente respecto
a i+j.

## 2. Kadane's algorithm.

El algoritmo de Jay Kadane resuelve el siguiente problema
con complejidad O(n):

Dado un array con n elementos enteros (posiblemente negativos),
hallar la suma maxima para toda subsecuencia continua 
(subarray, subintervalo) en el array.

```cpp
int kadane(int pos) {
	if (pos == n) return 0;
	if (vis[pos]) return memo[pos];
	vis[pos] = 1;
  	return memo[pos] = a[pos] + max(0, kadane(pos+1));
}
```

Lo que halla el algoritmo de kadane es: para cada posicion
de inicio 'pos' en mi array, hallar la maxima suma iniciando
en esa posicion hasta el final del array.

Vemos primero que si todos los numeros fueran positivos, siempre
me conviene tomar todos, entonces, si tengo la maxima respuesta
desde pos+1 hasta el final del array, entonces, si esta respuesta
es positiva, obviamente necesito tomar esa respuesta pero, en 
caso de ser negativa, nunca.

importante: el algoritmo de kadane, halla la respuesta comenzando
en toda posicion, no halla la solucion para todo el array, para
ellos tenemos que hacer un for mas.

```cpp
int ans = memo[1];
for (int i = 2; i <= n; ++i) {
	ans = max(ans, memo[i]);
}
//tambien:
int ans = *max_element(memo+1, memo+n+1);
``` 

solucion iterativa:

```cpp
dp[0] = 0;
for (int i = 1; i <= n; ++i) {
	dp[i] = a[i] + max(0, dp[i-1]);
}
```

## 3. Edit distance (Levenshtein's Distance):

Este problema se usa muchisimo para analizar similitudes
entre cadenas de adn, el problema se formula asi:

dados dos strings S y T, hallar la minima cantidad de cambios 
(eliminar un caracter, agregar un caracter o cambiar un caracter)
que se deben realizar para que edit(S) == T.


```cpp
int editDistance(int n, int m) { 
	if (n == 0 or m == 0) return n+m;
	if (vis[n][m]) return memo[n][m];
	int &ans = memo[n][m] = 1e9; //infinity
	ans = min(ans, editDistance(n-1, m-1) + s[n-1] != t[m-1]); //cambiar si es necesario
	ans = min(ans, editDistance(n-1, m) + 1); //eliminar caracter n.
	ans = min(ans, editDistance(n, m-1) + 1); //agregar caracter despues del caracter n.
	vis[n][m] = 1;
	return ans;
}
```

solucion iterativa:

```cpp
dp[0][0] = 0;
for (int i = 1; i <= n; ++i) dp[i][0] = i;
for (int i = 1; i <= m; ++i) dp[0][i] = i;
for (int i = 1; i <= n; ++i) {
	for (int j = 1; j <= m; ++j) {
		dp[i][j] = min(
			editDistance(i-1, j-1) + s[i-1] != t[j-1],
			min(
				editDistance(i-1, j) + 1,
				editDistance(i, j-1) + 1
			)
		);
	}
}
```cpp


## 4. Rod cutting

dado una barra de longitud n y el ri de hacer
cortes de tama;o pi, se desea cortarla en trozos 
mas pequeños tal que minimiza el costo.

```cpp
int rodCutting(int n) {
	if (n == 0) return 0;
	if (vis[n]) return memo[n];
	int &ans = memo[n] = INT_MAX;
	for (int i = 0; i < m; ++i) {
		if (n >= p[i]) {
			ans = min(ans, r[i] + rodCutting(n-i));
		}
	}
	vis[n] = 1;
	return ans;
}
```

solucion iterativa:

```cpp
dp[0] = 0;
for (int i = 1; i <= n; ++i)	
	int &ans = dp[i] = 1e9;
	for (int j = 0; j < m; ++j) {
		if (i >= p[j]) {
			ans = min(ans, r[j] + dp[i-p[j]]);
		}
	}
}
```

otra solucion iterativa:

```cpp
dp[0] = 0;
for (int i = 1; i <= n; ++i) dp[i] = 1e9;
for (int i = 0; i < m; ++i)	
	for (int j = n; j >= p[i]; --j) {
		dp[j] = min(dp[j], dp[j-p[i]]);
	}
}
```

ejercicio: pruebe que en el anterior codigo
no da lo mismo si el segundo for no es decreciente.


## 5. Longest Increasing subsequence.

enunciado: Dado un array de enteros, hallar
la subsecuencia creciente mas larga.

```cpp
void LIS(int pos) {
	if (n == 0) return 0;
	if (vis[pos]) return memo[pos];
	int &ans = memo[pos] = LIS(pos+1);
	for (int i = pos+1; i < n; ++i) {
		if (a[pos] < a[i]) {
			ans = max(ans, 1 + LIS(i));
		}
	}
	vis[pos] = 1;
	return ans;
}
```

esta es una solucion O(n^2), pero es la mejor?
No! La solucion actual considera lo siguiente, 
la mayor subsecuencia creciente comienza en esta 
posicion o en la siguiente... 

Nueva formulacion: sea dp[k] igual al menor
elemento final de una subsecuencia creciente
con k elementos. Entonces, construimos agregando
un elemento a la vez, al inicio dp[0] = -INF y 
dp[i] = INF, para i > 0. luego al agregar el 
primer elemento dp[0] = -INF, dp[1] = a[1],
dp[i] = INF para i > 1. Continuamos de esa
forma, luego al agregar el elemento a[k],
lo que haremos es buscar el mayor elemento
en dp[i] tal que dp[i] < a[k], luego dp[i+1] = a[k].

ejercicio. pruebe que dp[i] es creciente. (asuma que
INF < INF es verdadero). 

```cpp
for (int i = 1; i <= n; ++i) dp[i] = INF;
dp[0] = -INF;
for (int i = 1; i <= n; ++i) {
	int lo = 0, hi = n;
	while (lo < hi) {
		int mid = lo + (hi - lo) / 2;
		if (a[i] <= dp[mid]) lo = mid+1;
		else hi = mid;
	}
	dp[lo+1] = a[i];
}
```
ejercicio. es posible usar la minima cantidad
de elementos en dp?

nota: vea que la solucion es el indice del ultimo
elemento diferente de INF.
