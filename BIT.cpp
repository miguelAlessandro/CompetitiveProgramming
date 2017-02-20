//Binary Indexed Tree (Fenwick Tree)
/*
	Descripcion:
		
		Fenwick Tree es una estructura de datos avanzada que 
		sirve para propagar informacion en un array n-dimensional.

	ejemplo de uso:
	
		Tenemos n cajas numeradas desde el 1 hasta el n. Entonces
		las posibles queries son:
	
		1.- Poner un marmol en la i-esima caja
		2.- Sumar los marmoles desde la caja 1 a la caja r.

	ventajas:
		
		1.- Usa menos memoria que segment tree.
		2.- Facil de codear.
		3.- Puede ser usado en problemas de secuencias de numeros.

	Idea basica:
		
		Se sabe que nosotros podemos representar cualquier numero
		como la suma de potencias de 2.

		Si aplicamos esta idea nosotros podemos expresar la suma 
		de box[1] ... box[r] como la suma de a lo mas k elementos
		tal que 2^k sea la mayor potencia de dos cercana a r.

	Prerequisitos:

		ultimo bit encendido: para poder hallar cual es el ultimo
		bit encendido en la forma binaria de un numero x nosotros
		podemos usar la siguiente operacion x&(~x+1) o x&(-x)
		 
		Ahora basicamente la suma de box[1] ... box[20] puede ser 
		dividida como la suma de box[1] ... box[16] + la suma de 
		box[17] ... box[20]
		
		de lo cual tenemos BIT[16] = box[1] + ... + box[16] y
		BIT[20] = box[17] + ... box[20].

		siguiente posicion en el BIT: para obtener la siguiente
		posicion en el BIT nosotros solo restamos 2 al ultimo bit
		encendido de la actual posicion.
		
		ejemplo: 20 ==> 16 = 20 - 20&-20 ==> 0 = 16 - 16&-16. 

*/

#include <iostream>
using namespace std;
typedef long long ll;
const int N = 100000;

class BIT{
	private:
		ll ft[N];
		int n;
	public:
		void init(const int n){
			this->n = n;
			memset(ft+1, 0, sizeof(ll)*n);
		}
		
		void update(int x, const int v){
			while(x <= n){
				ft[x] += v;
				x += x&-x;
			}
		}
			
		void query(int x){
			long long sum = 0;
			while(x > 0){
				sum += ft[x];
				x -= x&-x;		
			}
		}		
};


int main(){

	

	return 0;
}
