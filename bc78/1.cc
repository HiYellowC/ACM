#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int MAXN = 1010;
const int MOD = 100000007;

int dp[MAXN][MAXN];
int g[MAXN][MAXN];

int gcd(int x, int y) {
	return y == 0 ? x : gcd(y, x % y);
}

void init() {
	for(int i = 1; i <= 1000; i++)
		for(int j = i; j <= 1000; j++)
			g[i][j] = g[j][i] = gcd(i, j);
}

int main() {
	init();
	int t;
	scanf("%d", &t);
	while(t--) {
		int n, num, MAX;
		scanf("%d", &n);
		memset(dp, 0, sizeof(dp));
		MAX = 0;
		for(int i = 1; i <= n; i++) {
			scanf("%d", &num);
			MAX = max(num, MAX);
			for(int j = 1; j <= MAXN; j++) {
				dp[i][j] = dp[i - 1][j] % MOD;
				int k = g[j][num];
				dp[i][k] = (dp[i][k] + dp[i][j]) % MOD;
			}
			dp[i][num] = (dp[i][num] + 1) % MOD;
		}
		int ans = 0;
		for(int i = 1; i <= MAX; i++) ans = ((LL)ans + (LL)dp[n][i] * i) % MOD;
		printf("%d\n", ans);
	}
	return 0;
}
