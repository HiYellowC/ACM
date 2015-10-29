#include <bits/stdc++.h>
#define INF 0x80
using namespace std;

int dp[110][55][2];
char str[110];

int main() {
	scanf("%s", str + 1);
	int len = strlen(str + 1);
	int t;
	scanf("%d", &t);
	memset(dp, INF, sizeof(dp));
	for(int i = 0; i <= t; i++) {
		if(str[1] == 'F') {
			if(i % 2 == 0) dp[1][i][0] = 1;
			else dp[1][i][1] = 0;
		}
		else {
			if(i % 2 == 1) dp[1][i][0] = 1;
			else dp[1][i][1] = 0;
		}
	}
	for(int i = 2; i <= len; i++)
		for(int k = 0; k <= t; k++) {
			for(int j = 0; j <= k; j++) {
				if(str[i] == 'F') {
					if(j % 2 == 0) dp[i][k][0] = max(dp[i][k][0], dp[i - 1][k - j][0] + 1), dp[i][k][1] = max(dp[i][k][1], dp[i - 1][k - j][1] - 1);
					else dp[i][k][0] = max(dp[i][k][0], dp[i - 1][k - j][1]), dp[i][k][1] = max(dp[i][k][1], dp[i - 1][k - j][0]);
				}	
				else {
					if(j % 2 == 1) dp[i][k][0] = max(dp[i][k][0], dp[i - 1][k - j][0] + 1), dp[i][k][1] = max(dp[i][k][1], dp[i - 1][k - j][1] - 1);
					else dp[i][k][0] = max(dp[i][k][0], dp[i - 1][k - j][1]), dp[i][k][1] = max(dp[i][k][1], dp[i - 1][k - j][0]);
				}
			}
		}
	int ans1 = max(dp[len][t][0], dp[len][t][1]);
	memset(dp, INF, sizeof(dp));
	for(int i = 0; i <= t; i++) {
		if(str[1] == 'F') {
			if(i % 2 == 0) dp[1][i][0] = -1;
			else dp[1][i][1] = 0;
		}
		else {
			if(i % 2 == 1) dp[1][i][0] = -1;
			else dp[1][i][1] = 0;
		}
	}
	for(int i = 2; i <= len; i++)
		for(int k = 0; k <= t; k++) {
			for(int j = 0; j <= k; j++) {
				if(str[i] == 'F') {
					if(j % 2 == 0) dp[i][k][0] = max(dp[i][k][0], dp[i - 1][k - j][0] - 1), dp[i][k][1] = max(dp[i][k][1], dp[i - 1][k - j][1] + 1);
					else dp[i][k][0] = max(dp[i][k][0], dp[i - 1][k - j][1]), dp[i][k][1] = max(dp[i][k][1], dp[i - 1][k - j][0]);
				}	
				else {
					if(j % 2 == 1) dp[i][k][0] = max(dp[i][k][0], dp[i - 1][k - j][0] - 1), dp[i][k][1] = max(dp[i][k][1], dp[i - 1][k - j][1] + 1);
					else dp[i][k][0] = max(dp[i][k][0], dp[i - 1][k - j][1]), dp[i][k][1] = max(dp[i][k][1], dp[i - 1][k - j][0]);
				}
			}
		}
	int ans2 = max(dp[len][t][0], dp[len][t][1]);
	printf("%d\n", max(ans1, ans2));
	return 0;
}
