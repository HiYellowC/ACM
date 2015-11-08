#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	srand(time(NULL));
	int t = 1;
	int n = 10;
	printf("%d %d\n", t, n);
	for(int i = 1; i <= n; i++) {
		printf("%d ", rand() % 2);	
	}
	printf("\n");
	int q = 100;
	printf("%d\n", q);
	while(q--) {
		int l, r;
		l = rand() % n + 1;
		r = rand() % n + 1;
		if(l > r) {
			int temp = l;
			l = r;
			r = temp;
		}
		printf("%d %d\n", l, r);
	}
	return 0;
}
