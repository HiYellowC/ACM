#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define INF 0x3f3f3f3f
#define Max 20000
using namespace std;

int n, t;
int val[110], c[110];
int dp[Max + 10];

void zero(int w, int v) {
	for(int i = Max; i >= w; i--)
		dp[i] = min(dp[i - w] + v, dp[i]);
}

void fun(int cur) {
	int k = 1;
	while(k < c[cur]) {
		zero(k * val[cur], k);
		c[cur] -= k;
		k *= 2;
	}
	zero(c[cur] * val[cur], c[cur]);
}

void comp() {
	for(int i = 1; i <= n; i++)
		for(int k = Max - val[i]; k >= 0; k--)
			dp[k] = min(dp[k + val[i]] + 1, dp[k]);
}

int main() {
	while(~scanf("%d%d", &n, &t)) {
		for(int i = 1; i <= n; i++)
			scanf("%d", &val[i]);
		for(int i = 1; i <= n; i++)
			scanf("%d", &c[i]);
		memset(dp, INF, sizeof(dp));
		dp[0] = 0;
		for(int i = 1; i <= n; i++)
			fun(i);
		comp();
		if(dp[t] == INF)
			printf("-1\n");
		else
			printf("%d\n", dp[t]);
	}	
	return 0;
}
