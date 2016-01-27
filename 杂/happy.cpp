#include <stdio.h>

long long gcd(long long a, long long b) {
	return b == 0 ? a : gcd(b, a % b);
}

/*int is_prim(int n) {
	int i;
	int flag = 1;
	for(i = 2; i * i <= n; i++) {
		if(n % i == 0) {
			flag = 0;
			break;
		}
	}
	return flag;
}*/

int eular(int n) {
	int i;
	long long result = 1;
	long long sum = n;
	long long s = n;
	for(i = 2; i <= s; i++) {
		if(n % i == 0) {
			result *= i;
			sum *= (i - 1);
			while(n % i == 0) {
				n /= i;
			}
		}
		if(n == 1)
			break;
	}
	return sum / result;
}

int main() {
	int m, k;
	int i;
	int total;
	while(~scanf("%d%d", &m, &k)) {
		if(m == 1)
			printf("%d\n", k);
		else {
			long long res = eular(m);
			long long cur = k / res;
			if(k % res == 0)
				cur--;
			k = k - cur * res;
			cur = cur * m + 1;
			long long i;
			long long temp;
			for(i = cur; k != 0; i++) {
				if(gcd(i, m) == 1) {
					temp = i;
					--k;
				}
			}
			printf("%lld\n", temp);
		}
	}
}
