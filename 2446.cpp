#include <stdio.h>
#include <string.h>

int m, n;
int array[35][35];
int con[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
int match[35][35][2];
bool vis[35][35];

bool is_r(int r) {
	return r <= m && r > 0;
}

bool is_c(int c) {
	return c <= n && c > 0;
}

void change_array(int r, int c, int num) {
	int i;
	for(i = 0; i < 4; i++) {
		if(is_r(r + con[i][0]) && is_c(c + con[i][1]) && !array[r + con[i][0]][c + con[i][1]])
			array[r + con[i][0]][c + con[i][1]] = num;
	}
}

bool dfs(int r, int c) {
	int i;
	int a, b;
	for(i = 0; i < 4; i++) {
		a = r + con[i][0];
		b = c + con[i][1];
		if(is_r(a) && is_c(b) && array[a][b] == 2 && !vis[a][b]) {
			vis[a][b] = 1;
			if(!match[a][b][0] || dfs(match[a][b][0], match[a][b][1])) {
				match[a][b][0] = r;
				match[a][b][1] = c;
				return true;
			}
		}
	}
	return false;
}

int main() {
	int K;
	int r, c;
	int i, k;
	int flag;
	int sum;
	while(~scanf("%d%d%d", &m, &n, &K)) {
		memset(array, 0, sizeof(array));
		memset(match, 0, sizeof(match));
		sum = flag = 0;
		for(i = 1; i <= K; i++) {
			scanf("%d%d", &c, &r);
			array[r][c] = 1;
		}
		K = 0;
		for(i = 1; i <= m; i++)
			for(k = 1; k <= n; k++) {
				if(array[i][k] != 1)
					K++;
				if(!array[i][k]) {
					if((i + k) % 2)
						array[i][k] = 2;
					else
						array[i][k] = 3;
				}
			}
		for(i = 1; i <= m; i++)
			for(k = 1; k <= n; k++) {
				if(array[i][k] == 3) {
					memset(vis, 0, sizeof(vis));
					if(dfs(i, k))
						sum++;
				}
			}
		if(K == sum * 2)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
