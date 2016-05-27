/*Optimal binary search:\\
\\
Supongamos que nosostros estamos diseñando un programa para traducir texto
desde ingles para frances. Para cada ocurrencia de cada palabra en ingles en el texto,
nosotros necesitamos buscar su equivalente en frances. nosotros deberiamos realizar
esta operación de busqueda edificando un árbol de busqueda binario con n palabras en ingles
como llaves y su equivalente en frances como datos satelitares. Porque nosotros haremos 
una busqueda en el árbol por cada palabra individual en el texto, nosotros queremos 
que el tiempo total de busqueda sea el menor posible. Nosotros debemos asegurar un tiempo
O(lg n) tiempo de busqueda por ocurrencia usando un arbol rojo y negro o algún otro árbol
balanceado de busqueda. Las palabras aparecen con diferente frecuencia, sin embargo,
y una frecuentemente palabra usada como "el" puede ser una raiz mientras que una palabra
raramente usada como "matacán" aparecerá cerca de la raíz. Tal organización debería ralentizar
la traducción, ya que el número de nodos visitados en la busqueda de una llave en el árbol
binario de busqueda es igual a uno más la profundidad del nodo que contiene la clave. Nosotros
queremos colocar cerca de la raíz las palabras más frecuentemente buscadas. además, algunas
palabras en el texto podrían no tener una traducción en frances, y tales palabras no deberían 
aparecer en el árbol de busqueda binario en absoluto. ¿cómo podemos hacer para organizar el
árbol de busqueda binario en cuanto a minimizar el número de nodos visitados en todas las
busquedas, dado que nosotros conocemos con que frecuencia ocurren las palabras?

			( k2 )										( k2 )
		   /      \									   /      \
	 ( k1 )        ( k4 )						 ( k1 )        ( k5 )
	/      \      /      \						/     \       /     \
   d0      d1 ( k3 )     ( k5 )				  d0       d1   ( k4 )   d5
			  /    \     /    \							   	/    \
			 d2    d3   d4    d5				 	   ( k3 )     d4
													   /	\		
													  d2     d3
				( a )                                    ( b )

Figura 15.9 Dos árboles binarios de busqueda para un conjunto de n = 5 llaves con las siguientes probabilidades

i |    0     1     2     3     4     5
pi|        0.15   0.10  0.05  0.10  0.20
qi|  0.05  0.10   0.05  0.05  0.05  0.10

a) Un árbol de busqueda binario con un costo esperado de busqueda 2.80.
b) Un árbol de busqueda binario con un costo esperado de busqueda 2.75. Este árbol es óptimo.


Lo que nosotros necesitamos es saber cómo es un árbol binario de busqueda optimo. 
Formalmente, nosotros obetenemos una secuencia K = <k1, k2, ..., kn> de n distintas llaves
ordenadas (tal que k1 < k2 < ... < kn), y nosotros desemos contruir un árbol de
busqueda binario desde estas llaves. Por cada ki, nosotros tenemos una porbabilidad pi que 
busquemos ki. Algunas busquedas pueden ser por valores no pertenecientes a K, y nosotros 
tenemos además n + 1 "llaves ficticias" d0, d1, d2, ..., dn representando valores que no están
en K. En particular, d0, representa todos los valores menos que k1, dn representa todos los
valores mayores que kn, y para i = 1, 2, ..., n-1, la llave fictícia di representa todos
los valores entre ki y k(i+1). Por cada llave fictícia di, nosotros tenemos una probabilidad qi
que una busqueda corresponda para di. Figura 15.9 vemos dos árboles de busqueda binarios para un conjunto
de n = 5 llaves. Cada llave ki es un nodo interno, y cada llave ficticia di es una hoja. Cada busqueda 
ya sea con exito (encontrando alguna llave ki) o sin exito (encontrando alguna llave fictícia di), y tal que tenemos
\\
	$$\sum_{i=1}^{n} \quad p_i \quad + \quad \sum_{i=0}^{n} \quad q_i \quad = \quad 1.\quad \quad 15.10$$


Porque nosotros tenemos probabilidades de busqueda por cada llave y por cada llave fictícia, nosotros podemos determinar
el costo esperado de una busqueda en un obtenido árbol de busqueda T. Supongamos que el actual costo de un árbol es igual
al número de nodos examinados, i.e., la profundidad de el nodo encontrado por una busqueda en T, más 1. Entonces el costo
esperado de una busqueda en T es\\
\\

$$E[costo busqueda en T] \quad =\quad \sum_{i=1}^{n} (depth_{T}(k_i)\quad + \quad 1).p_i \quad +\quad \sum_{i=0}^{n} (depth_{T}(d_i)
\quad +\quad 1).q_i \quad =\quad 1\quad +\quad \sum_{i=1}^{n} (depth_{T}(k_i).p_i \quad + \quad \sum_{i=0}^{n}depth_{T}(d_i).q_i) $$

\\
Donde $depth_{T}$ denota la profundidad de un nodo en el árbol T. La última igualdad se sigue de (15.10). In la figura 15.9(a), 
podemos calcular el costo de busqueda de nodo esperado para cada nodo:


nodo | profundidad | probabilidad | contribution

$k_1$ 	 	1		 	 0.15           0.30
$k_2$    	0        	 0.10           0.10
$k_3$    	2        	 0.05           0.15
$k_4$    	1       	 0.10			0.20
$k_5$    	2		  	 0.20 			0.60
$d_0$ 		2			 0.05   		0.15
$d_1$		2			 0.10			0.30
$d_2$		3			 0.05			0.20
$d_3$		3		     0.05			0.20
$d_4$		3			 0.05			0.20
$d_5$		3			 0.10			0.40

total								    2.80


Para un conjunto de probabilidades obtenido, nosotros deseamos construir un árbol de busqueda binario
donde el costo de busqueda esperado es el menor posible. Nosotros llamaremos a tal árbol un árbol de
busqueda binario óptimo. En la figura 15.9(b) observamos un árbol de busqueda óptimo para las 
probabilidades obtenidas en el caption de la figura; este costo esperado es 2.75. En este ejemplo
vemos que un árbol binario de busqueda óptimo no es necesariamente un árbol donde en general
la altura es la más pequeña. Y no necesariamente construiremos un árbol de busqueda óptimo poniendo
el nodo con la mayor probabilidad como raíz. Aquí la llave $k_5$ tiene la mayor probabilidad de busqueda
de alguna llave, sin embargo la raíz de el árbol de busqueda binario óptimo vemos que es $k_2$
(El menor costo esperado de algún árbol binario de busqueda con raíz &k_5& es 2.85)\\
Como con multiplicación de cadena de matrices, la comprobación exhaustiva de todas las posibilidades
falla para producir un algoritmo eficiente. Nosotros podemos etiquetar los nodos de algún n-nodo
árbol binario con la llaves $k_1$, $k_2$, ..., $k_n$ para construir un árbol de busqueda binario,
y entonces agregar las llaves ficticias como hojas. En el problema 12-4, nosotros vimos que el número
de árboles binarios con n nodos es $\omegha ({4^{n}\over n^{3\over 2}})$, y tanto nosotros deberiamos tener
que examinar un exponencial número de árboles binarios de busqueda en una exhaustiva busqueda. No es
sorprendente, resolveremos este problema con programación dinámica.

Paso 1: La estructura de un árbol binario de busqueda óptimo

Para caracterizar la óptima estructura de un árbol de busqueda binario óptimo, nosotros iniciamos 
con una observación sobre sus subárboles. Consideremos algún subárbol de un árbol binario de busqueda.
debería contener llaves en un continuo rango $k_i$, ..., $k_j$, para algún $1 <= i <= j <= n$. En suma,
un árbol que contiene llaves $k_i$, ..., $k_j$ también debe tener como sus hojas las llaves ficticias
$d_{i-1}$, ..., $d_j.$

Ahora nosotros podemos afirmar la óptima subestructura: Si un árbol binario de busqueda óptimo T tiene un
subárbol $T^{'}$ conteniendo $k_i, ..., k_j$, entonces este subárbol T^{'} debería ser también óptimo para
el subproblema con llaves $k_i$, ..., $k_j$ y las llaves ficticias $d_{i-1}$, ..., $d_j$. El usual cortar y pegar
argumento aplicado. Si hubiera un subárbol T_{''} donde el costo esperado es menor que el de T_{'}, entonces
nosotros deberiamos cortar T_{'} fuera de T y pegar en T_{''}, resultando en un árbol binario de bsuqueda de 
menor costo esperado que T, así contradiciendo la optimabilidad de T.


Nosotros necesitamos para armar una óptima subestructura ver que nosotros podemos construir una
solución óptima para el problema desde soluciones óptima para subproblemas. Obtenemos llaves 
$k_i$, ..., $k_j$, una de estas llaves, llamemos $K_r$ ($i<=r<=j$), es la raíz de un subárbol
óptimo conteniendo estas llaves. El árbol izquierdo de la raíz $k_r$ contiene las llaves $k_i$, ..., $k_{r-1}$
(y llaves ficticias $d_{i-1}$, ..., $d_{r-1}$), y el subárbol derecho contiene las llaves $k_{r+1}$, ...,
$k_j$ (y las llaves ficticias $d_r$, ..., $d_j$). Todo el tiempo que nosotros examinemos todas las raices candidatas $k_r$,
donde $i<=r<=j$, y nosotros determinamos todo árbol binario de busqueda óptimo conteniendo $k_i$, ..., $k_{r-1}$
y otros conteniendo $k_{r+1}, ..., k_{j}$, nosotros estamos garantizando que encontraremos un árbol binario de busqueda óptimo.

Hay un detalle digno de mención acerca de los subárboles "vacíos". Supongamos que en un subárbol con llaves $k_i$, ..., $k_j$,
nosotros seleccionamos $k_i$ como la raíz, por el argumento anterior, el subárbol izquierdo de $k_i$ contiene las llaves $k_i$, ...,
$k_{i-1}$. Interpretamos esta secuencia como que no contiene llaves. tener algo presente, sin embargo, el subárbol también
contiene llaves ficticias. Adoptamos la convención que un subárbol que contiene llaves actuales $k_i$, ..., $k_{i-1}$ no contiene
actualmente llaves, pero contiene la única llave ficticia $d_{i-1}$. Simetricamente si nosotros seleccionamos $k_{j}$ como la raíz
entonces el subárbol derecho de $k_j$ contiene las llaves $k_{j+1}$, ...,$k_j$; Este subárbol derecho contiene no llaves actuales, 
pero contiene la llave ficticia $d_j$.


Step 2: Una solución recursiva

Estamos listos para definir el valor de una solución recursiva óptima. Cojemos el dominio de nuestro subproblema como encontrando un
árbol binario de busqueda óptimo conteniendo las llaves $k_i$, ..., $k_j$, 	donde $i>=1$, $j<=n$, y $j>=i-1$. (Donde $j=i-1$, no existen
llaves actuales; nosotros tenemos justo la llave ficticia $d_{i-1}$.) Definamos e[i][j] como el costo de busqueda esperado 
de buscar en árbol binario de busqueda óptimo conteniendo las llaves $k_i$, ..., $k_j$. Por último, nosotros desemos computar
e[1][n].
\\

El caso fácil ocurre donde $j=i-1$. Entonces nosotros tenemos solo la llave ficticia $d_{i-1}$. El costo de busqueda 
esperado es  e[i][i-1] $=$ $q_{i-1}$.
\\

Cuando $j>=i$, nosotros necesitamos para seleccionar una raíz $k_r$ desde entre $k_i$, ..., $k_j$ y entonces hacer un árbol binario de
busqueda óptimo con las llaves $k_i, ..., $k_{r-1}$ como el subárbol izquierdo y un árbol binario de busqueda óptimos con las llaves
$k_{r+1}$, ..., $k_j$ como el subárbol derecho. ¿Qué ocurre con él costo busqueda esperado de un subárbol cuando éste se convierte
en un subárbol de un nodo? La profundidad de cada nodo incrementa en uno. Por la ecuación (15.11), el costo de busqueda esperado
de este subárbol incrementa por la suma de todas las probabilidades en el subárbol. Para un subárbol con llaves $k_i$, ..., $k_j$,
denotemos esta suma de probabilidades como w[i][j] $=$ $\sum_{l=i}^j p_l + \sum_{l=i-1}^j q_l$.

Por lo tanto, si $k_r$ es la raíz de un subárbol óptimo conteniendo las llaves $k_1$, ..., $k_j$, nosotros tenemos
e[i][j] = $p_r$ + (e[i][r-1] + w[i][r-1]) + (e[r+1][j] + w[r+1][j])

Señalamos que

w[i][j] = w[i][r-1] + $p_r$ + w[r+1][j]

Nostros reescribimos e[i][j] como

e[i][j] = e[i][r-1] + e[r+1][j] + w[i][j]				15.13

En la ecuación recursiva (15.13) asumimos que nosotros conocemos cual nodo $k_r$ usamos como la raíz.
Escojemos la raíz que da el menor costo esperado de busqueda, obteniendo la formula de nuestra
final ecuación recursiva:

e[i][j] $=$ \lbrace $q_{i-1}$, si j = i-1
					min_{i<=r<<=j}{e[i][r-1] + e[r+1][j] + w[i][j]}, si $i<=j$		15.14


El valor e[i][j] obtiene el costo esperado de busqueda en un árbol binario de busqueda óptimo.
Para ayudarnos a mantener un registro de la estructura del árbol binario de busqueda óptima, 
nosotros definimos root[i][j], para $1<=i<=j<=n$, para ser indexado r por el cual $k_r$ es la raiz de un 
árbol binario de busqueda óptimo conteniendo las llaves $k_i$, ..., $k_j$. A pesar de que 
nosotros vimos como computar el valor root[i][j], Nosotros dejamos la contrucción de un árbol binario de busqueda
óptimo para estos valores como ejercicio (15.5 - 1)

Paso 3: Computando el costo esperado de busqueda de un árbol binario de busqueda óptimo.

En este punto, Se habrá dado cuenta de algunas similitudes entre nuestra caracterización de nuestro
árbol binario de busqueda óptimo y la multiplicación de cadenas de matrices. Tanto para los dominios de los problemas,
nuestros subproblemas consisten de subrangos continuos indexados. Una directa, recursiva implementación de la ecuación
(15.14) sería tan ineficas como directa, recursivo algoritmo de multiplicación de cadenas de matrices. En lugar,
nosotros guardamos el valor de e[i][j] en una matriz e[1 ... n+1, 0 ... n]. El primer indice debe correr a n+1 en lugar de n
porque para tener un subárbol conteniendo solo la llave ficticia $d_0$, nosotros necesitamos para computar y guardar 
e[1][0]. Nosotros usamos solo las entradas e[i][j] por cada $j>=i-1$. Nosotros solo usamos una matriz root[i][j], 
para recordar la raíz del subárbol conteniendo llaves $k_i$, ..., $k_j$. Esta tabla usa solo las entradas para cada
$1 <= i <= j <= n$.
\\

Vamos  a necesitar otra tabla para la eficiencia. Mejor que computar el valor de w[i][j] desde cero cada vez que estamos 
calculando e[i][j] -deseamos nosotros hacer O(j-i) additions- nosotros guardamos estos valores en una tabla w[1 ...n+1,0 ...n].
Para el caso base, nosotros computamos w[i][i-1] = q_{i-1} para 1 <= i <= n+1. Para j>= i, nosotros computamos

					w[i][j] = w[i][j-1] + p_j + q_j
					
Así, nosotros podemos computar el O(n²) valores de w[i][j] in O(1) cada vez.
	El pseudocódigo que sigue recibe la entrada p_1, ..., p_n y q_0, ..., q_n y el tamaño n, y este retorna la tabla e y root.
*/	
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>	
#define N 100
#define fe(x, y, z) for(int x = y; x <= z; x++)
	
using namespace::std;

struct punto{
	int x, y;
	punto() {}
	punto(int xx, int yy) : x(xx), y(yy) {}
};


string key[N];
float e[N][N], w[N][N];
int root[N][N];
float p[N], q[N];
int n;

void optimal_BST( void ){
	fe(i, 1, n+1){
		e[i][i-1] = q[i-1];
		w[i][i-1] = q[i-1];
	}
	fe(l, 1, n)
		fe(i, 1, n-l+1){
			int j = i+l-1;
			e[i][j] = 1000000.0; //infinito sin overflow
			w[i][j] = w[i][j-1] + p[j] + q[j];
			fe(r, i, j){
				float t = e[i][r-1] + e[r+1][j] + w[i][j];
				if(t < e[i][j])
				{
					e[i][j] = t;
					root[i][j] = r;
				}
			}
		}	
}


void print_T2(int i, int j, int t){
	t += 3;
	if(i <= j){
		print_T2(i, root[i][j] - 1, t);
		cout << setw(t) << "(" << root[i][j] << ", " << e[i][j] << ")" << endl;
		print_T2(root[i][j] + 1, j, t);
	}
	else if(j == i -1)
		cout << setw(t) << "(" << "d" << j << ", " << e[i][j] << ")" << endl;
}


punto minimum(int i, int j){
	while(i < j)
		j = root[i][j] - 1;
	
	return punto(i, j);
}

punto maximum(int i, int j){
	while(i < j)
		i = root[i]{j] + 1;
	
	return punto(i, j);
}


bool erase(int i){
	if(n > 0){
		n--;
		q[i-1] += q[i] + p[i];
		for(int j = i; j <= n; j++)
			p[i] = p[i+1];
		for(int j = i; j <= n; j++)
			q[i] = q[i+1];
		optimal_BST();
	}
	else
		cout << "Warning!" << endl;

}

int main( void )
{
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> p[i];

	for(int i = 0; i <= n; i++)
		cin >> q[i];

	optimal_BST();

	//nodo* x = (nodo*)malloc(sizeof(nodo));
	//construction(1, n, &x);
	//print_T(x);
	cout << endl;
	print_T2(1, n, 0);
	cout << endl;

	int d;
	cin >> d;
	erase(d);
	cout << endl;
	print_T2(1, n, 0);
	cout << endl;
	return 0;
}




/*
A partir de la descripción anterior y de la similitud con el matrix_chain_order procedimiento en seccion 15.2, usted
deberia encontrar el funcionamiento de este proceso bastante sencillo. el bucle for de lineas 2-4 inicializa los valores
e[i][i-1] y w[i][i-1]. El bucle for de lineas 5-14 usa la recurrencia (15.14) y (15.15) para computar e[i][j] y w[i][j]
para todo 1 <=i<=j<=n. En la primera iteración, donde l=1, el bucle coputa e[i][i] y w[i][i] para i = 1, 2, ..., n.
La segunda iteración, con l=2, computa e[i][i+1] y w[i][i+1] para i = 1, 2, ..., n-1 y en adelante. El interior del bucle
for, en lineas 10-14, intenta cada cadidato indexado r para determinar cual llave k_r usa como la raíz de un árbol binario
de busqueda óptimo conteniendo llaves ki, ..., kj. Este bucle for guarda el valor correiente de el indexado por r in
root[i][j], cuando este encuentra la mejor llave para usar como root.

Figura 15.10 vemos las tablas e[i][j], w[i][j], y root[i][j] computado por el proceso optimal_bst sobre las llaves de
distribución vistos en figura 15.19. Como in la matrix_chain_multiplication ejemplo de figura 15.5, la tablas son rotadas
para hacer que las diagonales se muestren horizontalmente. Optimal_bst computa las filas desde bottom to top y desde
izquierda para derecha para cada fila.
*/














 
 
 
 
































