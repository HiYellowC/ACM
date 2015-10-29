#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	int t = 14;
	while(t--) {
		srand(time(NULL));
		printf("%d\n", 499999);
		for(int i = 1; i < 250000; i++) {
			int num = rand() % 1000000;
			int flag = rand() % 2;
			if(flag) num *= -1;
			printf("%d %d ", num, num);
		}
		printf("1000000\n");
	}
	return 0;
}
