#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int ans;
int n, m;
int in[10];
int ji[10], ou[10];
bool Map[10][10];
bool vis[10][10];

void dfs(int cur) {
	if(cur == n) {
		bool flag = true;
		for(int i = 1; i <= n; i++)
			if(ji[i] != ou[i]) {
				flag = false;
				break;
			}
		if(flag)
			ans++;
		return ;
	}
	int con = 0;
	int S[10];
	for(int i = 1; i <= n; i++)
		if(Map[cur][i] && !vis[cur][i])
			S[++con] = i;
	for(int i = 0; i < (1 << con); i++) {
		for(int k = 1; k <= con; k++) {
			if((1 << (k - 1)) & i)
				ji[cur]++, ji[S[k]]++;
			else 
				ou[cur]++, ou[S[k]]++;
			vis[cur][S[k]] = vis[S[k]][cur] = 1;
		}
		if(ji[cur] == ou[cur])
			dfs(cur + 1);
		for(int k = 1; k <= con; k++) {
			if((1 << (k - 1)) & i)
				ji[cur]--, ji[S[k]]--;
			else 
				ou[cur]--, ou[S[k]]--;
			vis[cur][S[k]] = vis[S[k]][cur] = 0;
		}
	}
}

int main() {
	int t;
	scanf("%d", &t);
	int a, b;
	while(t--) {
		scanf("%d%d", &n, &m);	
		ans = 0;
		memset(in, 0, sizeof(in));
		memset(Map, 0, sizeof(Map));
		memset(vis, 0, sizeof(vis));
		memset(ji, 0, sizeof(ji));
		memset(ou, 0, sizeof(ou));
		for(int i = 1; i <= m; i++) {
			scanf("%d%d", &a, &b);
			Map[a][b] = Map[b][a] = 1;
			in[a]++, in[b]++;
		}
		bool flag = true;
		for(int i = 1; i <= n; i++)
			if(in[i] % 2) {
				flag = false;
				break;
			}
		if(flag)
			dfs(1);
		printf("%d\n", ans);
	}
	return 0;
}
