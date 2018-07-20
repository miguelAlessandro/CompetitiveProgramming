#include <iostream>
#include <sstream>

using namespace::std;

int main(){

    string line, word;
    char c;
    
    while(getline(cin, line))
    {
        for(int i = 0; i < line.length(); i++)
            if(line[i] == ' ' || i == line.length() - 1)
            {
                if(line[i] != ' ')
                    word.push_back(line[i]);
                for(string::const_reverse_iterator it = word.crbegin(); it != word.crend(); ++it)
                    cout << *it;
                word.clear();
                if(line[i] == ' ')
                    cout << ' ';
            }
            else
                word.push_back(line[i]);
        cout << endl;
    }
    return 0;
}
