#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int MOD = 1e9 + 7;

int n, m, a, b, sum;

pair <int, int> e[3];

void fun(int dex) {
	if(abs(e[dex].first - a) > abs(e[dex].second - a)) swap(e[dex].first, e[dex].second);
	sum += (1 + abs(a - e[dex].first));
	a = e[dex].second;
}

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		LL ans = 0;
		scanf("%d%d", &n, &m);
		for(int i = 0; i < 3; i++) scanf("%d%d", &e[i].first, &e[i].second);
		int A, B;
		for(int i = 1; i <= m; i++) {
			scanf("%d%d", &A, &B);
			int con = abs(A - B);
			sum = 0, a = A, b = B, fun(0), fun(1), fun(2), con = min(con, sum + abs(a - b));
			sum = 0, a = A, b = B, fun(0), fun(2), fun(1), con = min(con, sum + abs(a - b));
			sum = 0, a = A, b = B, fun(1), fun(2), fun(0), con = min(con, sum + abs(a - b));
			sum = 0, a = A, b = B, fun(1), fun(0), fun(2), con = min(con, sum + abs(a - b));
			sum = 0, a = A, b = B, fun(2), fun(1), fun(0), con = min(con, sum + abs(a - b));
			sum = 0, a = A, b = B, fun(2), fun(0), fun(1), con = min(con, sum + abs(a - b));
			sum = 0, a = A, b = B, fun(0), fun(1), con = min(con, sum + abs(a - b));
			sum = 0, a = A, b = B, fun(0), fun(2), con = min(con, sum + abs(a - b));
			sum = 0, a = A, b = B, fun(1), fun(2), con = min(con, sum + abs(a - b));
			sum = 0, a = A, b = B, fun(1), fun(0), con = min(con, sum + abs(a - b));
			sum = 0, a = A, b = B, fun(2), fun(1), con = min(con, sum + abs(a - b));
			sum = 0, a = A, b = B, fun(2), fun(0), con = min(con, sum + abs(a - b));
			sum = 0, a = A, b = B, fun(1), con = min(con, sum + abs(a - b));
			sum = 0, a = A, b = B, fun(2), con = min(con, sum + abs(a - b));
			sum = 0, a = A, b = B, fun(0), con = min(con, sum + abs(a - b));
			ans = (ans % MOD + (i * (LL)con) % MOD) % MOD;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
