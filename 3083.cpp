#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
using namespace std;
#define Max 45

char map1[Max][Max], map2[Max][Max];
int m, n;
int x_start, y_start;
int x_end, y_end;
int cur[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
int res1, res2, res3;

typedef struct Node {
	int x, y, t;
}node;

void bfs() {
	queue<node>q;
	node New;
	int i;
	int x_now, y_now, t_now;
	int x_add, y_add, t_add;
	New = (node){x_start, y_start, 1};
	q.push(New);
	while(!q.empty()) {
		x_now = q.front().x;
		y_now = q.front().y;
		t_now = q.front().t;
		q.pop();
		if(x_now == x_end && y_now == y_end) {
			res1 = t_now;
			return ;
		}
		for(i = 0; i < 4; i++) {
			x_add = x_now + cur[i][0];
			y_add = y_now + cur[i][1];
			t_add = t_now + 1;
			if(x_add > 0 && x_add <= m && y_add > 0 && y_add <= n && map1[x_add][y_add] != '#') {
				map1[x_add][y_add] = '#';
				New = (node){x_add, y_add, t_add};
				q.push(New);
			}
		}
	}
}

void dfs1(int x, int y, int t) {
	int i;
	int num[4][2];
	for(i = 0; i < 4; i++)
		num[i][0] = cur[i][0], num[i][1] = cur[i][1];
	int flag;
	if(x == x_end && y == y_end) {
		res2 = t;
		return ;
	}
	else if(!res2) {
		for(i = 0; i < 4; i++)
			if(x + cur[i][0] > 0 && x + cur[i][0] <= m && y + cur[i][1] > 0 && y + cur[i][1] <= n && map2[x + cur[i][0]][y + cur[i][1]] != '#') {
				flag = cur[i][0] * 2 + cur[i][1];
				switch(flag) {
					case 1: {
								cur[0][0] = -1, cur[0][1] = 0;
								cur[1][0] = 0, cur[1][1] = 1;
								cur[2][0] = 1, cur[2][1] = 0;
								cur[3][0] = 0, cur[3][1] = -1;
								break;
							}
					case -1: {	
								cur[0][0] = 1, cur[0][1] = 0;
								cur[1][0] = 0, cur[1][1] = -1;
								cur[2][0] = -1, cur[2][1] = 0;
								cur[3][0] = 0, cur[3][1] = 1;
								break;
							}
					case -2: {
								cur[0][0] = 0, cur[0][1] = -1;
								cur[1][0] = -1, cur[1][1] = 0;
								cur[2][0] = 0, cur[2][1] = 1;
								cur[3][0] = 1, cur[3][1] = 0;
								break;
							}
					case 2: {
								cur[0][0] = 0, cur[0][1] = 1;
								cur[1][0] = 1, cur[1][1] = 0;
								cur[2][0] = 0, cur[2][1] = -1;
								cur[3][0] = -1, cur[3][1] = 0;
								break;
							 }
				}
				dfs1(x + num[i][0], y + num[i][1], t + 1);
				for(i = 0; i < 4; i++)
					cur[i][0] = num[i][0], cur[i][1] = num[i][1];
				if(res2)
					return ;
			}
	}
}

void dfs2(int x, int y, int t) {
	int i;
	int num[4][2];
	for(i = 0; i < 4; i++)
		num[i][0] = cur[i][0], num[i][1] = cur[i][1];
	int flag;
	if(x == x_end && y == y_end) {
		res3 = t;
		return ;
	}
	else if(!res3) {
		for(i = 0; i < 4; i++)
			if(x + cur[i][0] > 0 && x + cur[i][0] <= m && y + cur[i][1] > 0 && y + cur[i][1] <= n && map2[x + cur[i][0]][y + cur[i][1]] != '#') {
				flag = cur[i][0] * 2 + cur[i][1];
				switch(flag) {
					case 1: {
								cur[0][0] = 1, cur[0][1] = 0;
								cur[1][0] = 0, cur[1][1] = 1;
								cur[2][0] = -1, cur[2][1] = 0;
								cur[3][0] = 0, cur[3][1] = -1;
								break;
							}
					case -1: {	
								cur[0][0] = -1, cur[0][1] = 0;
								cur[1][0] = 0, cur[1][1] = -1;
								cur[2][0] = 1, cur[2][1] = 0;
								cur[3][0] = 0, cur[3][1] = 1;
								break;
							}
					case -2: {
								cur[0][0] = 0, cur[0][1] = 1;
								cur[1][0] = -1, cur[1][1] = 0;
								cur[2][0] = 0, cur[2][1] = -1;
								cur[3][0] = 1, cur[3][1] = 0;
								break;
							}
					case 2: {
								cur[0][0] = 0, cur[0][1] = -1;
								cur[1][0] = 1, cur[1][1] = 0;
								cur[2][0] = 0, cur[2][1] = 1;
								cur[3][0] = -1, cur[3][1] = 0;
								break;
							 }
				}
				dfs2(x + num[i][0], y + num[i][1], t + 1);
				for(i = 0; i < 4; i++)
					cur[i][0] = num[i][0], cur[i][1] = num[i][1];
				if(res3)
					return ;
			}
	}
}
int main() {
	int total;
	int i, k;
	char str[Max];
	scanf("%d", &total);
	while(total--) {
		res1 = res2 = res3 = 0;
		scanf("%d%d", &n, &m);
		for(i = 1; i <= m; i++) {
			scanf("%s", str);
			for(k = 1; k <= n; k++) {
				map1[i][k] = map2[i][k] = str[k - 1];
				if(map1[i][k] == 'S')
					x_start = i, y_start = k;
				if(map1[i][k] == 'E')
					x_end = i, y_end = k;
			}
		}
		bfs();
		dfs1(x_start, y_start, 1);
		dfs2(x_start, y_start, 1);
		printf("%d %d %d\n", res2, res3, res1);
	}
	return 0;
}
