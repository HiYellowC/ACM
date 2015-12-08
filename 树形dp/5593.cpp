#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int MAXN = 500010;

int N, K, A, B;
int dex, Start[MAXN], Next[MAXN], End[MAXN];
int fa[MAXN], dp[MAXN][11];

void Init() {
	dex = 0;
	memset(Start, 0, sizeof(Start));
	memset(dp, 0, sizeof(dp));
}

void BuildG(int a, int b) {
	Next[++dex] = Start[a];
	Start[a] = dex;
	End[dex] = b;
}

void dfs(int v) {
	for(int i = 0; i <= K; i++) dp[v][i] = 1;
	for(int i = Start[v]; i; i = Next[i]) {
		int to = End[i];	
		dfs(to);
		for(int j = 1; j <= K; j++) dp[v][j] += dp[to][j - 1];
	}
}

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		Init();
		scanf("%d%d%d%d", &N, &K, &A, &B);
		fa[1] = 0;
		for(int i = 2; i <= N; i++) {
			fa[i] = ((LL)A * i + B) % (i - 1) + 1;
			BuildG(fa[i], i);
		}
		dfs(1);			
		int ans = 0;
		for(int i = 1; i <= N; i++) {
			int sum = 0;	
			int old, now = i;
			for(int j = K; j >= 0; j--) {
				if(j == K) sum += dp[now][j];
				else if(j >= 1)sum += dp[now][j] - dp[old][j - 1];
				else sum += dp[now][j];
				old = now;
				now = fa[now];
				if(now == 0) break;
			}
			ans ^= sum;
		}
		printf("%d\n", ans);
	}
	return 0;
}
