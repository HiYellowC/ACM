#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int cash, n;
int c[20], d[20];
int dp[100010];

void comp(int v) {
	for(int i = v; i <= cash; i++)
		dp[i] = max(dp[i - v] + v, dp[i]);
}

void zero(int v) {
	for(int i = cash; i >= v; i--)
		dp[i] = max(dp[i - v] + v, dp[i]);
}

void fun(int dex) {
	if(c[dex] * d[dex] >= cash) 
		comp(d[dex]);
	else {
		int k = 1;
		while(k < c[dex]) {
			zero(k * d[dex]);
			c[dex] -= k;
			k *= 2;
		}
		zero(c[dex] * d[dex]);
	}
}

int main() {
	while(~scanf("%d%d", &cash, &n)) {
		for(int i = 1; i <= n; i++)
			scanf("%d%d", &c[i], &d[i]);
		memset(dp, 0, sizeof(dp));
		for(int i = 1; i <= n; i++)
			fun(i);
		printf("%d\n", dp[cash]);
	}
	return 0;
}
