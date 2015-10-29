#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define INF 0x3f3f3f3f
using namespace std;

const int MAXN = 1010;

int ldp[MAXN], rdp[MAXN];
int V[MAXN];
int high[MAXN];

int main() {
	int n;
	while(~scanf("%d", &n)) {
		double x;
		for(int i = 1; i <= n; i++) scanf("%lf", &x), high[i] = x * 100000;
		memset(V, INF, sizeof(V));
		int k = -1;
		int con = 0;
		for(int i = 1; i <= n; i++) {
			int *it = lower_bound(V + 1, V + 1 + n, high[i]);
			if(high[i] == *it) con++;
			else k = high[i];
			ldp[i] = (int)(it - V) + con;
			con = 0;
			*it = high[i];
		}
		memset(V, INF, sizeof(V));
		for(int i = n; i >= 1; i--) {
			int *it = lower_bound(V + 1, V + 1 + n, high[i]);
			rdp[i] = (int)(it - V);
			*it = high[i];
		}
		int ans = 1010;
		for(int i = 1; i <= n; i++)
			ans = min(ans, (n - i + 1 - rdp[i]) + (i - ldp[i]));
		printf("%d\n", ans);
	}
	return 0;
}
