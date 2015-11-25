#include <bits/stdc++.h>
using namespace std;

const int MAXN = 110;

int n;
int a[MAXN], dp[MAXN];

void fun1() { // n^2
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		dp[i] = 1;
		for(int j = i - 1; j >= 1; j--)
			if(a[i] > a[j]) dp[i] = max(dp[i], dp[j] + 1);
		ans = max(ans, dp[i]);
	}
	printf("fun1 answer is %d\n", ans);
}

void fun2() { // nlog(n)
	int ans = 0;
	int b[MAXN];
	memset(b, 0x3f, sizeof(b));
	for(int i = 1; i <= n; i++) {
		int *it = lower_bound(b + 1, b + 1 + n, a[i]);
		dp[i] = it - b;	
		*it = a[i];
		ans = max(dp[i], ans);
	}
	printf("fun2 answer is %d\n", ans);
}
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	fun1();
	memset(dp, 0, sizeof(dp));
	fun2();
	return 0;
}
