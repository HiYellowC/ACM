#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int Max = 305;
int n;

struct Treex {
	int treey[Max << 2];
	void Buildy(int l, int r, int i) {
		if(l == r) {
			scanf("%d", &treey[i]);
			return ;	
		}				
		int mid = (l + r) >> 1;
		Buildy(l, mid, i << 1);
		Buildy(mid + 1, r, i << 1 | 1);
		treey[i] = min(treey[i << 1], treey[i << 1 | 1]);
	}
	int Query(int y1, int y2, int l, int r, int i) {
		if(l == y1 && r == y2) {
			return treey[i];	
		}	
		int mid = (l + r) >> 1;
		if(y2 <= mid)
			return Query(y1, y2, l, mid, i << 1);
		else if(y1 > mid)
			return Query(y1, y2, mid + 1, r, i << 1 | 1);
		else 
			return min(Query(y1, mid, l, mid, i << 1), Query(mid + 1, y2, mid + 1, r, i << 1 | 1));
	}
};
Treex treex[Max << 2];

void PushUp(int i, int l, int r, int si) {
	if(l == r) {
		treex[i].treey[si] = min(treex[i << 1].treey[si], treex[i << 1 | 1].treey[si]);
		return ;
	}	
	int mid = (l + r) >> 1;
	PushUp(i, l, mid, si << 1);
	PushUp(i, mid + 1, r, si << 1 | 1);
	treex[i].treey[si] = min(treex[i << 1].treey[si], treex[i << 1 | 1].treey[si]);
}

void Build(int l, int r, int i) {
	if(l == r) {
		treex[i].Buildy(1, n, 1);
		return ;
	}
	int mid = (l + r) >> 1;
	Build(l, mid, i << 1);
	Build(mid + 1, r, i << 1 | 1);
	PushUp(i, 1, n, 1);
}

int Query(int x1, int y1, int x2, int y2, int l, int r, int i) {
	if(l == x1 && r == x2) {
		return treex[i].Query(y1, y2, 1, n, 1);
	}	
	int mid = (l + r) >> 1;
	if(x2 <= mid)
		return Query(x1, y1, x2, y2, l, mid, i << 1);
	else if(x1 > mid)
		return Query(x1, y1, x2, y2, mid + 1, r, i << 1 | 1);
	else
		return min(Query(x1, y1, mid, y2, l, mid, i << 1), Query(mid + 1, y1, x2, y2, mid + 1, r, i << 1 | 1));
}

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);		
		Build(1, n, 1);
		int q;
		scanf("%d", &q);
		int x1, x2, y1, y2;
		while(q--) {
			scanf("%d%d%d%d", &x1, &y1, &x2, &y2);	
			printf("%d\n", Query(x1, y1, x2, y2, 1, n, 1));
		}
	}
	return 0;
}
