#include <stdio.h>
#include <string.h>

int array[300010 << 2];

void change_tree(int left, int right, int tleft, int tright, int xi, int i) {
	if(left <= tleft && right >= tright) {
		if(!array[i])
			array[i] = xi;
		return ;
	}
	if(array[i]) {
		if(!array[i << 1])
			array[i << 1] = array[i];
		if(!array[i << 1 | 1])
			array[i << 1 | 1] = array[i];
		array[i] = 0;
	}
	int mid = (tleft + tright) >> 1;
	if(left <= mid)
		change_tree(left, right, tleft, mid, xi, i << 1);
	if(right >= mid + 1)
		change_tree(left, right, mid + 1, tright, xi, i << 1 | 1);
}

void search_tree(int tleft, int tright, int i) {
	if(tleft == tright) {
		printf("%d ", array[i]);
		return ;
	}
	if(array[i]) {
		if(!array[i << 1])
			array[i << 1] = array[i];
		if(!array[i << 1 | 1])
			array[i << 1 | 1] = array[i];
		array[i] = 0;
	}
	int mid = (tleft + tright) >> 1;
	search_tree(tleft, mid, i << 1);
	search_tree(mid + 1, tright, i << 1 | 1);
}

int main() {
	int n, m;
	int i, l, r, xi;
	while(~scanf("%d%d", &n, &m)) {
		memset(array, 0, sizeof(array));
		while(m--) {
			scanf("%d%d%d", &l, &r, &xi);
			if(r > n)
				r = n;
			if(l > n)
				continue;
			if(l <= xi - 1)
				change_tree(l, xi - 1, 1, n, xi, 1);
			if(xi + 1 <= r)
				change_tree(xi + 1, r, 1, n, xi, 1);
		}
		search_tree(1, n, 1);
		printf("\n");
	}
	return 0;
}
