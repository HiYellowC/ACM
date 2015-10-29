#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define Maxn 20010
#define Maxm 100010
using namespace std;

struct Edge {
	int a, b, val;
};

Edge edge[Maxm];

struct Node {
	int cost, cur;
};

Node query[5010];

long long ans[5010];
long long sum;

bool cmp1(Edge x, Edge y) {
	return x.val < y.val;
}

bool cmp2(Node x, Node y) {
	return x.cost < y.cost;
}

int par[Maxn], son[Maxn];

int Getf(int x) {
	return x == par[x] ? x : Getf(par[x]);
}

void Join(int a, int b) {
	int fa = Getf(a);
	int fb = Getf(b);
	if(fa == fb) return ;
	sum += (long long)son[fa] * son[fb];
	if(son[fa] < son[fb]) {
		par[fa] = fb;
		son[fb] += son[fa];
		son[fa] = 0;
	}
	else {
		par[fb] = fa;
		son[fa] += son[fb];
		son[fb] = 0;
	}
}

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n, m, q;
		scanf("%d%d%d", &n, &m, &q);
		for(int i = 1; i <= n; i++)
			par[i] = i, son[i] = 1;
		for(int i = 1; i <= m; i++)
			scanf("%d%d%d", &edge[i].a, &edge[i].b, &edge[i].val);
		sort(edge + 1, edge + 1 + m, cmp1);
		for(int i = 1; i <= q; i++)
			scanf("%d", &query[i].cost), query[i].cur = i;	
		sort(query + 1, query + 1 + q, cmp2);
		int s = 1;
		sum = 0;
		for(int i = 1; i <= q; i++) {
			int j;
			for(j = s; edge[j].val <= query[i].cost; j++) {
				Join(edge[j].a, edge[j].b);	
			}	
			s = j;
			ans[query[i].cur] = sum;
		}	
		for(int i = 1; i <= q; i++)
			printf("%lld\n", ans[i] * 2);
	}
	return 0;
}
