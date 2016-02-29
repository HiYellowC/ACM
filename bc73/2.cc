#include <bits/stdc++.h>
using namespace std;

const int MAXN = 110;

int n;
int dex, Start[MAXN], Next[MAXN * 2], End[MAXN * 2], Id[MAXN * 2];
bool vis[MAXN];

void BuildG(int x, int y, int i) {
	Next[++dex] = Start[x];
	Start[x] = dex;
	End[dex] = y;
	Id[dex] = i;
}

void dfs(int v, int x, int y) {
	vis[v] = true;
	for(int i = Start[v]; i; i = Next[i]) {
		int to = End[i];
		if(vis[to]) continue;
		if(Id[i] == x || Id[i] == y) continue;
		dfs(to, x, y);
	}
}

bool OK(int x, int y) {
	memset(vis, 0, sizeof(vis));
	dfs(1, x, y);
	for(int i = 1; i <= n; i++) if(!vis[i]) return false;
	return true;
}

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		memset(Start, 0, sizeof(Start));
		dex = 0;
		int x, y;
		for(int i = 1; i <= n + 1; i++) {
			scanf("%d%d", &x, &y);
			BuildG(x, y, i);
			BuildG(y, x, i);
		}
		int ans = 0;
		for(int i = 1; i <= n + 1; i++) if(OK(i, 0)) ans++;	
		for(int i = 1; i <= n + 1; i++)
			for(int j = i + 1; j <= n + 1; j++)
				if(OK(i, j)) ans++;
		printf("%d\n", ans);
	}
	return 0;
}
