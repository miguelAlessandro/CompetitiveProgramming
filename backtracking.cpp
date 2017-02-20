### Backtracking


	backtracking es un enfoque recursivo que se le da a los problemas
	de fuerza bruta en los que se desea hallar una n-tupla [x_1, x_2, 
	..., x_n] que cumpla con ciertas caracter\'isticas.

	
	backtracking es una herramienta muy \'util, analizaremos su
	forma m\'as b\'asica:


	'''cpp
		
		void backtrack(pos, [x_1, x_2, ...., x_pos-1], e_1, e_2, ..., e_k){

			if(ya forme mi tupla){
				analizar tupla
				return
			}

			for(para todos los posible x_pos)
				if([x_1, ..., x_pos] verifica las caracter\'isticas)
					backtrack(pos+1, [x_1, x_2, ..., x_pos], e'_1, e'_2, ..., e'_k)

		}

	'''

	Veremos m\'as utilidades de este enfoque en la pr\'actica, por ahora
	es un simple m\'etodo de construcci\'on.

### Partes de un backtracking

	- estados terminales:

		Los estados terminales son estados espec\'ificos en los cuales
		yo tengo que hacer una inspecci\'on sobre el resultado.

		Estos tienen que ser f\'aciles de hallar, generalmente
		algunos de los e_i o pos ser\'an suficientes.

	- transiciones de estado:

		Se llamar\'an transiciones entre estados a las llamadas
		recursivas.

	- estados bueno:

		En la transici\'on de pos a pos+1 siempre tiene que ser
		de un estado que no incumple las reglas a uno que tampoco 
		las incumple, as\'i siempre que nos toque analizar un estado
		ser\'a v\'alido.

	- espacio de estados:

		El espacio de estados es un conjunto de m-tuplas 
		que llevan informaci\'on suficiente para hacer las 
		transiciones entre estados, el error m\'as com\'un en
		alguien que recien empieza es caracterizar este espacio
		con m\'as dimensiones de las necesarias.

	- espacio de pseudo-estados:

		El espacio de peudo estados esta compuesto por
		k-tuplas que llevan informaci\'on extra para
		minimizar algunos c\'alculos.
	

### Formando nuestro espacio de estados.

	ejemplo simple: 
	
	supongamos que queremos hallar las distancias entre todas las
	permutaciones de los elementos {1, 2, ..., n} con dos \'unicos
	puntoa fijos.

	la distancia se define de la manera usual tal que para dos
	permutaciones P = {p_1, p_2, ..., p_n} y Q = {q_1, q_2, ..., q_n},
	|P-Q| = sqrt((p_1-q_1)^2 + (p_2-q_2)^2 + ... + (p^n-q^n)^2) 

	planteamiento de busqueda completa:

		reducci\'on del enunciado:

		- si yo tuviera la lista de todas las permutaciones 
		[p1, ..., pn] con solo dos puntos fijos, tenemos 
		que simplemente hallar todas las distancias...

		- hallar [p1, ..., pn] con dos puntos fijos lo atacaremos
		por backtracking...

		reconocimiento de estados:

		- primero debo guardar mis tuplas, por tanto como en
		la transicion esta tupla va cambiando, entonces
		debe ser parte de mis estados.

		- la cantidad de puntos fijos hasta el momento debe
		pertenecer a mi estados? claramente, no. Ya  
		que la actual tupla guarda esta informaci\'on
	
		- una mascada de bits que me diga cuales elemento he 
		usado? no.

		- cuantos elementos tiene nuestro vector? esto
		si, pero si uso un vector din\'amico esto ya se guarda...

		- el 2do y 3ro no son partes de los estados, pero seran
		partes de pseudo-estados.
		

	soluci\'on al backtracking:
	
		vector< vector<int> > solve;
		int n;
	
		void backtrack(int pos, vector<int>& p, int mask, int pf){

			if(pos == n){
				if(pf == 2) solve.push_back(p);		
				return;
			}
			
			for(int i = 0; i < n; ++i)
				if(((~mask)&(1<<i)) and pf+(pos==i) <= 2){
					p.push_back(i+1);
					backtrack(pos+1, p, mask|(1<<i), pf + (pos==i));
					p.pop_back();
				}
		}

	soluci\'on al problema:

		double ex2(double a){
			return a*a;
		}

		double dis(int x, int y){

			double r = 0;
			for(int i = 0; i < n; ++i)
				r += ex2(solve[x][i]-solve[y][i]);

			return sqrt(r);
		}

		vector<int> v;

		int main(){

			cin >> n;
			backtrack(0, v, 0, 0);			

			double ans = 0;
			for(int i = 0; i < solve.size(); ++i)
				for(int j = i+1; j < solve.size(); ++j)
					ans += dis(i, j);

			cout << 2.0*ans << endl;

			return 0;
		}


	calculando la complejidad:

		complejidad del backtracking
		
			ultimo nivel:
			T(n, per), usted estar\'a de acuerdo
			que la complejidad en este nivel
			es el n\'umero de permutaciones con 0, 1 y 2 
			puntos fijos.

			a\'un no tenemos las herramientas necesarias
			para atacar este tipo de problemas, pero se
			dejar\'a una aproximaci\'on: n!/e 
		
			tengamos en cuenta que cada estado es diferente a 
			los otros asi nuestra complejidad debe estar
			en el orden de (n+1)!/e, bueno con 10 funciona 
			en un tiempo < 3s.

	 	complejidad de la  soluci\'on:
	
			1.- la cantidad de permutaciones con dos puntos
			fijos es ~ (n-2)!/e.

			2.- hacemos un doble for y luego dis tiene
			complejidad O(n)

			3.- por tanto, nuestro algoritmo es O([(n-2)!/e]^2 *
			n + (n+1)!/e) = O([(n-2)!/e]^2*n),
			por stirling tenemos: 
			O(([(n-2)/e]^{n-2}*sqrt(2*pi*(n-2)))^2*n) = 
 			O(([(n-2)/e]^{n-2})^2 *(2*pi*(n^2))) 
			, que para n pequegno haciendo algunas aproximaciones
			tenemos O(n^{n+1}) por tanto: n $\leq$ 8.


### Problema de las 8 reinas.

	El problema de las 8 reinas, consiste en colocar
	8 reinas en un tablero de tal forma que ninguna 
	de ellas se ataquen entre si. Se le pide imprimir
	todas las configuraciones posibles. 

	- Planteamiento del problema  
	
		- Reducci\'on del enunciado:
		
			Este problema se puede solucionar encontrando
		todas las 8-tuplas [x_1, x_2, ..., x_8] de tal 
		forma que 8  damas en las posiciones (1, x_1),
		(2, x_2), ..., (8, x_8) no se ataquen entre si

		- reconocimiento de estados:
		
			- de la misma forma que el problema anterior,
		necesitamos la permutaci\'on que estamos llevando
		ya que tenemos que imprimir todas estas.

	 		- tambi\'en debemos saber cuantoe elementos
		tiene mi permutaci\'on.

		soluci\'on al backtracking:

		vector< vector<int> > solve;

		void backtrack(int pos, vector<int>& p){

			if(pos == 8){
				solve.push_back(p);
				return;
			}

			for(int i = 0; i < 8; ++i){
				
				bool attack = false;
				
				for(int j = 0; j < pos; ++j)
					if(i == p[j] or abs(i - p[j]) == pos-j){ // i == p[j] nos dice que 
						attack = true;						 // comparten la misma fila
						break;								 // abs(i-p[j]) == pos-j 
					}										 // indica que pertenecen a 
															 // la misma diagonal
				
				if(not attack){	
					p.push_back(i);
					backtrack(pos+1, p);
					p.pop_back();
				}
			}

		}	


		complejidad actual: O(n!*n^2) con n == 8
		
		
		- reconocimiento de pseudo-estados:
	
			1.- podemos llevar una mascara de bits
			para saber que filas estamos usando.
			
			un poco de geometr\'ia:

			que tienen en com\'un las posiciones
			(4, 1), (3, 2), (2, 3) y (1, 4)? 
			pertenecen a la misma recta 
			x + y = 5 y 
			las posciones (1, 3), (2, 4), (3, 5),
			(4, 6), (5, 7) y (6, 8)?
			pertencen a la recta y - x = 2.
		
			la primera pregunta: cuantas de estas
			rectas, de cada tipo, pasan por el tablero?

			rpta: 15 de cada tipo

			la siguiente pregunta: como enumero estas
			rectas?

			del primer tipo x+y = c tenemos:

			0 $\leq$ x $\leq$ 7, 
			0 $\leq$ y $\leq$ 7.

			entonces 0 $\leq$ x+y $\leq$ 14,
			por tanto con una mascara de bits 
			es suficiente.

			del segundo tipo y-x = c tenemos:

			-7 <= y-x <= 7 entonces debemos
			guardas en la masca de bits
			y-x+7.
			
		- Soluci\'on al backtracking con bitmask.

		vector< vector<int> > solve;

		bool match(int mask, int i){
			return (~mask)&(1<<i);
		}

		void backtrack(int pos, vector<int>& p, int row, int d1, int d2){

			if(pos == 8){
				solve.push_back(p);
				return;
			}	

			for(int i = 0; i < 8; ++i)
				if(match(row, i) and match(d1, i+pos) and match(d2, i-pos+7)){
					p.push_back(i+1);					
					backtrack(pos+1, p, row|(1<<i), d1|(1<<i+pos), d2|(1<<i-pos+7));
					p.pop_back();
				}
		}

		complejidad: O(n!*n)

		- Soluci\'on al problema:

		vector<int> v;
		
		int main(){

			backtrack(0, v, 0, 0, 0);
		
			for(auto r : solve){
				for(int it : r)	
					printf("%d ", it);
				puts("");
			}

			return 0;
		}

# Backtracking para problemas de optimizaci\'on (forma simple):

### El problema de la mochila

	tenemos una mochila que tiene una 
	capacidad de C kg. y n productos
	con un peso w_i y un valor v_i cada
	uno, y queremos maximixar el valor
	de los objetos en nuestra mochila
	sabiendo que hay una cantidad ilimitada
	de estos, ahora imprimir este m\'aximo 
	valor, con los respectios objetos.

	- reduccion del problema:

	queremos la n-tuplas [x_1, x_2, ..., x_n]
	tal que x_1*w_1 + ... x_n*w_n <= C con
	x_1*v_1 + ... + x_n*v_n lo m\'aximo posible

	- reconocimiento de estados:

		- pos, x_1, ..., x_{pos-1}.
	
	- reconocimiento de subestados:

		- x_1*w_1 + ... + x_{pos-1}*w_{pos-1}
		- x_1*w_2 + ... + x_{pos-1}*w_{pos-1}
 
	- Soluci\'on al problema:

	pair<vector<int>, int> solve; 	

	void backtrack(int pos, vector<int>& p, int sw, int sv){

		if(pos == n){
			if(sv > solve.second) solve.first = {p, sv};
			return;
		}

		for(int i = 0; (i*w[pos] + sw) <= C; ++i){
			p.push_back(i);
			backtrack(pos+1, p, sw + i*w[pos], sv + i*v[pos]);
			p.pop_back();
		}
	}	

#Backtracking para problemas de optimizaci\'on (forma ligera)

Supongamos que tenemos el problema anterior pero esta
vez no nos importa imprimir el vector [x_1, ..., x_n]

- deshaciendonos de algunos estados:
	
	- como podemos ver para este problema podemos quitar 
	el vector p ya que si no necesitamos imprimir los
	elementos los pseudo-estados se haran cargo.
	
	- bajando el pseudo-estado a optimizar
	(nueva estructura del backtracking)

	int backtrack(int pos, int sw){

		if(pos == n) return 0;

		int ans = 0;
		for(int i = 0; i*w[pos] + sw <= C; ++i)
			ans = max(ans, i*v[pos] + backtrack(pos+1, sw + i*w[pos]));

		return ans;
	}

	- pero podemos codearlo de otra forma:

	int backtracking(int pos, int C){

		if(pos == n) return 0;

		int ans = 0;
		for(int i = 0 ; i*w[i] <= C; ++i)
			ans = max(ans, i*v[pos] + backtracking(pos+1, C-i*w[pos]));

		return ans;
	}
	
	- analizaremos m\'as profundo este tipo de problemas
	cuando lleguemos a programaci\'on din\'amica.














