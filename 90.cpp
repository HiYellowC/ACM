#include <stdio.h>

int fun(int num, int Max) {
	int i;
	int res = 0;
	if(num == 0)
		return 1;
	else if(num < 0)
		return 0;
	else {
		for(i = Max; i > 0; i--) {
			res += fun(num - i, i);
		}
	}
	return res;
}

int main() {
	int total;
	int num;
	int result;
	scanf("%d", &total);
	while(total--) {
		scanf("%d", &num);
		result = fun(num, num);
		printf("%d\n", result);
	}
	return 0;
}
