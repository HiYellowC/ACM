#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1010;

int a[2][MAXN];

int main() {
	int n, num;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= i; j++) {
			scanf("%d", &num);
			a[i & 1][j] = max(num + a[!(i & 1)][j], num + a[!(i & 1)][j - 1]);
		}
	int MAX = 0x80000000;
	for(int i = 1; i <= n; i++) MAX = max(a[n & 1][i], MAX);
	printf("%d", MAX);
	return 0;
}
