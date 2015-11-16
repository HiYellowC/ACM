#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5010;

int n;
int bit[MAXN];
int a[MAXN];
int ans[MAXN];

int lowerbit(int x) {
	return x & (-x);
}

int getsum(int x) {
	int sum = 0;
	while(x) {
		sum += bit[x];
		x -= lowerbit(x);
	}
	return sum;
}

void add(int x) {
	while(x <= n) {
		bit[x]++;
		x += lowerbit(x);
	}	
}

int main() {
	while(~scanf("%d", &n)) {
		for(int i = 1; i <= n; i++) scanf("%d", &a[i]), a[i]++;
		memset(bit, 0, sizeof(bit));
		for(int i = n; i >= 1; i--) {
			ans[i] = getsum(a[i] - 1);
			add(a[i]);
		}
		int ANS = 0;
		for(int i = 1; i <= n; i++) ANS += ans[i];
		int con = ANS;
		for(int i = 1; i < n; i++) ANS = min(ANS, con + n - a[i] - a[i] + 1), con = con + n - a[i] - a[i] + 1;
		printf("%d\n", ANS);
	}
	return 0;
}
