#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct Goods {
	int p, h;
};

Goods a[1010];

bool cmp(Goods x, Goods y) {
	return x.p < y.p;
}

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n, m;
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= m; i++)
			scanf("%d%d", &a[i].p, &a[i].h);
		sort(a + 1, a + 1 + m, cmp);
		double ans = 0;
		for(int i = 1; i <= m; i++) 
			if(a[i].p * a[i].h <= n) {
				ans += (double)a[i].h;
				n -= a[i].p * a[i].h;
			}
			else {
				ans += (double)n / (double)a[i].p;
				break;
			}
		printf("%.2lf\n", ans);
	}
	return 0;
}
