#include <stdio.h>

long long dp[20][3]; // 0 - include 49  1 - no 49 2 - start with 9
int num[20];

int main() {
	int i;
	dp[0][1] = 1;
	for(i = 1; i < 20; i++) {
		dp[i][0] = dp[i - 1][0] * 10 + dp[i - 1][2];
		dp[i][1] = dp[i - 1][1] * 10 - dp[i - 1][2];
		dp[i][2] = dp[i - 1][1];
	}
	int total;
	long long n, ans;
	int len, last;
	bool flag;
	scanf("%d", &total);
	while(total--) {
		scanf("%lld", &n);
		n++;
		ans = 0;
		len = 0;
		while(n) {
			num[++len] = n % 10;
			n /= 10;
		}
		flag = 0;
		last = 0;
		for(i = len; i > 0; i--) {
			ans += num[i] * dp[i - 1][0];
			if(flag)
				ans += num[i] * dp[i - 1][1];
			if(!flag && num[i] > 4)
				ans += dp[i - 1][2];
			if(last == 4 && num[i] == 9)
				flag = 1;
			last = num[i];
		}
		printf("%lld\n", ans);
	}
	return 0;
}
