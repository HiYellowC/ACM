#include <stdio.h>
#include <string.h>
#define Max 301
#define INF 0x3f3f3f3f

int map[Max][Max];

int max(const int a, const int b) {
	return a > b ? a : b;
}

int main() {
	int v, l, num_of_search;
	int i, j, k, a, b, val;
	scanf("%d%d%d", &v, &l, &num_of_search);
	memset(map, INF, sizeof(map));
	for(i = 1; i <= l; i++) {
		scanf("%d%d%d", &a, &b, &val);
		map[a][b] = val;
	}
	for(i = 1; i <= v; i++)
		for(j = 1; j <= v; j++)
			for(k = 1; k <= v; k++)
				if(map[j][k] > max(map[j][i], map[i][k]))
					map[j][k] = max(map[j][i], map[i][k]);
	for(i = 1; i <= num_of_search; i++) {
		scanf("%d%d", &a, &b);
		if(map[a][b] == INF)
			printf("-1\n");
		else
			printf("%d\n", map[a][b]);
	}
	return 0;
}
