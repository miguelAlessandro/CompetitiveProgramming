#include <iostream>
#include <fstream>
#include <string>

using namespace::std;

string A, B;

int main(){
    ofstream fout("ride.out");
    ifstream fin("ride.in");

    fin >> A >> B;
    int a = 1, b = 1;
    for(string::iterator it = A.begin(); it != A.end(); ++it)
        a = a*(*it - 'A' + 1)%47;
    for(string::iterator it = B.begin(); it != B.end(); ++it)
        b = b*(*it - 'A' + 1)%47;
    if(a == b)
        fout << "GO" << endl;
    else
        fout << "STAY" << endl;

    return 0;
}
