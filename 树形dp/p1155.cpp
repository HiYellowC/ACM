#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3010;

int n, m;
int dex, Start[MAXN], Next[MAXN], End[MAXN], Cost[MAXN];
int val[MAXN];
int dp[MAXN][MAXN];

void Init() {
	dex = 0;
	memset(Start, 0, sizeof(Start));
	memset(dp, 0x3f, sizeof(dp));
	for(int i = 1; i <= n; i++) dp[i][0] = 0;
}

void BuildG(int a, int b, int c) {
	Next[++dex] = Start[a];
	Start[a] = dex;
	End[dex] = b;
	Cost[dex] = c;
}

int dfs(int v, int fa) {
	int ans = 0;
	for(int i = Start[v]; i; i = Next[i]) {
		int to = End[i];
		int cost = Cost[i];
		int now = dfs(to, v);
		int p;
		if(to >= n - m + 1) now++, p = 1;
		else p = 0;
		ans += now;
		for(int k = ans; k >= 1; k--)
			for(int j = now; j >= 1; j--)
				dp[v][k] = min(dp[v][k], dp[v][k - j] + (!p) * dp[to][j] + cost - p * val[to]);
	}
	return ans;
}

int main() {
	while(~scanf("%d%d", &n, &m)) {
		Init();	
		int k, a, b;
		for(int i = 1; i <= n - m; i++) {
			scanf("%d", &k);
			for(int j = 1; j <= k; j++) {
				scanf("%d%d", &a, &b);
				BuildG(i, a, b);
			}
		}
		for(int i = n - m + 1; i <= n; i++) scanf("%d", &val[i]);
		int now = dfs(1, -1);
		for(int i = n; i >= 0; i--) if(dp[1][i] <= 0) {printf("%d\n", i); break;};
	}	
	return 0;
}
