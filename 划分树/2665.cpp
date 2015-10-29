#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 100010;

int toleft[20][MAXN], val[20][MAXN];
int sorted[MAXN];

void BuildT(int tl, int tr, int i) {
	if(i == 1) {
		for(int j = tl; j <= tr; j++) scanf("%d", &val[i][j]), sorted[j] = val[i][j];
		sort(sorted + tl, sorted + tl + tr);
	}	
	if(tl == tr) return ;
	int mid = (tl + tr) >> 1;
	int con = mid - tl + 1;
	for(int j = tl; j <= tr; j++) if(val[i][j] < sorted[mid]) con--;
	int addl, addr;
	addl = addr = 0;
	for(int j = tl; j <= tr; j++)
		if(val[i][j] < sorted[mid] || (val[i][j] == sorted[mid] && con)) {
			val[i + 1][tl + addl++] = val[i][j];
			toleft[i][j] = toleft[i][j - 1] + 1;
			if(val[i][j] == sorted[mid]) con--;
		}
		else {
			val[i + 1][mid + 1 + addr++] = val[i][j];
			toleft[i][j] = toleft[i][j - 1];
		}
	BuildT(tl, mid, i + 1);
	BuildT(mid + 1, tr, i + 1);
}

int QueryT(int tl, int tr, int l, int r, int k, int i) {
	//printf("tl: %d tr: %d l: %d r: %d k: %d i: %d\n", tl, tr, l, r, k, i);	
	if(tl == tr) return val[i][tl];
	int con = toleft[i][r] - toleft[i][l - 1];
	int mid = (tl + tr) >> 1;
	int ll = toleft[i][l - 1] - toleft[i][tl - 1];
	int mm = toleft[i][r] - toleft[i][l - 1];
	if(con >= k) return QueryT(tl, mid, tl + ll, tl + ll + mm - 1, k, i + 1);
	else return QueryT(mid + 1, tr, mid + l - tl - ll + 1, mid + l - tl - ll + (r - l + 1 - mm), k - con, i + 1);
}

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n, m;
		scanf("%d%d", &n, &m);
		BuildT(1, n, 1);
		while(m--) {
			int l, r, k;
			scanf("%d%d%d", &l, &r, &k);
			printf("%d\n", QueryT(1, n, l, r, k, 1));
		}
	}
	return 0;
}
