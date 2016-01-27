#include <stdio.h>
#include <string.h>
#define Max 1000

int end[Max], next[Max];
int first[100];
int dex;
int n, m, k;
bool vis[100];
int match[100];

void build_G(int a, int b) {
	dex++;
	end[dex] = b;
	next[dex] = first[a];
	first[a] = dex;
}

bool dfs(int u) {
	int i;
	for(i = first[u]; i; i = next[i]) {
		if(!vis[end[i]]) {
			vis[end[i]] = 1;
			if(!match[end[i]] || dfs(match[end[i]])) {
				match[end[i]] = u;
				return true;
			}
		}
	}
	return false;
}

int main() {
	int i, j;
	int a, b;
	int res;
	while(scanf("%d", &n)) {
		if(!n)
			break;
		dex = res = 0;
		memset(first, 0, sizeof(first));
		memset(match, 0, sizeof(match));
		scanf("%d%d", &m, &k);
		for(i = 1; i <= k; i++) {
			scanf("%d%d%d", &j, &a, &b);
			if(a && b)
				build_G(a, b);
		}
		for(i = 1; i < n; i++) {
			memset(vis, 0, sizeof(vis));
			if(dfs(i)) 
				res++;
		}
		printf("%d\n", res);
	}
	return 0;
}
