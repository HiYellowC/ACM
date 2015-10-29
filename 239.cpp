#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
#define Max 501

vector<int> e[505];
bool vis[Max];
int match[Max];
int n, m;

bool dfs(int u) {
	int i;
	for(i = 0; i < e[u].size(); i++)
		if(!vis[e[u][i]]) {
			vis[e[u][i]] = true;
			if(!match[e[u][i]] || dfs(match[e[u][i]])) {
				match[e[u][i]] = u;
				return true;
			}
		}
	return false;
}

int main() {
	int i, total;
	int a, b;
	int sum;
	scanf("%d", &total);
	while(total--) {
		scanf("%d%d", &n, &m);
		sum = 0;
		memset(e, 0, sizeof(e));
		memset(match, 0, sizeof(match));
		for(i = 1; i <= m; i++) {
			scanf("%d%d", &a, &b);
			e[a].push_back(b);
		}
		for(i = 1; i <= n; i++) {
			memset(vis, 0, sizeof(vis));
			if(dfs(i))
				sum++;
		}
		printf("%d\n", sum);
	}
	return 0;
}
