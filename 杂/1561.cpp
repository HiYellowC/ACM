#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int dp[210][210], val[210];
vector <int> V[210];

void dfs(int v, int t) {
	dp[v][1] = val[v];
	int i, j, k;
	for(i = 0; i < V[v].size(); i++) {
		if(t > 1)
			dfs(V[v][i], t - 1);
		for(j = t; j >= 2; j--)
			for(k = 1; k < j; k++) {
				if(dp[v][j] < dp[v][j - k] + dp[V[v][i]][k])
					dp[v][j] = dp[v][j - k] + dp[V[v][i]][k];
			}
	}
}

int main() {
	int i, N, M, parent;
	while(scanf("%d%d", &N, &M)) {
		if(!N && !M)
			break;
		for(i = 0; i <= N; i++)
			V[i].clear();
		memset(dp, 0, sizeof(dp));
		for(i = 1; i <= N; i++) {
			scanf("%d%d", &parent, &val[i]);
			V[parent].push_back(i);
		}
		dfs(0, M + 1);
		printf("%d\n", dp[0][M + 1]);
	}
	return 0;
}
