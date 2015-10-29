#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MOD 1000000007
#define MAXN 100010
using namespace std;

typedef long long LL;

struct Node {
	LL x;
	int y;
};
Node node[MAXN * 2];

bool cmp(Node a, Node b) {
	return a.x < b.x;
}

LL Power[MAXN];

void Init() {
	Power[0] = 1;
	for(int i = 1; i <= 100000; i++)
		Power[i] = (Power[i - 1] * 2) % MOD;
	for(int i = 1; i <= 100000; i++)
		Power[i] = (Power[i] + Power[i - 1]) % MOD;
} 

int main() {
	int t;
	scanf("%d", &t);
	Init();
	while(t--) {
		int n;
		scanf("%d", &n);
		for(int i = 1; i <= 2 * n; i++) {
			scanf("%lld", &node[i].x);
			if(i & 1) node[i].y = 1;
			else node[i].y = -1;
		}
		sort(node + 1, node + 1 + 2 * n, cmp);
		node[0].x = node[1].x;
		LL ans = 0;
		int cur = 0;
		for(int i = 1; i <= 2 * n; i++) {
			if(node[i].x != node[i - 1].x) {
				LL len = node[i].x - node[i - 1].x;
				LL gx;
				if(n - cur - 1 < 0) gx = Power[n - 1];
				else gx = (Power[n - 1] - Power[n - cur - 1] + MOD) % MOD;
				ans = (ans + (len * gx) % MOD) % MOD;
			}
			cur += node[i].y;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
