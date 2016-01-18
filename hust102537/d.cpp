#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 8010;

int T[MAXN << 2];

int a[MAXN];

void BuildT(int l, int r, int i) {
	if(l == r) {
		T[i] = 1;
		return ;
	}
	int mid = (l + r) >> 1;
	BuildT(l, mid, i << 1);
	BuildT(mid + 1, r, i << 1 | 1);
	T[i] = T[i << 1] + T[i << 1 | 1];
}

int QueryT(int l, int r, int cur, int i) {
	if(l == r) return l;
	int mid = (l + r) >> 1;
	if(cur <= T[i << 1]) return QueryT(l, mid, cur, i << 1);
	else return QueryT(mid + 1, r, cur - T[i << 1], i << 1 | 1);
}

void UpdateT(int l, int r, int pos, int i) {
	if(l == r) {
		T[i] = 0;
		return ;
	}
	int mid = (l + r) >> 1;
	if(pos <= mid) UpdateT(l, mid, pos, i << 1);
	else UpdateT(mid + 1, r, pos, i << 1 | 1);
	T[i] = T[i << 1] + T[i << 1 | 1];
}

int main() {
	int n;
	while(~scanf("%d", &n)) {
		BuildT(1, n, 1);
		for(int i = 1; i < n; i++) scanf("%d", &a[i]);
		for(int i = n - 1; i >= 1; i--) {
			a[i + 1] = QueryT(1, n, a[i] + 1, 1);	
			UpdateT(1, n, a[i + 1], 1);
		}
		a[1] = QueryT(1, n, 1, 1);
		for(int i = 1; i <= n; i++) printf("%d\n", a[i]);
	}
	return 0;
}
