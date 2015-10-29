#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 1030
using namespace std;

int n;

int T[MAXN][MAXN];

int lowbit(int x) {
	return x & (-x);
}

void Update(int x, int y, int add) {
	for(int i = x; i <= n; i += lowbit(i))
		for(int k = y; k <= n; k += lowbit(k))
			T[i][k] += add;
}

int Query(int x, int y) {
	int ans = 0;
	for(int i = x; i > 0; i -= lowbit(i))
		for(int k = y; k > 0; k -= lowbit(k))
			ans += T[i][k];
	return ans;
}

int main() {
	int op;
	while(~scanf("%d", &op)) {
		if(op == 0) scanf("%d", &n);
		else if(op == 1) {
			int x, y, add;
			scanf("%d%d%d", &x, &y, &add);
			Update(x + 1, y + 1, add);
		}
		else if(op == 2) {
			int x1, x2, y1, y2;
			scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
			printf("%d\n", Query(x2 + 1, y2 + 1) - Query(x2 + 1, y1) - Query(x1, y2 + 1) + Query(x1, y1));
		}
		else break;
	}
	return 0;
}
