#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>
#define Max 100
using namespace std;

int array[Max + 1][Max + 1];
bool flag[Max * Max + 1];
bool vis[Max + 1][Max + 1];
int con[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
int cur = 0;
int sum = 0;
int result;

struct node {
	int x, y, t;
};

void build_map(int r, int c, int num) {
if(r < 1 || c < 1 || r > Max || c > Max || array[r][c]) {
		cur = (cur + 1) % 4;
		return ;
	}
	array[r][c] = num;
	sum++;
	while(sum < Max * Max) {
		build_map(r + con[cur][0], c + con[cur][1], num - 1);
	}
}

void is_prime() {
	int i, k;
	for(i = 2; i + i <= Max * Max; i++)
		if(!flag[i])
			for(k = i + i; k <= Max * Max; k += i)
				flag[k] = 1;
	flag[1] = 1;
}

void bfs(int r_start, int c_start, int end) {
	int s[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};
	int x_now, y_now, t_now;
	int i, x_add, y_add;
	queue<node>Q;
	node n, l;
	n = (node){r_start, c_start, 0};
	Q.push(n);
	while(!Q.empty()) {
		x_now = Q.front().x;
		y_now = Q.front().y;
		t_now = Q.front().t;
		if(array[x_now][y_now] == end) {
			result = t_now;
			return ;
		}
		Q.pop();
		for(i = 0; i < 4; i++) {
			x_add = x_now + s[i][0];
			y_add = y_now + s[i][1];
			if(x_add >= 1 && x_add <= Max && y_add >= 1 && y_add <= Max && !vis[x_add][y_add] && flag[array[x_add][y_add]]) {
				vis[x_add][y_add] = 1;
				l = (node){x_add, y_add, t_now + 1};
				Q.push(l);
			}
		}
	}
}

int main() {
	int x, y;
	int i, k;
	int r_start, c_start, r_end, c_end;
	int time = 0;
	build_map(1, 1, Max * Max);
	is_prime();
	/*for(i = 1; i <= 20; i++) {
		for(k = 1; k <= 20; k++)
			printf("%3d ", array[i][k]);
		printf("\n");
	}*/
	while(~scanf("%d%d", &x, &y)) {
		r_start = c_start = r_end = c_end = 0;
		result = -1;
		memset(vis, 0, sizeof(vis));
		for(i = 1; i <= Max; i++) {
			for(k = 1; k <= Max; k++) {
				if(array[i][k] == x) {
					r_start = i;
					c_start = k;
				}
				if(r_start)
					break;
			}
			if(r_start)
				break;
		}
		if(x && y && flag[y])
			bfs(r_start, c_start, y);
		if(result != -1)
			printf("Case %d: %d\n", ++time, result);
		else
			printf("Case %d: impossible\n", ++time);
	}
	return 0;
}
