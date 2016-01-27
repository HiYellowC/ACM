#include <iostream>
#include <cstdio>
using namespace std;
#define Max 0x3f3f3f3f

typedef struct Edge {
	int a, b;
	int cost;
}Edge;

int v, l;
Edge edge[100];
int dis[100];

bool bellman_ford() {
int i, j;
	dis[1] = 0;
	for(i = 2; i <= v; i++)
		dis[i] = Max;
	for(i = 1; i <= v - 1; i++) {
		for(j = 1; j <= l; j++) {
			if(dis[edge[j].b] > dis[edge[j].a] + edge[j].cost) {
				dis[edge[j].b] = dis[edge[j].a] + edge[j].cost;
			}
		}
	}
	for(i = 1; i <= l; i++) {
		if(dis[edge[i].b] > dis[edge[i].a] + edge[i].cost)
			return false;
	}
	return true;
}

int main() {
	scanf("%d%d", &v, &l);
	int i;
	for(i = 1; i <= l; i++)
		scanf("%d%d%d", &edge[i].a, &edge[i].b, &edge[i].cost);
	if(bellman_ford()) {
		for(i = 1; i <= v; i++)
			printf("the NO.%d is %d\n", i, dis[i]);
	}
	else
		printf("error!\n");
	return 0;
}
