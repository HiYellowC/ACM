#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	srand(time(NULL));
	int n = 100000;
	int m = 10000;
	printf("%d %d\n", n, m);
	for(int i = 1; i <= m; i++) {
		int d = rand() % 3 + 1;
		int x = rand() % n + 1;
		int y = rand() % n + 1;
		if(d == 3)
			printf("%d %d\n", d, x);
		else 
			printf("%d %d %d\n", d, x, y);
	}
	return 0;
}
