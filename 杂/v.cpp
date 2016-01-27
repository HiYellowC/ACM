#include <stdio.h>
#include <string.h>
#define Max 100

int v, l;
int dex;
int num[Max];
int low[Max];
bool e[Max][Max];
bool flag[Max];

int min(int a, int b) {
	return a < b ? a : b;
}

void dfs(int cur, int father) {
	int i;
	int child = 0;
	dex++;
	num[cur] = low[cur] = dex;
	for(i = 1; i <= v; i++) {
		if(e[cur][i]) {
			if(!num[i]) {
				child++;
				dfs(i, cur);
				low[cur] = min(low[cur], low[i]);
				if((cur == 1 && child >= 2) || (cur != 1 && low[i] >= num[cur]))
					flag[cur] = 1;
			}
			else if(i != father)
				low[cur] = min(low[cur], num[i]);
		}
	}
}

int main() {
	int i;
	int a, b;
	while(~scanf("%d%d", &v, &l)) {
		if(!v || !l)
			break;
		dex = 0;
		memset(e, 0, sizeof(e));
		memset(flag, 0, sizeof(flag));
		memset(num, 0, sizeof(num));
		for(i = 1; i <= l; i++) {
			scanf("%d%d", &a, &b);
			e[a][b] = e[b][a] = 1;
		}
		dfs(1, 1);
		for(i = 1; i <= v; i++) {
			printf("i: %d num: %d low: %d\n", i, num[i], low[i]);
			if(flag[i])
				printf("%d ", i);
		}
		printf("\n");
	}
	return 0;
}
