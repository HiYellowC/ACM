#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

typedef long long LL;

const int MAXN = 500010;

int N, K, A, B;
int dex, Start[MAXN * 2], Next[MAXN * 2], End[MAXN * 2];
//LL dp[MAXN][11];
LL sum, ans;

void BuildG(int a, int b) {
	Next[++dex] = Start[a];
	Start[a] = dex;
	End[dex] = b;
	Next[++dex] = Start[b];
	Start[b] = dex;
	End[dex] = a;
}

void dfs(int v, int con) {
	sum++;
	if(con == 0) return ;
	for(int i = Start[v]; i; i = Next[i]) {
		int to = End[i];
		dfs(to, con - 1);
	}
}

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		ans = 0;
		scanf("%d%d%d%d", &N, &K, &A, &B);
		memset(Start, 0, sizeof(Start));
		dex = 0;
		for(int i = 2; i <= N; i++) BuildG(((LL)A * i + B) % (i - 1) + 1, i);	
		for(int i = 1; i <= N; i++) dfs(i, K), ans ^= sum, sum = 0;
		printf("%lld\n", ans);
	}
	return 0;
}
