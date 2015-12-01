#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int MAXN = 100010;

LL a[MAXN], sorted[MAXN];
int con[MAXN];

int main() {
	LL n, p;
	scanf("%lld%lld", &n, &p);
	for(int i = 1; i <= n; i++) scanf("%lld", &a[i]), sorted[i] = a[i];
	sort(sorted + 1, sorted + 1 + n);
	int dex = 0;
	sorted[0] = -1;
	for(int i = 1; i <= n; i++)
		if(sorted[i] != sorted[i - 1]) con[++dex]++;
		else con[dex]++;
	int m = unique(sorted + 1, sorted + 1 + n) - sorted - 1;
	for(int i = 1; i <= m; i++) con[i] += con[i - 1];
	int ans = 0;
	for(int i = 1; i <= m; i++) {
		int sum = upper_bound(sorted + 1, sorted + 1 + m, sorted[i] * p) - sorted - 1;	
		sum = con[sum] - con[i - 1];
		ans = max(ans, sum);
	}
	printf("%d\n", ans);
	return 0;
}
