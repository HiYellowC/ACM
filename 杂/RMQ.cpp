#include <stdio.h>
#include <math.h>

inline int max(int a, int b) {
	return a > b ? a : b;
}

int Array[10] = {3, 2, 4, 5, 6, 8, 1, 2, 9, 7};
int f[10][5];

int main() {
	for(int i = 0; i < 10; i++) 
		f[i][0] = Array[i];
	for(int i = 1; i <= (int)(log(10) / log(2)); i++)
		for(int k = 0; k <= 10 - (int)pow(2, i); k++)
			f[k][i] = max(f[k][i - 1], f[k + (int)pow(2, i - 1)][i - 1]);
	while(1) {
		int a, b;
		scanf("%d%d", &a, &b);
		int s = (int)(log(b - a + 1) / log(2));
		printf("%d", max(f[a][s], f[b - (int)pow(2, s) + 1][s]));
	}
	return 0;
}
