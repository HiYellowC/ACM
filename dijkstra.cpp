#include <iostream>
#include <cstdio>
#include <cstring>
#define N 110
#define Max 0x3f3f3f3f
using namespace std;

int v, l;
int map[N][N];
int dis[N];
bool visit[N];

void dijkstra() {
	visit[1] = true;
	dis[1] = 0;
	int i, j, k;
	int temp;
	int key;
	for(i = 2; i <= v; i++) {
		visit[i] = false;
		dis[i] = map[1][i];
	}
	for(i = 2; i <= v; i++) {
		temp = Max;
		key = 0;
		for(j = 2; j <= v; j++) {
			if(!visit[j] && dis[j] < temp) {
				temp = dis[j];
				k = j;
				key = 1;
			}
		}
		if(key == 0) {
			printf("error!\n");
			return ;
		}
		visit[k] = true;
		for(j = 2; j <= v; j++) {
			if(!visit[j] && dis[j] > dis[k] + map[k][j])
				dis[j] = dis[k] + map[k][j];
		}
	}
	for(i = 1; i <= v; i++)
		printf("%d : %d\n", i, dis[i]);
	printf("\n");
}

int main() {
	scanf("%d%d", &v, &l);
	int i;
	int a, b, cost;
	memset(map, Max, sizeof(map));
	for(i = 1; i <= l; i++) {
		scanf("%d%d%d", &a, &b, &cost);
		map[a][b] = cost;
	}
	dijkstra();
	return 0;
}
