#include <stdio.h>
#include <string.h>

int a[35][35];

void Init() {
	memset(a, 0, sizeof(a));
	for(int i = 1; i <= 30; i++) {
		scanf("%d", &a[i][31]);
		a[i][i] = 1;
		if(i % 6 != 1)
			a[i][i - 1] = 1;
		if(i % 6 != 0)
			a[i][i + 1] = 1;
		if(i > 6)
			a[i][i - 6] = 1;
		if(i < 25)
			a[i][i + 6] = 1;
	}
}

void gauss() {
	int i, j, k;
	for(i = 1; i <= 30; i++) {
		for(k = i; k <= 30; k++)
			if(a[k][i])
				break;
		if(k != i)
			for(j = 1; j <= 31; j++) {
				int temp;
				temp = a[k][j];
				a[k][j] = a[i][j];
				a[i][j] = temp;
			}
		for(k = 1; k <= 30; k++)
			if(k != i && a[k][i])
				for(j = 1; j <= 31; j++)
					a[k][j] ^= a[i][j];
	}
}

int main() {
	int t, cur = 0;
	scanf("%d", &t);
	while(t--) {
		Init();
		/*for(int i = 1; i <= 30; i++) {
			for(int k = 1; k <= 31; k++)
				printf("%d ", a[i][k]);
			printf("\n");
		}*/
		gauss();
		printf("PUZZLE #%d\n", ++cur);
		for(int i = 1; i <= 30; i++) {
			printf("%d", a[i][31]);
			if(i % 6)
				printf(" ");
			else
				printf("\n");
		}
	}
	return 0;
}
