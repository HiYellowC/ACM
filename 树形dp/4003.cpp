#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10010;

int N, S, K;
int dex, Start[MAXN], Next[MAXN * 2], End[MAXN * 2], Val[MAXN * 2];
int dp[MAXN][11];

void Init() {
	dex = 0;
	memset(Start, 0, sizeof(Start));
	memset(dp, 0, sizeof(dp));
}

void BuildG(int a, int b, int c) {
	Next[++dex] = Start[a];
	Start[a] = dex;
	End[dex] = b;
	Val[dex] = c;
}

void dfs(int v, int fa) {
	for(int i = Start[v]; i; i = Next[i]) {
		int to = End[i];
		if(to != fa) {
			dfs(to, v);
			for(int k = K; k >= 0; k--) {
				dp[v][k] += dp[to][0] + 2 * Val[i];
				for(int j = 1; j <= k; j++)
					dp[v][k] = min(dp[v][k], dp[v][k - j] + dp[to][j] + j * Val[i]);
			}
		}
	}
}

int main() {
	while(~scanf("%d%d%d", &N, &S, &K)) {
		Init(); 
		int a, b, c;
		for(int i = 1; i < N; i++) {
			scanf("%d%d%d", &a, &b, &c);
			BuildG(a, b, c);
			BuildG(b, a, c);
		}
		dfs(S, -1);
		printf("%d\n", dp[S][K]);
	}
	return 0;
}
