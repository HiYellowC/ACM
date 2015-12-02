#include <bits/stdc++.h>
using namespace std;

const int MAXN = 110;

int cost[MAXN][MAXN];

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		for(int j = i + 1; j <= n; j++)
			scanf("%d", &cost[i][j]);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			for(int k = 1; k <= n; k++)
				cost[j][k] = min(cost[j][k], cost[j][i] + cost[i][k]);
	printf("%d\n", cost[1][n]);
	return 0;
}
