#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int MAXN = 100010;

struct Node {
	int w, s;
};

Node node[MAXN];

bool cmp(Node x, Node y) {
	return x.w < y.w;
}

int main() {
	int n;
	while(~scanf("%d", &n)) {
		for(int i = 1; i <= n; i++) scanf("%d%d", &node[i].w, &node[i].s);
		sort(node + 1, node + 1 + n, cmp);
		LL ans = 0;
		LL sum = 0;
		for(int i = 1; i <= n; i++) {
			ans = max(ans, max(sum - (LL)node[i].s, (LL)0));
			sum += (LL)node[i].w;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
