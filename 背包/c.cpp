#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define INF 0x3f3f3f3f
using namespace std;

int a[10010];

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int E, F;
		scanf("%d%d", &E, &F);
		memset(a, INF, sizeof(a));
		int m = F - E;
		int x;
		scanf("%d", &x);
		int v, w;
		a[0] = 0;
		for(int i = 1; i <= x; i++) {
			scanf("%d%d", &v, &w);
			for(int k = w; k <= m; k++)
				a[k] = min(a[k - w] + v, a[k]);
		}
		if(a[m] == INF)
			printf("This is impossible.\n");
		else
			printf("The minimum amount of money in the piggy-bank is %d.\n", a[m]);
	}
	return 0;
}
