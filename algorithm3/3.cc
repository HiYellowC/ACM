#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1010;

int dp[MAXN];

int main() {
	int n, w;
	scanf("%d%d", &n, &w);
	for(int i = 1; i <= n; i++) {
		int cost, val;
		scanf("%d%d", &cost, &val);
		for(int k = w; k >= cost; k--)
		   dp[k] = max(dp[k], dp[k - cost] + val);	
	}
	printf("%d\n", dp[w]);
	return 0;
}
