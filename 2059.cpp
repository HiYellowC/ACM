#include <stdio.h>

int get_gcd(int a, int b) {
	return b == 0 ? a : get_gcd(b, a % b);
}

int main() {
	int a, b;
	int l, r;
	int n, num;
	int i, gcd;
	int res;
	while(~scanf("%d%d", &a, &b)) {
		gcd = get_gcd(a, b);
		scanf("%d", &n);
		while(n--) {
			scanf("%d%d", &l, &r);
			num = r < gcd ? r : gcd;
			res = -1;
			for(i = num; i >= l; i--) {
				if(a % i == 0 && b % i == 0) {
					res = i;
					break;
				}
			}
			printf("%d\n", res);
		}
	}
	return 0;
}
