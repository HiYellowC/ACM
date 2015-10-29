#include <stdio.h>

int dp[10][3]; // 0 - no 4 and 62 1 - no 4 and 62 but start with 2

int GetAns(int n) {
	if(n == 0)
		return 1;
	int num[10];
	int len = 0;
	int ans = 0;
	int i;
	int last1 , last2;
	last1 = last2 = 0;
	while(n) {
		num[++len] = n % 10;
		n /= 10;
	}
	for(i = len; i > 0; i--) {
		if(last2 == 4 || (last1 == 6 && last2 == 2))
			break;
		ans += num[i] * dp[i - 1][0];
		if(num[i] > 4)
			ans -= dp[i - 1][0];
		if(num[i] > 6)
			ans -= dp[i - 1][1];
		if(last2 == 6 && num[i] > 2)
			ans -= dp[i - 1][0];
		last1 = last2;
		last2 = num[i];
	}
	return ans;
}

int main() {
	int i;
	dp[0][0] = 1;
	for(i = 1; i < 10; i++) {
		dp[i][0] = 9 * dp[i - 1][0] - dp[i - 1][1];
		dp[i][1] = dp[i - 1][0];
	}
	int n, m;
	while(scanf("%d%d", &n, &m)) {
		if(!n && !m)
			break;
		printf("%d\n", GetAns(m + 1) - GetAns(n));
	}
	return 0;
}
