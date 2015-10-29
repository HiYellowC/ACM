#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;

int bit[40];
LL f[40][4];

LL dp(int pos, int st, bool flag) {
	if(pos == 0) return st == 2;
	if(flag && f[pos][st] != -1) return f[pos][st];
	long long ans = 0;
	int x = flag ? 9 : bit[pos];
	for(int i = 0; i <= x; i++) {
		if((st == 2) || (st == 1 && i == 9))
			ans += dp(pos - 1, 2, flag || i < x);
		else if(i == 4)
			ans += dp(pos - 1, 1, flag || i < x);
		else
			ans += dp(pos - 1, 0, flag || i < x);
	}
	if(flag) f[pos][st] = ans;
	return ans;
}

LL calc(LL x) {
	int len = 0;
	while(x) {
		bit[++len] = x % 10;
		x /= 10;
	}
	return dp(len, 0, 0);
}

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		LL n;
		memset(f, -1, sizeof(f));
		scanf("%lld", &n);
		printf("%lld\n", calc(n));
	}
	return 0;
}
