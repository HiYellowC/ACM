#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1010;
struct Nodey {
	int l, r;
	int val;
};
int n;
int locx[MAXN], locy[MAXN];

struct Nodex {
	int l, r;
	Nodey sty[MAXN * 3];
	void build(int i, int _l, int _r) {
		sty[i].l = _l;
		sty[i].r = _r;
		sty[i].val = 0;
		if(_l == _r) {
			locy[_l] = i;
			return ;
		}
		int mid = (_l + _r) >> 1;
		build(i << 1, _l, mid);
		build(i << 1 | 1, mid + 1, _r);
	}
	void add(int i , int _l, int _r, int val) {
		if(sty[i].l == _l && sty[i].r == _r) {
			sty[i].val += val;
			return ;
		}	
		int mid = (sty[i].l + sty[i].r) >> 1;
		if(_r <= mid) add(i << 1, _l, _r, val);
		else if(_l > mid) add(i << 1 | 1, _l, _r, val);
		else add(i << 1, _l, mid, val), add(i << 1 | 1, mid + 1, _r, val);
	}	
}stx[MAXN * 3];

void build(int i, int l, int r) {
	stx[i].l = l;
	stx[i].r = r;
	stx[i].build(1, 1, n);
	if(l == r) {
		locx[l] = i;
		return ;
	}
	int mid = (l + r) >> 1;
	build(i << 1, l, mid);
	build(i << 1 | 1, mid + 1, r);
}

void add(int i, int x1, int x2, int y1, int y2, int val) {
	if(stx[i].l == x1 && stx[i].r == x2) {
		stx[i].add(1, y1, y2, val);
		return ;
	}
	int mid = (stx[i].l + stx[i].r) / 2;
	if(x2 <= mid) add(i << 1, x1, x2, y1, y2, val);
	else if(x1 > mid) add(i << 1 | 1, x1, x2, y1, y2, val);
	else add(i << 1, x1, mid, y1, y2, val), add(i << 1 | 1, mid + 1, x2, y1, y2, val);
}

int sum(int x, int y) {
	int ret = 0;
	for(int i = locx[x]; i; i >>= 1)
		for(int j = locy[y]; j; j >>= 1)
			ret += stx[i].sty[j].val;
	return ret;
}

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int q;
		scanf("%d%d", &n, &q);
		build(1, 1, n);
		char op[2];
		int x1, x2, y1, y2;
		while(q--) {
			scanf("%s", op);
			if(op[0] == 'C') {
				scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
				add(1, x1, x2, y1, y2, 1);
			}
			else {
				scanf("%d%d", &x1, &y1);
				if(sum(x1, y1) % 2 == 0) printf("0\n");
				else printf("1\n");
			}
		}
		printf("\n");
	}
	return 0;
}
