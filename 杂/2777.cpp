#include <stdio.h>
#define Max 100001

int result[Max << 2][2];
int num;

void build_tree(int left, int right, int i) {
	result[i][0] = 1;
	result[i][1] = 0;
	if(left == right)
		return ;
	int mid = (left + right) >> 1;
	build_tree(left, mid, i << 1);
	build_tree(mid + 1, right, i << 1 | 1);
}

void change_tree(int left, int right, int tleft, int tright, int col, int i) {
	if(left == tleft && right == tright) {
		result[i][0] = 1 << (col - 1);
		result[i][1] = col;
		return ;
	}
	if(result[i][1]) {
		result[i << 1][1] = result[i << 1 | 1][1] = result[i][1];
		result[i << 1][0] = 1 << (result[i << 1][1] - 1);
		result[i << 1 | 1][0] = 1 << (result[i << 1 | 1][1] - 1);
		result[i][1] = 0;
	}
	int mid = (tleft + tright) >> 1;
	if(right <= mid)
		change_tree(left, right, tleft, mid, col, i << 1);
	else if(left >= mid + 1)
		change_tree(left, right, mid + 1, tright, col, i << 1 | 1);
	else {
		change_tree(left, mid, tleft, mid, col, i << 1);
		change_tree(mid + 1, right, mid + 1, tright, col, i << 1 | 1);
	}
	result[i][0] = result[i << 1][0] | result[i << 1 | 1][0];
}

void search_tree(int left, int right, int tleft, int tright, int i) {
	if(left == tleft && right == tright) {
		num = num | result[i][0];
		return ;
	}
	if(result[i][1]) {
		result[i << 1][1] = result[i << 1 | 1][1] = result[i][1];
		result[i << 1][0] = result[i][0];
		result[i << 1 | 1][0] = result[i][0];
		result[i][1] = 0;
	}
	int mid = (tleft + tright) >> 1;
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
	int i;
	int RES;
	int L, T, O;
	int A, B, C;
	char str[5];
	scanf("%d%d%d", &L, &T, &O);
	build_tree(1, L, 1);
	while(O--) {
		scanf("%s", str);
		if(str[0] == 'C') {
			scanf("%d%d%d", &A, &B, &C);
			if (A <= B)
				change_tree(A, B, 1, L, C, 1);
			else
				change_tree(B, A, 1, L, C, 1);
		}
		else {
			scanf("%d%d", &A, &B);
			RES = num = 0;
			if (A <= B)
				search_tree(A, B, 1, L, 1);
			else 
				search_tree(B, A, 1, L, 1);
			for(i = 0; i < T; i++) {
				if(num & 1)
					RES++;
				num >>= 1;
			}
			printf("%d\n", RES);
		}
	}
	return 0;
}
