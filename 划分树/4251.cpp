#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 100010;

int val[20][MAXN], toleft[20][MAXN];
int sorted[MAXN];

void BuildT(int tl, int tr, int i) {
	if(tl == tr) return ;
	int mid = (tl + tr) >> 1;
	int con = mid - tl + 1;
	for(int j = tl; j <= tr; j++) if(val[i][j] < sorted[mid]) con--;
	int lp = tl;
	int rp = mid + 1;
	for(int j = tl; j <= tr; j++)
		if(val[i][j] < sorted[mid] || (val[i][j] == sorted[mid] && con)) {
			val[i + 1][lp++] = val[i][j];
			toleft[i][j] = toleft[i][j - 1] + 1;
			if(val[i][j] == sorted[mid]) con--;
		}
		else {
			val[i + 1][rp++] = val[i][j];
			toleft[i][j] = toleft[i][j - 1];
		}
	BuildT(tl, mid, i + 1);
	BuildT(mid + 1, tr, i + 1);
}

int QueryT(int tl, int tr, int l, int r, int k, int i) {
	if(tl == tr) return val[i][tl];
	int mid = (tl + tr) >> 1;
	int ll = toleft[i][l - 1] - toleft[i][tl - 1];
	int mm = toleft[i][r] - toleft[i][l - 1];
	if(mm >= k) return QueryT(tl, mid, tl + ll, tl + ll + mm - 1, k, i + 1);
	else return QueryT(mid + 1, tr, mid + l - tl - ll + 1, mid + l - tl - ll + (r - l + 1 - mm), k - mm, i + 1);
}

int main() {
	int n, tt = 1;
	while(~scanf("%d", &n)) {
		for(int i = 1; i <= n; i++) scanf("%d", &sorted[i]), val[0][i] = sorted[i];
		sort(sorted + 1, sorted + 1 + n);
		BuildT(1, n, 0);
		int m;
		scanf("%d", &m);
		printf("Case %d:\n", tt++);
		while(m--) {
			int l, r;
			scanf("%d%d", &l, &r);
			printf("%d\n", QueryT(1, n, l, r, (r - l + 2) / 2, 0));
		}
	}
	return 0;
}
