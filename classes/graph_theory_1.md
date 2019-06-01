# Teoria de grafos

### 0. espectativas

- definir un grafo

- aprender a representar un grafo en computadora

- definir que es una busqueda en un grafo


### 1. definicion

La teoria de grafos estudia las relaciones entre
pares de objetos. Se define un grafo como un par
ordenado de dos conjuntos V y E, donde E pertenece al conjunto de pares ordenados de V.

G = (V, E)

A V se le llama vertices y E aristas. 

### 2. Busquedas en grafos

La busqueda en un grafo es una busqueda sistematica de ir sobre las aristas para 
poder visitar los vertices del grafo.

Claro! Hay muchas formas de recorrer un grafo... Pero, de que son importantes todas estas formas? 

Pues... cada una nos da una informacion diferente del grafo! Nos hablan sobre su estructura, y nos
dan mucha mas informacion. Por tanto estas clases de grafos hablaremos de algoritmos que nos digan aspectos de los grafos que nos permitan razonar sobre ellos. Por eso no es de sorprenderse que los algoritmos de busqueda son el corazon de este campo.


### 3. Representacion de grafos

Antes de avalanzarnos sobre los algoritmos de busqueda, es sumamente importante poder representar un grafo en computadora. Hoy veremos dos de las formas mas comunes que son la matriz de adjacencia y las listas de adjacencia.


##### 3.1 Matriz de adjacencia

La matriz de adjacencia se usa para guardar grafos densos, que quiere decir que la cantidad de aristas es cerca a C(V, 2). Esta usa O(V^2)
de memoria.

La representacion por matriz de adjacencia almacena una matriz con entradas g[i][j] en 1 cuando el nodo
i y el nodo j son adjacentes y 0 en otro caso.

```cpp
cin >> n >> m;
for (int i = 1; i <= m; ++i) {
  int a, b;
  cin >> a >> b;
  g[a][b] = 1;
  g[b][a] = 1;
}
```

##### 3.2 Listas de adjacencia

Las listas de adjacencia se usan para guardar grafos esparsos en los cuales la cantidad de aristas es cercana a una funcion lineal de la cantidad de vertices. Esta usa V + 2E de memoria,
para guardar el grafo O(V+E).

Las representacion por listas de adjacencia,
mantiene una lista de elementos para cada nodo, estos elementos son los nodos adjacentes a este.
Es claro que como cada arista tiene dos vertices
finales, entonces, la cantidad de espacio es el doble de la cantidad de aristas.

```cpp
cin >> n >> m; //leo #V y #E
for (int i = 1; i <= m; ++i) { //leo cada arista
  int a, b;
  cin >> a >> b;
  g[a].push_back(b);
  g[b].push_back(a);
}
``` 

##### 3.3 preguntas

- dado las listas de adjacencia de un grafo dirigido (es un grafo
en el cual puede existir la arista (a, b) pero, no necesariamente
la arista (b, a)). en que complejidad puedo hallar el grado de salida,
y en que complejidad puedo hallar el grado de entrada?

- dado un grafo dirigido en que complejidad puedo hallar el grafo transpuesto
para listas de adjacencia y para matriz de adjacencia.

- dado un grafo con multiples aristas repetidas, como puedo volver
este grafo un grafo simple en O(V + E) (hint: se puede usar algo mas de memoria)

- **interactive problem**: recibiras t (<= 500) consultas, en cada
consultas recibiras n (<= 1000), que es la cantidad de nodos de un 
grafo dirigido fijo, uno puede consultar por si existe la arista (a, b),
esa arista es dirigida y tenga en cuenta que la respuesta no tiene
que ver por si existe la arista (b, a). Por cada caso se pide
responder si existe un nodo con out-deg n-1 e in-deg 0.


#### 4. depth-first search:

El algoritmo de busqueda pro profundidad es sin duda una de los algoritmos
mas simples en teoria de grafos pero, al mismo tiempo uno de los terriblemente
mas poderosos, quizas el que revela mas informacion de la que a simple vista
parece sobre la estructura del mismo. 

Este algoritmo visita los vecinos de un nodo siempre y cuando no haya sido visitado
antes, y lo hace apenas pueda. esto se puede esquematizar asi:

Implementacion con listas de adjacencias O(V + E):

```cpp 
void dfs(int v) {
  vis[v] = 1;
  for (int u : g[v]) {
    if (not vis[u]) {
      dfs(u);
    }}
}
```

Implementacion con matriz de adjacencia O(V^2):

```cpp 
void dfs(int v) {
  vis[v] = 1;
  for (int u = 1; u <= n; ++u) {
    if (g[v][u] and not vis[u]) {
      dfs(u);
    }}
}
```










