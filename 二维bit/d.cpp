#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 1030
using namespace std;

int n;

struct Treex {
	int treey[MAXN << 2];
	void Update(int y, int add, int l, int r, int i) {
		if(l == r) {
			treey[i] += add;
			return;
		}	
		int mid = (l + r) >> 1;
		if(y <= mid)
			Update(y, add, l, mid, i << 1);
		else
			Update(y, add, mid + 1, r, i << 1 | 1);
		treey[i] = treey[i << 1] + treey[i << 1 | 1];
	}
	int Query(int y1, int y2, int l, int r, int i) {
		if(y1 <= l && y2 >= r)
			return treey[i];
		int mid = (l + r) >> 1;
		int ans = 0;
		if(y1 <= mid)
			ans += Query(y1, y2, l, mid, i << 1);
		if(y2 > mid)
			ans += Query(y1, y2, mid + 1, r, i << 1 | 1);
		return ans;
	}
}treex[MAXN << 2];

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

void Update(int x, int y, int add, int l, int r, int i) {
	if(l == r) {
		treex[i].Update(y, add, 1, n, 1);
		return ;
	}
	int mid = (l + r) >> 1;
	if(x <= mid)
		Update(x, y, add, l, mid, i << 1);
	else
		Update(x, y, add, mid + 1, r, i << 1 | 1);
	treex[i].Update(y, add, 1, n, 1);
}

int Query(int x1, int x2, int y1, int y2, int l, int r, int i) {
	if(x1 <= l && x2 >= r)
		return treex[i].Query(y1, y2, 1, n, 1);	
	int mid = (l + r) >> 1;
	int ans = 0;
	if(x1 <= mid)
		ans += Query(x1, x2, y1, y2, l, mid, i << 1);
	if(x2 > mid)
		ans += Query(x1, x2, y1, y2, mid + 1, r, i << 1 | 1);
	return ans;
}

int main() {
	int op;
	while(~scanf("%d", &op)) {
		if(op == 0) scanf("%d", &n);
		else if(op == 1) {
			int x, y, add;
			scanf("%d%d%d", &x, &y, &add);
			Update(x + 1, y + 1, add, 1, n, 1);
		}
		else if(op == 2) {
			int x1, x2, y1, y2;
			scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
			printf("%d\n", Query(x1 + 1, x2 + 1, y1 + 1, y2 + 1, 1, n, 1));	
		}
		else break;
	}
	return 0;
}
