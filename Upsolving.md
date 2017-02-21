problem 1:

solo existen 4 tipos de rangos segun la paridad de los limites

[par, par] : #escalones_pares - #escalones_impares = 1.
[par, impar] : #escalones_pares - #escalones_impares = 0.
[impar, par] : #escalones_pares - #escalones_impares = -1.
[impar, impar] : #escalones_impares - #escalones_pares = 0.

por tanto:
	 | #escalones_pares - #escalones_impares | <= 1

ademas, hay una entrada que no cumple la regla y es:

	#escalons_pares = #escalones_impares = 0 

dado que por lo menos debe haber un escalon.

code 1: O(1)

	cin >> a >> b;
	if(abs(a-b) <= 1 and (a or b)) cout << "YES" << endl;
	else cout << "NO" << endl;


////////////////////////////////////////////////////////////////////////

problem 2:

				CC
			 CCCCCCC    h2       --> subida = a cm/h (dia)
			CCCCCMCCC   |		 <-- bajada = b cm/h (noche)
			 CCCCCCC    |
			   CCCC     |
				||      |
				||  h1  |     
				||D	|   |
				||	|   |

inicio: 2 p.m.
hora de dormir: 10 p.m
hora de despertar: 10 a.m

primero debemos ver en que casos llega a la manzana en el primer dia:
que es cuando a*8 + h1 >= h2

segundo deberiamos preguntarnos en que casos no podemos llegar y en
que casos si, si no se pudo llegar el primer dia:

	dado que no se pudo llegar el primer dia, supongamos que se llego
	a una altura X < h2, entonces tenemos dos casos: 
		- los siguientes dias vamos alcanzando una altura mas alta.
		- los siguientes dias vamos retrocediendo o quedandonos en el mismo lugar.

	ahora, si sucede lo segundo primero tenemos que x = h1 + 8*a luego
	de nuestra condicion: 
		
		h1 + 8*a >= h1 + 20*a - 12*b --> b >= a


	en otro caso tenemos en los siguientes dias al finalizar el dia y noche: //se puede solucionar con simulacion O(n) 

		 		dia   |   noche
			   -----------------
		h1 + 8*a  	  |  h1 + 8*a - 12*b
	h1 + 20*a - 12*b  |  h1 + 20*a - 24*b 
	h1 + 32*a - 24*b  |  ...
			...		  |
			

	como no se cumple b >= a, entonces se debe cumplir a-b > 0, entonces
	al finalizar el dia k+1, nosotros tenemos que la altura alcanzada es:
		
				h1 + 8*a + 12*k*(a-b)

 
	como a-b > 0 entonces, entonces se alcanzara la altura h2 por primera
	vez en el menor k que cumpla:

			h1 + 8*a + 12*k*(a-b) >= h2

	pero esta es la definicion del minimo entero, por tando tenemos:

			k = ceil( (h2 - h1 - 8*a)/(12*(a-b)) ) = floor( (h2 - h1 + 4*a - 12*b - 1)/(12*(a-b)) )

code 2: O(1)

	cin >> h1 >> h2 >> a >> b; 

	if(h1 + 8*a >= h2) cout << 0 << endl;
	else if(a <= b) cout << -1 << endl;
	else cout << (h2 - h1 + 4*a - 12*b - 1)/(12*(a-b)) << endl;


//////////////////////////////////////////////////////////////////////////////////////////

problem 3:

	
	Lo primero que tenemos que observar es que al elevar 1378^n y sacar su ultimo digito
	tenemos que ese digito denotado x se puede ver hallar resolviendo la siguientes
	ecuacion modular:


				1378^n ~ x (mod 10) 
				(1370 + 8)^n ~ x (mod 10)   
				(10*k + 8)^n ~ x (mod 10)
				C(n, 0)*[(10*k)^n] + C(n, 1)*[(10*k)^n-1]*8	+ ... + C(n, n)*8^n ~ x (mod 10) 
				10*k' + 8^n ~ x (mod 10) //C(n, n) = 1
 				8^n ~ x (mod 10)	

	para solucionar este problema en un caso general y no solo para ocho, necesitamos
	conocer algunos conceptos de teoria de numeros, pero para este problema la
	restriccion (mod 10) tenemos que x pertenece al conjunto {0, 1, ..., 9}, ahora
	si observamos las primeras potencias de 8 modulo 10:

				8^1, 8^2, 8^3, 8^4, 8^5, ...
				  8,   4,   2,   6,   8, ...

	y podemos notar que estos 4 primeros numeros se repiten infinitamente... Pero, no 
	nos olvidemos del 0, ya que 8^0 = 1 y es un caso especial.


 
code 3: O(1)


	cin >> n;
	
	if(n == 0) cout << 1;
	else if(n%4 == 1) cout << 8;
	else if(n%4 == 2) cout << 4;
	else if(n%4 == 3) cout << 2;
	else cout << 6;

	cout << endl;


//////////////////////////////////////////////////////////////////////////////////////////

problem 4: 

	sean x_1, x_2, ..., x_n las fichas que me dan cada dia, entonces nos piden optimizar : 
		
		max(floor{(w_1*a)/b} + floor{(w_2*a)/b} + ... + floor{(w_n*a)/b})

		0 <= w_1 <= x_1
			.
			.
			.
		0 <= w_n <= x_n

	pero, dado que son variables independientes tenemos que es igual:
	
	 	max(floor{(w_1*a)/b}) + max(floor{(w_2*a)/b}) + ... + max(floor{(w_n*a)/b})
	
	
		0 <= w_1 <= x_1
			.
			.
			.
		0 <= w_n <= x_n


	por tanto solo debemos que optimizar por cada dia:

	veamos la funcion f(x) = floor((w_i*a)/b):

		
			|
		   H|					----
			|				----
		   .|			----
		   .|		----
		   .|	----
		   1|________________________________
			0 1 2      ....       x_i       	


	entonces si queremos obtener el maximo valor debe ser H,
	sea f(a_0) = f(a_1) = ... = f(a_k) = H, ahora nuestra 
	respuesta es k, sabemos:
	
		floor{[(a_0 + k)*a]/b} = H = floor{[a_0*a]/b},
		ademas sea a_0*a = b*l + f, entonces
		x_i*a = b*l + f + k*a, ahora como f < b, entonces
		x_i*a ~ k*a (mod b) -> k = [(x_i*a)%b]/a.


code 4: O(n)
		
	cin >> n;
	for(int i = 0; i < n; ++i){
		cin >> x_i;
		cout << ((x_i*a)%b)/a << " ";
	}
	cout << endl;



//////////////////////////////////////////////////////////////////////////////////////////////

problem 5:

	En este problema se pide hacer  un ordenamiento z, si es posible, en otro caso
	imprimir "impossible".

		
	input: a_1, a_2, ..., a_n.

	output: b_1, b_2, ..., b_n. z-ordenado 


			|
			|      |
			|	|  |     |           |
			|	|  |  |  |     |  |  |
			|	|  |  |  |     |  |  |
			|	|  |  |  |  |  |  |  |
			|______________________________
			   b_1   	...          b_N

	 solucion facil (easy greedy): O(nlgn)

		supongamos que tenemos los elementos a ordenados de menor a mayor, entonces
		nos basta partir por la mitad (ceil, floor) y formar el siguiente
		array c_1 = a_1, c_2 = a_n, c_3 = a_2, ..., c_(n-1) = a_(ceil(n/2)+1), c_n = a_(ceil(n/2)) 

		afirmacion: c es z-ordenado:

		prueba: dada esta construccion sea r el menor indice que no cumple la regla de
		estar z-ordenado, entonces: 
			si r es impar entonces ocurre:
	
				c_(r-1) <= c_r >= c_(r+1) pero dada la construccion 
				c_r = a_k para k <= ceil(n/2) y de la misma forma
				c_(r-1) = a_p y a_(r+1) = a_q para p y q > ceil(n/2)
				pero, como a esta ordenado de mayor a menor (-><-)

			si r es par, tenemos:

				c_(r-1) >= c_r <= c_(r+1) y de la misma forma
				que en el caso impar p y q <= ceil(n/2) y r > ceil(n/2) (-><-)

		por tanto, c es z-ordenado

		code:
			cin >> n;
			for(int i = 0; i < n; ++i)
				cin >> a[i];
			sort(a, a+n);
			for(int i = 0; i < n; ++i)
				if(i%2) cout << a[n-1-i/2] << " ";
				else cout << a[i/2] << " ";
			cout << endl;

	solucion dificil (easy-medium greedy): O(n)

		sea la siguiente construccion: recorremos los indices de a desde el 1 al n
		si estamos en una posicion impar y se cumple a_i > a_(i+1) entonces, 
		swap(a_i, a_(i+1)), si la posicion es par y a_i < a_(i+1) entonces,
		swap(a_i, a_(i+1)).

		afirmacion: bajo esta construccion a es z-ordenado

		prueba: sea la construccion descrita sea r el menor indice que falla la regla:
				
				si r es impar entonces:
				
					a_(r-1) >= a_r > a_(r+1), pero si nosotros hacemos swap(a_r, a_(r+1))
					tenemos a_(r-1) > a_(r+1) < a_r y dada la construciion no se debio
					hacer un swap (-><-)
			
				si r es par: (pruebe de la misma forma)

			por tanto, a ahora es z-ordenado.

		code:

			cin >> n;
			for(int i = 0; i < n; ++i){ 
				cin >> a[i];
		
				if(i%2 and a[i] < a[i-1]) swap(a[i], a[i-1]);
				else if(i%2 == 0 and a[i] > a[i-1]) swap(a[i], a[i-1]);
			}

			for(int i = 0; i < n; ++i)
				cout << a[i] << " "; 
			cout << endl;		


