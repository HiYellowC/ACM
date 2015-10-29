#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 110
using namespace std;

int w, h;
int T[MAXN][MAXN];

int lowbit(int x) {
	return x & (-x);
}

void add(int x, int y) {
	for(int i = x; i <= h; i += lowbit(i))
		for(int k = y; k <= w; k += lowbit(k))
			T[i][k]++;
}

int count(int x, int y) {
	int ans = 0;
	if(x <= 0 || y <= 0) return 0;
	for(int i = x; i; i -= lowbit(i))
		for(int k = y; k; k -= lowbit(k))
			ans += T[i][k];
	return ans;
}

int Query(int x, int y) {
	int ans = 0;
	for(int i = x; i <= h; i++)
		for(int k = y; k <= w; k++)
			ans = max(ans, count(i, k) - count(i, k - y) - count(i - x, k) + count(i - x, k - y));
	return ans;
}

int main() {
	int n;
	while(~scanf("%d", &n) && n) {
		memset(T, 0, sizeof(T));
		scanf("%d%d", &w, &h);
		int x, y;
		for(int i = 1; i <= n; i++) {
			scanf("%d%d", &x, &y);
			add(y, x);
		}
		scanf("%d%d", &x, &y);
		printf("%d\n", Query(y, x));
	}
	return 0;
}
