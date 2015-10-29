#include <stdio.h>
#include <string.h>

//int array[1001][2];
//int result[1001][1001];
int res[1001];

inline int max(int a, int b) {
	return a > b ? a : b;
}

/*int dp1(int n, int v) {
	if(n <= 0 || v <= 0)
		return 0;
	else if(result[n][v])
		return result[n][v];
	else {
		if(v - array[n - 1][0] >= 0)
			return result[n][v] = max(dp1(n - 1, v), dp1(n - 1, v - array[n - 1][0]) + array[n - 1][1]);
		else
			return result[n][v] = dp1(n - 1, v);
	}
}*/

/*void dp2(int n, int v) {
	int i, k;
	for(i = 1; i <= n; i++)
		for(k = 0; k <= v; k++) {
			if(k - array[i - 1][0] >= 0)
				result[i][k] = max(result[i - 1][k], result[i - 1][k - array[i - 1][0]] + array[i - 1][1]);
			else
				result[i][k] = result[i - 1][k];
		}
}*/

int main() {
	int n, v, i, k;
	int c, w;
	while(scanf("%d%d", &n, &v)) {
//		memset(result, 0, sizeof(result));
		memset(res, 0, sizeof(res));
		if(!n && !v)
			break;
//		for(i = 0; i < n; i++)
//			scanf("%d%d", &array[i][0], &array[i][1]);
		for(i = 1; i <= n; i++) {
			scanf("%d%d", &c, &w);
			for(k = v; k >= c; k--) {
				res[k] = max(res[k], res[k - c] + w);
				if(i == n)
					break;
			}
		}
		printf("%d\n", res[v]);
	}
	return 0;
}
