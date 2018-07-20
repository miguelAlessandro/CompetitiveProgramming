#include <iostream>
#include <stack>
#include <cstdio>

using namespace::std;

int t;
string A;
char c;
stack<char> P;

int main(){

    cin >> t;
    getline(cin, A);
    while(t--)
    {
        getline(cin, A);
        for(string::const_iterator it = A.cbegin(); it != A.cend(); ++it)
            if(*it == '(' || *it == '[')
                P.push(*it);
            else if(*it == ')')
            {   
                if(P.empty() || P.top() != '('){
                    P.push('+');
                    break;
                }
                P.pop();
            }
            else if(*it == ']')
            {
                if(P.empty() || P.top() != '['){
                    P.push('+');
                    break;
               }
               P.pop();
            }
        
        if(P.empty())
            cout << "Yes" << endl;
        else
            cout << "No" << endl;

        while(not P.empty()) P.pop(); 
    }
    return 0;
}
