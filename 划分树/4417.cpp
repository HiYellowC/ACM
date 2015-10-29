#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 100010;

int val[20][MAXN], toleft[20][MAXN];
int sorted[MAXN];
int ans;

void BuildT(int tl, int tr, int i) {
	if(tl == tr) {
		val[i][tl] = sorted[tl];
		return ;
	}
	int mid = (tl + tr) >> 1;
	int con = mid - tl + 1;
	int pl = tl;
	int pr = mid + 1;
	for(int j = tl; j <= tr; j++) if(val[i][j] < sorted[mid]) con--;
	for(int j = tl; j <= tr; j++) 
		if(val[i][j] < sorted[mid] || (val[i][j] == sorted[mid] && con)) {
			val[i + 1][pl++] = val[i][j];
			toleft[i][j] = toleft[i][j - 1] + 1;
			if(val[i][j] == sorted[mid]) con--;
		}
		else {
			val[i + 1][pr++] = val[i][j];
			toleft[i][j] = toleft[i][j - 1];
		}
	BuildT(tl, mid, i + 1);
	BuildT(mid + 1, tr, i + 1);
}

void QueryT(int tl, int tr, int l, int r, int h, int i) {
	if(l > r) return ;
	if(tl == tr) {
		if(val[i][tl] <= h) ans++;
		return ;	
	}	
	int mid = (tl + tr) >> 1;
	int ll = toleft[i][l - 1] - toleft[i][tl - 1];
	int mm = toleft[i][r] - toleft[i][l - 1];
	//printf("mid: %d h: %d mm: %d\n", sorted[mid], h, mm);
	if(h >= sorted[mid]) {
		ans += mm;
		QueryT(mid + 1, tr, mid + 1 + (l - tl - ll), mid + (l - tl - ll) + (r - l + 1 - mm), h, i + 1);
	}
	else QueryT(tl, mid, tl + ll, tl + ll + mm - 1, h, i + 1);
}

int main() {
	int t, tt = 1;
	scanf("%d", &t);
	while(t--) {
		int n, m;
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= n; i++) scanf("%d", &sorted[i]), val[0][i] = sorted[i];
		sort(sorted + 1, sorted + 1 + n);
		BuildT(1, n, 0);
		printf("Case %d:\n", tt++);
		while(m--) {
			int l, r, h;
			scanf("%d%d%d", &l, &r, &h);
			ans = 0;
			QueryT(1, n, l + 1, r + 1, h, 0);
			printf("%d\n", ans);
		}
	}
	return 0;

