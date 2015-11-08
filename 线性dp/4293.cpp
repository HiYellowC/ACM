#include <bits/stdc++.h>
using namespace std;

const int MAXN = 510;

struct Node {
	int l, r;
};

int n;
int con[MAXN][MAXN];
int dp[MAXN];
Node node[MAXN];

bool cmp(Node x, Node y) {
	return x.r < y.r || (x.r == y.r && x.l > y.l);	
}

int main() {
	while(~scanf("%d", &n)) {
		int a, b;
		memset(dp, 0, sizeof(dp));
		memset(con, 0, sizeof(con));
		for(int i = 1; i <= n; i++) {
			scanf("%d%d", &a, &b);
			node[i].l = a + 1;
			node[i].r = n - b;
		}
		sort(node + 1, node + 1 + n, cmp);
		for(int i = 1; i <= n; i++) {
			int l = node[i].l;
			int r = node[i].r;
			if(node[i].r < node[i].l || node[i].r - node[i].l + 1 > n || con[l][r] == r - l + 1) continue;
			con[l][r]++;
			dp[r] = max(dp[r], dp[l - 1] + con[l][r]);
			for(int k = r + 1; k <= n; k++) dp[k] = dp[r];
		}
		printf("%d\n", dp[n]);
	}
	return 0;
}
