#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define Max 100010
using namespace std;

typedef long long LL;

LL sum[Max];
LL p[50];
int n, con;

void Init() {
	for(LL i = 1; i <= 1e10; i *= 2)
		p[con++] = i;
	p[con] = 1e10 + 1;
	p[0] = 0;
}

LL count(LL a, LL b) {
	int l, r;
	l = r = 0;
	LL ans = 0;
	for(int i = 1; i <= n; i++) {
		if(l < i) l = i;
		if(r < i) r = i;
		while(l <= n && sum[l] - sum[i - 1] < a) l++;
		while(r <= n && sum[r] - sum[i - 1] < b) r++;
		r--;
		if(l == n + 1 || r == i - 1 || r < l) continue;
		ans += (LL)(r - l + 1) * i + (LL)(l + r) * (r - l + 1) / 2;
	}
	return ans;
} 

int main() {
	Init();
	int t;
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) {
			scanf("%lld", &sum[i]);
			sum[i] += sum[i - 1];
		}
		LL ans = 0;
		for(int i = 0; i < con; i++) {
			ans += (LL)(i + 1) * count(p[i], p[i + 1]);	
		}
		printf("%lld\n", ans);
	}
	return 0;
}
