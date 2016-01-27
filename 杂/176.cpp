#include <stdio.h>

int res[501][10];

int fun(int m, int n) {
	if(n == 1)
		return m;
	else if(m == n)
		return 1;
	else
		return fun(m - 1, n) + fun(m - 1, n - 1);
}

int fun2(int k, int s) {
	if(res[k][s])
		return res[k][s];
	if(k == 1 || s == 1 || k == 0)
		return 1;
	if(k == s)
		return res[k][s] = 1 + fun2(k, s - 1);
	if(k < s)
		return res[k][s] = fun2(k, k);
	if(k > s)
		return res[k][s] = fun2(k - s, s) + fun2(k, s - 1);
}

int fun3(int n, int k) {
	if(n < k)
		return 0;
	else if(k == 1 || k == n)
		return 1;
	else
		return fun3(n - k, k) + fun3(n - 1, k - 1);
}

void fun4() {
	int i, j;
	for(i = 1; i <= 500; i++)
		res[i][1] = 1;
	for(i = 1; i <= 6; i++)
		res[i][i] = 1;
	for(i = 3; i <= 500; i++)
		for(j = 2; j <= i && j <= 6; j++)
			res[i][j] = res[i - j][j] + res[i - 1][j - 1];
}

int main() {
	int m, n;
	fun4();
	while(~scanf("%d%d", &m, &n)) {
		printf("%d\n", fun(m, n));
	}
	return 0;
}
