#include <stdio.h>
#include <string.h>

int s[100001], to[200001], next[200001];
bool vis[100001];
int res[100001];
int n, cur;

void dfs(int v) {
	vis[v] = true;
	int i;
	for(i = s[v]; i != -1; i = next[i]) {
		if(!vis[to[i]]) {
			res[to[i]] = v;
			dfs(to[i]);
		}
	}
}

int main() {
	int total;
	scanf("%d", &total);
	int N, S;
	int i, a, b;
	while(total--) {
		memset(s, -1, sizeof(s));
		memset(vis, 0, sizeof(vis));
		scanf("%d%d", &N, &S);
		n = N;
		cur = 1;
		while(--N) {
			scanf("%d%d", &a, &b);
			next[cur] = s[a];
			s[a] = cur;
			to[cur++] = b;
			next[cur] = s[b];
			s[b] = cur;
			to[cur++] = a;
		}
		res[S] = -1;
		dfs(S);
		for(i = 1; i <= n; i++)
			printf("%d ", res[i]);
		printf("\n");
	}
	return 0;
}
