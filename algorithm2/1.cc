#include <bits/stdc++.h>
using namespace std;

const int MAXN = 500;

int a[MAXN][MAXN];

int pow(int n, int k) {
	int ans = 1;
	while(k) {
		if(k & 1) ans *= n;
		k >>= 1;
		n = n * n;
	}
	return ans;
}

void fun(int n) {
	if(n == 1) {
		a[n][n] = 1;
		return ;
	}
	fun(n / 2);
	for(int i = 1; i <= n / 2; i++)
		for(int k = 1; k <= n / 2; k++)
			a[n / 2 + i][n / 2 + k] = a[i][k], a[n / 2 + i][k] = a[i][n / 2 + k] = a[i][k] + n / 2;

}

void show(int n) {
	for(int i = 1; i <= n; i++) {
		for(int k = 1; k <= n; k++)
			printf("%d ", a[i][k]);
		printf("\n");
	}
}

int main() {
	int n, k;
	scanf("%d", &k);
	n = pow(2, k);
	fun(n);
	show(n);
	return 0;
}
