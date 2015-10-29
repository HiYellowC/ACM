#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;

const int MAXN = 100010;

int val[20][MAXN], toleft[20][MAXN];
int sorted[MAXN];
LL sum[20][MAXN];
LL SUM[MAXN];

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
			sum[i][j] = sum[i][j - 1] + val[i][j];
			if(val[i][j] == sorted[mid]) con--;
		}
		else {
			val[i + 1][pr++] = val[i][j];
			toleft[i][j] = toleft[i][j - 1];
			sum[i][j] = sum[i][j - 1];
		}
	BuildT(tl, mid, i + 1);
	BuildT(mid + 1, tr, i + 1);
}

LL QueryT(int tl, int tr, int l, int r, int k, int i, bool flag) {
	if(tl == tr) {
		if(flag) return val[i][tl];
		else return 0;
	}
	int mid = (tl + tr) >> 1;
	int ll = toleft[i][l - 1] - toleft[i][tl - 1];
	int mm = toleft[i][r] - toleft[i][l - 1];
	if(k <= mm) return QueryT(tl, mid, tl + ll, tl + ll + mm - 1, k, i + 1, flag);
	else return (sum[i][r] - sum[i][l - 1]) * 2 + QueryT(mid + 1, tr, mid + 1 + l - tl - ll, mid + l - tl - ll + (r - l + 1 - mm), k - mm, i + 1, flag);
}

int main() {
	int t, tt = 1;
	scanf("%d", &t);
	while(t--) {
		int n;
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) scanf("%d", &sorted[i]), val[0][i] = sorted[i], SUM[i] = SUM[i - 1] + sorted[i];
		sort(sorted + 1, sorted + 1 + n);
		BuildT(1, n, 0);
		int q;
		scanf("%d", &q);
		printf("Case #%d:\n", tt++);
		while(q--) {
			int l, r;
			scanf("%d%d", &l, &r);
			l++, r++;
			LL ans;
			if((r - l + 1) % 2) {
				ans = SUM[r] - SUM[l - 1] - QueryT(1, n, l, r, (r - l + 1) / 2 + 1, 0, 1);
			}
			else {
				ans = SUM[r] - SUM[l - 1] - QueryT(1, n, l, r, (r - l + 1) / 2 + 1, 0, 0);
			}
			printf("%lld\n", ans);
		}
		printf("\n");
	}
	return 0;
}
