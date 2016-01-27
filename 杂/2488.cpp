#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
#define Max 10

int m, n;
int flag;
int sum;
int map[Max][Max];
int con[2][2][2][2] = {1, 2, -1, 2, 1, -2, -1, -2, 2, 1, 2, -1, -2, 1, -2, -1};
int space[64][2];

void dfs(int x, int y, int cur) {
	int i, j, k;
	for(i = 0; i < 2; i++)
		for(j = 0, j < 2; j++)
			for(k = 0; k < 2; k++)
				if(map[x + con[i][j][k][0]][y + con[i][j][k][1]] == 0) {
					map[x + con[i][j][k][0]][y + con[i][j][k][1]] = 1;
					space[cur + 1][0] = x + con[i][j][k][0];
					space[cur + 1][0] = y + con[i][j][k][1];
					if(cur + 1 == sum) {
						flag = 1;
						return ;
					}
					dfs(x + con[i][j][k][0], y + con[i][j][k][1], cur + 1);
					map[x + con[i][j][k][0]][y + con[i][j][k][1]] = 0;
				}
}

int main() {
	int total, cur;
	cur = 1;
	scanf("%d", &total);
	while(total--) {
		memset(map, 0, sizeof(map));
		flag = 0;
		scanf("%d%d", &m, &n);
		sum = m * n;
		int i, k;
		for(i = 1; i <= m; i++) {
			for(k = 1; k <= n; k++) {
				space[0][0] = i;
				space[0][1] = k;
				dfs(i, k, 0);
				if(flag)
					break;
			}
			if(flag)
				break;
		}
		printf("Scenario #%d:\n", cur++);
		if(flag) {
			for(i = 0; i <= )
		}
		else
			printf("impossible\n");
	}
	return 0;
}
