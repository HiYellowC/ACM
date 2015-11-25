#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1010;

int a[MAXN], b[MAXN];
int dp[MAXN][MAXN];

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for(int i = 1; i <= m; i++) scanf("%d", &b[i]);
	for(int i = 1; i <= n; i++)
		for(int k = 1; k <= m; k++)
			if(a[i] == b[k]) dp[i][k] = dp[i - 1][k - 1] + 1;
			else dp[i][k] = max(dp[i - 1][k], dp[i][k - 1]);
	printf("the answer is %d\n", dp[n][m]);
	return 0;
}
