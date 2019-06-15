# BFS & DFS 

### 0. expectativas:

- entender como funciona por dentro el algoritmo de bfs.
- ver que el bfs genera un arbol especial.
- verificar la correctitud del algoritmo bfs.
- entender como modificar sutilemente el algoritmo.

### 1. introduccion:

Como ya sabemos la idea central de los algoritmos de busqueda es recorrer
sistematicamente las aristas para darnos informacion de los grafos. En el caso 
de bfs, este podemos verlo como ir revisando circulos concentricos en el
source de menor a mayor distancia, y ademas genera lo que llamamos el bfs 
tree, que es el arbol de distancias minimas desde el source hasta todos los 
demas nodos. este arbol me permite recuperar caminos y otras cosas. 

### 2. bfs

El algoritmo de bfs podriamos decir que trabaja coloreando nodos como 
negro y gris, donde gris es para nodos en la frontera actual y negro para 
los nodos que ya visite. 

el bfs se construye comenzando por un source (gris) y expandiendose, los
nodos grises visitan todos sus vertices adjacentes que no han sido visitados 
para volverlos grises y convirtiendo al final el nodo en negro.

una comun implementacion con estas contemplaciones seria:

```cpp
enum color {WHITE, GRAY, BLACK};
void bfs(int src) {
	for (int i = 1; i <= n; ++i) {
		distance[i] = INF;
		color[i] = WHITE;
		parent[i] = -1;
	}
	color[src] = GRAY;
	dist[src] = 0;
	queue<int> Q; Q.push(src);
	while (not Q.empty()) {
		int q = Q.front(); Q.pop();
		for (int v : g[q]) {
			if (color[v] == WHITE) {
				color[v] = GRAY;
				distance[v] = distance[q] + 1;
				parent[v] = q;
				Q.push(v);
			}}}
}
```

### 3. Invariantes en el bfs

- La cola en el bfs solo mantiene nodos grises.
- Cada nodo es encolado a lo mas una vez (solo sucede cuando no esta pintando).
- el algoritmo se ejecuta en O(V + E)


### 4. Correctitud de la distancia minima

#### lemma 1.  (lemma de la frontera)
para cualquier arista e = (u, v): dist(s, v) <= dist(s, u) + 1. donde dist(a, b)
es la distancia minima desde a hasta b.

##### prueba:
Si u es alcanzable desde s, entonces la distancia minima de v no puede ser 
mayor que la distancia minima desde u mas la arista (u, v). Si no es alcanzable dist(s, u) = infinity lo cual cumple con el lemma.

#### Lemma 2.  (lemma de encapsulamiento)
Sea un bfs corrido desde cualquier nodo s entonces para todo nodo u, 
dist[u] >= dist(s, u).

##### prueba:
Para la primera encolacion dist[s] = 0 y dist[v] = inf, para v != s. Supongamos
que el lemma se cumple hasta las n primeras encolaciones, se la encolacion
n+1, tenemos: dist[v] = dist[u] + 1, pero como dist[u] >= dist(s, u), entonces, 
dist[v] >= dist(s, u) + 1, y usando el lemma anterior, dist[v] >= dist(s, v).

#### Lemma 3. (lemma de la distancia x tiempo)
Sea cualquier determinado momento de la ejecucion, la cola tiene los 
elementos <v1, v2, ..., vk>, entonces, vk <= v1 + 1 y vi <= vi+1.

##### prueba:
Para probarlo usamos induccion sobre el numero de las operaciones en 
la cola. al desencolar un elemento la afirmacion se mantiene inalterable, 
ya que dist[vk] <= dist[v1] + 1<= dist[v2] + 1. 
Por otro lado para la encolacion, sea el nodo v, nosotros debemos ver que
antes de ello hemos quitado el nodo u  (padre de v) desde la cola, y ahora 
el primer nodo de la cola cumple dist(s, v1) >= dist(s, u), ademas si encolamos 
un nodo v, cumple que dist(s, vk) <= dist(s, u) + 1 = dist(v) <= dist(s, v1) + 1.

#### corolario 4. 
Si vi es encolado antes que vj, entonces dist[vi] <= dist[vj].

Del lemma anterior ya que los valores en la cola van aumentando 
progresivamente.

#### teorema 5 (correctitud del bfs).
BFS computa la distancia minima desde el source, es mas, permite hallar el camino minimo siguiendo el array parent.

##### prueba: 
Supongamos que esto no es asi, y consideremos el primer momento del 
algoritmo en que se le asigna un valor que no es el indicado a un nodo v. 
en primer lugar  v != source, y v es alcanzable desde source, en otro caso 
cumple con lo ya dicho, entonces, sea u el nodo padre en el camino minimo 
desde el source a v, entonces, de como se eligio u, dist[u] = dist(s, u), luego tenemos dist[v] > dist(s, v) = dist(s, u) + 1 = dist[u] + 1.

Ahora sea la vez que el algoritmo proceso a u, entonces si v era blanco, 
claramente procesa bien la respuesta y seria una contradiccion, si 
v es negro entonces tenemos por la propiedad de la cola que dist[v] <= dist[u] 
que contradice la anterior desigualdad y por ultimo si fuera gris, entonces 
sea w su padre y por lo cual dist[v] == dist[w] + 1 <= dist[u] + 1 que otra 
vez contradice la anterior desigualdad.

Por ultimo note que el padre de v cumple con que dist[u] + 1 = dist[v], lo cual 
nos dice que nos acerca un paso al source por tanto podemos llegar en 
la distancia minima al source siguiente este camino.

### bfs tree: 
si enlazamos los padres de cada nodo con el nodo mismo, vemos que 
los nodos no forman ciclos por que la distancia siempre es creciente. 
y dado que todos los nodos alcanzables desde el root tienen un camino 
hacia al root por medio de los padres, vemos que necesariamente se 
forma una arbol.

### ejercicios:

1. ver que las aristas del bfs-tree dependen del orden en que son 
procesadas las listas de adjacencias de cada nodo.

2. diga como se puede hacer para que los hijos de un nodo del bfs 
tree tengan orden creciente.

3. de un ejemplo de un arbol dentro de un grago que tenga las misma 
propiedades de un bfs-tree pero, que no se pueda generar haciendo un bfs.
sin importar como esten ordenadas las aristas.

4. en este mundo hay gente buena y mala, tu tienes una lista de n 
compa;eros de clases y r relaciones de enemistad entre ellos, realice 
un algoritmo que asigne a cada persona un rotulo entre bueno y malo
 tal que cada una de las relaciones sea entre una persona buena y una mala.

5. halle el diametro de un arbol.

6. diga una forma de recorrer un grafo pero que pase por cada 
arista exactamente dos veces (por cada direccion).

### BFS 0|1
Es posible resolver problemas en los cuales se tenga que las aristas son 
binarias. Gracias al lemma 3, se puede hacer algunas modificaciones al
momento de encolar, cada vez que un elemento con arista 1 es encolado,
este se encola de forma normal, y cuando un elemento con arista 0 es
encolado, este se encola al inicio de la cola.

#### Lemma 6: (bfs 0|1)
Todo nivel es procesado correctamente.

##### prueba: 
El nivel 0 es procesado correctamente, supongamos que los 
primeros n niveles son procesados correctamente, y sea el nivel n+1, 
vemos que en la cola se mantiene la propiedad de distancias no 
decreciente, y supongamos que un elemento es asignado incorrectamente,
esto solo sucede si la arista es 1, como fue asignado incorrectamente, 
los nodos en el nivel actual deben tener una arista 0, por tanto este es
procesado antes y permite poner al inicio de la cola el elemento mal encolado.

```cpp
void bfs(int src) {
	for (int i = 1; i <= n; ++i) {
		dis[i] = INF;
	}
	dis[src] = 0;
	deque<int> Q; Q.push_back(src);
	while (not Q.empty()) {
		int q = Q.front(); Q.pop_front();
		for (auto edge : g[q]) {
			if (dis[q] + edge.w < dis[edge.v]) {
				dis[edge.v] = dis[q] + edge.w;
				if (edge.w == 1) Q.push_back(edge.v);
				else Q.push_front(edge.v);
			}}}
}
```
otra forma de implementarlo es por cada nivel primero procesar los nodos 
con arista 0 con un dfs ya que necesitan ser proesados antes.
```cpp
queue<int> Q;
void dfs(int node) {
   //Traverse through the 0-connected component
   for (auto v : G0[node])
      if (not vis[v]) {
         vis[v] = 1;
         dist[v] = dist[node];
         dfs(v);
      }
   //Push the unvisited 1-cost neighbours
   for(auto v : G1[node])
      if(not vis[v]) {
         vis[v] = 1;
         dist[v] = dist[node] + 1;
         Q.push(v);
      }
}

void bfs1_0(int src) {
   Q.push(src);
   vis[src] = 1;
   while (not Q.empty()) {
      int q = Q.front(); Q.pop();
      dfs(q);
   }
}
```
### Generalizacion

Podriamos tener los pesos [0, ..., k] y tener una implementacion O(kV + E), para
lograr esto debemos poder mantener los k niveles en la cola, para lograr esto
tendriamos una cola por cada nivel, de tal forma que es posible acceder de
forma rapida a cada uno.

### Problems:

- [REVERSE - cocechef](https://www.codechef.com/problems/REVERSE)
- [11573 - Ocean Currents](https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2620)
- [28 - Error](https://a2oj.com/p?ID=28)
- [B. Chamber of Secrets](https://codeforces.com/contest/173/problem/B)
- [C. Three States](https://codeforces.com/contest/590/problem/C)
- [B. Labyrinth](https://codeforces.com/contest/1063/problem/B)
- [DoNotTurn - topcoder](https://community.topcoder.com/stat?c=problem_statement&pm=10337)
- [A. The Fair Nut and the Best Path](https://codeforces.com/problemset/problem/1083/A)
- [Problem 2. Barn Painting](http://www.usaco.org/index.php?page=viewproblem2&cpid=766)

### Referencias:

- [bfs 0/1 codeforces](https://codeforces.com/blog/entry/22276)
- Introduction to algorithms, 3er edition, 2009, comer, leirson
- [bfs 0/1 competitive programming](https://cp-algorithms.com/graph/01_bfs.html)


### DFS

DFS logra ser un algortimo simple que guarda muchos secretos, primero
veamos como funciona en un arbol simple.

#### Trees & DFS

Los arboles son sumamente interesantes, la primera gran relacion que podemos
encontrar entre estos dos conceptos es la tan llamada parentizacion, sucede que 
al entrar en un nodo, nosotros podemos dejar timestamps que nos indican el
momento inicial y final de un subtree.

### dfs timestamp

```cpp
int time = 0;
void dfs(int node, int parent) {
	st[node] = time++;
	for (int v : g[node]) {
		if (v == parent) continue;
		dfs(v, node);
	}
	nd[node] = time-1;
}
```
Algunas estructuras de datos trabajan mejor sobre arrays que sobre arboles, este
metodo tambien es llamado aplanamiento del arbol.

Otra caractizacion interesante es el euler tour tree, que podria decirse que es la
huella que deja el dfs al recorrer un arbol.

### dfs Euler tour tree
```cpp
int time = 0;
void dfs(int node, int parent) {
	euler[time++] = node;
	for (int v : g[node]) {
		if (v == parent) continue;
		dfs(v, node);
		euler[time++] = node;
	}
}
```
Cuando se relizen algoritmos como los del LCA, una forma de computarlo es 
procesando este array euler, que nos esta diciendo algo sobre la profundidad 
de cada nodo en el arbol.

### dfs jumps: 

Otra forma interesante de trabajar con dfs en arboles, es poder procesar
informacion suficiente para saber que nodo es el L-esimo ancestro de un nodo.
Para ello se puede mantener un array que nos proporcione que nodo esta a 
una distancia 2^k de un nodo dado.

```cpp
void dfs(int node, int parent) {
	st[node][0] = parent;
	for (int k = 1; k < LOG; ++k) {
		st[node][k] = st[st[node][k-1]][k-1];
	}
	for (int v : g[node]) {
		if (v == parent) continue;
		dfs(v, node);
	}
}
int jump(int node, int L) {
	for (int k = 0; k < LOG; ++k) {
		if (l & (1<<k)) {
			node = st[node][k];
		}}
	return node;
}
```
