#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>
#define Max 5001
#define INF 0x3f3f3f3f
using namespace std;

struct edge {
	int End, len, cost, next;
};
edge e[80001];
int First[Max];
int num_of_e;
int start, end;
int max_of_energy;
int dis[Max], energy[Max];
bool vis[Max];

void build_G(int a, int b, int val1, int val2) {
	num_of_e++;
	e[num_of_e].End = b;
	e[num_of_e].cost = val1;
	e[num_of_e].len = val2;
	e[num_of_e].next = First[a];
	First[a] = num_of_e;
}

void spfa() {
	int cur;
	int k;
	queue<int>Q;
	vis[start] = true;
	Q.push(start);
	dis[start] = 0;
	energy[start] = 0;
	while(!Q.empty()) {
		cur = First[Q.front()];
		while(cur) {
			k = e[cur].End;
			if(dis[k] > dis[Q.front()] + e[cur].len && energy[Q.front()] + e[cur].cost <= max_of_energy) {
				dis[k] = dis[Q.front()] + e[cur].len;
				energy[k] = energy[Q.front()] + e[cur].cost;
				energy[k] = energy[Q.front()] + e[cur].cost;
				if(!vis[k]) {
					Q.push(k);
					vis[k] = true;
				}
			}
			cur = e[cur].next;
		}
		vis[Q.front()] = false;
		Q.pop();
	}
}

int main() {
	int n, m;
	int a, b, val1, val2;
	int i;
	scanf("%d%d", &n, &m);
	for(i = 1; i <= m; i++) {
		scanf("%d%d%d%d", &a, &b, &val1, &val2);
		build_G(a, b, val1, val2);
		build_G(b, a, val1, val2);
	}
	scanf("%d%d", &start, &end);
	scanf("%d", &max_of_energy);
	memset(dis, INF, sizeof(dis));
	spfa();
	if(dis[end] == INF)
		printf("-1\n");
	else
		printf("%d\n", dis[end]);
	return 0;
}
