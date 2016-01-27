#include <stdio.h>
#define Max 25

int m, n;
int map[Max][Max];
int x_start, y_start;
int x_end, y_end;
int res;
int con[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};

void dfs(int x, int y, int t) {
	int i, k;
	int x_add, y_add;
	if(t > 10)
		return ;
	if(x == x_end && y == y_end) {
		if(t < res || res == -1)
			res = t;
	}
	else {
		for(i = 0; i < 4; i++) {
			if(x + con[i][0] > 0 && x + con[i][0] <= m && y + con[i][1] > 0 && y + con[i][1] <= n && map[x + con[i][0]][y + con[i][1]] != 1) {
				x_add = x + con[i][0];
				y_add = y + con[i][1];
				while(x_add > 0 && x_add <= m && y_add > 0 && y_add <= n && map[x_add][y_add] == 0) {
					x_add += con[i][0];
					y_add += con[i][1];
				}
				if(x_add <= 0 || x_add > m || y_add <= 0 || y_add > n)
					continue;
				if(map[x_add][y_add] == 3)
					dfs(x_add, y_add, t + 1);
				if(map[x_add][y_add] == 1) {
					map[x_add][y_add] = 0;
					dfs(x_add - con[i][0], y_add - con[i][1], t + 1);
					map[x_add][y_add] = 1;
				}
			}
		}
	}
}

int main() {
	int i, k;
	while(scanf("%d%d", &n, &m)) {
		if(!n || !m)
			break;
		res = -1;
		for(i = 1; i <= m; i++)
			for(k = 1; k <= n; k++) {
				scanf("%d", &map[i][k]);
				if(map[i][k] == 2)
					x_start = i, y_start = k;
				if(map[i][k] == 3)
					x_end = i, y_end = k;
			}
		map[x_start][y_start] = 0;
		dfs(x_start, y_start, 0);
		printf("%d\n", res);
	}
	return 0;
}
