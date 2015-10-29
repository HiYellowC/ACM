#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <ctime>
using namespace std;
#define Max 110
#define INF 65536 * 2

char map[Max][Max];
bool sta[Max][Max][INF];
int m, n;
int num_of_checkpoint;
int x_start, y_start;
int result = -1;

typedef struct Point {
	int x, y, t;
	int flag;
}point;

void bfs() {
	queue<point>q;
	point p;
	int i, k, j;
	int cur[2][2][2] = {0, 1, 0, -1, 1, 0, -1, 0};
	int x_now, y_now, t_now, sta_now;
	int x_add, y_add, t_add, sta_add;
	int con;
	p.x = x_start;
	p.y = y_start;
	p.t = 0;
	p.flag = 0;
	q.push(p);
	while(!q.empty()) {
		x_now = q.front().x;
		y_now = q.front().y;
		t_now = q.front().t;
		sta_now = q.front().flag;
		q.pop();
		for(i = 0; i < 2; i++)
			for(k = 0; k < 2; k++) {
				x_add = x_now + cur[i][k][0];
				y_add = y_now + cur[i][k][1];
				t_add = t_now + 1;
				sta_add = sta_now;
				if(map[x_add][y_add] != '#' && sta[x_add][y_add][sta_now] == false) {
					sta[x_add][y_add][sta_now] = true;
					if(map[x_add][y_add] <= 'z' && map[x_add][y_add] >= 'a') {
						sta[x_add][y_add][1 << (map[x_add][y_add] - 'a')] = true;
						sta[x_add][y_add][sta_now + (1 << (map[x_add][y_add] - 'a'))] = true;
						sta_add += (1 << (map[x_add][y_add] - 'a'));
					}
					con = 1;
					while(con < sta_add) {
						if(con & sta_add)
							sta[x_add][y_add][sta_add - con] = true;
						con <<= 1;
					}
					if(sta[x_add][y_add][(1 << num_of_checkpoint) - 1] == true && map[x_add][y_add] == 'G') {
						result = t_add;
						return ;
					}
					p = (point){x_add, y_add, t_add, sta_add};
					q.push(p);
				}
			}
	}
}

int main() {
	clock_t start, end;
	start = clock();
	int i, k;
	char str[Max];
	scanf("%d%d", &m, &n);
	for(i = 1; i <= n; i++) {
		scanf("%s", str);
		for(k = 1; k <= m; k++) {
			map[i][k] = str[k - 1];
			if(map[i][k]  == 'S')
				x_start = i, y_start = k;
			if(map[i][k] == '@')
				map[i][k] = 'a' + num_of_checkpoint++;
		}
	}
	bfs();
	printf("%d\n", result);
	end = clock();
	printf("the run time is %lf\n", (double)(end - start) / CLOCKS_PER_SEC);
	return 0;
}
