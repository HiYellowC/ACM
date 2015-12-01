#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100010;

int sum[MAXN];

int main() {
	int n;
	scanf("%d", &n);
	int num;
	for(int i = 1; i <= n; i++) scanf("%d", &num), sum[i] = sum[i - 1] + num;
	int m;
	scanf("%d", &m);
	while(m--) {
		int a, b;
		scanf("%d%d", &a, &b);
		if(a > b) swap(a, b);
		printf("%d\n", min(sum[b - 1] - sum[a - 1], sum[n] - sum[b - 1] + sum[a - 1]));
	}
	return 0;
}
