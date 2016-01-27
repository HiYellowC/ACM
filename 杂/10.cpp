#include <stdio.h>
#include <string.h>

int map[101][101];
int result[101][101];
int cur[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
int R, C;

int fun(int a, int b) {
	int i, num;
	int & con = result[a][b];
	if(con)
		return con;
	for(i = 0; i < 4; i++) {
		if(a + cur[i][0] <= R && b + cur[i][1] <= C && map[a][b] < map[a + cur[i][0]][b + cur[i][1]]) {
			num = fun(a + cur[i][0], b + cur[i][1]);
			if(1 + num > con)
				con = num + 1;
		}
	}
	return con;
}

int main() {
	int total;
	int i, k, num, RES;
	scanf("%d", &total);
	while(total--) {
		scanf("%d%d", &R, &C);
		memset(result, 0, sizeof(result));
		RES = 0;
		for(i = 1; i <= R; i++)
			for(k = 1; k <= C; k++)
				scanf("%d", &map[i][k]);
		for(i = 1; i <= R; i++)
			for(k = 1; k <= C; k++) {
				num = fun(i, k);
				if(num > RES)
					RES = num;
			}
		printf("%d\n", RES + 1);
	}
	return 0;
}
