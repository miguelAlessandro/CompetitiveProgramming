#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const double eps = 1e-9;

struct Point{
    double x, y;
    
    Point(){}
    Point(double x, double y){this->x = x; this->y = y;}
    
    bool operator<(const Point& p) const{
        return x < p.x || x == p.x && y < p.y;
    }
    
    Point operator-(const Point& p) const{
        return Point(x-p.x, y-p.y);
    }
    
    double operator*(const Point& p) const{
        return x*p.y - y*p.x;
    }
};

vector<Point> convexHull(vector<pont>& P){
    int n = P.size(), k = 0;
    vector<Point> H(2*n);
    
    sort(P.begin(), P.end());

    for(int i = 0; i < n; ++i){
        while(k >= 2 and 
             (H[k-1]-H[k-2])*(P[i]-H[k-2]) <= eps) --k;
        H[k++] = P[i];
    }
    for(int i = n-2, t = k + 1; i >= 0; --i){
        while(k >= t and 
             (H[k-1]-H[k-2])*(P[i]-H[k-2]) <= eps) --k;
        H[k++] = P[i];
    }
    H.resize(k-1);
    return H;
}


int main(){



    return 0;
}
