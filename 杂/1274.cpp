#include <stdio.h>
#include <string.h>

int N, M;
bool map[401][401];
bool flag[401];
int match[401];

bool dfs(int a) {
	int i;
	for(i = N + 1; i <= N + M; i++) {
		if(!flag[i] && map[a][i]) {
			flag[i] = 1;
			if(!match[i] || dfs(match[i])) {
				match[a] = i;
				match[i] = a;
				return true;
			}
		}
	}
	return false;
}

int main() {
	int i, j, k, num_of_stall, sum;
	while(~scanf("%d%d", &N, &M)) {
		memset(map, 0, sizeof(map));
		memset(match, 0, sizeof(match));
		sum = 0;
		for(i = 1; i <= N; i++) {
			scanf("%d", &num_of_stall);
			for(k = 1; k <= num_of_stall; k++) {
				scanf("%d", &j);
				map[i][N + j] = map[N + j][i] = 1;
			}
		}
		for(i = 1; i <= N; i++) {
			memset(flag, 0, sizeof(flag));
			if(dfs(i))
				sum++;
		}
		printf("%d\n", sum);
	}
	return 0;
}
