#include <iostream>
#include <cstdio>
#include <cstring>
#define Max 100000
#define MOD 998244353
using namespace std;

typedef long long LL;

LL dp1[Max + 10], dp2[Max + 10];
LL sum[Max + 10];
int n, c, l, r;

void Init() {
	dp1[0] = 1;
	for(int i = 1; i < 500; i++) {
		for(int j = 0; j < i; j++)
			dp2[j] = 0;
		for(int j = i; j <= Max; j++) {
			dp2[j] = (dp1[j - i] + dp2[j - i]) % MOD;
			sum[j] = (sum[j] + dp2[j]) % MOD;
		}
		swap(dp1, dp2);
	}
	for(int i = 2; i <= Max; i++)
		sum[i] = (sum[i - 1] + sum[i]) % MOD;
}

int main() {
	Init();
	int t;
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d%d%d", &n, &c, &l, &r);
		l -= c, r -= c;
		LL ans;
		if(l == 0)
			ans = (sum[r] + 1) % MOD;
		else
			ans = (sum[r] - sum[l - 1] + MOD) % MOD;
		printf("%lld\n", ans);
	}
	return 0;
}
