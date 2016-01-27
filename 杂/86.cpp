#include <iostream>
#include <cstdio>
#include <algorithm>
#define Max 1000001
using namespace std;

int array[Max];

bool cmp(int a, int b) {
	return a < b;
}

bool fun(int num, int n) {
	int left, right, mid;
	left = 0;
	right = n - 1;
	while(left <= right) {
		mid = (left + right) / 2;
		if(array[mid] < num)
			left = mid + 1;
		else if(array[mid] > num)
			right = mid - 1;
		else
			return 1;
	}
	return 0;
}

int main() {
	int i, m, n, num;
	scanf("%d%d", &m, &n);
	for(i = 0; i < m; i++)
		scanf("%d", &array[i]);
	sort(array, array + m, cmp);
	while(n--) {
		scanf("%d", &num);
		if(fun(num, m))
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
