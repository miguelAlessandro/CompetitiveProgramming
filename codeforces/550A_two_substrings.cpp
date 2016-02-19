#include <iostream>

using namespace::std;

string A;

int main( void )
{   
    cin >> A;
    int m = A.length();

    bool c = false, d = false, e = false, g = false;
    
    for(int i = 0; i < m - 1; i++)
    {
        if(A[i] == 'A' && A[i+1] == 'B' && !e)
        {
            for(int j = m - 1; j > i + 2; j--)
                if(A[j] == 'A' && A[j-1] == 'B')
                {
                    cout << "YES" << endl;
                    c = true;
                    break;
                }
            e = true;
        }
        else if(A[i] == 'B' && A[i+1] == 'A' && !g)
        {
            for(int j = m - 1; j > i+2; j--)
                if(A[j] == 'B' && A[j-1] == 'A')
                {
                    cout << "YES" << endl;
                    d = true;
                    break;
                }
            g = true;
        }

        if(c || d)
            break;
    }
    if(!c && !d)
        cout << "NO" << endl;
    
    return 0;
}
