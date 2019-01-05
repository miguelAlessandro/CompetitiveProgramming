/**
 *      meeting point
 *      =============
 *
 *      @autor  Miguel Min\'i
 *      @tag    geometry, rotate, range query, sweep line 
 *      @idea   
 *            - distance with 8 direction is L - infinity distance, then 
 *              dist((x1, y1), (x2, y2)) = max(|x1-x2|, |y1-y2|).[1]
 *              
 *            
 *            - let point be (x, y) and hyperplanes[2] be  H = [X - Y = x-y] and I = [X + Y = x+y]
 *            then:
 *            
 *            for any point (x', y') in {(H+ U I+) U (H- U I-)}, 
 *                  dist((x, y), (x', y')) = abs(y - y');
 *
 *            for any point (x'', y'') in {(H- U I+) U (H+ U I-)}, 
 *                 dist((x, y), (x'', y'')) = abs(x - x'')
 *            
 *                                         \ H+ U I+/
 *                                          \      /
 *                                           \    /           
 *                                  H+ U I-    . (x, y)   H- U I+
 *                                           /    \
 *                                          /      \
 *                                         / H- U I-\
 *
 *             - if we rotate - 45 degrees, then:                  
 *                                                
 *                                                 |
 *                                     H+ U I+     |       H- U I+
 *                                                 |      
 *                                                 |(x, y)
 *                                -----------------.-------------------
 *                                                 |
 *                                                 |    
 *                                      H+ U I-    |       H- U I-
 *                                                 |
 *
 *             - We can sort the points with: 
 *              
 *                      bool cmp(Point p, Point q) {
 *                          return p.x < q.x or p.x == q.x and p.y < q.y;
 *                      };
 *                       
 *             - Traverse these and maintain in four Fenwick Trees, respond easily, for example: 
 *             
 *                        suppose we stay in point (x, y), we traverse all less point for this moment
 *                        and if we want to respond for points in H+ U I+ then:                           
 *
 *                                query_BIT_to_y_in_range_with_weigth(y, maxy) - y * query_BIT_to_y_range_count(y, maxy)
 *
 *                        this query return sum for all y in points after to transform - y * number of points y in same range.
 *                        the same form to x.
 *      
 *        note than: [ax + by = c]+ == [ax + by >= c] and [ax + by = c]- == [ax + by <= c] 
 *
 *        [1] https://en.wikipedia.org/wiki/L-infinity
 *        [2] https://en.wikipedia.org/wiki/Hyperplane
 */

#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
struct Node {
    int x, y;
    int a, b;
} P[MAXN];
int n;


//// fenwick tree
long long ft[2][MAXN], sum[2][MAXN];
void update(int id, int pos, int v) {
    while (pos < MAXN) {    
        ft[id][pos] += v;
        sum[id][pos] += 1;
        pos += pos&-pos;
    }
}
long long query(int id, int pos, int x) {
    long long ans = 0;
    int cnt = 0;
    while (pos > 0) {
        ans += ft[id][pos];
        cnt += sum[id][pos];
        pos -= pos&-pos;
    }
    return ans - cnt *1ll* x;
}
////

long long distFrom[MAXN];
int main() {
    scanf("%d", &n);
    map<int, int> X, Y;
    for (int i = 0; i < n; ++i) {
        int x, y;
        scanf("%d %d", &x, &y); 
        P[i] = {x - y, x + y, x, y};
        X[x-y]; Y[x+y];
    }
    
    //coordinate compression
    int nx = 1;
    for (auto& x : X) x.second = nx++;
    int ny = 1;
    for (auto& y : Y) y.second = ny++;
    for (int i = 0; i < n; ++i) {
        P[i].x = X[P[i].x];
        P[i].y = Y[P[i].y];
    }
    
    //sort to sweep line
    sort(P, P+n, [](Node p, Node q) {
        return p.x < q.x or p.x == q.x and p.y < q.y;
    });
    
    for (int i = 0; i < n; ++i) {
        //respond for hyperplanes 
        distFrom[i] += abs(query(0, P[i].y-1, P[i].a));
        distFrom[i] += abs(query(1, MAXN-1, P[i].b) - query(1, P[i].y-1, P[i].b)); 
        
        //update point
        update(0, P[i].y, P[i].a);
        update(1, P[i].y, P[i].b);
    }
    memset(ft, 0, sizeof ft);
    memset(sum, 0, sizeof sum);
    for (int i = n-1; i >= 0; --i) {
        distFrom[i] += abs(query(1, P[i].y, P[i].b));
        distFrom[i] += abs(query(0, MAXN-1, P[i].a) - query(0, P[i].y, P[i].a));
        update(0, P[i].y, P[i].a);
        update(1, P[i].y, P[i].b);
    }
   
    printf("%lld\n", *min_element(distFrom, distFrom+n));
    return 0;
}
