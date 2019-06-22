## dfs

- dfs es quizas el algoritmo de exploracion mas simple 
de entender, pero incriblemente util para describir el 
grafo. 

```cpp
int time = 0;
enum colors{WHITE, GRAY, BLACK};
void dfs(int x) {
	d[x] = time++;
	c[x] = GRAY;
	for (int v : g[x]) {
		if (c[v] == WHITE) {
			dfs(v);
		}
	}
	c[x] = BLACK;
	f[x] = time++;
}
```

Como podemos ver, el dfs tiene la misma complejidad
que el bfs, ya que solo se aplica la funcion a nodos
que tengan color WHITE, y luego de ello se vuelve GRAY.

## teorema 1. (teorema de la parentisazion)

En cualquier dfs para un grafo G y nodos u, v en G, se 
cumple:

1. los intervalos [u.d, u.f], [v.d, v.f] son disjuntos.

2. uno de los intervalos [u.d, u.f], [v.d, v.f] esta
contenido en el otro, y esto solo sucede cuando un nodo
es decendiente de otro.

prueba: 

sin perdida de generalidad asumamos u.d < v.d. Ahora
puede suceder dos situaciones, v.d < u.f lo que quiere
decir que v fue descubierto cuando u era gris, que implica
que v es descendiente de u. es mas, como v fue descubierto
despues que u, todos los vecinos de v ya fueron explorados, 
por fando v.f < u.f. en otro caso u.f < v.d, y los intervalos
son disjuntos.

### corolario 2.

El nodo v es descendiente de un nodo u en el dfs si y solo
si el intervalo de v esta incluido en el intervalo de u.

## teorema 3. (white-path theorem)

El nodo v es descenciente de u si y solo si al momento de
setear u.d, existe un camino de nodos con color WHITE, desde
u hasta v.

prueba:

Si v = u, entonces el path desde u hasta v contiene solo el 
vertice u, que al momento de setear u.d es blanco. Ahora, 
supongamos que v es un descendiente propio de u en el dfs forest.
por tanto por el corolario 2. u.d < v.d y asi es blanco al setear
u.d. ahora suponamos que hay un white path desde u hasta v, y
v no es descendiente de u, sin perdida de generalidad sea v 
el primero que no es descendiente de u en el path desde u hasta v.
Y sea w el predecesor de v, por tanto w.f <= u.f (pueden ser el mismo),
pero antes que w es finalizado w va hacia v, por tanto el intervalo
de v esta incluido en el intervalo de w y este en el intervalo de u,
por tanto por el teorema 1. v es descendiente de u.


Clasificacion de aristas:

Otra gran propiedad del dfs es que la busqueda puede ser usada
para clasificar aristas, el tipo de cada arista puede darnos informacion
primordial de muchisimas caracteristicas del grafo.

	- un grafo es acyclico si no tiene back edges
	
	- los puentes de un grafo no pueden ser tree edges.

Un grafo puede tener los siguientes tipos de aristas:


	1. tree edges: son edges (a, b) en el dfs forest si
	b fue primero descubierto por a.

	2. back-edges: son edges (a, b) tal que b es un ancestro
	de a. (los self-loops son considerados back-edges)

	3. forward-edges: son arsitas que no son edge-trees que conectan
	un nodo a su descendiente.

	4. cross-edges: son todas las otras aristas. 

Una forma facil de clasificar las aristas es por medio del color del
nodo de destino.

	1. WHITE indica un tree-edge
	
	2. GRAY indica una back-edge 
	
	3. black indica o un front-edge o una cross-edge
	
En un grafo no dirigido, (a, b)	y (b, a) son la misma, solo consideramos
la primera clasificacion.
	
## Teorema 4:

En un dfs de un grafo no dirigido, toda arista de G solo es entre un tree-edge 
o una back-edge.

prueba:

Sea una arista (u, v) arbitraria de G, y supongamos sin perdida de generalidad que 
u.d < v.d. Entonces la busqueda deberia descubrir v y luego finalizar u. Lo cual
diremos que es edge-tree solo si (u, v) es descubierto antes que (v, u), en otro
caso (v, u) es una back-edge.


## problemas:

1. ver que tambien se puede clasificar las aristas (u, v) como:

	- tree-edge or forward-edge: u.d < v.d < v.f < u.f
	
	- back-edge: v.d <= u.d < u.f <= v.f
	
	- cross-edge: v.d < v.f < u.d < u.f
	
2. ver que en un grafo no dirigido las aristas son clasificadas como
tree-edges o back-edges solo dependiendo de si esta visitado o no 
el nodo de destino.

3. use un stack para eliminar la recusion

4. obten un contraejemplo tal que en un grafo dirigido existe un path
de u hasta v, y u.d < v.d entonces v es descendiente de u.

5. Obten un contraejemplo para la conjetura que si un grafo dirigido 
G contiene un path desde u para v, entonces cualquer dfs deberia resultar 
en v.d <= u.f

6. De un ejemplo de un grafo en que un nodo teniendo in-degree y out-degree
diferente de 0 pueda terminar en un tree solo on ese nodo luego de correr
un dfs.

7. en que parte del codigo deberias agregar lineas para identificar
los distintos tipos de aristas.

8. de un algoritmo para colorear las componentes conexas de un grafo no
dirigido

9. un grafo G es simplemente conectado si para todo nodo u, v a lo mas
existe un simple path desde u hacia v.

10. dado un grafo aciclico, halle el longest path entre dos nodos.
