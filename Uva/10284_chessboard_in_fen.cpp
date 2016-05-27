#include <iostream>
#include <cstdio>
#include <string>
#include <cctype>
#include <cstring>
#define FOR(A, i) for(typeof A.begin() i = A.begin(); i != A.end(); ++i)
#define N 15

int dki[8] = {0, -1, -1, -1, 0, 1, 1, 1},
    dkj[8] = {1, 1, 0, -1, -1, -1, 0, 1},
    dpiw[2] = {-1, -1},
    dpjw[2] = {1, -1},
    dpib[2] = {1, 1},
    dpjb[2] = {1, -1},
    dni[8] = {-1, -2, -2, -1, 1, 2, 2, 1},
    dnj[8] = {2, 1, -1, -2, -2, -1, 1, 2};

char T[N][N];

using namespace::std;


string row;
bool visit[N][N];

bool limite(int a, int b){
    return (a >= 1 && a <= 8 && b >= 1 && b <= 8);
}


void king(int i, int j){
    visit[i][j] = true;
    for(int l = 0; l < 8; ++l){
        int a = i + dki[l], b = j + dkj[l];
        if(limite(a, b))
            visit[a][b] = true;
    }
}


void peon(int i, int j, char p){
    visit[i][j] = true;
    if(p == 'p')
        for(int l = 0; l < 2; ++l){
            int a = i + dpib[l], b = j + dpjb[l];
            if(limite(a, b))
                visit[a][b] = true;
        }
    else
        for(int l = 0; l < 2; ++l){
            int a = i  + dpiw[l], b = j + dpjw[l];
            if(limite(a, b))
                visit[a][b] = true;
        }
}


void knight(int i, int j){
    visit[i][j] = true;
    for(int l = 0; l < 8; ++l){
        int a = i + dni[l], b = j + dnj[l];
        if(limite(a, b))
            visit[a][b] = true;
    }
}


void rook(int i, int j){
    visit[i][j] = true;
    for(int l = 1; l <= 8; ++l){
        int a = i + l;
        if(limite(a, j)){
            visit[a][j] = true;
            if(T[a][j] != '.')
                break;
        }
        else break;
    }
    for(int l = 1; l <= 8; ++l){
        int a = i - l;
        if(limite(a, j)){
            visit[a][j] = true;
            if(T[a][j] != '.')
                break;
        }
        else break;
    }
    for(int l = 1; l <= 8; ++l){
        int b = j + l;
        if(limite(i, b)){
            visit[i][b] = true;
            if(T[i][b] != '.') break;
        }
        else break;
    }
    for(int l = 1; l <= 8; ++l){
        int b = j - l;
        if(limite(i, b)){
            visit[i][b] = true;
            if(T[i][b] != '.') break;
        }
        else break;
    }
}

void bishop(int i, int j){
    
    bool m = true, n = true, p = true, q = true;
    visit[i][j] = true;
    for(int l = 1; l <= 8; ++l)
    {
        int a = i + l, b = j + l, c = i - l, d = j - l;
        if(limite(a, b) && m){
            visit[a][b] = true;
            if(T[a][b] != '.') m = false;
        }
        if(limite(c, d) && n){
            visit[c][d] = true;
            if(T[c][d] != '.') n = false;
        }
        if(limite(c, b) && p){
            visit[c][b] = true;
            if(T[c][b] != '.') p = false;
        }
        if(limite(a, d) && q){
            visit[a][d] = true;
            if(T[a][d] != '.') q = false;
        } 
    }
}


int main(){

    while(getline(cin, row)){
        memset(visit, false, sizeof visit);
        memset(T, '.', sizeof T); 
        int cont = 0;
        int i(1), j(1);
        FOR(row, it){
            if(*it == '/'){++i; j = 1;}
            else if(isdigit(*it)){j += (*it - '0');}
            else {T[i][j] = '*'; ++j;}
        }
        /*for(int i = 1; i <= 8; ++i)
        {
            for(int j = 1; j <= 8; ++j)
                cout << T[i][j];
            cout << endl;
        }*/


        i = 1; j = 1;
        FOR(row, it){
            //cout << *it;
            if(*it == '/') {++i; j = 1;}
            else if(isdigit(*it)) {j += (*it - '0');}
            else if(*it == 'k' || *it == 'K')   
                {king(i, j); ++j;}
            else if(*it == 'p' || *it == 'P')
                {peon(i, j, *it); ++j;}
            else if(*it == 'n' || *it == 'N')
                {knight(i, j); ++j;}
            else if(*it == 'r' || *it == 'R')
                {rook(i, j); ++j;}
            else if(*it == 'b' || *it == 'B')
                {bishop(i, j); ++j;}
            else if(*it == 'q' || *it == 'Q')
                {rook(i, j); bishop(i, j); ++j;}
        }

        //cout << endl;
        for(int m = 1; m <= 8; ++m){

            for(int n = 1; n <= 8; ++n){
                //cout << (int)visit[m][n];
                if(!visit[m][n]) ++cont;

            }
            //cout << endl;
        }

        cout << cont << endl;
    }

    return 0;
}
