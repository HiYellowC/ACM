#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int bit[101];

int fun(int n, int m) {
	int sum = 0;
	while(n) {
		sum += (n % m) * (n % m);
		n /= m;
	}
	return sum;
}

int main() {
	int n, m;
	while(~scanf("%d%d", &n, &m)) {
		long long sum = 0;
		for(int i = 1; i * i <= n; i++)
			if(n % i == 0) {
				sum += fun(i, m);
				if(i * i != n) sum += fun(n / i, m);
			}
		int dex = 0;
		while(sum) {
			bit[++dex] = sum % m;
			sum /= m;
		}
		for(int i = dex; i >= 1; i--) {
			if(bit[i] >= 10) printf("%c", bit[i] - 10 + 'A');
			else printf("%d", bit[i]);
		}
		printf("\n");
	}
	return 0;
}
