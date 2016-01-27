#include <iostream>
#include <cstdio>
#include <cstring>
#define Max 40010
using namespace std;

#pragma comment(linker, "/STACK:102400000,102400000")

int n, m;
int dex, Start[Max], Next[Max * 2], End[Max * 2], weight[Max];
int S[Max], N[500], E[500];
int dis[Max], par[Max];
int ans[210];

void Init() {
	dex = 0;
	memset(Start, 0, sizeof(Start));
	memset(S, 0, sizeof(S));
	memset(dis, -1, sizeof(dis));
	for(int i = 1; i <= n; i++)
		par[i] = i;
}

void BuildG(int a, int b) {
	Next[++dex] = Start[a];
	Start[a] = dex;
	End[dex] = b;
}

void BuildQ(int a, int b) {
	N[++dex] = S[a];
	S[a] = dex;
	E[dex] = b;
}

int Join(int v) {
	if(v != par[v])
		par[v] = Join(par[v]);
	return par[v];
}

void Union(int p, int v) {
	int f1 = Join(p);
	int f2 = Join(v);
	par[f2] = f1;
}

void Tarjan(int v, int w, int p) {
	dis[v] = w;
	for(int i = Start[v]; i; i = Next[i]) {
		int to = End[i];
		if(to == p)
			continue;
		Tarjan(to, w + weight[(i + 1) / 2], v);	
		Union(v, to);
	}
	for(int i = S[v]; i; i = N[i]) {
		int to = E[i];
		if(dis[to] >= 0) {
			ans[(i + 1) / 2] = dis[v] + dis[to] - 2 * dis[Join(to)];	
//			printf("xu: %d v: %d to: %d\n", (i + 1) / 2, v, to);
		}
	}	
}

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d", &n, &m);
		Init();
		int a, b, c;
		for(int i = 1; i < n; i++) {
			scanf("%d%d%d", &a, &b, &c);
			BuildG(a, b);
			BuildG(b, a);
			weight[i] = c;
		}
		dex = 0;
		for(int i = 1; i <= m; i++) {
			scanf("%d%d", &a, &b);
			BuildQ(a, b);
			BuildQ(b, a);
		}
		Tarjan(1, 0, 1);
		for(int i = 1; i <= m; i++)
			printf("%d\n", ans[i]);
	}
	return 0;
}
