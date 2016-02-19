#include <bits/stdc++.h>

using namespace::std;


string A, B;

bool palindromo = false;

bool es_palindromo(string& A)
{
    int l = A.length() - 1;
    for(int i = 0; i < A.length()/2; i++)
    {
        if(A[i] != A[l])
            return false;
        l--;    
    }
    return true;
}

int main( void )
{
    cin >> A;
    
    if(es_palindromo(A))
    {
        for(int i = 0; i < A.length(); i++)
        {
            if(i == A.length()/2)
                cout << A[i];
            cout << A[i];
        }
        cout << endl;
    }
    else
    {
        B = A;
        B.push_back(A[0]);
        if(es_palindromo(B))
           palindromo = true;
        
        B.clear();

        B.push_back(A[A.length() - 1]);
        for(int i = 0; i < A.length(); i++)
            B.push_back(A[i]);

        if(es_palindromo(B))
            palindromo = true;

        else
        {
            for(int i = 0; i < A.length(); i++)
            {
                B.clear();
                for(int j = 0; j < A.length(); j++)
                {
                    if(i >= A.length()/2 && A.length() - i - 1 == j)
                        B.push_back(A[i]);

                    B.push_back(A[j]);

                    if(i < A.length()/2 && A.length() - i - 1 == j)
                          B.push_back(A[i]);
                }
                if(es_palindromo(B))
                {
                    palindromo = true;
                    break;
                }
            }
        }

        if(palindromo)
        {
            cout << B << endl;
        }
        else
            cout << "NA" << endl;
    }
    

    return 0;
}
