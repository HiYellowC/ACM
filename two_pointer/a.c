#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	int p;
	p = 1000000;
	srand(time(NULL));
	printf("%d\n", p);
	for(int i = 1; i <= p; i++)
		printf("%d ", rand() % 1000000);
	printf("\n");
	return 0;
}
