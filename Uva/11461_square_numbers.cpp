#include <iostream>

using namespace::std;

int a, b, ca, cb;

int main( void ){

    while(cin >> a >> b && a + b != 0){

        cb = ca = 0;
        for(int i = 1; i*i < a; i++)
            ca++;
        for(int j = 1; j*j <= b; j++)
            cb++;

        cout << cb - ca << endl;
    }

    return 0;
}
