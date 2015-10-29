#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define Max 10010
#define INF 0x80000000
using namespace std;

int dp[11][Max];
vector < pair<int, int> > V[11];

int main() {
	int N, M, K;
	while(~scanf("%d%d%d", &N, &M, &K)) {
		int a, b, c;
		for(int i = 1; i <= K; i++)
			V[i].clear();
		for(int i = 1; i <= N; i++) {
			scanf("%d%d%d", &a, &b, &c);
			V[a].push_back(make_pair(b, c));
		}
		bool flag = false;
		for(int i = 1; i <= K; i++) {
			if(V[i].size() == 0) {
				flag = true;
				break;
			}	
		}
		if(flag) {
			printf("Impossible\n");
			continue;
		}
		for(int i = 1; i <= K; i++)
			for(int j = 0; j <= M; j++)
				dp[i][j] = INF;
		for(int i = 0; i <= M; i++)
			dp[0][i] = 0;
		for(int i = 1; i <= K; i++)
			for(int j = 0; j < V[i].size(); j++)
				for(int k = M; k >= V[i][j].first; k--)
					dp[i][k] = max(dp[i][k], max(dp[i][k - V[i][j].first] + V[i][j].second, dp[i - 1][k - V[i][j].first] + V[i][j].second));
		if(dp[K][M] < 0)
			printf("Impossible\n");
		else
			printf("%d\n", dp[K][M]);
	}
	return 0;
}
