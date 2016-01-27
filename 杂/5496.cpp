#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MOD 1000000007
#define MAXN 100010
using namespace std;

typedef long long LL;

int a[MAXN], b[MAXN];
LL p[MAXN];
LL sum[MAXN];

void Init() {
	p[0] = 1;
	for(int i = 1; i < MAXN; i++) p[i] = (p[i - 1] * 2) % MOD;
}

int main() {
	Init();
	int t;
	scanf("%d", &t);
	while(t--) {
		int n;
		LL ans = 0;
		memset(sum, 0, sizeof(sum));
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) scanf("%d", &a[i]), b[i] = a[i];
		for(int i = 1; i <= n; i++) ans = (ans + (LL)a[i] * p[n - 1]) % MOD;
		sort(b + 1, b + 1 + n);
		int m = unique(b + 1, b + 1 + n) - b - 1;
		for(int i = 1; i <= n; i++) {
			int x = lower_bound(b + 1, b + 1 + m, a[i]) - b;
			ans = ((ans - ((p[n - i] * (LL)a[i]) % MOD) * sum[x]) % MOD + MOD) % MOD;
			sum[x] = (sum[x] + p[i - 1]) % MOD;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
