#include <bits/stdc++.h>
using namespace std;

int fun(int n, int m, int k) {
	int ans = 0;
	for(int i = 2; i <= n; i++)
		ans = (ans + k) % i;
	int s = (m - k % n + 1 + n) % n;
	ans = (ans + s) % n;
	return ans + 1;
}

int main() {
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	int ans = fun(n, m - 1, k);
	printf("the answer is %d\n", ans);
	return 0;
}
