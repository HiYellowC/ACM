#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200010;

int T[MAXN << 2];

void BuildT(int l, int r, int i) {
	if(l == r) {
		scanf("%d", &T[i]);
		return ;
	}
	int mid = (l + r) >> 1;
	BuildT(l, mid, i << 1);
	BuildT(mid + 1, r, i << 1 | 1);
	T[i] = max(T[i << 1], T[i << 1 | 1]);
}

int QueryT(int l, int r, int ll, int rr, int i) {
	if(l == ll && r == rr) return T[i];	
	int mid = (l + r) >> 1;
	if(rr <= mid) return QueryT(l, mid, ll, rr, i << 1);
	else if(ll > mid) return QueryT(mid + 1, r, ll, rr, i << 1 | 1);
	else return max(QueryT(l, mid, ll, mid, i << 1), QueryT(mid + 1, r, mid + 1, rr, i << 1 | 1));
}

void UpdateT(int l, int r, int id, int v, int i) {
	if(l == r) {
		T[i] = v;
		return ;
	}
	int mid = (l + r) >> 1;
	if(id <= mid) UpdateT(l, mid, id, v, i << 1);
	else UpdateT(mid + 1, r, id, v, i << 1 | 1);
	T[i] = max(T[i << 1], T[i << 1 | 1]);
}

int main() {
	int n, m;
	while(~scanf("%d%d", &n, &m)) {
		BuildT(1, n, 1);	
		char op[2];
		int a, b;
		while(m--) {
			scanf("%s%d%d", op, &a, &b);	
			if(op[0] =='Q') printf("%d\n", QueryT(1, n, a, b, 1));
			else UpdateT(1, n, a, b, 1);
		}
	}
	return 0;
}
