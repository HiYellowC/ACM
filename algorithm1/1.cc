#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100010;

int array[MAXN];

void MergeArray(int *begin, int *end, int *mid) {
	int newarray[end - begin + 5];
	int len = end - begin;
	int *left = begin;
	int *right = mid;
	int *it = newarray;
	while(left < mid && right < end) {
		if(*left < *right) *(it++) = *(left++);
		else *(it++) = *(right++);
	}
	while(left < mid) *(it++) = *(left++);
	while(right < end) *(it++) = *(right++);
	it = newarray;
	while(begin < end) *(begin++) = *(it++);
}

void MergeSort1(int *begin, int *end) {
	int len = end - begin;
	if(len > 1) {
		int mid = len / 2;
		MergeSort1(begin, begin + mid);
		MergeSort1(begin + mid, end);
		MergeArray(begin, end, begin + len / 2);
	}
}

void MergeSort2(int *begin, int *end) {
	int len = end - begin;
	for(int i = 2; i / 2 <= len; i *= 2) {
		int *it = begin;
		while(it + (i / 2) < end) {
			MergeArray(it, min(it + i, end), it + (i / 2));
			it += i;
		}
	}
}	

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &array[i]);
	clock_t start, end;
	start = clock();
	MergeSort1(array + 1, array + 1 + n);
	end = clock();
	printf("100000数据量测试\n");
	printf("递归归并:%lfs\n", (double)(end - start) / (double)CLOCKS_PER_SEC);
	start = clock();
	MergeSort2(array + 1, array + 1 + n);
	end = clock();
	printf("非递归归并:%lfs\n", (double)(end - start) / (double)CLOCKS_PER_SEC);
	//for(int i = 1; i <= n; i++) printf("%d ", array[i]);
	return 0;
}
