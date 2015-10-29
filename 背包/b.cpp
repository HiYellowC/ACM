#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

int a[25];
int n, ans, sum;

void fun(int x, int begin) {
	if(x > sum / 2)
		return ;
	for(int i = begin; i <= n; i++) {
		if(x + a[i] > ans && x + a[i] <= sum / 2)
			ans = x + a[i];
		fun(x + a[i], i + 1);
	}
}

int main() {
	while(~scanf("%d", &n)) {
		sum = ans = 0;
		for(int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			sum += a[i];
		}
		fun(0, 1);
		printf("%d\n", sum - 2 * ans);
	}
	return 0;
}
