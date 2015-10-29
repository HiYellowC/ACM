#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	srand(time(NULL));
	int t = 20;
	while(true) {
	t--;
	if(t == 0) {
		printf("0\n");
		break;
	}
	int n = rand() % 100 + 1;
	printf("%d\n", n);
	for(int i = 1; i <= n; i++) {
		int num;
		num = rand() % 1001;
		printf("%d ", num);
	}
	printf("\n");
	}
	return 0;
}
