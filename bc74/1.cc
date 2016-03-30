#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

typedef long long LL;

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int a, n, tmp;
		scanf("%d", &n);
		LL ans = 1;	
		for(int i = 1; i < n; i++) {
			scanf("%d", &a);
			if(a > n - i) ans = 0;
			if(i == 1) {
				ans = (ans * 26) % MOD;
				tmp = a;
			}
			else {
				tmp--;
				if(tmp < 0) ans = (ans * 25) % MOD, tmp = a;
				if(a != tmp) ans = 0;
			}
		}
		if(!tmp) ans = (ans * 25) % MOD;
		printf("%lld\n", ans);
	}
	return 0;
}
