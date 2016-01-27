#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#define Max 10010
using namespace std;

vector <int> V[Max];

struct Pond {
	int val, num;
};
long long sum;

Pond pond[Max];

bool vis[Max];
int cnt;

void dfs(int v) {
	vis[v] = true;
	sum += (long long)pond[v].val;
	cnt++;
	for(int i = 0; i < V[v].size(); i++) {
		if(!vis[V[v][i]]) {
			dfs(V[v][i]);
		}	
	}
}

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n, m;
		scanf("%d%d", &n, &m);
		memset(vis, 0, sizeof(vis));
		for(int i = 1; i <= n; i++) {
			scanf("%d", &pond[i].val);
			pond[i].num = 0;
		}
		int a, b;
		for(int i = 1; i <= m; i++) {
			scanf("%d%d", &a, &b);
			pond[a].num++, pond[b].num++;	
			V[a].push_back(b);
			V[b].push_back(a);
		}	
		bool flag = true;
		while(flag) {
			flag = false;
			for(int i = 1; i <= n; i++) {
				if(!vis[i] && pond[i].num < 2) {
					vis[i] = true;
					flag = true;
					for(int k = 0; k < V[i].size(); k++)
						pond[V[i][k]].num--;
				}	
			}
		}
		long long ans = 0;
		for(int i = 1; i <= n; i++) {
			if(!vis[i]) {
				sum = 0;
				cnt = 0;
				dfs(i);	
				if(cnt & 1)
					ans += sum;
			}
		}
		printf("%lld\n", ans);
		for(int i = 1; i <= n; i++)
			V[i].clear();
	}
	return 0;
}
