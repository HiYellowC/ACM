#include <stdio.h>
#define Max 100

int get_prvot(int a, int b) {
	return (a + b) / 2;
}

void q_sort(int left, int right, int *array) {
	if(left >= right)
		return ;
	int a = left;
	int b = right;
	int prvot = array[right];
	while(left < right) {
		while(array[left] <= prvot && left < right)
			left++;
		if(left < right)
			array[right] = array[left];
		while(array[right] >= prvot && left < right)
			right--;
		if(left < right)
			array[left] = array[right];
	}
	array[left] = prvot;
	q_sort(a, left - 1, array);
	q_sort(left + 1, b, array);
}

int main() {
	int array[Max];
	int i, n;
	scanf("%d", &n);
	for(i = 1; i <= n; i++)
		scanf("%d", &array[i]);
	q_sort(1, n, array);
	for(i = 1; i <= n; i++)
		printf("%d ", array[i]);
	printf("\n");
	return 0;
}
