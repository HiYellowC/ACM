#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define INF 0x3f3f3f3f
using namespace std;

int a[1010];

int main() {
	int n;
	while(~scanf("%d", &n)) {
		memset(a, INF, sizeof(a));
		int num, ans = 0;
		for(int i = 1; i <= n; i++) {
			scanf("%d", &num);
			int *it = lower_bound(a + 1, a + 1 + n, num);
			ans = max(ans, (int)(it - a));
			*it = num;
		}
		printf("%d\n", ans);
	}
	return 0;
}
