#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
	int m;
	m = 100;
	printf("%d\n", m);
	srand(time(NULL));
	for(int i = 1; i <= m; i++) {
		int op = rand() % 2;
		if(op == 0) {
			printf("I ");
			int a, b, c;
			a = rand() % 101 + 100;
			b = rand() % 101;
			c = rand() % 101;
			printf("%d %d %d\n", a, b, c);
		}
		else {
			printf("Q ");
		}

	}
	return 0;
}
