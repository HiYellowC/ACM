#include <stdio.h>
#define Max 1000000

int array[Max];
int result[Max];

int main() {
	int i;
	int N, M;
	int start, end;
	scanf("%d%d", &N, &M);
	for(i = 1; i <= N; i++) {
		scanf("%d", &array[i]);
		result[i] = result[i - 1] + array[i];
	}
	while(M--) {
		scanf("%d%d", &start, &end);
		printf("%d\n", result[end] - result[start - 1]);
	}
	return 0;
}
