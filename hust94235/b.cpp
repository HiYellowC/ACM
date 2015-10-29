#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 100010;

int dp[MAXN];
int w[12], v[12];
int cash;

void complete(int V) {
	for(int i = V; i <= cash; i++)
		dp[i] = max(dp[i], dp[i - V] + V);
}

void zeroone(int V) {
	for(int i = cash; i >= V; i--)
		dp[i] = max(dp[i], dp[i - V] + V);
}

int main() {
	while(~scanf("%d", &cash)) {
		int n;
		scanf("%d", &n);
		memset(dp, 0, sizeof(dp));
		for(int i = 1; i <= n; i++) scanf("%d%d", &w[i], &v[i]);
		for(int i = 1; i <= n; i++) {
			if(w[i] * v[i] >= cash)
				complete(v[i]);
			else {
				int k = 1;
				while(k <= w[i]) {
					zeroone(k * v[i]);
					w[i] -= k;
					k *= 2;	
				}
				zeroone(w[i] * v[i]);
			}
		}
		printf("%d\n", dp[cash]);
	}
	return 0;
}
