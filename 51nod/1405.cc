#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int MAXN = 100010;

int n;
LL ans[MAXN];
int son[MAXN];
int dex, Start[MAXN], Next[MAXN * 2], End[MAXN * 2];

void buildG(int a, int b) {
	Next[++dex] = Start[a];
	Start[a] = dex;
	End[dex] = b;
}

LL dfs(int v, int fa) {
	LL con = 0;
	for(int i = Start[v]; i; i = Next[i]) {
		int to = End[i];
		if(to != fa) {
			con += dfs(to, v);
			son[v] += (son[to] + 1);
		}
	}
	return con + (LL)son[v];
}

void dfs2(int v, int fa) {
	if(v != 1) ans[v] = ans[fa] - (LL)son[v] + ((LL)n - son[v] - 2);
	for(int i = Start[v]; i; i = Next[i]) {
		int to = End[i];
		if(to != fa) dfs2(to, v);
	}
}

int main() {
	scanf("%d", &n);
	int a, b;
	for(int i = 1; i < n; i++) {
		scanf("%d%d", &a, &b);
		buildG(a, b);
		buildG(b, a);
	}
	ans[1] = dfs(1, -1);
	dfs2(1, -1);
	for(int i = 1; i <= n; i++) printf("%lld\n", ans[i]);
	return 0;
}
