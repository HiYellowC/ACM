#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int MAXN = 10000000;

LL a[MAXN];

LL fun(int n) {
	if(n < MAXN && a[n]) return a[n];
	if(n == 1) {
		if(n < MAXN) a[n] = 1;
		return 1;
	}
	LL ans = 0;
	for(LL i = 2; i * i <= n; i++) {
		if(n % i == 0) { 
			ans += fun(n / i);
			if(i * i != n) ans += fun(i);
		}
	}
	ans++;
	if(n < MAXN) a[n] = ans;
	return ans;
}

int main() {
	int n;	
	scanf("%d", &n);
	LL ans = fun(n);	
	printf("the answer is %lld\n", ans);
	return 0;
}
