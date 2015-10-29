#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	srand(time(NULL));
	int n = 1001;
	int m = 500;
	printf("%d %d\n", n, m);
	for(int i = 1; i <= n; i++) {
		int a = rand() % 10001;
		int b = rand() % 10001;
		printf("%d %d\n", a, b);
	}
	for(int i = 1; i <= 10000; i++) {
		int flag = rand() % 2;
		int a = rand() % n + 1;
		int b = rand() % n + 1;
		if(flag) printf("O %d\n", a);	
		else printf("S %d %d\n", a, b);
	}
	return 0;
}
