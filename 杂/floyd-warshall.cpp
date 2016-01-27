#include <stdio.h>
#define INF 0x3f3f3f3f
#define Max 100

int map[Max][Max];

int main() {
	int v, l;
	int i, k, j;
	int a, b, val;
	scanf("%d%d", &v, &l);
	for(i = 1; i <= v; i++)
		for(k = 1; k <= v; k++)
			if(k == i)
				map[i][k] = 0;
			else
				map[i][k] = INF;
	for(i = 1; i <= l; i++) {
		scanf("%d%d%d", &a, &b, &val);
		map[a][b] = val;
	}
	for(i = 1; i <= v; i++)
		for(k = 1; k <= v; k++)
			for(j = 1; j <= v; j++)
				if(map[k][j] > map[k][i] + map[i][j])
					map[k][j] = map[k][i] + map[i][j];
	for(i = 1; i <= v; i++)
		for(k = 1; k <= v; k++)
			printf("%d->%d: %d\n", i, k, map[i][k]);
	return 0;
}
