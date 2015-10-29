#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int dp[110];

void comp(int n, int p, int h) {
	for(int i = p; i <= n; i++)
		dp[i] = max(dp[i], dp[i - p] + h);
}

void zero(int n, int p, int h) {
	for(int i = n; i >= p; i--)
		dp[i] = max(dp[i], dp[i - p] + h);
}

void fun(int n, int p, int h, int c) {
	if(p * c >= n)
		comp(n, p, h);
	else {
		int k = 1;
		while(k < c) {
			zero(n, p * k, h * k);
			c -= k;
			k *= 2;
		}
		zero(n, p * c, h * c);
	}
}

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		memset(dp, 0, sizeof(dp));
		int n, m;
		scanf("%d%d", &n, &m);
		int p, h, c;
		for(int i = 1; i <= m; i++) {
			scanf("%d%d%d", &p, &h, &c);
			fun(n, p, h, c);
		}	
		printf("%d\n", dp[n]);
	}
	return 0;
}
