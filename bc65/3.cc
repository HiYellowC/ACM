#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 50010;

int a[MAXN], ans[MAXN];

int T[MAXN << 2];

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

int QueryT(int l, int r, int k, int i) {
	if(l == r) return l;
	int mid = (l + r) >> 1;
	if(k <= T[i << 1]) return QueryT(l, mid, k, i << 1);
	else return QueryT(mid + 1, r, k - T[i << 1], i << 1 | 1);
}

void UpdateT(int l, int r, int k, int i) {
	if(l == r) {
		T[i] = 0;
		return ;
	}
	int mid = (l + r) >> 1;
	if(k <= T[i << 1]) UpdateT(l, mid, k, i << 1);
	else UpdateT(mid + 1, r, k - T[i << 1], i << 1 | 1);
	T[i] = T[i << 1] + T[i << 1 | 1];
}

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n;
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
		BuildT(1, n, 1);
		for(int i = n; i >= 1; i--) {
			int con = a[i] - a[i - 1];
			ans[i] = QueryT(1, n, i - con, 1);
			UpdateT(1, n, i - con, 1);
		}
		for(int i = 1; i <= n; i++) printf("%d%c", ans[i], " \n"[i == n]);
	}
	return 0;
}
