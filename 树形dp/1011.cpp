#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;

int n, m;
int dp[MAXN][MAXN];
int f[MAXN][MAXN];
int dex, Start[MAXN], Next[MAXN * 2], End[MAXN * 2];
int xx[MAXN], yy[MAXN];

void Init() {
	dex = 0;
	memset(Start, 0, sizeof(Start));
	memset(dp, 0, sizeof(dp));
	memset(f, 0, sizeof(f));
}

void BuildG(int a, int b) {
	Next[++dex] = Start[a];
	Start[a] = dex;
	End[dex] = b;
}

void dfs(int v, int fa) {
	for(int i = Start[v]; i; i = Next[i]) {
		int to = End[i];
		if(fa != to) {
			dfs(to, v);
			for(int k = m; k >= 0; k--)
				for(int j = 1; j <= k; j++)
					f[v][k] = max(f[v][k], dp[to][j] + f[v][k - j]);
		}
	}
	int x = (xx[v] + 19) / 20;
	for(int i = x; i <= m; i++) dp[v][i] = f[v][i - x] + yy[v];
}

int main() {
	while(~scanf("%d%d", &n, &m)) {
		if(n == -1 && m == -1) break;
		Init();
		for(int i = 1; i <= n; i++) scanf("%d%d", &xx[i], &yy[i]);
		for(int i = 1; i < n; i++) {
			int a, b;
			scanf("%d%d", &a, &b);
			BuildG(a, b);
			BuildG(b, a);
		}
		if(m == 0) {
			printf("0\n");
			continue;
		}
		dfs(1, -1);
		printf("%d\n", dp[1][m]);
	}
	return 0;
}
