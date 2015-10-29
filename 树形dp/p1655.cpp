#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define Max 20010
using namespace std;

int n;
int Start[Max], Next[Max * 2], End[Max * 2];
int dex;
int son[Max];
int ans, ansid;

void Init() {
	memset(Start, 0, sizeof(Start));
	dex = 0;
	ans = Max;
}

void BuildG(int a, int b) {
	Next[++dex] = Start[a];
	Start[a] = dex;
	End[dex] = b;
}

void dfs(int v, int fa) {
	son[v] = 0;
	int tmp, maxn = 0;
	for(int i = Start[v]; i; i = Next[i]) {
		int to = End[i];
		if(to != fa) {
			dfs(to, v);
			tmp = son[to] + 1;
			maxn = max(maxn, tmp);
			son[v] += son[to] + 1;
		}
	}
	maxn = max(maxn, n - 1 - son[v]);
	if(maxn < ans || maxn == ans && v < ansid)
		ansid = v, ans = maxn;
}

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		Init();
		scanf("%d", &n);
		int a, b;
		for(int i = 1; i < n; i++) {
			scanf("%d%d", &a, &b);
			BuildG(a, b);
			BuildG(b, a);
		}
		dfs(1, -1);
		printf("%d %d\n", ansid, ans);
	}
	return 0;
}
