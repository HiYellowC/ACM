#include <stdio.h>
#define INF 0x80000000

int array[101][101];

int main() {
	int total;
	int i, k, j, r, c;
	int RES, max, sum;
	scanf("%d", &total);
	while(total--) {
		scanf("%d%d", &r, &c);
		for(i = 1; i <= r; i++)
			for(k = 1; k <= c; k++) {
				scanf("%d", &array[i][k]);
				array[i][k] += array[i - 1][k];
			}
		RES = INF;
		for(i = 1; i <= r; i++)
			for(k = i; k <= r; k++) {
				for(j = 1, sum = 0, max = INF; j <= c; j++) {
					sum += (array[k][j] - array[i - 1][j]);
					if(sum > max)
						max = sum;
					if(sum < 0)
						sum = 0;
				}
				if(max > RES)
					RES = max;
			}
		printf("%d\n", RES);
	}
	return 0;
}
