#include <bits/stdc++.h>
using namespace std;

const int MAXN = 160;

int n, p;
int dex, Start[MAXN], Next[2 * MAXN], End[2 * MAXN];
int dp[MAXN][MAXN], son[MAXN];

void Init() {
	dex = 0;
	memset(Start, 0, sizeof(Start));
	memset(dp, 0x3f, sizeof(dp));
	memset(son, 0, sizeof(son));
	for(int i = 1; i <= n; i++) dp[i][0] = 0;
}

void BuildG(int a, int b) {
	Next[++dex] = Start[a];
	Start[a] = dex;
	End[dex] = b;
}

int dfs(int v, int fa) {
	son[v] = 1;
	for(int i = Start[v]; i; i = Next[i]) {
		int to = End[i];
		if(to != fa) {
			son[v] += dfs(to, v);
			for(int j = son[v]; j >= 1; j--) {
				for(int k = j; k >= 0; k--)
					dp[v][j] = min(dp[v][j], dp[v][j - k] + dp[to][k]);
				if(son[to] <= j) dp[v][j] = min(dp[v][j], dp[v][j - son[to]] + 1);
			}
		}
	}
	return son[v];
}

int main() {
	while(~scanf("%d%d", &n, &p)) {
		Init();	
		for(int i = 1; i < n; i++) {
			int a, b;
			scanf("%d%d", &a, &b);
			BuildG(a, b);
			BuildG(b, a);
		}
		int ans = 0x3f3f3f3f;
		dfs(1, -1);
		for(int i = 1; i <= n; i++) {
			if(i == 1) ans = min(ans, dp[i][n - p]);
			else ans = min(ans, dp[i][son[i] - p] + 1);
		}
		printf("%d\n", ans);
	}
	return 0;
}
