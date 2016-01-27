#include <stdio.h>

int Array[101];
int dp[101][101];

inline int Min(int a, int b) {
	return a < b ? a : b;
}

int main() {
	int n;
	scanf("%d", &n);
	int i, k, j;
	for(i = 1; i <= n; i++)
		scanf("%d", &Array[i]);
	for(i = 3; i <= n; i++)
		for(k = 1; k <= n - i + 1; k++) {
			int l, r;
			l = k, r = l + i - 1;
			for(j = l + 1; j <= r - 1; j++)
				if(!dp[l][r])
					dp[l][r] = dp[l][j] + dp[j][r] + Array[j] * Array[l] * Array[r];
				else
					dp[l][r] = Min(dp[l][r], dp[l][j] + dp[j][r] + Array[j] * Array[l] * Array[r]);
		}
	printf("%d\n", dp[1][n]);
	return 0;
}
