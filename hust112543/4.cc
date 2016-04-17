#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int MAXN = 45;

int a[MAXN];
LL dp[2][1 << 22];

int main() {
	int t, tt = 1;
	scanf("%d", &t);
	while(t--) {
		int n, m;
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
		memset(dp, 0, sizeof(dp));	
		dp[0][0] = 1;
		LL Max = a[1];
		for(int i = 1; i <= n; i++) {
			for(int j = 0; j <= Max; j++) {
				dp[1][j] += dp[0][j];
				dp[1][j ^ a[i]] += dp[0][j];
				Max = max(Max, (LL)j ^ a[i]);
			}
			for(int j = 0; j <= Max; j++) dp[0][j] = dp[1][j];
			memset(dp[1], 0, sizeof(dp[1]));
		}
		LL ans = 0;
		for(int i = 0; i < m; i++) ans += dp[0][i];
		printf("Case #%d: %lld\n", tt++, ((LL)1 << n) - ans);
	}
	return 0;
}
