#include <iostream>
#include <cstdio>
#include <cstring>
#define Max 1<<9
using namespace std;

typedef long long LL;

LL n, m, k;
LL p;
LL status[Max], num[Max];
LL dp[81][21][Max];

bool Check(LL x) {
	if(x & (x << 1))
		return false;
	return true;
}

LL GetNum(LL x) {
	LL ans = 0;
	while(x) {
		if(x & 1)
			ans++;
		x >>= 1;
	}
	return ans;
}

void Init() {
	LL i;
	p = 0;
	memset(dp, 0, sizeof(dp));
	for(i = 0; i < (1 << m); i++)
		if(Check(i)) {
			status[p] = i;
			num[p++] = GetNum(i);
		}
}

int main() {
	LL r, i, l, j;
	while(~scanf("%lld%lld%lld", &n, &m, &k)) {
		if(!(n && m)) {
			printf("0\n");
			continue;
		}
		if(n < m) {
			int temp;
			temp = n; 
			n = m;
			m = temp;
		}
		Init();
		for(i = 0; i < p; i++)
			dp[1][num[i]][i] = 1;
		for(r = 2; r <= n; r++)
			for(i = 0; i < p; i++)
				for(l = 0; l < p; l++)
					if(!(status[i] & status[l]))
						for(j = 0; j <= k; j++)
							if(j - num[i] >= 0)
								dp[r][j][i] += dp[r - 1][j - num[i]][l];
		LL ans = 0;
		for(i = 0; i < p; i++)
			ans += dp[n][k][i];
		printf("%lld\n", ans);

	}
	return 0;
}
