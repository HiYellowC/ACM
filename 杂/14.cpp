#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct act {
	int l, r;
};

act a[10000];

bool cmp(act a, act b) {
	return a.r < b.r;
}

int main() {
	int total, i, n, p, conut;
	scanf("%d", &total);
	while(total--) {
		scanf("%d", &n);
		for(i = 1; i <= n; i++)
			scanf("%d%d", &a[i].l, &a[i].r);
		sort(a + 1, a + 1 + n, cmp);
		conut = p = 1;
		for(i = 2; i <= n; i++) {
			if(a[i].l > a[p].r) {
				conut++;
				p = i;
			}
		}
		printf("%d\n", conut);
	}
	return 0;
}
