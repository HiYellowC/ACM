#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define EPS 1e-6
using namespace std;

struct Treex {
	double treey[105 << 2];
	void Update(int y, double val, int l, int r, int i) {
		if(l == r) {
			treey[i] = max(treey[i], val);	
			return ;
		}	
		int mid = (l + r) >> 1;
		if(y <= mid)
			Update(y, val, l, mid, i << 1);
		else
			Update(y, val, mid + 1, r, i << 1 | 1);
		treey[i] = max(treey[i << 1], treey[i << 1 | 1]);
	}
	double Query(int h1, int h2, int l, int r, int i) {
		if(l == h1 && r == h2) {
			return treey[i];
		}		
		int mid = (l + r) >> 1;
		if(h2 <= mid)
			return Query(h1, h2, l, mid, i << 1);
		else if(h1 > mid)
			return Query(h1, h2, mid + 1, r, i << 1 | 1);
		else
			return max(Query(h1, mid, l, mid, i << 1), Query(mid + 1, h2, mid + 1, r, i << 1 | 1));
	}
}treex[1005 << 2];

void Init() {
	for(int i = 0 ; i < 1005 << 2; i++)
		memset(treex[i].treey, 0, sizeof(treex[i].treey));
}

void PushUp(int i, int l, int r, int si) {
	if(l == r) {
		treex[i].treey[si] = max(treex[i << 1].treey[si], treex[i << 1 | 1].treey[si]);
		return ;
	}
	int mid = (l + r) >> 1;
	PushUp(i, l, mid, si << 1);
	PushUp(i, mid + 1, r, si << 1 | 1);
	treex[i].treey[si] = max(treex[i << 1].treey[si], treex[i << 1 | 1].treey[si]);
}

void Update(int x, int y, double val, int l, int r, int i) {
	if(l == r) {
		treex[i].Update(y, val, 1, 101, 1);
		return ;
	}	
	int mid = (l + r) >> 1;
	if(x <= mid)
		Update(x, y, val, l, mid, i << 1);
	else
		Update(x, y, val, mid + 1, r, i << 1 | 1);
	PushUp(i, 1, 101, 1);
}

double Query(int h1, int h2, int a1, int a2, int l, int r, int i) {
	if(a1 == l && a2 == r) {
		return treex[i].Query(h1, h2, 1, 101, 1);	
	}
	int mid = (l + r) >> 1;
	if(a2 <= mid)
		return Query(h1, h2, a1, a2, l, mid, i << 1);
	else if(a1 > mid)
		return Query(h1, h2, a1, a2, mid + 1, r, i << 1 | 1);
	else
		return max(Query(h1, h2, a1, mid, l, mid, i << 1), Query(h1, h2, mid + 1, a2, mid + 1, r, i << 1 | 1));
}

int main() {
	int m;
	char op[2];
	while(~scanf("%d", &m)) {
		if(!m) break;
		Init();
		while(m--) {
			scanf("%s", op);
			if(op[0] == 'I') {
				int h;
				double a, l;
				scanf("%d%lf%lf", &h, &a, &l);
				Update((int)(a * 10) + 1, h - 99, l, 1, 1001, 1);
			}
			else {
				int h1, h2;
				double a1, a2;
				scanf("%d%d%lf%lf", &h1, &h2, &a1, &a2);
				if(h2 < h1) swap(h1, h2);
				if(a2 < a1) swap(a1, a2);
				double ans = Query(h1 - 99, h2 - 99, (int)(a1 * 10) + 1, (int)(a2 * 10) + 1, 1, 1001, 1);
				if(fabs(ans) < EPS)
					printf("-1\n");
				else
					printf("%.1lf\n", ans);
			}
		}
	}
	return 0;
}
