#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int MAXN = 210;

LL a[MAXN], b[MAXN];
LL dp[MAXN][MAXN];

int main() {
	int t, tt = 1;
	scanf("%d", &t);
	while(t--) {
		int n;
		scanf("%d", &n);
		memset(dp, 0x3f, sizeof(dp));
		for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
		for(int i = 1; i <= n; i++) scanf("%lld", &b[i]);
		b[0] = b[n + 1] = 0;
		for(int i = 1; i <= n; i++) dp[i][i] = a[i] + b[i - 1] + b[i + 1];
		for(int i = 2; i <= n; i++)
			for(int k = 1; k <= n - i + 1; k++) {
				int s = k;
				int e = s + i - 1;
				for(int j = s; j <= e; j++) {
					if(j == s) dp[s][e] = min(dp[s][e], dp[s + 1][e] + a[j] + b[s - 1] + b[e + 1]);
					else if(j == e) dp[s][e] = min(dp[s][e], dp[s][e - 1] + a[j] + b[s - 1] + b[e + 1]);
					else dp[s][e] = min(dp[s][e], dp[s][j - 1] + dp[j + 1][e] + a[j] + b[s - 1] + b[e + 1]);
				}
			}
		printf("Case #%d: %lld\n", tt++, dp[1][n]);
	}
	return 0;
}
