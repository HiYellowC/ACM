#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100010;
const int MAXM = 2000010;

int n, m;
int a[MAXN], sorted[MAXN], root[MAXN], T[MAXM], lson[MAXM], rson[MAXM];
int dex, Start[MAXN], Next[MAXN * 2], End[MAXN * 2];
int dep[MAXN], step[MAXN * 2], app[MAXN], lca[MAXN * 2][20];

void Init() {
	dex = 0;
	memset(Start, 0, sizeof(Start));
}

void BuildG(int a, int b) {
	Next[++dex] = Start[a];
	Start[a] = dex;
	End[dex] = b;
}

int BuildT(int l, int r) {
	int now = ++dex;
	T[now] = 0;
	if(l == r) return now;
	int mid = (l + r) >> 1;
	lson[now] = BuildT(l, mid);
	rson[now] = BuildT(mid + 1, r);
	return now;
}

int UpdateT(int oldroot, int pos, int val) {
	int now = ++dex;
	int tmp = now;
	T[now] = T[oldroot] + val;
	int l = 1, r = m;
	while(l < r) {	
		int mid = (l + r) >> 1;
		if(pos <= mid) {
			rson[now] = rson[oldroot];
			lson[now] = ++dex;
			T[lson[now]] = T[lson[oldroot]] + val;
			now = lson[now], oldroot = lson[oldroot];
			r = mid;
		}
		else {
			lson[now] = lson[oldroot];
			rson[now] = ++dex;
			T[rson[now]] = T[rson[oldroot]] + val;
			now = rson[now], oldroot = rson[oldroot];
			l = mid + 1;
		}
	}
	return tmp;
}

int QueryT(int rootl, int rootr, int Lca, int k) {
	int rootlca = root[Lca];
	int pos = lower_bound(sorted + 1, sorted + 1 + m, a[Lca]) - sorted;
	int l = 1, r = m;
	while(l < r) {
		int mid = (l + r) >> 1;
		int con = T[lson[rootl]] + T[lson[rootr]] - 2 * T[lson[rootlca]];	
		if(pos <= mid && pos >= l) con++;
		if(k <= con) {
			rootl = lson[rootl];
			rootr = lson[rootr];
			rootlca = lson[rootlca];
			r = mid;
		}
		else {
			rootl = rson[rootl];
			rootr = rson[rootr];
			rootlca = rson[rootlca];
			l = mid + 1;
			k -= con;
		}
	}
	return l;
}

void dfs_UpdateT(int v, int fa) {
	int pos = lower_bound(sorted + 1, sorted + 1 + m, a[v]) - sorted;
	root[v] = UpdateT(root[fa], pos, 1);
	for(int i = Start[v]; i; i = Next[i]) {
		int to = End[i];
		if(to != fa) dfs_UpdateT(to, v);
	}
}

void dfs(int v, int fa, int deep) {
	step[++dex] = v;
	dep[v] = deep;
	app[v] = dex;
	for(int i = Start[v]; i; i = Next[i]) {
		int to = End[i];
		if(to != fa) dfs(to, v, deep + 1), step[++dex] = v;
	}
}

void LCA() {
	memset(app, 0, sizeof(app));
	dfs(1, -1, 1);	
	for(int i = 1; i <= dex; i++) lca[i][0] = step[i];
	for(int i = 1; (1 << i) <= dex; i++)
		for(int k = 1; k + (1 << i) - 1 <= dex; k++)
			lca[k][i] = dep[lca[k][i - 1]] < dep[lca[k + (1 << (i - 1))][i - 1]] ? lca[k][i - 1] : lca[k + (1 << (i - 1))][i - 1];
}

int QueryL(int l, int r) {
	l = app[l];
	r = app[r];
	if(r < l) swap(l, r);
	int i = (int)(log(r - l + 1) / log(2));
	return dep[lca[l][i]] <= dep[lca[r - (1 << i) + 1][i]] ? lca[l][i] : lca[r - (1 << i) + 1][i];
}

int main() {
	int q;
	while(~scanf("%d%d", &n, &q)) {
		Init();
		for(int i = 1; i <= n; i++) scanf("%d", &a[i]), sorted[i] = a[i];
		sort(sorted + 1, sorted + 1 + n);
		m = unique(sorted + 1, sorted + 1 + n) - sorted - 1;
		for(int i = 1; i < n; i++) {
			int a, b;
			scanf("%d%d", &a, &b);
			BuildG(a, b);
			BuildG(b, a);
		}
		dex = 0;
		root[0] = BuildT(1, m);
		dfs_UpdateT(1, 0);
		dex = 0;
		LCA();
		while(q--) {
			int l, r, k;
			scanf("%d%d%d", &l, &r, &k);
			printf("%d\n", sorted[QueryT(root[l], root[r], QueryL(l, r), k)]);
		}
	}
	return 0;
}
