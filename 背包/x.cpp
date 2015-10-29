#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define Max 110
using namespace std;

int v[Max], w[Max];
int dp[1010][35];
int a[35], b[35];

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int N, V, K;
		memset(dp, 0, sizeof(dp));
		memset(a, -1, sizeof(a));
		memset(b, -1, sizeof(b));
		scanf("%d%d%d", &N, &V, &K);
		for(int i = 1; i <= N; i++)
			scanf("%d", &v[i]);
		for(int i = 1; i <= N; i++)
			scanf("%d", &w[i]);
		for(int i = 1; i <= N; i++)
			for(int k = V; k >= w[i]; k--) {
				for(int j = 1; j <= K; j++) {
					a[j] = dp[k - w[i]][j] + v[i];
					b[j] = dp[k][j];
				}	
				int dex1, dex2, dex3;
				dex1 = dex2 = dex3 = 1;
				while(dex3 <= K && (dex1 <= K || dex2 <= K)) {
					if(a[dex1] > b[dex2])
						dp[k][dex3] = a[dex1], dex1++;
					else 
						dp[k][dex3] = b[dex2], dex2++;
					if(dp[k][dex3] != dp[k][dex3 - 1])
						dex3++;
				}
			}
		printf("%d\n", dp[V][K]);
	}
	return 0;
}
