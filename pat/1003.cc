#include <bits/stdc++.h>
using namespace std;

const int MAXN = 510;

int n, m, C1, C2;
int dex, Start[MAXN], Next[MAXN * 2], End[MAXN * 2], Cost[MAXN * 2];
int val[MAXN];
int dis[MAXN], con[MAXN], sum[MAXN];
bool vis[MAXN];

void BuildG(int a, int b, int c) {
	Next[++dex] = Start[a];
	Start[a] = dex;
	End[dex] = b;
	Cost[dex] = c;
}

void dij() {
	memset(dis, 0x3f, sizeof(dis));
	dis[C1] = 0, vis[C1] = true, con[C1] = 1, sum[C1] = val[C1];
	int s = C1;
	for(int i = 1; i <= n; i++) {
		int MAX = 0x3f3f3f3f;
		for(int k = 0; k < n; k++) {
			if(!vis[k] && dis[k] < MAX) s = k, MAX = dis[k];
		}
		vis[s] = true;
		for(int k = Start[s]; k; k = Next[k]) {
			int to = End[k];
			int cost = Cost[k];
			if(dis[to] == dis[s] + cost) con[to] += con[s], sum[to] = max(sum[to], sum[s] + val[to]);
			else if(dis[to] > dis[s] + cost) dis[to] = dis[s] + cost, con[to] = con[s], sum[to] = sum[s] + val[to];
		}
	}
}

int main() {
	scanf("%d%d%d%d", &n, &m, &C1, &C2);
	for(int i = 0; i < n; i++) scanf("%d", &val[i]);
	int a, b, c;
	for(int i = 1; i <= m; i++) {
		scanf("%d%d%d", &a, &b, &c);
		BuildG(a, b, c);
		BuildG(b, a, c);
	}
	dij();
	printf("%d %d\n", con[C2], sum[C2]);
	return 0;
}
