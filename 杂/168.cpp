#include <stdio.h>
#include <string.h>
#define Max 200

int room[Max];

int main() {
	int total;
	int num;
	int i, k, a, b, c;
	int max;
	scanf("%d", &total);
	while(total--) {
		memset(room, 0, sizeof(room));
		scanf("%d", &num);
		for(i = 0; i < num; i++) {
			scanf("%d%d%d", &a, &b, &c);
			for(k = b; k < b + c; k++)
				room[k] += a;
		}
		max = 0;
		for(i = 0; i < Max; i++)
			if(room[i] > max)
				max = room[i];
		printf("%d\n", max);
	}
	return 0;
}
