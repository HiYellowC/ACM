#include <stdio.h>
#define Max 100010
#define INF 0x3f3f3f3f
int a[Max], b[Max];
int c[Max];

int find(int *a, int len, int num) {
	int left = 0;
	int right = len - 1;
	int mid;
	while(left <= right) {
		mid = (left + right) / 2;
		if(a[mid] < num)
			left = mid + 1;
		else if(a[mid] > num)
			right = mid - 1;
		else
			return mid;
	}
	return left;
}

int main() {
	int i, j, k;
	int len;
	while(~scanf("%d", &len)) {
		for(i = 1; i <= len; i++)
			b[i] = 1;
		for(i = 1; i <= len; i++)
			c[i] = INF;
		/*for(i = 1; i <= len; i++) {
			scanf("%d", &a[i]);
			for(k = i; k >= 1; k--) {
				if(a[i] > a[k] && b[i] < b[k] + 1)
					b[i] = b[k] + 1;
			}
		}*/
		for(i = 1;i <= len; i++) {
			scanf("%d", &a[i]);
			j = find(c + 1, len, a[i]) + 1;
			c[j] = a[i];
			b[i] = j;
		}
		int max = 0;
		for(i = 1; i <= len; i++)
			if(max < b[i])
				max = b[i];
		printf("%d\n", max);
	}
	return 0;
}
