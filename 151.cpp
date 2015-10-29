#include <stdio.h>

int main() {
	// 23 28  33
	int a, b, c, d;
	int result;
	int cur = 1;
	while(scanf("%d%d%d%d", &a, &b, &c, &d)) {
		if(a + b + c + d == -4)
			break;
		a %= 23;
		b %= 28;
		c %= 33;
		result = (5544 * a + 14421 * b + 1288 * c) % 21252;
		printf("Case %d: the next triple peak occurs in ", cur++);
		while(result <= d)
			result += 21252;
		printf("%d", result - d);
		printf(" days.\n");
	}
	return 0;
}
