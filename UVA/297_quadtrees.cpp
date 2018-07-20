#include <iostream>
#include <string>

using namespace::std;

int t;
string f, s;
int timess, timesf;

void podar(int&, string&);
int recursive(string& F, string& S, int pixels){

    if(F[timesf] == 'f'){
        
        ++timesf;
        if(S[timess++] == 'p')
            podar(timess, S);

        return pixels;
    }
    if(S[timess] == 'f'){
        ++timess;
        if(F[timesf++] == 'p')
            podar(timesf, F);
        
        return pixels;
    }

    if(S[timess] == 'p' && F[timesf] == 'p'){
        ++timess; ++timesf;
        int r = 0;
        for(int i = 0; i < 4; ++i){
            r += recursive(F, S, pixels/4);
        }
        return r;   
    }
    if(F[timesf] == 'p' && S[timess] == 'e'){
        int r = 0;
        ++timesf;
        for(int i = 0; i < 4; ++i){
            r += recursive(F, S, pixels/4);
            --timess;
        }
        ++timess;
        return r;
    }
    if(F[timesf] == 'e' && S[timess] == 'p'){
        int r = 0;
        ++timess;
        for(int i = 0; i < 4; ++i){
            r += recursive(F, S, pixels/4);
            --timesf;
        }
        ++timesf;
        return r;
    }
    ++timess; ++timesf;
    return 0;
}

void podar(int& times, string& S){
    for(int i = 0; i < 4; ++i)
        if(S[times++] == 'p')
            podar(times, S);
}


int main(){

    cin >> t;
    while(t--){
       	cin >> f;
       	cin >> s;
        timesf = timess = 0;
        cout << "There are " << recursive(f, s, 1024) << " black pixels.\n";       
    }
    //cout << "\n";
    return 0;
}
