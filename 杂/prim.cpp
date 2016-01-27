#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
#define INF 0x3f3f3f3f
#define Max 100

int v, l;
int map[Max][Max];
int lowcost[Max];
bool visit[Max];
int sum;

void prim() {
	int i, j, k;
	memset(lowcost, INF, sizeof(lowcost));
	visit[1] = true;
	for(i = 2; i <= v; i++) 
		lowcost[i] = map[1][i];
	for(i = 2; i <= v; i++) {
		int temp = INF;
		int key = 0;
		for(j = 2; j <= v; j++) {
			if(!visit[j] && lowcost[j] < temp) {
				temp = lowcost[j];
				k = j;
				key = 1;
			}
		}
		if(key == 0) {
			printf("error!\n");
			exit(0);
		}
		sum += temp;
		visit[k] = true;
		for(j = 2; j <= v; j++) {
			if(!visit[j] && map[k][j] < lowcost[j])
				lowcost[j] = map[k][j];
		}
	}
}

int main() {
	scanf("%d%d", &v, &l);
	int i;
	int a, b, cast;
	memset(map, INF, sizeof(map));
	for(i = 1; i <= l; i++) {
		scanf("%d%d%d", &a, &b, &cast);
		if(cast < map[a][b]) {
			map[a][b] = map[b][a] = cast;
		}
	}
	prim();
	printf("the result is %d\n", sum);
	return 0;
}
