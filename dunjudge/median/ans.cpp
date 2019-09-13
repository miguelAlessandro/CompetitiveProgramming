#include <bits/stdc++.h>
#include "device.h"
using namespace std;

int Med3(int a, int b, int c);

int random(int l, int r) {
	return rand() % (r - l + 1) + l; 
}

typedef vector<int> vi;
int solve(int n, vi& L, vi& M, vi& R, int a, int b) {
    if (L.size() == n/2) return a;
    if (R.size() == n/2) return b;
    if (R.size() > L.size()) {
        swap(L, R);
        swap(a, b);
    }
    vi X, Y;
    if (L.size() > n/2) {
        int b2 = L[random(1, L.size()) - 1];
        for (int e : L) {
            if (b2 == e) continue;
            int x = Med3(a, b2, e);
            if (x == b2) X.push_back(e);
            else Y.push_back(e);
        }
        L.clear();
        for (int e : M) L.push_back(e);
        L.push_back(b);
        for (int e : R) L.push_back(e);
        M = Y; R = X; b = b2;
        return solve(n, L, M, R, a, b);
    } else {
        R.push_back(b);
        b = M[random(1, M.size()) - 1];
        for (int e : M) {
            if (e == b) continue;
            int x = Med3(a, b, e);
            if (x == b) X.push_back(e);
            else Y.push_back(e);
        }
        if (X.size() + R.size() > n/2) {
            M = X;
            for (int e : Y) L.push_back(e);
            L.push_back(a);
            a = b; b = R.back();
            R.pop_back();
            return solve(n, L, M, R, a, b);
        } else {
            M = Y;
            for (int e : X) R.push_back(e); 
            return solve(n, L, M, R, a, b);
        }
    }
}

int Median(int n) {
    if (n == 1) return 1;
    if (n == 3) return Med3(1, 2, 3);
	srand(time(0));
	int a, b;
	do {
	    a = random(1, n);
	    b = random(1, n);
	} while (a==b);
	vector<int> L, M, R;
	for (int i = 1; i <= n; ++i) {
		if (i == b or i == a) continue; 
		int x = Med3(a, b, i);
		if (x == a) L.push_back(i);
		else if (x == b) R.push_back(i);
		else M.push_back(i);
	}
    return solve(n, L, M, R, a, b);
}
