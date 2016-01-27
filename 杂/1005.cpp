#include <stdio.h>

int dp[1010];
int time[110], val[110];

inline int Max(int a, int b) {
	return a > b ? a : b;
}

int main() {
	int T, M;
	scanf("%d%d", &T, &M);
	int i, k;
	for(i = 1; i <= M; i++)
		scanf("%d%d", &time[i], &val[i]);
	for(i = 1; i <= M; i++)
		for(k = T; k > 0; k--)
			if(k >= time[i])
				dp[k] = Max(dp[k], dp[k - time[i]] + val[i]);
	printf("%d\n", dp[T]);
	return 0;
}
