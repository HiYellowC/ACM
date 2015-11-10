#include <bits/stdc++.h>
using namespace std;

const int MAXN = 60010;
const int MAXQ = 10010;
const int MAXM = 2500010;

int n, m, dex;
int a[MAXN], sorted[MAXN], root[MAXN], lower[MAXN], temp[MAXN];
int T[MAXM], lson[MAXM], rson[MAXM];

struct Query {
	int kind, a, b, c;
}query[MAXQ];

int BuildT(int l, int r) {
	int now = ++dex;
	T[now] = 0;
	if(l == r) return now;
	int mid = (l + r) >> 1;
	lson[now] = BuildT(l, mid);
	rson[now] = BuildT(mid + 1, r);
	return now;
}

int UpdateT(int oldroot, int pos, int val) {
	int now = ++dex;
	int tmp = now;
	T[now] = T[oldroot] + val;
	int l = 1, r = m;
	while(l < r) {
		int mid = (l + r) >> 1;
		if(pos <= mid) {
			rson[now] = rson[oldroot];
			lson[now] = ++dex;
			T[lson[now]] = T[lson[oldroot]] + val;
			now = lson[now], oldroot = lson[oldroot];
			r = mid;
		}
		else {
			lson[now] = lson[oldroot];
			rson[now] = ++dex;
			T[rson[now]] = T[rson[oldroot]] + val;
			now = rson[now], oldroot = rson[oldroot];
			l = mid + 1;
		}
	}
	T[now] = T[oldroot] + val;
	return tmp;
}

int lowerbit(int x) {
	return x & (-x);
}

int getsum(int x) {
	int ans = 0;
	while(x) {
		ans += T[lson[temp[x]]];
		x -= lowerbit(x);
	}
	return ans;
}

int QueryT(int l, int r, int k) {
	int rootl = root[l];
	int rootr = root[r];
	int left = 1, right = m;
	for(int i = r; i; i -= lowerbit(i)) temp[i] = lower[i];
	for(int i = l; i; i -= lowerbit(i)) temp[i] = lower[i];
	while(left < right) {
		int con = T[lson[rootr]] - T[lson[rootl]] + getsum(r) - getsum(l);
		int mid = (left + right) >> 1;
		if(k <= con) {
			for(int i = r; i; i -= lowerbit(i)) temp[i] = lson[temp[i]];
			for(int i = l; i; i -= lowerbit(i)) temp[i] = lson[temp[i]];
			rootl = lson[rootl], rootr = lson[rootr];
			right = mid;
		}
		else {
			k -= con;	
			for(int i = r; i; i -= lowerbit(i)) temp[i] = rson[temp[i]];
			for(int i = l; i; i -= lowerbit(i)) temp[i] = rson[temp[i]];
			rootl = rson[rootl], rootr = rson[rootr];
			left = mid + 1;
		}
	}
	return left;
}

void UpdateL(int x, int pos, int val) {
	while(x <= n) {
		lower[x] = UpdateT(lower[x], pos, val);
		x += lowerbit(x);
	}
}

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int q;
		dex = m = 0;
		scanf("%d%d", &n, &q);
		for(int i = 1; i <= n; i++) scanf("%d", &a[i]), sorted[++m] = a[i];
		char op[2];	
		for(int i = 1; i <= q; i++) {
			scanf("%s", op);
			if(op[0] == 'Q') scanf("%d%d%d", &query[i].a, &query[i].b, &query[i].c), query[i].kind = 1;
			else scanf("%d%d", &query[i].a, &query[i].b), query[i].kind = 2, sorted[++m] = query[i].b;
		}
		sort(sorted + 1, sorted + 1 + m);
		m = unique(sorted + 1, sorted + 1 + m) - sorted - 1;
		root[0] = BuildT(1, m);
		for(int i = 1; i <= n; i++) {
			int pos = lower_bound(sorted + 1, sorted + 1 + m, a[i]) - sorted;
			root[i] = UpdateT(root[i - 1], pos, 1);
		}
		for(int i = 1; i <= n; i++) lower[i] = root[0];
		for(int i = 1; i <= q; i++) {
			if(query[i].kind == 1) printf("%d\n", sorted[QueryT(query[i].a - 1, query[i].b, query[i].c)]);
			else {
				int pos = lower_bound(sorted + 1, sorted + 1 + m, a[query[i].a]) - sorted;
				UpdateL(query[i].a, pos, -1);
				pos = lower_bound(sorted + 1, sorted + 1 + m, query[i].b) - sorted;
				UpdateL(query[i].a, pos, 1);
				a[query[i].a] = query[i].b;
			}
		}
	}
	return 0;
}
