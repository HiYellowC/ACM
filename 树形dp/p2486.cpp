#include <bits/stdc++.h>
using namespace std;

const int MAXN = 110;

int n, k;
int dex, Start[MAXN], Next[2 * MAXN], End[2 * MAXN];
int val[MAXN];
int dp[MAXN][2 * MAXN][2];

void Init() {
	dex = 0;
	memset(Start, 0, sizeof(Start));
}

void BuildG(int a, int b) {
	Next[++dex] = Start[a];
	Start[a] = dex;
	End[dex] = b;
	memset(dp, 0, sizeof(dp));
}

void dfs(int v, int fa) {
	for(int i = 0; i <= k; i++) dp[v][i][1] = dp[v][i][0] = val[v];
	for(int i = Start[v]; i; i = Next[i]) {
		int to = End[i];
		if(to != fa) {
			dfs(to, v);
			for(int j = k; j >= 0; j--)
				for(int l = j; l >= 0; l--) {
					if(j - l - 2 >= 0) {
						dp[v][j][1] = max(dp[v][j][1], dp[v][j - l - 2][1] + dp[to][l][1]);
						dp[v][j][0] = max(dp[v][j][0], dp[v][j - l - 2][0] + dp[to][l][1]);
					}
					if(j - l - 1 >= 0)
						dp[v][j][0] = max(dp[v][j][0], dp[v][j - l - 1][1] + dp[to][l][0]);
				}
		}
	}
}

int main() {
	while(~scanf("%d%d", &n, &k)) {
		Init();	
		for(int i = 1; i <= n; i++) scanf("%d", &val[i]);
		for(int i = 1; i < n; i++) {
			int a, b;
			scanf("%d%d", &a, &b);
			BuildG(a, b);
			BuildG(b, a);
		}
		dfs(1, 0);
		printf("%d\n", max(dp[1][k][0], dp[1][k][1]));
	}
	return 0;
}
