#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10010; 

int ll[MAXN], rr[MAXN];
int a[32 * MAXN];
int T[32 * 3 * MAXN];
int TT[32 * 3 * MAXN];

void BuildT(int l, int r, int i) {
	if(l == r) {
		T[i] = a[l];
		return ;
	}
	int mid = (l + r) >> 1;
	BuildT(l, mid, i << 1);
	BuildT(mid + 1, r, i << 1 | 1);
	T[i] = max(T[i << 1], T[i << 1 | 1]);
}

void BuildTT(int l, int r, int i) {
	if(l == r) {
		TT[i] = a[l];
		return ;
	}
	int mid = (l + r) >> 1;
	BuildTT(l, mid, i << 1);
	BuildTT(mid + 1, r, i << 1 | 1);
	TT[i] = min(TT[i << 1], TT[i << 1 | 1]);
}

int QueryT(int tl, int tr, int l, int r, int i) {
	if(l == tl && r == tr) return T[i];
	int mid = (tl + tr) >> 1;
	if(r <= mid) return QueryT(tl, mid, l, r, i << 1);
	else if(l > mid) return QueryT(mid + 1, tr, l, r, i << 1 | 1);
	else return max(QueryT(tl, mid, l, mid, i << 1), QueryT(mid + 1, tr, mid + 1, r, i << 1 | 1));
}

int QueryTT(int tl, int tr, int l, int r, int i) {
	if(l == tl && r == tr) return TT[i];
	int mid = (tl + tr) >> 1;
	if(r <= mid) return QueryTT(tl, mid, l, r, i << 1);
	else if(l > mid) return QueryTT(mid + 1, tr, l, r, i << 1 | 1);
	else return min(QueryTT(tl, mid, l, mid, i << 1), QueryTT(mid + 1, tr, mid + 1, r, i << 1 | 1));
}

int main() {
	int t, tt = 1;
	scanf("%d", &t);
	while(t--) {
		int n, m;
		scanf("%d%d", &n, &m);
		int dex = 0;
		for(int i = 1; i <= n; i++) {
			int num;
			scanf("%d", &num);
			ll[i] = dex + 1;
			a[++dex] = num % m;
			num /= m;
			while(num) {
				a[++dex] = num % m;
				num /= m;
			}
			rr[i] = dex;
			for(int k = ll[i]; k <= (ll[i] + rr[i]) >> 1; k++) swap(a[k], a[ll[i] + rr[i] - k]);
		}
		BuildT(1, dex, 1);
		BuildTT(1, dex, 1);
		printf("Case #%d:\n", tt++);
		int q;
		scanf("%d", &q);
		while(q--) {
			int l, r;
			scanf("%d%d", &l, &r);
			printf("%d\n", QueryT(1, dex, ll[l], rr[r], 1) - QueryTT(1, dex, ll[l], rr[r], 1));
		}
	}
	return 0;
}
