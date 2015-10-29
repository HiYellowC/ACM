#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 1010
#define MOD 1000000007
using namespace std;

int r, c;
int maxn, q;

struct QQ {
	int x1, x2;
	int y1, y2;
	int v;
};
QQ Q[15];

bool cmp(QQ x, QQ y) {
	return x.v < y.v;
}

struct Treex {
	int treey[MAXN * 3];
	bool flagy[MAXN * 3];
	void PushDown(int i, int m) {
		if(flagy[i]) {
			flagy[i << 1] = flagy[i << 1 | 1] = flagy[i];
			treey[i << 1] = m - (m >> 1); 
			treey[i << 1 | 1] = m >> 1;
			flagy[i] = 0;
		}	
	}
	void Update(int y1, int y2, int l, int r, int i) {
		if(y1 == l && y2 == r) {
			flagy[i] = 1;
			treey[i] = y2 - y1 + 1;
			return ;
		}
		PushDown(i, r - l + 1);
		int mid = (l + r) >> 1;
		if(y2 <= mid)
			Update(y1, y2, l, mid, i << 1);
		else if(y1 > mid)
			Update(y1, y2, mid + 1, r, i << 1 | 1);
		else
			Update(y1, mid, l, mid, i << 1), Update(mid + 1, y2, mid + 1, r, i << 1 | 1);
		treey[i] = treey[i << 1] + treey[i << 1 | 1];
	}
	int Query(int y1, int y2, int l, int r, int i) {
		if(y1 <= l && y2 >= r)
			return treey[i];
		PushDown(i, r - l + 1);
		int mid = (l + r) >> 1;
		int ans = 0;
		if(y1 <= mid)
			ans += Query(y1, y2, l, mid, i << 1);
		if(y2 > mid)
			ans += Query(y1, y2, mid + 1, r, i << 1 | 1);
		return ans;
	}
}treex[MAXN * 3];

void PushUp(int i, int l, int r, int si) {
	if(l == r) {
		treex[i].treey[si] = treex[i << 1].treey[si] + treex[i << 1 | 1].treey[si];
		return ;
	}
	int mid = (l + r) >> 1;
	PushUp(i, l, mid, si << 1);
	PushUp(i, mid + 1, r, si << 1 | 1);
	treex[i].treey[si] = treex[i].treey[si << 1] + treex[i].treey[si << 1 | 1];
}

void Update(int x1, int x2, int y1, int y2, int l, int r, int i) {
	if(l == r) {
		treex[i].Update(y1, y2, 1, c, 1);
		return ;
	}
	int mid = (l + r) >> 1;
	if(x1 <= mid)
		Update(x1, x2, y1, y2, l, mid, i << 1);
	if(x2 > mid)
		Update(x1, x2, y1, y2, mid + 1, r, i << 1 | 1);
	treex[i].Update(y1, y2, 1, c, 1);
}

int Query(int x1, int x2, int y1, int y2, int l, int r, int i) {
	if(x1 <= l && x2 >= r)
		return treex[i].Query(y1, y2, 1, c, 1);	
	int mid = (l + r) >> 1;
	int ans = 0;
	if(x1 <= mid)
		ans += Query(x1, x2, y1, y2, l, mid, i << 1);
	if(x2 > mid)
		ans += Query(x1, x2, y1, y2, mid + 1, r, i << 1 | 1);
	return ans;
}

int Power(int n, int m) {
	int ans = 1;
	while(m) {
		if(m & 1)
			ans = (ans * n) % MOD;
		m >>= 1;
		n = (n * n) % MOD;
	}
	return ans;
}

int main() {
	int t, tt = 1;
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d", &r, &c);
		scanf("%d%d", &maxn, &q);
		for(int i = 1; i <= q; i++)
			scanf("%d%d%d%d%d", &Q[i].x1, &Q[i].y1, &Q[i].x2, &Q[i].y2, &Q[i].v);
		sort(Q + 1, Q + 1 + q, cmp);
		int ans = 0;
		for(int i = 1; i <= q; i++) {
			int num = Query(Q[i].x1, Q[i].x2, Q[i].y1, Q[i].y2, 1, r, 1);	
			num = (Q[i].x2 - Q[i].x1 + 1) * (Q[i].y2 - Q[i].y1 + 1) - num;
			ans = (ans + Power(Q[i].v, num)) % MOD;
			printf("ans: %d\n", ans);
			Update(Q[i].x1, Q[i].x2, Q[i].y1, Q[i].y2, 1, r, 1);	
		}
		int num = Query(1, r, 1, c, 1, r, 1);
		num = r * c - num;
		ans = (ans + Power(maxn, num)) % MOD;
		printf("Case #%d: %d\n", tt++, ans);
	}
	return 0;
}
