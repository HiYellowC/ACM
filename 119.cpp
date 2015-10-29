#include <stdio.h>
#define Max 100001
#define INF 0x7f7f7f7f
int MAX, MIN;	

typedef struct Node {
	int nmax, nmin;
}node;

node n[Max << 2];

inline int max(int a, int b) {
	return a > b ? a : b;
}

inline int min(int a, int b) {
	return a < b ? a : b;
}

void build_tree(int left, int right, int i) {
	if(left == right) {
		int val;
		scanf("%d", &val);
		n[i].nmax = n[i].nmin = val;
		return ;
	}
	int mid = (left + right) / 2;
	build_tree(left, mid, i << 1);
	build_tree(mid + 1, right, i << 1 | 1);
	n[i].nmax = max(n[i << 1].nmax, n[i << 1 | 1].nmax);
	n[i].nmin = min(n[i << 1].nmin, n[i << 1 | 1].nmin);
}

void search_tree(int left, int right, int tleft, int tright, int i) {
	if(left == tleft && right == tright) {
		if(MAX < n[i].nmax)
			MAX = n[i].nmax;
		if(MIN > n[i].nmin)
			MIN = n[i].nmin;
		return ;
	}
	int mid = (tleft + tright) / 2;
	if(right <= mid)
		search_tree(left, right, tleft, mid, i << 1);
	else if(left >= mid + 1)
		search_tree(left, right, mid + 1, tright, i << 1 | 1);
	else {
		search_tree(left, mid, tleft, mid, i << 1);
		search_tree(mid + 1, right, mid + 1, tright, i << 1 | 1);
	}
}

int main() {
	int N, Q;
	int left, right;
	scanf("%d%d", &N, &Q);
	build_tree(1, N, 1);
	while(Q--) {
		scanf("%d%d", &left, &right);
		MAX = 0, MIN = INF;
		search_tree(left, right, 1, N, 1);
		printf("%d\n", MAX - MIN);
	}
	return 0;
}
