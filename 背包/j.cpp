#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MOD 1000000007
using namespace std;

int n, m, k;
int LCM[1010][1010];
int dp[2][1010][1010];
int fact[1010], cnt;

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b) {
	return a / gcd(a, b) * b;
}

void Init() {
	for(int i = 1; i <= 1000; i++)
		for(int j = 1; j <= i; j++)
			LCM[j][i] = LCM[i][j] = lcm(i, j);
}

void solve() {
	cnt = 0;
	for(int i = 1; i <= m; i++)
		if(m % i == 0) fact[cnt++] = i;
	int now = 0;
	memset(dp[now], 0, sizeof(dp[now]));
	for(int i = 0; i < cnt; i++)
		dp[now][fact[i]][fact[i]] = 1;
	for(int i = 1; i < k; i++) {
		now ^= 1;
		for(int p = 1; p <= n; p++)
			for(int q = 0; q < cnt; q++)
				dp[now][p][fact[q]] = 0;
		for(int p = 1; p <= n; p++)
			for(int q = 0; q < cnt; q++) {
				if(dp[now ^ 1][p][fact[q]] == 0) continue;
				for(int j = 0; j < cnt; j++) {
					int now_sum = p + fact[j];
					if(now_sum > n) continue;
					int now_lcm = LCM[fact[q]][fact[j]];
					dp[now][now_sum][now_lcm] += dp[now ^ 1][p][fact[q]];
					dp[now][now_sum][now_lcm] %= MOD;
				}
			}
	}
	printf("%d\n", dp[now][n][m]);
}

int main() {
	Init();
	while(~scanf("%d%d%d", &n, &m, &k)) {
		solve();	
	}
	return 0;
}

