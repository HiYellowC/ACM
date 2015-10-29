#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;

int v[11] = {10000, 5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5};
LL dp[30010];

int main() {
	double x;
	while(~scanf("%lf", &x)) {
		int Money = x * 100 + 0.5;
		if(Money == 0) break;
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		for(int i = 0; i < 11; i++)
			for(int k = v[i]; k <= Money; k++)
				dp[k] += dp[k - v[i]];
		printf("%6.2lf%17lld\n", x, dp[Money]);
	}
	return 0;
}
