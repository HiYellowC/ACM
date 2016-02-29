#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n, m;
		scanf("%d%d", &n, &m);
		printf("%lld\n", (long long)n / 2 + (long long)m / 2);
	}
	return 0;
}
