//Bitset
#include <iostream>
using namespace std;

struct Bitset{
  long long m;
  Bitset(int x = 0){m = x;}
  const static long long empty_set = 0;
  bool Find(int in){return m&(1LL<<in);}
  void Erase(int in){ m &= ~in;}
  void Insert(int in){m |= in;}
  int cardinal(){return __builtin_popcount(m);}
  bool operator==(const Bitset& X){return m == X.m;}
  bool operator==(const long long& X){return m == X;}
  friend long long Union(const Bitset& X, const Bitset& Y){return X.m|Y.m;}
  friend long long Intersect(const Bitset& X, const Bitset& Y){return X.m&Y.m;}
  friend long long Xor(const Bitset& X, const Bitset& Y){return X.m^Y.m;}
};

int main(){  

  Bitset A, B, C;
  
  A.Insert(1); 
  A.Insert(2);
  A.Insert(5);
  
  B.Insert(4);
  B.Insert(5);
  B.Insert(3);
	
  C.Insert(1); 
  C.Insert(2);
  C.Insert(3);
  C.Insert(4);
  C.Insert(5);

  if(C == Intersect(A, B)) cout << "A U B = C" << endl;

  return 0;
}
