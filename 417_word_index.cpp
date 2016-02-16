#include <iostream>
#include <string>
#include <map>
#define f(x, y, z) for(char x = y; x <= z; ++x)
using namespace::std;

struct comparable{
    bool operator()(const string& p, const string& q) const{
        return (p.length() < q.length() || (p.length() == q.length() && p < q));
    }
};

int main(){
    string s;
    map<string, int, comparable> M;

    string B;
    f(i, 'a', 'z')
    {   
        B.push_back(i);
        M[B];   
        f(j, i+1, 'z')
        {
            B.push_back(j);
            M[B];
            f(k, j+1, 'z')
            {
                B.push_back(k);
                M[B];
                f(l, k+1, 'z')
                {
                    B.push_back(l);
                    M[B];
                    f(m, l+1, 'z')
                    {
                        B.push_back(m);
                        M[B];
                        B.pop_back();
                    }
                    B.pop_back();
                }
                B.pop_back();
            }
            B.pop_back();
        }
        B.pop_back();
    }           

    int t = 1;
    for(map<string, int>::iterator it = M.begin(); it != M.end(); ++it)
        it->second = t++;       

    while(getline(cin, s))
        cout << M[s] << endl;

    return 0;
}
