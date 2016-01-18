#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 110;

int a[MAXN], p[MAXN];

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int c;		
		for(int i = 1; i <= c; i++) scanf("%d%d", &a[i], &p[i]);
		int ans = (a[n] + 10) * p[n];
		int cost = p[n];
		for(int i = n - 1; i >= 1; i--)
			ans = min(ans + (a[i] + 10) * p[i], ans + a[i] * cost), cost = p[i];
		printf("%d\n", ans);
	}
	return 0;
}
