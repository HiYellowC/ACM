#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int MAXN = 100010;

LL T[MAXN << 2];
bool flag[MAXN << 2];

void BuildT(int l, int r, int i) {
	if(l == r) {
		scanf("%lld", &T[i]);
		if(T[i] <= 1) flag[i] = true;
		else flag[i] = false;
		return ;
	}
	int mid = (l + r) >> 1;
	BuildT(l, mid, i << 1);
	BuildT(mid + 1, r, i << 1 | 1);
	T[i] = T[i << 1] + T[i << 1 | 1];
	if(flag[i << 1] && flag[i << 1 | 1]) flag[i] = true;
	else flag[i] = false;
}

void UpdateT(int l, int r, int ll, int rr, int i) {
	if(flag[i]) return ;
	if(l == r) {
		T[i] = (LL)sqrt((double)T[i]);
		if(T[i] <= 1) flag[i] = true;
		else flag[i] = false;
		return ;
	}
	int mid = (l + r) >> 1;
	if(ll <= mid) UpdateT(l, mid, ll, rr, i << 1);
	if(rr > mid) UpdateT(mid + 1, r, ll, rr, i << 1 | 1);
	T[i] = T[i << 1] + T[i << 1 | 1];
	if(flag[i << 1] && flag[i << 1 | 1]) flag[i] = true;
	else flag[i] = false;
} 

LL QueryT(int l, int r, int ll, int rr, int i) {
	if(l == ll && r == rr) return T[i];
	int mid = (l + r) >> 1;
	if(rr <= mid) return QueryT(l, mid, ll, rr, i << 1);
	else if(ll > mid) return QueryT(mid + 1, r, ll, rr, i << 1 | 1);
	else return QueryT(l, mid, ll, mid, i << 1) + QueryT(mid + 1, r, mid + 1, rr, i << 1 | 1);
}

int main() {
	int n, tt = 1;
	while(~scanf("%d", &n)) {
		BuildT(1, n, 1);	
		int q;
		scanf("%d", &q);
		printf("Case #%d:\n", tt++);
		while(q--) {
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			if(b > c) swap(b, c);
			if(a == 0) UpdateT(1, n, b, c, 1);
			else printf("%lld\n", QueryT(1, n, b, c, 1));
		}
		puts("");
	}
	return 0;
}
