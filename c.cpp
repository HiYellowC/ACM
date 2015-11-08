#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100010;

int a[MAXN], b[MAXN];

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n;
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
		a[n + 1] = 0;
		for(int i = 1; i <= n; i++) if(a[i] == 1 && a[i - 1] == 0 && a[i + 1] == 0) a[i] = 0;
		for(int i = 1; i <= n + 1; i++) b[i] = a[i];
		for(int i = 1; i <= n; i++) {
			if(b[i] == 1 && b[i - 1] == 0) a[i] = a[i - 1] + 1;
			else a[i] = a[i - 1];
		}
		int q;
		scanf("%d", &q);
		while(q--) {
			int l, r;
			scanf("%d%d", &l, &r);
			int ans = a[r] - a[l - 1];
			if(b[r] == 1 && b[r + 1] == 1) ans--;
			if(a[l - 1] == a[r + 1] && b[l - 1] == 1 && b[r + 1] == 1) ans++;
			printf("%d\n", ans);
		}
	}
	return 0;
}
