#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char str[5010];
int dp[2][5010];

int main() {
	int n;
	while(~scanf("%d", &n)) {
		scanf("%s", str + 1);
		memset(dp, 0, sizeof(dp));
		for(int i = 2; i <= n; i++)
			for(int k = 1; k <= n - i + 1; k++)
				if(str[k] == str[k + i - 1])
					dp[i & 1][k] = dp[i & 1][k + 1];
				else
					dp[i & 1][k] = min(dp[!(i & 1)][k], dp[!(i & 1)][k + 1]) + 1;
		printf("%d\n", dp[n & 1][1]);
	}
	return 0;
}
