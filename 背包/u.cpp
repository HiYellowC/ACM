#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define INF 0x3f3f3f3f
using namespace std;

int a[1010];
int dp[1010];

int main() {
	int n, m;
	while(~scanf("%d", &n)) {
		if(n == 0) break;
		memset(dp, 0, sizeof(dp));
		for(int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		sort(a + 1, a + 1 + n);
		scanf("%d", &m);
		if(m < 5)
			printf("%d\n", m);
		else {
			for(int i = 1; i <= n - 1; i++)
				for(int k = m - 5; k >= a[i]; k--)
					dp[k] = max(dp[k], dp[k - a[i]] + a[i]);
			printf("%d\n", m - a[n] - dp[m - 5]);
		}
	}
	return 0;
}
