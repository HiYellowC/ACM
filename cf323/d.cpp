#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 110
#define INF 0x3f3f3f3f
using namespace std;

int a[MAXN];
int v[20010];
int f[20010], g[20010];
int vis[310];
int cnt[310];

int main() {
	int n, T;
	scanf("%d%d", &n, &T);
	for(int i = 0; i < n; i++) scanf("%d", &a[i]), vis[a[i]]++;
	int ans = 0;
	if(T <= 200) {
		memset(v, INF, sizeof(v));	
		for(int i = 0; i < T * n; i++) {
			int dex = upper_bound(v, v + T * n, a[i % n]) - v;
			v[dex] = a[i % n];
			ans = max(dex + 1, ans);
		}
		printf("%d\n", ans);
	}
	else {
		memset(v, INF, sizeof(v));
		for(int i = 0; i < 100 * n; i++) {
			int dex = upper_bound(v, v + 100 * n, a[i % n]) - v;
			v[dex] = a[i % n];
			g[i] = dex + 1;
		}	
		memset(v, INF, sizeof(v));
		for(int i = 100 * n - 1; i >= 0; i--) {
			int dex = upper_bound(v, v + 100 * n, -a[i % n]) - v;
			v[dex] = -a[i % n];
			f[i] = dex + 1;
			cnt[a[i % n]] = max(cnt[a[i % n]], dex + 1);
		}
		for(int i = 0; i < 100 * n; i++) {
			int add = 0;
			for(int k = a[i % n]; k >= 1; k--) add = max(add, cnt[a[i % n]]);
			ans = max(ans, g[i] + vis[a[i % n]] * (T - 200) + add);		
		}	
		printf("%d\n", ans);
	}
	return 0;
}
