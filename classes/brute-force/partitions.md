# Brute Force: Partitions

usted esta en medio de una competencia, quedan pocos minutos\... y lee el
siguiente problema: 

Se le proporciona un grafo con n <= 40 nodos (posiblemente completo). 
Debe imprimir el cardinal del [maximo conjunto independiente](https://en.wikipedia.org/wiki/Maximal_independent_set).

![MIS](https://en.wikipedia.org/wiki/Maximal_independent_set#/media/File:Cube-maximal-independence.svg)

Usted comienza a pensar como solucionar este problema, a primera vista
un brute force solution no ayudaria, el tiempo se le escapa, piensa que tal 
vez puede armar una solucion con [flow network theory](https://en.wikipedia.org/wiki/Flow_network), toma su plantilla 
de [Dinic Algorithm](https://en.wikipedia.org/wiki/Dinic%27s_algorithm) (un algoritmo realmente difícil de implementar).  Se da 
cuenta que para algunos casos su algoritmo cumple\... Decide enviar y probar
suerte, pero recibe un ineludible **wrong answer**, verifica algunos casos a 
mano, y encuentra un contraejemplo, se desespera, y el tiempo
inexorablemente cae.

Usted luego del contest, decide conversar con su amigo que obtuvo un
**accepted** en el dichoso problema. Luego de intercambiar unas cuantas
palabras mete el problema a colación, él sin ningún reparo le dice: 

*"me acorde que ese era un problema [NP complete](https://en.wikipedia.org/wiki/NP-completeness), asi que mande 
un brute force solution y paso, no demostre la complejidad."*

Luego de escuchar esas palabras, caes rendido a la simplicidad del problema,
y que no es realmente difícil probar la complejidad.

##### solution:
```cpp
typedef long long llong;
int MIS(llong graph, vector<llong> neighboorhood) {
	if(graph == 0) return 0; //Empty set of vertex (empty set of vertex == empty graph?).
	int node = 63 - __builting_clzll(graph & -graph); //position LSO (vertex with lowest id).
	return max(
		1 + MIS(~neighboorhood[node] & graph), //take node (& neighboors? of course...).
		MIS(~node & graph) //no take node. 
	);
}

int solve(vector<vector<int>> Adj) {
	int ord = Adj.size(); //order(Adjacent(G))
	llong graph = (1ll<<ord) - 1; //all nodes
	vector<llong> neighboorhood(ord); //close neighboors set (even the node)
	for (int u = 0; u < Adj.size(); ++u) {
		neighboorhood[u] = 1ll<<u;
		for (int v : Adj[u]) {
			neighboorhood[u] |= 1ll<<v;
		}
	}
	return MIS(graph, neighboorhood);
}
```

Primero veamos la correctitud de la solucion. 
