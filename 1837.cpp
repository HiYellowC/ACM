#include <stdio.h>

int dp[21][15001];

int main() {
	int i, k, j, n, g;
	int c[21], w[21];
	scanf("%d%d", &n, &g);
	for(i = 1; i <= n; i++)
		scanf("%d", &c[i]);
	for(i = 1; i <= g; i++)
		scanf("%d", &w[i]);
	dp[0][7500] = 1;
	for(i = 1; i <= g; i++)
		for(k = 1; k <= 15000; k++)
			if(dp[i - 1][k])
				for(j = 1; j <= n; j++)
					dp[i][k + w[i] * c[j]] += dp[i - 1][k];
	printf("%d\n", dp[g][7500]);
	return 0;
}
