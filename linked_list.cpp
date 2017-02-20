#include <iostream>
using namespace std;

template<class T>
class List{
	private:
		static struct node{
			T key;
			node* next;
		} *head, *z, *t;		
	public:
		List(){
			head = new node;
			z = new node;
			z->next = head->next = z;
		}		
		void delete_next(node* t){
			t->next = t->next->next;
		}
	node* insertafter(T v, node* t){
		node* x = new node;
		x->key = v; x->next = t->next;
		t->next = x;
		return x;
	}
};

int main(){

	return 0;
}
