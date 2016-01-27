#include <stdio.h>
#include <string.h>

char str[10001];
char c[10001];
int res[10001];

int find(char *a, int len, char ch) {
	int left = 0;
	int right = len;
	int mid;
	while(left <= right) {
		mid = (left + right) / 2;
		if(a[mid] < ch)
			left = mid + 1;
		else if(a[mid] > ch)
			right = mid - 1;
		else
			return mid;
	}
	return left;
}

int main() {
	int total;
	int len;
	int Max;
	int i, j, k;
	scanf("%d", &total);
	while(total--) {
		scanf("%s", str);
		len = strlen(str);
		for(i = 0; i < len; i++)
			res[i] = 1;
		for(i = 1; i <= len; i++)
			c[i] = 'z' + 1;
		for(i = 0; i < len; i++) {
			j = find(c, i + 1, str[i]);
			c[j] = str[i];
			res[i] = j;
		}
		Max = 1;
		for(i = 0; i < len; i++)
			if(Max < res[i])
				Max = res[i];
		printf("%d\n", Max);
	}
	return 0;
}
