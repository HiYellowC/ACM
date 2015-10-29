#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int MAXN = 1010;
const LL MOD = 1000000007;

LL C[MAXN * 2][MAXN * 2];

void Init() {
	for(int i = 1; i < MAXN; i++) C[i][0] = 1;
	for(int i = 1; i < MAXN; i++) C[i][i] = 1;
	for(int i = 1; i < MAXN; i++)
		for(int k = 1; k < i; k++)
			C[i][k] = (C[i - 1][k - 1] + C[i - 1][k]) % MOD;
}

int main() {
	Init();
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	printf("%lld\n", (C[n - 1][2 * k] * C[m - 1][2 * k]) % MOD);
	return 0;
}
