#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m;
bool vis[110][110];
char Map[110][110];
int cur[8][2] = {1, 1, 1, 0, 1, -1, 0, 1, 0, -1, -1, 1, -1, 0, -1, -1};

void dfs(int r, int c) {
	if(r > n || r < 1 || c > m || c < 1 || Map[r][c] == '*' || vis[r][c]) return ;
	vis[r][c] = 1;
	for(int i = 0; i < 8; i++)
		dfs(r + cur[i][0], c + cur[i][1]);
}

int main() {
	while(~scanf("%d%d", &n, &m)) {
		if(!n) break;
		memset(vis, 0, sizeof(vis));
		for(int i = 1; i <= n; i++)
			scanf("%s", Map[i] + 1);
		int ans = 0;
		for(int i = 1; i <= n; i++)
			for(int k = 1; k <= m; k++)
				if(Map[i][k] == '@' && !vis[i][k])
					dfs(i, k), ans++;
		printf("%d\n", ans);
	}
	return 0;
}
