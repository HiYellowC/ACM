#include <stdio.h>

int array[500001];

int main() {
	int i;
	array[1] = 1;
	for(i = 2; i <= 500000; i++) {
		if(i - 1 == array[i - 1])
			array[i] = 2;
		else
			array[i] = array[i - 1] + 2;
	}
	int n;
	while(scanf("%d", &n)) {
		if(!n)
			break;
		printf("%d\n", array[n]);
	}
	return 0;
}
