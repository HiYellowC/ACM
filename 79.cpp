#include <stdio.h>
#define Max 21

int array[Max];
int result[Max];

int main() {
	int total;
	int m;
	int i, k;
	int max;
	scanf("%d", &total);
	while(total--) {
		scanf("%d", &m);
		for(i = 0; i < m; i++) {
			scanf("%d", &array[i]);
			result[i] = 1;
		}
		for(i = 1; i < m; i++)
			for(k = 0; k < i; k++)
				if(array[i] < array[k] && result[i] < result[k] + 1)
					result[i] = result[k] + 1;
		max = 0;
		for(i = 0; i < m; i++)
			if(max < result[i])
				max = result[i];
		printf("%d\n", max);
	}
	return 0;
}
