#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 100010;

int n, m;
bool dp[MAXN];
int a[MAXN], c[MAXN];
int queue[MAXN];

int main() {
	while(~scanf("%d%d", &n, &m)) {
		if(!n && !m) break;
		memset(dp, 0, sizeof(dp));
		dp[0] = true;
		for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
		for(int i = 1; i <= n; i++) scanf("%d", &c[i]);
		//二进制优化
		/****************
		for(int i = 1; i <= n; i++) {
			if(c[i] * a[i] >= m) {
				for(int j = a[i]; j <= m; j++)
					if(dp[j - a[i]]) dp[j] = true;
			}
			else {
				int k = 1;
				while(k <= c[i]) {
					for(int j = m; j >= k * a[i]; j--)
						if(dp[j - k * a[i]]) dp[j] = true;
					c[i] -= k;
					k <<= 1;
				}
				for(int j = m; j >= c[i] * a[i]; j--)
					if(dp[j - c[i] * a[i]]) dp[j] = true;
			}
		}
		***************/
		//单调队列优化
		//由于每种状态只有0 1两种值，所以这里的队列并非单调队列，借用sum保存队列里的和，很巧妙Orz...
		for(int i = 1; i <= n; i++) {
			if(c[i] * a[i] >= m) {
				for(int j = a[i]; j <= m; j++)
					if(dp[j - a[i]]) dp[j] = true;
			}
			else {
				for(int d = 0; d < a[i]; d++) {
					int sum = 0, st = 0, ed = -1;
					for(int v = d; v <= m; v += a[i]) {
						if(ed - st == c[i]) {
							sum -= queue[st++];	
						}	
						queue[++ed] = dp[v];
						sum += dp[v];
						if(sum) dp[v] = true;
					}
				}	
			}
		}

		int ans = 0;
		for(int i = 1; i <= m; i++) if(dp[i]) ans++;
		printf("%d\n", ans);
	}
	return 0;
}
