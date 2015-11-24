#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <map>
#include <sstream>
using namespace std;

const int MAXN = 210;

int n, m;
char str[20010];
map <string, int> M;
int dex, Start[MAXN], Next[MAXN], End[MAXN];
int val[MAXN];
int dp[MAXN][MAXN];
bool vis[MAXN];

void Init() {
	dex = 0;
	memset(dp, 0x3f, sizeof(dp));
	for(int i = 0; i <= n; i++) dp[i][0] = 0;
	memset(Start, 0, sizeof(Start));
	memset(vis, 0, sizeof(vis));
	M.clear();
}

void BuildG(int a, int b) {
	Next[++dex] = Start[a];
	Start[a] = dex;
	End[dex] = b;
}

int dfs(int v, int fa) {
	int son = 1;
	for(int i = Start[v]; i; i = Next[i]) {
		int to = End[i];
		int tmp = dfs(to, v);
		son += tmp;
		for(int j = n; j >= 0; j--)
			for(int k = 0; k <= j; k++)
				dp[v][j] = min(dp[v][j], dp[v][j - k] + dp[to][k]);
	}
	if(v != 0) dp[v][son] = val[v];
	return son;
}

int main() {
	stringstream Cin;
	string name;
	while(gets(str)) {
		if(str[0] == '#') break;
		sscanf(str, "%d%d", &n, &m);
		Init();
		int cur = 0;
		for(int i = 1; i <= n; i++) {
			gets(str);
			Cin.clear();
			Cin.str(str);
			Cin >> name;
			if(M[name] == 0) M[name] = ++cur;
			int u = M[name];
			Cin >> val[u];
			while(Cin >> name) {
				if(M[name] == 0) M[name] = ++cur;
				BuildG(u, M[name]);
				vis[M[name]] = true;
			}
		}
		for(int i = 1; i <= n; i++)
			if(!vis[i]) BuildG(0, i);
		int son = dfs(0, -1);
		int ans = 0x3f3f3f3f;
		for(int i = m; i <= n; i++) ans = min(ans, dp[0][i]);
		printf("%d\n", ans);
	}
	return 0;
}
