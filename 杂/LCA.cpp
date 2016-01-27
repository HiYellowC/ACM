#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#define Max 10010
using namespace std;

int n;
int deep[Max];
int e[Max], R[Max];
int f1[Max][100], f2[Max][Max];
int dex;
vector <int> V[Max];
bool vis[Max];

void dfs(int v, int d) {
	vis[v] = true;
	e[++dex] = v;
	deep[v] = d;
	for(int i = 0; i < V[v].size(); i++)
		if(!vis[V[v][i]]) {
			dfs(V[v][i], d + 1);
			e[++dex] = v;
		}
}

void RMQ() {
	for(int i = 1; i <= dex; i++)
		f1[i][0] = deep[e[i]], f2[i][0] = e[i];
	for(int i = 1; i <= (int)(log(dex) / log(2)); i++)
		for(int k = 1; k <= dex + 1 - (int)(pow(2, i)); k++) {
			if(f1[k][i - 1] > f1[k + (int)pow(2, i - 1)][i - 1]) {
				f1[k][i] = f1[k + (int)pow(2, i - 1)][i - 1];
				f2[k][i] = f2[k + (int)pow(2, i - 1)][i - 1];
			}
			else {
				f1[k][i] = f1[k][i - 1];
				f2[k][i] = f2[k][i - 1];
			}
		}
}

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n - 1; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		V[a].push_back(b);
		V[b].push_back(a);
	}
	dfs(1, 1);
	for(int i = 1; i <= dex; i++)
		if(!R[e[i]])
			R[e[i]] = i;
	RMQ();
	while(1) {
		int a, b;
		scanf("%d%d", &a, &b);
		a = R[a];
		b = R[b];
		if(a > b)
			swap(a, b);
		int s = (int)(log(b - a + 1) / log(2));
		if(f1[a][s] > f1[b - (int)pow(2, s) + 1][s])
			printf("%d\n", f2[b - (int)pow(2, s) + 1][s]);
		else
			printf("%d\n", f2[a][s]);
	}
	return 0;
}
