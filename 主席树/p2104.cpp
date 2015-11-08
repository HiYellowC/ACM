#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100010;
const int MAXM = MAXN * 25;

int n, m, q, dex;
int a[MAXN], sorted[MAXN], root[MAXN];
int T[MAXM], lson[MAXM], rson[MAXM];

void Init() {
	dex = 0;
	sort(sorted + 1, sorted + 1 + n);
	m = unique(sorted + 1, sorted + 1 + n) - sorted - 1;
}

int BuildT(int l, int r) {
	int now = ++dex;
	T[now] = 0;
	if(l == r) return now;
	int mid = (l + r) >> 1;
	lson[now] = BuildT(l, mid);
	rson[now] = BuildT(mid + 1, r);
	return now;
}

int UpdateT(int l, int r, int pos, int val, int i) {
	int now = ++dex;
	int tmp = now;
	int oldnow = root[i];
	T[now] = T[oldnow] + val;
	while(l < r) {
		int mid = (l + r) >> 1;
		if(pos <= mid) {
			rson[now] = rson[oldnow];
			lson[now] = ++dex;
			T[dex] = T[lson[oldnow]] + val;
			now = lson[now], oldnow = lson[oldnow];
			r = mid;
		}
		else {
			lson[now] = lson[oldnow];
			rson[now] = ++dex;
			T[dex] = T[rson[oldnow]] + val;
			now = rson[now], oldnow = rson[oldnow];
			l = mid + 1;
		}
	}
	return tmp;
}

int QueryT(int l, int r, int k) {
	int nowl = root[l];
	int nowr = root[r];
	l = 1, r = m;
	while(l < r) {
		int mid = (l + r) >> 1;
		if(T[lson[nowl]] - T[lson[nowr]] >= k) {
			nowl = lson[nowl];
			nowr = lson[nowr];
			r = mid;	
		}
		else {
			k -= T[lson[nowl]] - T[lson[nowr]];
			nowl = rson[nowl];
			nowr = rson[nowr];
			l = mid + 1;
		}
	}
	return l;
}

int main() {
	while(~scanf("%d%d", &n, &q)) {
		for(int i = 1; i <= n; i++) scanf("%d", &a[i]), sorted[i] = a[i];
		Init();
		root[n + 1] = BuildT(1, m);
		for(int i = n; i >= 1; i--) {
			int pos = lower_bound(sorted + 1, sorted + 1 + m, a[i]) - sorted;
			root[i] = UpdateT(1, m, pos, 1, i + 1);
		}
		while(q--) {
			int l, r, k;
			scanf("%d%d%d", &l, &r, &k);
			printf("%d\n", sorted[QueryT(l, r + 1, k)]);
		}
	}
	return 0;
}
