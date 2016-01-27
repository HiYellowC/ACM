#include <stdio.h>
#include <string.h>
#define Max 100001

typedef struct Node {
	int number;
	int col;
}node;

node n[Max * 4];
int result;

void build_tree(int left, int right, int i) {
	if(left == right) {
		n[i].number = 1;
		n[i].col = 0;
		return ;
	}
	int mid = (left + right) / 2;
	build_tree(left, mid, i << 1);
	build_tree(mid + 1, right, i << 1 | 1);
	n[i].number = n[i << 1].number + n[i << 1 | 1].number;
	n[i].col = 0;
}

void change_tree(int left, int right, int c, int tleft, int tright, int i) {
	if(left <= tleft && right >= tright) {
		n[i].col = c;
		n[i].number = c * (tright - tleft + 1);
		return ;
	}
	if(n[i].col) {
		n[i << 1].col = n[i << 1 | 1].col = n[i].col;
		int len = tright - tleft + 1;
		n[i << 1].number = (len - (len >> 1)) * n[i].col;
		n[i << 1 | 1].number = (len >> 1) * n[i].col;
		n[i].col = 0;
	}
	int mid = (tleft + tright) / 2;
	if(left <= mid)
		change_tree(left, right, c, tleft, mid, i << 1);
	if(right >= mid + 1)
		change_tree(left, right, c, mid + 1, tright, i << 1 | 1);
	n[i].number = n[i << 1].number + n[i << 1 | 1].number;
}

/*void search_tree(int left, int right, int tleft, int tright, int i) {
	if(left == tleft && right == tright) {
		if(result < n[i].number)
			result = n[i].number;
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
}*/

/*void change1_tree(int tleft, int tright, int cur, int num, int i) {
	if(tleft == tright) {
		n[i].number = num;
		return ;
	}
	int mid = (tleft + tright) / 2;
	if(cur <= mid)
		change1_tree(tleft, mid, cur, num, i << 1);
	else
		change1_tree(mid + 1, tright, cur, num, i << 1 | 1);
	n[i].number = get_max(n[i << 1].number, n[i << 1 | 1].number);
}*/



int main() {
	int total;
	int cur = 1;
	int N, Q;
	int x, y, z;
	scanf("%d", &total);
	while(total--) {
		scanf("%d%d", &N, &Q);
		build_tree(1, N, 1);
		while(Q--) {
			 scanf("%d%d%d", &x, &y, &z);
			 change_tree(x, y, z, 1, N, 1);
		}
		printf("Case %d: The total value of the hook is %d.\n", cur++, n[1].number);
	}
	return 0;
}
