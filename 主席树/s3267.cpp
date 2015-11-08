#include <bits/stdc++.h>
using namespace std;

const int MAXN = 30010;

int n, dex;
int a[MAXN], root[MAXN];
int T[MAXN * 35], lson[MAXN * 35], rson[MAXN * 35];
map <int, int> M;

int BuildT(int l, int r) {
	int now = ++dex;
	T[now] = 0;
	if(l == r) return now;
	int mid = (l + r) >> 1;
	lson[now] = BuildT(l, mid);
	rson[now] = BuildT(mid + 1, r);
}

int UpdateT(int oldroot, int pos, int val) {
	int now = ++dex;
	int tmp = now;
	T[now] = T[oldroot] + val;
	int l = 1, r = n;
	while(l < r) {
		int mid = (l + r) >> 1;
		if(pos <= mid) {
			rson[now] = rson[oldroot];
			lson[now] = ++dex;
			T[lson[now]] = T[lson[oldroot]] + val;
			oldroot = lson[oldroot], now = lson[now];
			r = mid;
		}
		else {
			lson[now] = lson[oldroot];
			rson[now] = ++dex;
			T[rson[now]] = T[rson[oldroot]] + val;
			oldroot = rson[oldroot], now = rson[now];
			l = mid + 1;
		}
	}
	return tmp;
}

int QueryT(int now, int pos) {
	int ans = 0;
	int l = 1, r = n;
	while(l < r) {
		int mid = (l + r) >> 1;
		if(pos <= mid) {
			now = lson[now];
			r = mid;
		}
		else {
			ans += T[lson[now]];
			now = rson[now];
			l = mid + 1;
		}
	}
	ans += T[now];
	return ans;
}

int main() {
	while(~scanf("%d", &n)) {
		dex = 0, M.clear();
		for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
		root[n + 1] = BuildT(1, n);
		for(int i = n; i >= 1; i--) {
			if(M[a[i]]) {
				int tmp = UpdateT(root[i + 1], M[a[i]], -1);
				root[i] = UpdateT(tmp, i, 1);
			}
			else root[i] = UpdateT(root[i + 1], i, 1);
			M[a[i]] = i;	
		}
		int q;
		scanf("%d", &q);
		while(q--) {
			int l, r;
			scanf("%d%d", &l, &r);
			printf("%d\n", QueryT(root[l], r));
		}
	}
	return 0;
}
