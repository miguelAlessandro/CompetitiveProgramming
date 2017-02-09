int lcp(int x, int y){ 
    if (x == y) return n-x;
    int r = 0;
  
    int len = 0;
    while((1<<len) < n) len++;
  
    for (int i = len; i >= 0; --i)
        if(x >= n or y >= n) break;
        else if(P[i][x] == P[i][y]){
            x += (1<<i);
            y += (1<<i);
            r += (1<<i); 
        }
      
    return r;
} 
