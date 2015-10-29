#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int dp[3010];

struct Node {
	int a, b, c;
};
Node node[1010];

bool cmp(Node x, Node y) {
	return x.c < y.c;
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int n, t;
		scanf("%d%d", &n, &t);
		memset(dp, 0, sizeof(dp));
		for(int i = 1; i <= n; i++) scanf("%d%d%d", &node[i].a, &node[i].b, &node[i].c);
		sort(node + 1, node + 1 + n, cmp);
		for(int i = 1; i <= n; i++) {
			for(int k = t; k >= node[i].c; k--)
				dp[k] = max(dp[k], dp[k - node[i].c] + max(node[i].a - node[i].b * k, 0));
		}
		int ans = 0;
		for(int i = 0; i <= t; i++) ans = max(ans, dp[i]);
		printf("%d\n", ans);
	}
	return 0;
}
