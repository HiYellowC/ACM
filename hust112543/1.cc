#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000010;

int a[MAXN];

int main() {
	int t, tt = 1;
	scanf("%d", &t);
	while(t--) {
		int n;
		scanf("%d", &n);
		for(int i = 0; i < n; i++) scanf("%d", &a[i]);
		int tmp = n;
		int ans = 0;
		for(int i = n - 1; i >= 0; i--) {
			if(tmp == a[i]) tmp--;
			else if(tmp > a[i]) i++, tmp--, ans++;
		}
		printf("Case #%d: %d\n", tt++, ans);
	}
	return 0;
}
