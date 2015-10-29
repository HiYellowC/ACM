#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int val[6010];
int dp[6010][2];
bool vis[6010];
vector <int> V[6010];

inline int Max(int a, int b) {
	return a > b ? a : b;
}

void dfs(int v) {
	vis[v] = 1;
	int i;
	for(i = 0; i < V[v].size(); i++) {
		if(!vis[V[v][i]]) {
			dfs(V[v][i]);
			dp[v][1] += Max(dp[V[v][i]][0], 0);
			dp[v][0] += Max(dp[V[v][i]][1], Max(dp[V[v][i]][0], 0));
		}
	}
	dp[v][1] += val[v];
}

int main() {
	int i, N;
	scanf("%d", &N);
	for(i = 1; i <= N; i++)
		scanf("%d", &val[i]);
	int a, b;
	for(i = 1; i < N; i++) {
		scanf("%d%d", &a, &b);
		V[a].push_back(b);
		V[b].push_back(a);
	}
	scanf("%d%d", &a, &b);
	dfs(1);
	printf("%d\n", Max(dp[1][0], dp[1][1]));
	return 0;
}
