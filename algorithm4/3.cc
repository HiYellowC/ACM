#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1010;
const int INF = 0x3f3f3f3f;

int n;
int a[MAXN];
int dp[MAXN][MAXN]; 

int fun1(int l, int r) {
	memset(dp, 0, sizeof(dp));
	int con = r - l + 1;
	for(int i = 2; i <= con; i++)
		for(int j = l; j <= r - i + 1; j++) {
			int s = j;
			int e = j + i - 1;
			int sum;
			if(s == 0) sum = a[e];
			else sum = a[e] - a[s - 1]; 
			for(int k = s; k < e; k++)
				dp[s][e] = max(dp[s][k] + dp[k + 1][e] + sum, dp[s][e]);
		}
	return dp[l][r];
}

int fun2(int l, int r) {
	memset(dp, INF, sizeof(dp));
	for(int i = l; i <= r; i++) dp[i][i] = 0;
	int con = r - l + 1;
	for(int i = 2; i <= con; i++)
		for(int j = l; j <= r - i + 1; j++) {
			int s = j;
			int e = j + i - 1;
			int sum;
			if(s == 0) sum = a[e];
			else sum = a[e] - a[s - 1]; 
			for(int k = s; k < e; k++)
				dp[s][e] = min(dp[s][k] + dp[k + 1][e] + sum, dp[s][e]);
		}
	return dp[l][r];
}

int main() {
	int sum = 0;
	int ans1 = -INF;
	int ans2 = INF;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", &a[i]), sum += a[i];
	for(int i = n; i < 2 * n; i++) a[i] = a[i - n];
	for(int i = 1; i < 2 * n; i++) a[i] += a[i - 1];
	for(int i = 1; i < n; i++)
		for(int j = i; j < n; j++) {
			ans1 = max(ans1, fun1(i, j) + fun1(j + 1, i - 1 + n) + sum);
			ans2 = min(ans2, fun2(i, j) + fun2(j + 1, i - 1 + n) + sum);
		}
	if(n == 1) ans1 = ans2 = 0;
	printf("%d\n%d\n", ans2, ans1);
	return 0;
}
