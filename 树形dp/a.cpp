#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define Max 6010
using namespace std;

int rating[Max];
int Start[Max], Next[Max * 2], End[Max * 2];
int dex;
bool vis[Max];
int dp[Max][2];

void Init() {
	dex = 0;
	memset(Start, 0, sizeof(Start));
	memset(vis, 0, sizeof(vis));
}

void BuildG(int a, int b) {
	Next[++dex] = Start[a];
	Start[a] = dex;
	End[dex] = b;
}

void dfs(int v) {
	vis[v] = 1;
	dp[v][0] = 0, dp[v][1] = rating[v];
	for(int i = Start[v]; i; i = Next[i]) {
		int to = End[i];	
		if(!vis[to]) {
			dfs(to);
			dp[v][0] += max(dp[to][1], dp[to][0]);
			dp[v][1] += dp[to][0];
		}
	}
}

int main() {
	int n;
	while(~scanf("%d", &n)) {
		Init();
		for(int i = 1; i <= n; i++)
			scanf("%d", &rating[i]);
		int l, r;
		while(scanf("%d%d", &l, &r)) {
			if(!l && !r) break;
			BuildG(l, r);
			BuildG(r, l);
		}
		int ans = 0;
		for(int i = 1; i <= n; i++) 
			if(!vis[i]) {
				dfs(i);
				ans += max(dp[i][0], dp[i][1]);
			}
		printf("%d\n", ans);
	}
	return 0;
}
