#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1010;

double dp[MAXN][MAXN];

int main() {
	int w, b;
	scanf("%d%d", &w, &b);
	for(int i = 1; i <= w; i++) dp[i][0] = 1;
	for(int i = 0; i <= b; i++) dp[0][i] = 0;
	for(int i = 1; i <= w; i++)
		for(int k = 1; k <= b; k++) {
			dp[i][k] = (double)i / (double)(i + k);	
			double con = (double)k / (double)(i + k) * (double)(k - 1) / (double)(i + k - 1);
			if(k >= 2) dp[i][k] += con * (double)i / (double)(i + k - 2) * dp[i - 1][k - 2];
			if(k >= 3) dp[i][k] += con * (double)(k - 2) / (double)(i + k - 2) * dp[i][k - 3];
		}
	printf("%.9lf\n", dp[w][b]);
	return 0;
}
