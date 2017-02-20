#ifdef JUDGE
#include <fstream>
std::ifstream cin("aplusb.in");
std::ofstream cout("aplusb.out");
#else
#include <iostream>
#endif
using namespace std;
  
int main() {
    int a, b;
    cin >> a >> b;
    cout << a + b << endl;
    return 0;
}
