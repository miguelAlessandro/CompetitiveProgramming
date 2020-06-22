/**
 *	@name COCI 2015 contest 3 #4 SLon
 *	@author Miguel Mini
 *	@tag recursion, number_theory
 *	@idea
 *			optimizations:
 *				- if current expresion E is equal (F)
 *				solve F.
 *
 *				- if expresion E is only a number return value
 *	
 *				- solve the last + or - that is not covered 
 *				by a parenthesis (skip number and parenthesis)
 *
 *				- solve ther last * that is not covered by 
 *				a parenthesis (skip number and parenthesis)
 *
 *				- if there is not + to solve more, now we must 
 *				avoid them to improve complexity
 * 
 *	@complexity O(m + |A|) or O(|A| + log(m))
**/

#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
char a[maxn];
int p, mod;
int value[maxn];
int init[maxn];
int bck[maxn];

int add(int a, int b) {
	return a + b >= mod ? a + b - mod : a + b;
}

int mul(long long a, long long b) {
	return a * b % mod;
}

typedef pair<int, int> pii;
pii oper(pii p, pii q, char op) {
	if (op == '+') {
		return {add(p.first, q.first), add(p.second, q.second)};	
	}
	if (op == '-') {
		return {add(p.first, mod - q.first), add(p.second, mod - q.second)};
	}
	if (op == '*') {
		return {
			add(mul(p.first, q.second), mul(q.first, p.second)), 
			mul(p.second, q.second)
		};
	}
}

pii reduce(int l, int r, bool tom) {
	if (l == r) return a[r] == 'x' ? pii(1, 0) : pii(0, value[r]);
	if (init[r] == l) return {0, value[r]};
	if (bck[r] == l) return reduce(l+1, r-1, 1);
	if (tom)
	for (int i = r; i >= l; --i) {
		if (a[i] == ')') {
			i = bck[i];
		} else if (isdigit(a[i])) {
			i = init[i];
		} else if (a[i] == '+' or a[i] == '-') {
			return oper(reduce(l, i-1, 1), reduce(i+1, r, 0), a[i]);
		}
	}
	for (int i = r; i >= l; --i) {
		if (a[i] == ')') {
			i = bck[i];
		} else if (isdigit(a[i])) {
			i = init[i];
		} else if (a[i] == '*') {
			return oper(reduce(l, i-1, 0), reduce(i+1, r, 1), a[i]);
		}
	}
} 

void preprocess() {
	stack<int> p;
	bool last = 0;
	memset(init, -1, sizeof init);
	memset(bck, -1, sizeof bck);
	for (int i = 0; a[i]; ++i) {
		if (a[i] == '(') p.push(i);
		else if (a[i] == ')') bck[i] = p.top(), p.pop();
	
		if (isdigit(a[i])) {
			if (last) {
				value[i] = add(mul(10, value[i-1]), a[i] - '0');	
				init[i] = init[i-1];
			} else {
				value[i] = add(a[i] - '0', 0);
				init[i] = i;
				last = 1;
			}
		} else {
			last = 0;
		}	
	}
}

int main() {
	scanf("%s %d %d", a, &p, &mod);
	preprocess();
	auto eq = reduce(0, strlen(a) - 1, 1);
	for (int i = 0; i < mod; ++i) {
		if (add(mul(i, eq.first), eq.second) == p) {
			printf("%d\n", i);
			return 0;
		}
	}
	return 0;
}
