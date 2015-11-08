#include <stdio.h>
#include <stdlib.h>

int main() {
	int n = 100000;
	printf("%d\n", n);
	for(int i = 1; i <= n; i++) {
		int num;
		num = rand() % 10000000;
		printf("%d ", num);
	}
	printf("\n");
	return 0;
}
