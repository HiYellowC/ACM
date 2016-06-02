#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100010;
const int MOD = 1e9 + 7;

int a[MAXN], pos[MAXN];

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for(int i = 1; i <= n; i++) {
		int num = a[i];
		a[i] = (a[i - 1] * 2 + 1) % MOD;
		if(pos[num]) a[i] = (a[i] - 1 + MOD) % MOD;
		a[i] = (a[i] - a[pos[num] - 1] + MOD) % MOD;
		pos[num] = i;
	}
	printf("%d\n", a[n]);
	return 0;
}
