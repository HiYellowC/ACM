#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;

const int MAXN = 1000010;

int a[MAXN], sum[MAXN];
LL pre[MAXN];
LL ans[MAXN];
int vis[MAXN];

int main() {
	int n;
	while(~scanf("%d", &n) && n) {
		memset(vis, 0, sizeof(vis));
		for(int i = 1; i <= n; i++) scanf("%d", &a[i]);	
		sum[n + 1] = 0;
		for(int i = n; i >= 1; i--) {
			if(!vis[a[i]]) sum[i] = sum[i + 1] + 1;
			else sum[i] = sum[i + 1];
			vis[a[i]] = 1;
		}
		memset(vis, 0, sizeof(vis));
		memset(pre, 0, sizeof(pre));
		for(int i = 1; i <= n; i++) {
			if(!vis[a[i]]) pre[i]++;
			else pre[i - vis[a[i]]]++;
			vis[a[i]] = i;
		}
		for(int i = n - 1; i >= 1; i--) pre[i] += pre[i + 1];	
		ans[1] = n;
		for(int i = 2; i <= n; i++)
			ans[i] = ans[i - 1] - sum[n - i + 2] + pre[i];
		int m;
		scanf("%d", &m);
		while(m--) {
			int w;
			scanf("%d", &w);
			printf("%lld\n", ans[w]);
		}
	}
	return 0;
}
