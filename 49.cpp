#include <stdio.h>
#include <string.h>
#define Max 30010

int result[Max];

inline int max(int a, int b) {
	return a > b ? a : b;
}

int main() {
	int total;
	int n, m, i, k;
	int value, lv;
	scanf("%d", &total);
	while(total--) {
		scanf("%d%d", &n, &m);
		memset(result, 0, sizeof(result));
		for(i = 1; i <= m; i++) {
			scanf("%d%d", &value, &lv);
			for(k = n; k >= value; k--)
				result[k] = max(result[k], result[k - value] + value * lv);
		}
		printf("%d\n", result[n]);
	}
	return 0;
}
