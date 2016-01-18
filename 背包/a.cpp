#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int a[5010];

struct good {
	int p, q, v;
};

good gd[510];

bool cmp(good a, good b) {
	return (a.p - a.q) > (b.p - b.q);
}

int main() {
	int n, m;
	while(~scanf("%d%d", &n, &m)) {
		int p, q, v;
		memset(a, 0, sizeof(a));
		for(int i = 1; i <= n; i++)
			scanf("%d%d%d", &gd[i].p, &gd[i].q, &gd[i].v);
		sort(gd + 1, gd + 1 + n, cmp);
		for(int i = 1; i <= n; i++) {
			for(int k = m; k >= gd[i].q; k--)
				a[k] = max(a[k], a[k - gd[i].p] + gd[i].v);
		}
		printf("%d\n", a[m]);
	}
	return 0;
}
