#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int a[110][110];
int dp[110];

int main() {
	int n, m;
	while(~scanf("%d%d", &n, &m)) {
		if(n == 0 && m == 0) break;
		for(int i = 1; i <= n; i++)
			for(int k = 1; k <= m; k++)
				scanf("%d", &a[i][k]);
		memset(dp, 0, sizeof(dp));
		for(int i = 1; i <= n; i++)
			for(int k = m; k >= 1; k--)
				for(int j = 1; j <= m; j++)
					if(k < j)
						continue;
					else
						dp[k] = max(dp[k], dp[k - j] + a[i][j]);
		printf("%d\n", dp[m]);
	}
	return 0;
}
