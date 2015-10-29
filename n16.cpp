#include <stdio.h>
#include <string.h>

int n, x[1001], y[1001];
int dis[1001];
bool e[1001][1001];

int dp(int v) {
	if(dis[v] > 0)
		return dis[v];
	dis[v] = 1;
	int i;
	for(i = 1; i <= n; i++)
		if(e[v][i]) {
			int num = dp(i);
			dis[v] = num + 1 > dis[v] ? num + 1 : dis[v];
		}
	return dis[v];
}

int main() {
	int i, k, total, ans;
	scanf("%d", &total);
	while(total--) {
		scanf("%d", &n);
		ans = 0;
		memset(e, 0, sizeof(e));
		memset(dis, 0, sizeof(dis));
		for(i = 1; i <= n; i++)
			scanf("%d%d", &x[i], &y[i]);
		for(i = 1; i <= n; i++)
			for(k = 1; k <= n; k++)
				if((x[k] < x[i] && y[k] < y[i]) || (x[k] < y[i] && y[k] < x[i]))
					e[i][k] = 1;
		for(i = 1; i <= n; i++) {
			int num = dp(i);
			ans = num > ans ? num : ans;
		}
		printf("%d\n", ans);
	}
	return 0;
}
