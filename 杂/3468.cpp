#include <stdio.h>
#define Max 100001

long long result[Max << 2][2];
long long RES;

void build_tree(long long left, long long right, int i) {
	if(left == right) {
		scanf("%lld", &result[i][0]);
		result[i][1] = 0;
		return ;
	}
	int mid = (left + right) >> 1;
	build_tree(left, mid, i << 1);
	build_tree(mid + 1, right, i << 1 | 1);
	result[i][0] = result[i << 1][0] + result[i << 1 | 1][0];
	result[i][1] = 0;
}

void change_tree(long long left, long long right, long long tleft, long long tright, long long num, int i) {
	if(left <= tleft && right >= tright) {
		result[i][0] += (tright - tleft + 1) * num;
		result[i][1] += num;
		return ;
	}
	if(result[i][1]) {
		result[i << 1][1] += result[i][1];
		result[i << 1 | 1][1] += result[i][1];
		result[i << 1][0] += result[i][1] * ((tright - tleft + 1) - (tright - tleft + 1) / 2);
		result[i << 1 | 1][0] += result[i][1] * ((tright - tleft + 1) / 2);
		result[i][1] = 0;
	}
	long long mid = (tleft + tright) >> 1;
	if(left <= mid)
		change_tree(left, right, tleft, mid, num, i << 1);
	if(right >= mid + 1)
		change_tree(left, right, mid + 1, tright, num, i << 1 | 1);
	result[i][0] = result[i << 1][0] + result[i << 1 | 1][0];
}

void search_tree(long long left, long long right, long long tleft, long long tright, int i) {
	if(left <= tleft && right >= tright) {
		RES += result[i][0];
		return ;
	}
	if(result[i][1]) {
		result[i << 1][1] += result[i][1];
		result[i << 1 | 1][1] += result[i][1];
		result[i << 1][0] += result[i][1] * ((tright - tleft + 1) - (tright - tleft + 1) / 2);
		result[i << 1 | 1][0] += result[i][1] * ((tright - tleft + 1) / 2);
		result[i][1] = 0;
	}
	long long mid = (tleft + tright) >> 1;
	if(left <= mid)
		search_tree(left, right, tleft, mid, i << 1);
	if(right >= mid + 1)
		search_tree(left, right, mid + 1, tright, i << 1 | 1);
}

/*void fun(long long left, long long right, int i) {
	printf("l: %lld r: %lld  res0: %lld res1: %lld  i: %d\n", left, right, result[i][0], result[i][1], i);
	if(left == right)
		return ;
	int mid = (left + right) >> 1;
	fun(left, mid, i << 1);
	fun(mid + 1, right, i << 1 | 1);
}*/

int main() {
	long long N, Q;
	long long A, B, C;
	char str[2];
	scanf("%lld%lld", &N, &Q);
	build_tree(1, N, 1);
	while(Q--) {
		scanf("%s", str);
		if(str[0] == 'Q') {
//			fun(1, N, 1);
			getchar();
			RES = 0;
			scanf("%lld%lld", &A, &B);
			search_tree(A, B, 1, N, 1);
			printf("%lld\n", RES);
		}
		else {
			scanf("%lld%lld%lld", &A, &B, &C);
			change_tree(A, B, 1, N, C, 1);
		}
	}
	return 0;
}
