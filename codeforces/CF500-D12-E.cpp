/**
 *  Codeforces 500 DIV 1 and 2 E
 *  @overview given n dominoes, find the cost to push x-th domino and declive that y-th  
 *  @solution:
 *    - you can use off line preprocessing and respond queries with most large x.
 *    - join i domino-set with i+1 domino-set, update length of empty spaces beginning
 *    in i-th posicion (empty spaces of no-merged dominoes), set this in sum[]
 *    - answer sum[x-th domino-set] - sum[y-th domino-set], this is correct because
 *    if you no merge x-th domino-set with y-th domino-set then y-th domino-set isnt modificated.
 */

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
int id[MAXN], rnk[MAXN];
int p[MAXN], l[MAXN];
int sum[MAXN], lft[MAXN];
int nxt[MAXN];
int ans[MAXN];
int dis[MAXN];
int scope[MAXN];
int curSum = 0;
int q;
int n;
struct Query {
	int x, y, id;
} Q[MAXN];

void init(int n) {
	for (int i = n; i >= 1; --i) {
		id[i] = i;
		rnk[i] = 0;
		lft[i] = i;
		
		nxt[i] = i!=n ? i+1 : 0;
		scope[i] = p[i] + l[i];
		dis[i] = i!=n ? max(0, p[i+1] - scope[i]) : 0;
		//sum[i] = i!=n ? dis[i] + sum[i+1] : 0;
	}
}

int get(int x) {
	return x != id[x] ? id[x] = get(id[x]) : x;
}

void u(int x, int y) {
	x = get(x);
	y = get(y);
	
	if (x == y) return;
	if (rnk[x] < rnk[y]) swap(x, y);
	id[y] = x;
	rnk[x] += rnk[x] == rnk[y];
	
	//sum[x] = curSum;
	nxt[x] = max(nxt[x], nxt[y]);
	if (lft[x] < lft[y]) {
		dis[x] = dis[y];
	}
	scope[x] = max(scope[x], scope[y]);
	lft[x] = min(lft[x], lft[y]);
}

void add(int pos) {
	int cur = pos;
	curSum += dis[cur];
	while (get(cur) != get(n) and p[lft[get(nxt[cur])]] <= scope[cur]) {
		curSum -= dis[cur];		
		u(cur, nxt[cur]);
		cur = get(cur);
		
		curSum -= dis[cur];
		dis[cur] = cur!=get(n) ? max(p[lft[get(nxt[cur])]] - scope[cur], 0) : 0;
		curSum += dis[cur];
	}
	sum[cur] = curSum;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d %d", p+i, l+i);
	}
	
	scanf ("%d", &q);
	for (int i = 0; i < q; ++i) {
		scanf("%d %d", &Q[i].x, &Q[i].y);
		Q[i].id = i;
	}
	
	sort(Q, Q+q, [](Query p, Query q) {return p.x > q.x;});
	init(n);	

	int j = n-1;
	for (int i = 0; i < q; ++i) {
		while (Q[i].x <= j) {
			add(j--);
		}	
		
		ans[Q[i].id] = sum[get(Q[i].x)] - sum[get(Q[i].y)];
	}
	
	for (int i = 0; i < q; ++i) {
		printf("%d\n", ans[i]);
	}
	
	
	return 0;
}
