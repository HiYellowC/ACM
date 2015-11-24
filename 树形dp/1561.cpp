#include <bits/stdc++.h>
using namespace std;

const int MAXN = 210;

int n, m;
int dex, Start[MAXN], Next[MAXN], End[MAXN];
int dp[MAXN][MAXN], f[MAXN][MAXN];
int val[MAXN];

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
		dfs(to, v);
		for(int j = m; j >= 1; j--)
			for(int k = 0; k <= j; k++)
				f[v][j] = max(f[v][j], f[v][j - k] + dp[to][k]);
	}
	if(v == 0)
		for(int i = 0; i <= m; i++) dp[v][i] = f[v][i];
	else
		for(int i = 1; i <= m; i++) dp[v][i] = f[v][i - 1] + val[v];
}

int main() {
	while(~scanf("%d%d", &n, &m)) {
		if(n == 0 && m == 0) break;
		Init();
		int a;
		for(int i = 1; i <= n; i++) {
			scanf("%d%d", &a, &val[i]);
			BuildG(a, i);
		}
		dfs(0, -1);
		printf("%d\n", dp[0][m]);
	}
	return 0;
}
