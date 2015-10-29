#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 200010
using namespace std;

long long ans[MAXN];

struct Edge {
	int a, b, cost;
};

Edge edge[MAXN];

int fa[MAXN], son[MAXN];

bool cmp(Edge x, Edge y) {
	return x.cost > y.cost;
}

int getfa(int x) {
	int root = x;
	while(fa[root] != root) root = fa[root];
	while(x != root) {
		int tmp = fa[x];
		fa[x] = root;
		x = tmp;
	}
	return root;
}

int main() {
	int n;
	while(~scanf("%d", &n)) {
		for(int i = 1; i <= n; i++) fa[i] = i, son[i] = 1, ans[i] = 0;
		for(int i = 1; i < n; i++) scanf("%d%d%d", &edge[i].a, &edge[i].b, &edge[i].cost);	
		sort(edge + 1, edge + n, cmp);
		long long sum1, sum2;
		for(int i = 1; i < n; i++) {
			int aa = getfa(edge[i].a);
			int bb = getfa(edge[i].b);
			sum1 = ans[bb] + (long long)son[aa] * edge[i].cost;
			sum2 = ans[aa] + (long long)son[bb] * edge[i].cost;
			if(sum1 > sum2) fa[aa] = bb, son[bb] += son[aa], ans[bb] = sum1;
			else fa[bb] = aa, son[aa] += son[bb], ans[aa] = sum2;
		}
		printf("%lld\n", max(sum1, sum2));
	}
	return 0;
}
