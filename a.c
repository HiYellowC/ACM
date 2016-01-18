#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	srand(time(NULL));
	int t = 5;
	int n;
	while(t--) {
		if(t == 0) n = 1000;	
		else n = rand() % 1000 + 1;
		printf("%d\n", n);
		for(int i = 1; i <= n; i++) {
			int num = rand() % 0x7fffffff + 1;	
			printf("%d%c", num, " \n"[i == n]);
		}
	}
	return 0;
}
