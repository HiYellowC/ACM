#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int MAXN = 2010;

int n, m;
int pos[MAXN];
double dp[MAXN];

double cla(int l) {
	return 1e6 * (log((double)l) / log(2.0));
}

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= m; i++) scanf("%d", &pos[i]);
		sort(pos + 1, pos + 1 + m);
		memset(dp, 0, sizeof(dp));
		int dex = 1;
		for(int i = pos[dex]; i < n; i++) {
			// pos[i];
			if(dex < m && i == pos[dex + 1]) dex++;
			if(dex == 1) dp[i] = cla(i + 1);
			else {
				for(int j = pos[dex - 1]; j < pos[dex]; j++) dp[i] = max(dp[i], dp[j] + cla(i - j));
			}
		}
		printf("%lld\n", (LL)floor(dp[n - 1]));
	}
	return 0;
}
