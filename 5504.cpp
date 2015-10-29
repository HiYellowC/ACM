#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;

LL a[65];

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n;
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
		sort(a + 1, a + n + 1);
		int sum = 0;
		LL ans = 1;
		for(int i = 1; i <= n; i++)
			if(a[i] > 0) ans *= a[i], sum++;
		for(int i = 1; i < n; i++)
			if(a[i] < 0 && a[i + 1] < 0) ans *= (a[i] * a[i + 1]), sum += 2, i++;
		if(sum == 0) ans = a[n];
		printf("%lld\n", ans);
	}
	return 0;
}
