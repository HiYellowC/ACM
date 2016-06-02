#include <bits/stdc++.h>
using namespace std;

const int MAXN = 300;
const int INF = 0x3f3f3f3f;

int Map[MAXN][MAXN], dis[25][25], mark[MAXN][MAXN], leap[MAXN][MAXN];
int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
int coord[25][3], dp[1 << 18][20], n, m;

struct node {
	int x, y;
	int step;
}a, b;

void bfs(int k) {
	a.x = coord[k][1];
	a.y = coord[k][2];
	a.step = 0;
	queue<node>q;
	memset(mark, 0, sizeof(mark));
	mark[a.x][a.y] = 1;
	q.push(a);
	while(!q.empty()) {
		b = q.front();
		q.pop();
		for(int i = 0; i < 4; i++) {
			a.x = b.x + dir[i][0];
			a.y = b.y + dir[i][1];
			a.step = b.step + 1;
			if(a.x <= 0 || a.x > n || a.y <= 0 || a.y > m) continue;
			if(Map[a.x][a.y] == -1) continue;
			if(mark[a.x][a.y] == 0) {
				mark[a.x][a.y] = 1;
				if(leap[a.x][a.y] > -1) dis[k][leap[a.x][a.y]] = dis[leap[a.x][a.y]][k] = a.step;
				q.push(a);
			}
		}
	}
}

int main() {
	while(~scanf("%d%d", &n, &m)) {
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++) {
				scanf("%d", &Map[i][j]);
				leap[i][j] = -1;
			}
		if(Map[1][1] == 0 && (n > 1 || m > 1)) {
			printf("you loss!\n");
			continue;
		}
		else if(n == 1 && m == 1) {
			printf("%d\n", Map[1][1]);
			continue;
		}
		int t = -1;
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++) {
				if(Map[i][j] > 0) {
					coord[++t][1] = i;
					coord[t][2] = j;
					leap[i][j] = t;
				}	
			}
		if(Map[n][m] == 0) {
			coord[++t][1] = n;
			coord[t][2] = m;
			leap[n][m] = t;
		}
		memset(dis, INF, sizeof(dis));
		for(int i = 0; i < t; i++) {
			dis[i][i] = 0;
			bfs(i);
		}
		dis[t][t] = 0;
		memset(dp, -1, sizeof(dp));
		dp[1][0] = Map[1][1];
		int k = (1 << (t + 1));
		int Max = -1;
		for(int i = 1; i < k; i++) {
			for(int j = 0; j <= t; j++) {
				if((i & (1 << j)) == 0) continue;
				if(dp[i][j] < 0) continue;
				for(int x = 0; x <= t; x++) {
					if(x == j) continue;
					if(dp[i][j] < dis[j][x]) continue;
					if((i & (1 << x))) continue;
					dp[i | (1 << x)][x] = max(dp[i | (1 << x)][x], dp[i][j] - dis[x][j] + Map[coord[x][1]][coord[x][2]]);
					Max = max(Max, dp[i | (1 << x)][x] - dis[x][t]);
				}
			}		
		}
		if(Max < 0) printf("you loss!\n");
		else printf("%d\n", Max);
	}
	return 0;
}
