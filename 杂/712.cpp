#include <stdio.h>
#include <string.h>

int Map[51][51];
int dp[110][51][51];

int n, m;

inline int Max(int a, int b) {
	return a > b ? a : b;
}

int main() {
	int total;
	scanf("%d", &total);
	int i, k;
	while(total--) {
		scanf("%d%d", &n, &m);
		for(i = 1; i <= n; i++)
			for(k = 1; k <= m; k++)
				scanf("%d", &Map[i][k]);
		memset(dp, 0, sizeof(dp));
		int step = n + m;
		int x1, x2, a, b;
		a = Map[1][1];
		b = Map[n][m];
		Map[1][1] = Map[n][m] = 0;
		for(i = 3; i <= step; i++)
			for(x1 = 1; x1 <= n; x1++)
				for(x2 = 1; x2 <= n; x2++) {
					int y1, y2;
					y1 = i - x1, y2 = i - x2;
					if(x1 == x2 && i != step)
						continue;
					if(y1 < 1 || y1 > m || y2 < 1 || y2 > m)
						continue;
					dp[i][x1][x2] = Max(Max(dp[i - 1][x1 - 1][x2 - 1], dp[i - 1][x1 - 1][x2]), Max(dp[i - 1][x1][x2 - 1], dp[i - 1][x1][x2]));
					dp[i][x1][x2] += (Map[x1][y1] + Map[x2][y2]);
				}
		printf("%d\n", dp[step][n][n] + a + b);
	}
	return 0;
}
