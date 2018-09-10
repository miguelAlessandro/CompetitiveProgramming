/**
 *  codeforces Div 1-2 C
 *  @overview: find the closest point with constant observation angle on three circles.
 *  - intersection is line o circle.
 *  - line to line only solve system ecuation
 *  - line with circle: calculate distance, rotate vector normal for ecuation ax+by+c (v = (a, b)) and sum to
 *  center of segment inside of circle (easy with proyection)
 *  - circle with circle: use cosine formula, rotate center to center vector and scaling with radius.
 *  tricks:
 *    - parallel lines
 *    - no circle touching line
 *    - no circle touching circle.
 *    - circle inside at circle.
 */




#include <bits/stdc++.h>
using namespace std;
#define double long double
struct Point {
    double x, y;    
    Point operator-(const Point p) {return {x-p.x, y-p.y};}
    Point operator+(const Point p) {return {x+p.x, y+p.y};}
    Point operator*(const double k) {return {x*k, y*k};}
    Point operator/(const double k) {return {x/k, y/k};}
};

double cross(Point p, Point q) {
    return p.x * q.y - p.y * q.x;
}
double dot(Point p, Point q) {
    return p.x * q.x + p.y * q.y;
}
Point rotate(Point p, double theta) {
    Point dir = {cos(theta), sin(theta)};
    return {p.x * dir.x - p.y * dir.y, p.x * dir.y + p.y * dir.x};
}
Point rotate90(Point p) {
    return {p.y, -p.x};
}

double norm(Point v) {
    return sqrt(dot(v, v));
}
double sdist(Point p, Point q) {
    return dot(p-q, p-q);
}
Point reScaling(Point p, double k) {
    return (p / norm(p)) * k; 
}
Point proy(Point p, Point q) {
    return (p * dot(p, q)) / dot(p, p);
}

const double eps = 1e-7;

vector<Point> capCC(Point c1, double r1, Point c2, double r2) {
    vector<Point> ans;
    double max_dis = r1 + r2;
    double sd = sdist(c1, c2);
    double asrt = max_dis * max_dis - sd;
    if (asrt > 0 and sqrt(sd) + min(r1, r2) >= max(r1, r2)) {      
        double theta = acos((sd + r1 * r1 - r2 * r2) / 2.l / r1 / sqrt(sd));
        Point v = reScaling(c2 - c1, r1);
        Point vl = rotate(v, theta) + c1; ans.emplace_back(vl);
        Point vr = rotate(v, -theta) + c1; ans.emplace_back(vr);
    }
    return ans;
}

void PP2Line(Point p, Point q, double& a, double& b, double& c) {
    a = p.y - q.y;
    b = q.x - p.x;
    c = cross(p, q);
}

vector<Point> capLC(Point c1, double r1, Point p, Point q) {
    double a, b, c;
    PP2Line(p, q, a, b, c);
    Point dir = {a, b};
    double dis = abs(dot(dir, c1) + c) / norm(dir);
    vector<Point> ans;
    if (dis < r1) {
        Point s = q + proy(p-q, c1-q);
        
        Point v = rotate90(dir);
        v = reScaling(v, sqrt(r1*r1 - dis*dis));
        Point vl = s - v; ans.emplace_back(vl);
        Point vr = s + v; ans.emplace_back(vr);
    } 
    return ans;
}

vector<Point> capLL(Point p1, Point q1, Point p2, Point q2) {
    double a1, b1, c1;
    PP2Line(p1, q1, a1, b1, c1);
    double a2, b2, c2;
    PP2Line(p2, q2, a2, b2, c2);
    vector<Point> ans;
    double det = cross({a1, b1}, {a2, b2});
    if(abs(det) > eps) { 
        double x1 = cross({a1, -c1}, {a2, -c2}) / det;
        double x2 = cross({-c1, b1}, {-c2, b2}) / det;
        ans.push_back({x2, x1});
    }
    return ans;
}

void toL(double a, double b, double c, Point& p, Point& q) {
    if (abs(a) < eps) {
        p = {0.L, -c/b};
        q = {1.L, -c/b};
    } else if (abs(b) < eps) {
        p = {-c/a, 0.L};
        q = {-c/a, 1.L};
    } else {
        p = {0.L, -c/b};
        q = {-c/a, 0.L};
    }
}

void toC(double c, double d, double e, Point& C, double& r) {
    C = {-c/2, -d/2};
    r = sqrt(c*c + d*d - 4.L*e) / 2.L;
}

void initL(Point c1, Point c2, Point& p, Point& q) {
    double a = 2 * (c2.x - c1.x);
    double b = 2 * (c2.y - c1.y);
    double c = c1.x * c1.x - c2.x * c2.x + c1.y * c1.y - c2.y * c2.y;
    toL(a, b, c, p, q);
}
void initC(Point c1, double r1, Point c2, double r2, Point& C, double& r) {
    double k = r2*r2 - r1*r1;
    double c = 2 * (c2.x * r1 * r1 - c1.x * r2 * r2);
    double d = 2 * (c2.y * r1 * r1 - c1.y * r2 * r2);
    double e = (c1.x * c1.x + c1.y * c1.y)* r2 * r2 - (c2.x * c2.x + c2.y * c2.y) * r1 * r1;
    toC(c/k, d/k, e/k, C, r);
}

int main() {

    Point c[3];
    int r[3];
    for (int i = 0; i < 3; ++i) {
        cin >> c[i].x >> c[i].y >> r[i];
    }
    
    vector<Point> ans;
    if (r[0] == r[1]) {
        Point p1, p2;
        initL(c[0], c[1], p1, p2);
        if (r[1] == r[2]) {
            Point q1, q2;
            initL(c[1], c[2], q1, q2);
            ans = capLL(p1, p2, q1, q2);
        } else {
            Point c1;
            double r1;
            initC(c[1], r[1], c[2], r[2], c1, r1);
            ans = capLC(c1, r1, p1, p2);
        }
    } else {
        Point c2;
        double r2;
        initC(c[0], r[0], c[1], r[1], c2, r2);
        if (r[1] == r[2]) {
            Point q1, q2;
            initL(c[1], c[2], q1, q2);
            ans = capLC(c2, r2, q1, q2);
        } else {
            Point c1;
            double r1;
            initC(c[1], r[1], c[2], r[2], c1, r1);
            ans = capCC(c1, r1, c2, r2);
        }
    }
    
    if (not ans.empty()) {
    double mx = 1e18;
    Point x;
    for (int i = 0; i < ans.size(); ++i) {
        if (mx > sdist(ans[i], c[0])) {
            mx = sdist(ans[i], c[0]);
            x = ans[i];
        }
    }

    cout << setprecision(7) << fixed << x.x << " " << x.y << endl;
    }
    
    return 0;
}
