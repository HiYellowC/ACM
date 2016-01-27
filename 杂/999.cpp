#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
using namespace std;
#define Max 110

int n, m, t;
int x_start, y_start;
char map[Max][Max];
bool flag[Max][Max][4];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int res;

typedef struct Node {
	int x, y, t;
}node;

void bfs() {
	queue<node>q;
	node New;
	int i, k;
	int x_add, y_add;
	int x_now, y_now, t_now;
	int cur[2][2][2] = {0, 1, 0, -1, 1, 0, -1, 0};
	New.x = x_start;
	New.y = y_start;
	New.t = 0;
	flag[x_start][y_start][0] = true;
	if(map[x_start][y_start] == 'd')
		flag[x_start][y_start][1] = true;
	else if(map[x_start][y_start] == 'e')
		flag[x_start][y_start][2] = true;
	else if(map[x_start][y_start] == 'h')
		flag[x_start][y_start][3] = true;
	q.push(New);
	while(!q.empty()) {
		x_now = q.front().x;
		y_now = q.front().y;
		t_now = q.front().t;
		q.pop();
		if(flag[x_now][y_now][3] == true) {
			res = t_now;
			return ;
		}
		for(i = 0; i < 2; i++)
			for(k = 0; k < 2; k++) {
				x_add = x_now + cur[i][k][0];
				y_add = y_now + cur[i][k][1];
				if(x_add >= 1 && x_add <= n && y_add >= 1 && y_add <= m && map[x_add][y_add] != 'X' && map[x_add][y_add] != 'D' && map[x_add][y_add] != 'E') {
					if(flag[x_add][y_add][0] == false || (flag[x_add][y_add][1] == false && flag[x_now][y_now][1] == true) || (flag[x_add][y_add][2] == false && flag[x_now][y_now][2] == true)) {
						flag[x_add][y_add][0] = true;
						if(flag[x_now][y_now][1])
							flag[x_add][y_add][1] = flag[x_now][y_now][1];
						if(flag[x_now][y_now][2])
							flag[x_add][y_add][2] = flag[x_now][y_now][2];
						if(map[x_add][y_add] == 'd'){
							flag[x_add][y_add][1] = true;
							if(flag[x_now][y_now][2])
								flag[x_add][y_add][3] = true;
						}
						if(map[x_add][y_add] == 'e') {
							flag[x_add][y_add][2] = true;
							if(flag[x_now][y_now][1])
								flag[x_add][y_add][3] = true;
						}
						if(map[x_add][y_add] == 'h'){
							flag[x_add][y_add][3] = true;
						}
						New.x = x_add;
						New.y = y_add;
						New.t = t_now + 1;
						q.push(New);
					}
				}
			}
		}
		res = -1;
}

bool is_true(int x, int y) {
	if(x <= 0 || x > n || y <= 0 || y > m || map[x][y] == 'X' || map[x][y] == 'E' || map[x][y] == 'D')
		return false;
	return true;
}

void init(int *p, char ch) {
	int tx, ty, i;
	for(i = 0; i < 4; i++) {
		tx = p[0] + dx[i];
		ty = p[1] + dy[i];
		while(is_true(tx, ty)) {
			if(map[tx][ty] == '.' || map[tx][ty] == 'S')
				map[tx][ty] = ch;
			else
				map[tx][ty] = 'h';
			tx += dx[i];
			ty += dy[i];
		}
	}
}

int main() {
	int cur = 1;
	int i, k, j, D[2], E[2];
	char str[Max];
	while(~scanf("%d%d%d", &n, &m, &t)) {
		res = 999999;
		for(i = 1; i <= n; i++) {
			scanf("%s", str);
			for(k = 1; k <= m; k++) {
				for(j = 0; j < 4; j++)
					flag[i][k][j] = false;
				map[i][k] = str[k - 1];
				if(map[i][k] == 'S')
					x_start = i, y_start = k;
			   else	if(map[i][k] == 'D')
					D[0] = i, D[1] = k;
			   else	if(map[i][k] == 'E')
				    E[0] = i, E[1] = k;
			}
		}
		init(D, 'd');
		init(E, 'e');
		bfs();
		if(res <= t)
			printf("Case %d:\n%d\n", cur++, res);
		else
			printf("Case %d:\n-1\n", cur++);
	}
	return 0;
}
