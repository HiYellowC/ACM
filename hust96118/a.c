#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
	srand(time(NULL));
	int n = 10;
	for(int i = 1; i <= 10; i++) {
		int num = rand() % 2;
		if(num) printf("T");
		else printf("F");
	}
	printf("\n%d\n", rand() % 10 + 1);
	return 0;
}
