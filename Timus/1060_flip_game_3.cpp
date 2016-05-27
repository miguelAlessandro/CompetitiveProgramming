#include <cstdio>
#include <cstring>
#include <queue>

unsigned short dj[5] = {1, 0, -1, 0, 0},
               di[5] = {0, -1, 0, 1, 0},
               bitmask[1<<4], dist[1<<16],
               estado = 0,
               i, j, k, q, s;
std::queue<unsigned short> Q;

int main(){

    for(i = 0; i < 4; ++i){
        for(j = 0; j < 4; ++j){
            if(getchar() == 'b')
                estado |= (1 << (4*i + j));
        	for(k = 0; k < 5; ++k){
        		q = i + di[k], s = j + dj[k];
           		if(q >= 0 && q < 4 && s >= 0 && s < 4)
            		bitmask[4*i + j] |= (1 << (4*q + s));
  			}
  		}
  		getchar();
  	}

    std::memset(dist, ~0, sizeof dist);
    Q.push(estado);
    dist[estado] = 0;
    while(!Q.empty()){
        q = Q.front(); Q.pop();   
        if(q == 0 || q == (unsigned short)~0) {printf("%hu\n", dist[q]); return 0;}
        for(i = 0; i < 16; ++i){
            s = q^bitmask[i];
            if(dist[s] > dist[q] + 1)
                dist[s] = dist[q] + 1, Q.push(s);
        }
    }
    puts("Impossible");

    return 0;
}






