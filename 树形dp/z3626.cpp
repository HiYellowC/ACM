#include <bits/stdc++.h>
using namespace std;

const int MAXN = 110;

int n, m;
int dex, Start[MAXN], Next[MAXN * 2], End[MAXN * 2], Cost[MAXN * 2];
int Val[MAXN];
int dp[MAXN][MAXN * 2];

void Init() {
	dex = 0;
	memset(Start, 0, sizeof(Start));
	memset(dp, 0, sizeof(dp));
}

void BuildG(int a, int b, int c) {
	Next[++dex] = Start[a];
	Start[a] = dex;
	End[dex] = b;
	Cost[dex] = c;
}

void dfs(int v, int fa) {
	for(int i = Start[v]; i; i = Next[i]) {
		int to = End[i];
		if(to != fa) {
			dfs(to, v);
			for(int k = m; k >= Cost[i] * 2; k--)
				for(int j = k - Cost[i] * 2; j >= 0; j--)
					dp[v][k] = max(dp[v][k], dp[v][k - j - Cost[i] * 2] + dp[to][j] + Val[to]);
		}
	}	
}

int main() {
	while(~scanf("%d", &n)) {
		Init();
		for(int i = 1; i <= n; i++) scanf("%d", &Val[i]);
		for(int i = 1; i < n; i++) {
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);	
			BuildG(a, b, c);
			BuildG(b, a, c);
		}
		int k;
		scanf("%d%d", &k, &m);
		dfs(k, -1);
		printf("%d\n", dp[k][m] + Val[k]);
	}	
	return 0;
}
