#include <bits/stdc++.h>
using namespace std;

const int MAXN = 210;

int a[MAXN], b[MAXN];
int dp[MAXN][MAXN];

int main() {
	int t, tt = 1;
	scanf("%d", &t);
	while(t--) {
		int n;
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
		for(int i = 1; i <= n; i++) scanf("%d", &b[i]);
		memset(dp, 0x3f, sizeof(dp));
		for(int i = 1; i <= n; i++) dp[i][i] = a[i] + b[i + 1] + b[i - 1];
		for(int i = 2; i <= n; i++)
			for(int s = 1; s <= n - i + 1; s++) {
				int e = s + i - 1;
				for(int j = s; j <= e; j++) {
					if(j == s) dp[s][e] = min(dp[s][e], dp[s + 1][e] + a[j] + b[s - 1] + b[e + 1]);	
					else if(j == e) dp[s][e] = min(dp[s][e], dp[s][e - 1] + a[j] + b[s - 1] + b[e + 1]);
					else dp[s][e] = min(dp[s][e], dp[s][j - 1] + dp[j + 1][e] + a[j] + b[s - 1] + b[e + 1]);
				}
			}
		printf("Case #%d: %d\n", tt++, dp[1][n]);
	}
	return 0;
}
