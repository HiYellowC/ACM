#include <bits/stdc++.h>
using namespace std;

const int MAXN = 8010;

int T[MAXN << 2], lazy[MAXN << 2];
int a[MAXN], ans[MAXN];

void PushDown(int l, int r, int i) {
	if(lazy[i]) {
		lazy[i << 1] = lazy[i << 1 | 1] = T[i << 1] = T[i << 1 | 1] = lazy[i];
		lazy[i] = T[i] = 0;
	}
}

void UpdateT(int l, int r, int ll, int rr, int c, int i) {
	if(l == ll && r == rr) {
		T[i] = lazy[i] = c;	
		return ;
	}
	PushDown(l, r, i);
	int mid = (l + r) >> 1;
	if(rr <= mid) UpdateT(l, mid, ll, rr, c, i << 1);
	else if(ll > mid) UpdateT(mid + 1, r, ll, rr, c, i << 1 | 1);
	else UpdateT(l, mid, ll, mid, c, i << 1), UpdateT(mid + 1, r, mid + 1, rr, c, i << 1 | 1);
}

int QueryT(int l, int r, int pos, int i) {
	if(l == r) return T[i];
	PushDown(l, r, i);
	int mid = (l + r) >> 1;
	if(pos <= mid) return QueryT(l, mid, pos, i << 1);
	else return QueryT(mid + 1, r, pos, i << 1 | 1);
}

int main() {
	int n;
	while(~scanf("%d", &n)) {
		memset(T, 0, sizeof(T));
		memset(lazy, 0, sizeof(lazy));
		memset(ans, 0, sizeof(ans));
		for(int i = 1; i <= n; i++) {
			int l, r, c;
			scanf("%d%d%d", &l, &r, &c);
			l++, c++;
			UpdateT(1, 8001, l, r, c, 1);
		}	
		for(int i = 1; i <= 8001; i++) a[i] = QueryT(1, 8001, i, 1);
		for(int i = 1; i <= 8001; i++) if(a[i] && a[i] != a[i - 1]) ans[a[i]]++;
		for(int i = 1; i <= 8001; i++) if(ans[i]) printf("%d %d\n", i - 1, ans[i]);
		puts("");
	}
	return 0;
}
