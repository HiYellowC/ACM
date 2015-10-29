#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define MAXN 200010
using namespace std;

typedef long long LL;

LL a[MAXN];
LL front[MAXN], back[MAXN];

int main() {
	int n, k, x;
	scanf("%d%d%d", &n, &k, &x);
	LL Max = 0;
	for(int i = 1; i <= n; i++) scanf("%I64d", &a[i]);
	for(int i = 1; i <= n; i++) front[i] = front[i - 1] | a[i];
	for(int i = n; i >= 1; i--) back[i] = back[i + 1] | a[i];
	LL tmp = 1;
	for(int i = 1; i <= k; i++) tmp *= (LL)x;
	LL ans = 0;
	for(int i = 1; i <= n; i++) ans = max(ans, (tmp * a[i]) | front[i - 1] | back[i + 1]);
	printf("%I64d\n", ans);
	return 0;
}
