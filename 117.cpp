#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
#define Max 1000001

struct node {
	int val, cur;
};

node n[Max];
int result[Max];

bool cmp(const node a, const node b) {
	if(a.val != b.val)
		return a.val < b.val;
	else
		return a.cur < b.cur;
}

/*int search_tree(int left, int right, int tleft, int tright, int i) {
	if(left <= tleft && right >= tright)
		return result[i];
	int sum = 0;
	int mid = (tleft + tright) >> 1;
	if(left <= mid)
		sum += search_tree(left, right, tleft, mid, i << 1);
	if(right >= mid + 1)
		sum += search_tree(left, right, mid + 1, tright, i << 1 | 1);
	return sum;
}*/

/*void change_tree(int num, int tleft, int tright, int i) {
	if(tleft == tright) {
		result[i] = 1;
		return ;
	}
	int mid = (tleft + tright) >> 1;
	if(num <= mid)
		change_tree(num, tleft, mid, i << 1);
	else
		change_tree(num, mid + 1, tright, i << 1 | 1);
	result[i] = result[i << 1] + result[i << 1 | 1];
}*/

/*int search(int n) {
	int sum = 0;
	while(n) {
		sum += result[n];
		n -= (n & (-n));
	}
	return sum;
}

void change(int n) {
	while(n < Max) {
		result[n] += 1;
		n += (n & (-n));
	}
}*/

void merge_array(int left, int right, int *array, int *new_array) {
	int i, a, b, mid, con;
	a = left;
	b = right;
	con = 1;
	mid = (a + b) >> 1;
	while(a <= mid && b <= left) {
		if(array[a] < array[b])
			new_array[con++] = array[a++];
		else
			new_array[con++] = array[b++];
	}
	while(a <= mid)
		new_array[con++] = array[a++];
	while(b <= left)
		new_array[con++] = array[b++];
	for(i = 1; i < con; i++)
		array[left + i - 1] = new_array[i]; 
}

void merge_sort(int left, int right, int *array, int *new_array) {
	if(left == right)
		return ;
	else {
		int mid = (left + right) >> 1;
		merge_sort(left, mid);
		merge_sort(mid + 1, right);
		merge_array(left, right, array, new_array);
	}
}

int main() {
	int total;
	int i, N;
	long long RES;
	scanf("%d", &total);
	while(total--) {
		scanf("%d", &N);
		RES = 0;
		for(i = 1; i <= N; i++) {
			scanf("%d", &n[i].val);
			n[i].cur = i;
		}
		sort(n + 1, n + N + 1, cmp);
		for(i = 1; i <= N; i++) {
			RES += (search(N) - search(n[i].cur));
			change(n[i].cur);
		}
		memset(result, 0, sizeof(result));
		printf("%lld\n", RES);
	}
	return 0;
}
