#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 250010
using namespace std;

int a[MAXN];
int c[510];
int vis[MAXN];

int gcd(int x, int y) {
	return y == 0 ? x : gcd(y, x % y);
}

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n * n; i++) scanf("%d", &a[i]);
	sort(a + 1, a + 1 + n * n);
	int dex = 1;
	vis[dex] = 1;
	for(int i = 2; i <= n * n; i++)
		if(a[i] == a[i - 1]) vis[dex]++;
		else vis[++dex]++;
	int m = unique(a + 1, a + 1 + n * n) - a - 1;
	dex = 1;
	c[dex] = a[m];
	vis[m]--;
	for(int i = m; i >= 1; ) {
		if(!vis[i]) {
			i--;
			continue;
		}
		for(int k = 1; k <= dex; k++) {
			int GCD = gcd(c[k], a[i]);
			int x = lower_bound(a + 1, a + 1 + m, GCD) - a;
			vis[x] -= 2;
		}
		vis[i]--;
		c[++dex] = a[i];
	}
	for(int i = 1; i <= dex; i++) printf("%d%c", c[i], " \n"[i == dex]);
	return 0;
}
