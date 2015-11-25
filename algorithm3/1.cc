#include <bits/stdc++.h>
using namespace std;

const int MAXN = 110;

int a[MAXN];
int dp[MAXN][MAXN];
vector <int> V[MAXN][MAXN];

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n;
		scanf("%d", &n);
		for(int i = 1; i <= n + 1; i++) scanf("%d", &a[i]);
		memset(dp, 0x3f, sizeof(dp));
		for(int i = 1; i <= n; i++) dp[i][i] = 0;
		for(int i = 2; i <= n; i++) 
			for(int j = 1; j <= n - i + 1; j++) {
				int id;
				for(int k = j; k < j + i - 1; k++) {
					int sum = dp[j][k] + dp[k + 1][j + i - 1] + a[j] * a[k + 1] * a[j + i];
					if(sum < dp[j][j + i - 1]) dp[j][j + i - 1] = sum, id = k;
				}
				for(int k = 0; k < V[j][id].size(); k++) V[j][j + i - 1].push_back(V[j][id][k]);
				for(int k = 0; k < V[id + 1][j + i - 1].size(); k++) V[j][j + i - 1].push_back(V[id + 1][j + i - 1][k]);
				V[j][j + i - 1].push_back(id);
			}
		printf("the answer is %d\n", dp[1][n]);
		for(int i = 0; i < V[1][n].size(); i++) printf("step: %d select: %d\n", i + 1, V[1][n][i]);
	}
	return 0;
}
