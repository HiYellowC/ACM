#include <stdio.h>
#include <string.h>

int map[53][53];
int dp[105][53][53];

inline int max(int a, int b, int c, int d) {
	if(a < b)
		a = b;
	if(c < d)
		c = d;
	return a > c ? a : c;
}

int main() {
	int total;
	int i, j, k, m, n;
	int RES;
	scanf("%d", &total);
	while(total--) {
		scanf("%d%d", &m, &n);
		for(i = 1; i <= m; i++)
			for(k = 1; k <= n; k++)
				scanf("%d", &map[i][k]);
//		for(j = 2; j <= m + n; j++)
			for(i = 1; i <= m; i++)
				for(k = 1; k <= m; k++)
					for(j = 2; j <= m + n; j++)
					if(j >= i && j >= k && i != k)
						dp[j][i][k] = max(dp[j - 1][i][k], dp[j - 1][i - 1][k], dp[j - 1][i - 1][k - 1], dp[j - 1][i][k - 1]) + map[i][j - i] + map[k][j - k];
		RES = dp[m + n - 1][m - 1][m] > dp[m + n - 1][m][m - 1] ? dp[m + n - 1][m - 1][m] : dp[m + n - 1][m][m - 1];
		printf("%d\n", RES);
	}
	return 0;
}
