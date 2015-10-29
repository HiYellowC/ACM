#include <stdio.h>
#define Max 5001

int result[Max << 2];
int number[Max];

void build_tree(int left, int right, int i) {
	result[i] = 0;
	if(left == right)
		return ;
	int mid = (left + right) >> 1;
	build_tree(left, mid, i << 1);
	build_tree(mid + 1, right, i << 1 | 1);
}

int search_tree(int left, int right, int tleft, int tright, int i) {
	if(left == tleft && right == tright)
		return result[i];
	int mid = (tleft + tright) >> 1;
	if(right <= mid)
		return search_tree(left, right, tleft, mid, i << 1);
	else if(left >= mid + 1)
		return search_tree(left, right, mid + 1, tright, i << 1 | 1);
	else
		return search_tree(left , mid, tleft, mid, i << 1) + search_tree(mid + 1, right, mid + 1, tright, i << 1 | 1);
}

void change_tree(int cur, int tleft, int tright, int i) {
	if(tleft == tright) {
		result[i]++;
		return ;
	}
	int mid = (tleft + tright) >> 1;
	if(cur <= mid)
		change_tree(cur, tleft, mid, i << 1);
	else
		change_tree(cur, mid + 1, tright, i << 1 | 1);
	result[i] = result[i << 1] + result[i << 1 | 1];
}

int main() {
	int i, n;
	while(~scanf("%d", &n)) {
		build_tree(0, n - 1, 1);
		int sum = 0;
		for(i = 0; i < n; i++) {
			scanf("%d", &number[i]);
			sum += search_tree(number[i], n - 1, 0, n - 1, 1);
			change_tree(number[i], 0, n - 1, 1);
		}
		int ans = sum;
		for(i = 0; i < n; i++) {
			sum = sum + n - 2 * number[i] - 1;
			if(sum < ans)
				ans = sum;
		}
		printf("%d\n", ans);
	}
	return 0;
}
