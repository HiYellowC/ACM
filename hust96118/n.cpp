#include <bits/stdc++.h>
using namespace std;

int n, m;
int v[110];
int dp[10010];
int val[110][110];
int maxval[110][110];

void Init() {
	for(int i = 1; i <= n; i++)
		for(int k = 1; k <= v[i]; k++) 
			val[i][k] += val[i][k - 1];
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= v[i]; j++)
			for(int k = 1; k <= j + 1; k++)
				maxval[i][j] = max(maxval[i][j], val[i][v[i]] - (val[i][k + v[i] - j - 1] - val[i][k - 1]));
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &v[i]);
		for(int k = 1; k <= v[i]; k++) scanf("%d", &val[i][k]);
	}
	Init();
	for(int i = 1; i <= n; i++)
		for(int k = m; k >= 1; k--)
			for(int j = 1; j <= min(k, v[i]); j++)
				dp[k] = max(dp[k - j] + maxval[i][j], dp[k]);
	printf("%d\n", dp[m]);
	return 0;
}
