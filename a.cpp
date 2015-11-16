#include <bits/stdc++.h>
using namespace std;

int n;
bool flag;
int res[30][30];
int Map[30][30];
int con[30];

void dfs(int v, int t) {
	if(t == n + 1) {
		flag = true;
		return ;
	}
	for(int i = 0; i < 26; i++) {
		if(Map[v][i]) {
			bool vis = false;
			if(res[v][i] == Map[v][i]) {
				vis = true;
				res[v][i]--;
				Map[i][v]--;
			}
			Map[v][i]--;
			dfs(i, t + 1);
			Map[v][i]++;
			if(vis) res[v][i]++, Map[i][v]++;
		}	
		if(flag) return ;
	}
}

int main() {
	int t, tt = 1;
	scanf("%d", &t);
	char str[25];
	int key;
	while(t--) {
		scanf("%d", &n);
		memset(Map, 0, sizeof(Map));
		memset(con, 0, sizeof(con));
		memset(res, 0, sizeof(res));
		for(int i = 1; i <= n; i++) {
			scanf("%s%d", str, &key);
			int len = strlen(str) - 1;
			Map[str[0] - 'a'][str[len] - 'a']++;
			if(key) {
				Map[str[len] - 'a'][str[0] - 'a']++;
				if(str[0] != str[len]) res[str[len] - 'a'][str[0] - 'a']++, res[str[0] - 'a'][str[len] - 'a']++;
			}
			con[str[len] - 'a']++, con[str[0] - 'a']++;
		}
		int num = 0;
		for(int i = 0; i < 26; i++)
			if(con[i] % 2) num++;
		flag = false;
		if(num == 2 || num == 0) {
			if(num == 2) {
				for(int i = 0; i < 26; i++) {
					if(con[i] % 2) dfs(i, 1);
					if(flag) break;
				}
			}
			else {
				for(int i = 0; i < 26; i++)
					if(con[i]) {
						dfs(i, 1);
						break;
					}
			}
		}
		if(flag) printf("Case %d: Well done!\n", tt++);
		else printf("Case %d: Poor boy!\n", tt++);
	}
	return 0;
}
