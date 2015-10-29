#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;

LL dp[2][6005][3];

struct node {
	int x;
	long long y;
};
node p[1005];

int main() {
	int t, tt = 1;
	scanf("%d", &t);
	while(t--) {
		memset(dp, 0, sizeof(dp));
		memset(p, 0, sizeof(p));
		int n, l;
		scanf("%d%d", &n, &l);
		long long ans = 0;
		for(int i = 1; i <= n; i++) {
			scanf("%d%lld", &p[i].x, &p[i].y);	
			p[i].x *= 2;
			ans = max(ans, p[i].y);
		}
		l *= 2;
		int now = 1;
		for(int i = 1; i <= n; i++) {
			now = 1 - now;
			for(int j = 0; j <= l; j++)
				for(int k = 0; k < 3; k++)
					dp[now][j][k] = dp[1 - now][j][k];
			for(int j = l; j >= p[i].x / 2; j--) {
				for(int k = 0; k < 3; k++) {
					if(j >= p[i].x) dp[now][j][k] = max(dp[now][j][k], dp[1 - now][j - p[i].x][k] + p[i].y);
					if(k) dp[now][j][k] = max(dp[now][j][k], dp[1 - now][j - p[i].x / 2][k - 1] + p[i].y);
				}	
			}
		}
		for(int i = 0; i < 2; i++)
			for(int j = 0; j <= l; j++)
				for(int k = 0; k < 3; k++)
					ans = max(dp[i][j][k], ans);
		printf("Case #%d: %lld\n", tt++, ans);	
	}
	return 0;
}
