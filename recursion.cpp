### Recursion

- Usualmente en ciencias de la computacion se habla de recursi\'on 
a la propiedad que tienen las funciones de llamarse a si mismas. 

- En matem\'aticas la noci\'on de recursion es muy similar, y se 
denota a las funciones o estructuras que tienen la singularidad 
de expresarse en terminos de si misma.

ejemplos:

	1. Factorial (!): el factorial muy ampliamente conocido, 
	se define de una forma recursiva:

					  {	1			si n = 1
				n! =  {	
					  { n * (n-1)!	en otro caso

	2. Greatest common divisor (gcd): El m\'aximo com\'un divisor es una
	funci\'on entera de dos variables muy \'util en teor\'ia de n\'umeros
	y se define como sigue:

						 { a		  	si b = 0	
			gcd(a, b) =  {
						 { gcd(b, a%b)  en otro caso


	3. Ackermann's function: La funci\'on de ackerman que a primera vista
	no es muy simple, tiene aplicaciones sorprendentes en muchos campos de
	las ciencias de la computaci\'on:

					 { j+1				si k = 0
			A_k(j) = {
					 {	A_{k-1}^{j+1}	en otro caso

	

### Enfoques:

	Hay ciertos enfoques que se dan a la recursi\'on, usualmente estos 
	enfoques vienen de su uso al resolver problemas del paradigma de 
	divide y conquitaras(Divide and Conquer):

	- Enfoque usual: 
	
	supongamos que queremos hacer un determinado trabajo, para ello 
	disponemos de un n\'umero ilimitado de trabajadores, tal que cada
	trabajador tiene un jefe y un jefe puede tener muchos trabajadores
	a su cargo.

	Para hacer el cometido cada jefe envi\'a a hacer su trabajo a sus 
	subordinados y ellos a los suyos, y as\'i. esto sigue de este modo
	hasta que ya no se pueda dividir m\'as el trabajo y alguien
	har\'a lo suyo y listo.  
	   

	ejemplo:
	
	merge-sort O(nlgn): Supongamos que queremos ordenar un array A 
	de n elementos de menor a mayor, entonces vamos a llamar a dos 
	trabajadores que ordenen los floor(n/2) y ceil(n/2) que forman 
	todos los elementos.

	code:
		
		void mergeSort(int l, int r){ 

			if(l+1>r) return; //1 elemento ya esta ordanado por si mismo 

			int mid = (l+r)/2;
			mergeSort(l, mid); //mando la primera mitad a un trabajador
			mergeSort(mid+1, r); //mando la segunda mitad al otro
			merge(l, r); //junto cada mitad inteligentemente 
		}				 //(esto se explicada en su debido momento).

		
	binary search O(lgn): pensemos que nuestro algoritmo merge sort 
	funcion\'o correctamente, ahora nos aqueja una duda: Esta el 
	n\'umero x en nuestro array?, lo primero que se nos venga a la 
	mente puede ser una fuerza bruta sobre los elementos y asi un 
	O(n) algoritmo para encontrarlo pero, recordemos que est\'a 
	ordenado! Resolvamos el problema as\'i: miremos el elemento en 
	el medio de nuestro array digamos en la posicion r, entonces 
	los elementos se cumple: $A_1 \leq \dots \leq A_{r-1} \leq A_r
	\leq A_{r+1} \leq \dots \leq A_n$ ahora si A_r == x, resolvimos
	el problema, en cambio si x < A_r entonces debo buscar en los 
	r-1 primeros elementos y si x > A_r en los n-r \'ultimos. As\'i
	nuestro algorimo es:

	code:
	
		bool binary_search(int l, int r, int x){
						
			if(l==r) return A[l] == x; //con un solo elemento es f\'acil.
			
			int mid = (l+r)/2;	//determinamos la mitad.
			if(A[mid] == x) return true;
			if(A[mid] > x) return binary_search(l, mid, x) //busco en la primera mitad
			if(A[mid] < x) return binary_search(mid+1, r, x); //busco en la segunda
		}


	
	Enfoque backtrack:

	Supongamos que tenemos que recorrer un laberinto pero, desde luego no
	sabemos por donde ir, entonces, marcar\'e la posici\'on que ocupo e ir\'e 
	a una posici\'on no marcada si no encuentro soluci'on regresare a
	mi actual posici\'on y buscare otro camino, as\'i si hay salida la
	encontrar\'e.

 
	Ejemplo:

		
	depth first search (dfs): la busqueda por profundidad plantea este
	enfoque recursivo para resolver por ejemplo el problema del laberinto:

	
	void dfs(pos){
		marcar pos = true;
		if(salida == pos) return true;

		bool sali = false;
		for(todos las posiciones v que puedo ir desde pos)
			if(no marque v)
				sali = sali or dfs(v);

		return sali;
	}

	
	Enfoque grafos:

	Este es un enfoque \'util que nos servira m\'as adelante, y es ver 
	todo el proceso de la busqueda en vez de solo un estado a la vez.
	Por ahora no se hablara de este enfoque pero nos daremos cuenta
	de muchas conexiones con la teor\'ia de grafos.

	
### C\'alculo de la complejidad de un algoritmo recursivo.

	No siempre es f\'acil hallar la complejidad de una recursi\'on,
	pero algo s\'i es seguro, para resolver este tipo de complejidades
	debemos conocer como resolver una funci\'on recursiva.

	metodos simples:	

	ejemplo 1: sea la funcion recursiva:

			   {  1			   , n == 0 
		T(n) = {
			   {  2*T(n-1) + 1 , en otro caso.


	Para resolver este tipo de funciones recursivas podremos usar
	nuestros conocimientos de notaci\'on asint\'otica y haremos
	algunas asunciones:

	simple inspecci\'on:

	T(n) = 2*(2*T(n-2) + 1) + 1 = 4*T(n-2) + 3 = 8*T(n-3) + 7 =
	... = (2^n)*T(0) + 2^n - 1 = 2^{n+1} - 1.

	por tanto T(n) = 2^{n+1} - 1 = $O$(2^n).


	ejemplo 2: tenemos la siguiente recursi\'on:

					{ 1			  , n == 1
			T(n) =  {
					{ 2*T(n/2) + 1, en otro caso.
	

	Asunci\'on n es una potencia de 2, sea n = 2^m, entonces,
	haciendo el respectivo cambio de variable:

					 { 1				, 2^m == 1 
			T(2^m) = {
					 { 2*T(2^{m-1}) + 1 , en otro caso

	Ahora haremos un cambio de variable y llamaremos G a la funci\'on
	que cumple G(m) = T(2^m):

					{ 1					, m == 0
			G(m) =  {
					{ 2*G(m-1) + 1    	, en otro caso.
	

	pero, este problema ya lo hicimos:

				  
			G(m) = 2^{m+1} - 1


	ahora regresamos a nuestra variable n y tenemos:

			T(n) = 2*n - 1 = O(n)

	
	ejemplo 3 (merge sort):
	
				   { 0			  , n == 1
			T(n) = {
				   { 2*T(n/2) + n , en otro caso


	aqu\'i tambi\'en usaremos un cambio de variable y
	definamos una nueva funci\'on G igual que en el
	anterior ejemplo:

				   { 0			    , m == 0
			G(m) = {
				   { 2*G(m-1) + 2^m , en otro caso

  
	si evaluamos tenemos:

		G(m) = 4*G(m-2) + 2*2^m = 8*G(m-3) + 3*2^m = 
		... = 2^m*G(0) + m*2^m = m*2^m = 
		lg(n)*n = O(nlgn).

	entonces T(n) = O(nlgn).

	metodos m\'as complicados:

	ejemplo 1: tenemos la siguiente recursi\'on:
		
			   { 1				, n <= 2
		T(n) = {	    
			   { T(n-1) + T(n-2), en otro caso.

	
	para ello tomamos su polinomio caracter\'istico:

	
		X^n - X^{n-1} - X^{n-2} = 0

	y hallamos sus soluci\'on homogenea desechando 
	las soluciones nulas, entonces tenemos:

		X^2 - X - 1 = 0

	con raices X_1 = (1+sqrt(5))/2, X_2 = (1-sqrt(5))/2

	por tanto la soluci\'on seria:

		
		T(n) = c_1*X_1^n + c_2*X_2^n

	y hallando T(1) y T(2) tenemos:

		T(n) = (1/sqrt(5))*(X_1^n - X_2^n).


	

























