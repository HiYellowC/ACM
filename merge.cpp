#include <stdio.h>
#define Max 100

int min(int a, int b) {
	return a < b ? a : b;
}

void merge_array(int *array, int *new_array, int first, int last) {
	int mid = (first + last) / 2;
	int a = first;
	int b = mid + 1;
	int num = 0;
	while(a <= mid && b <= last) {
		if(array[a] < array[b])
			new_array[num++] = array[a++];
		else
			new_array[num++] = array[b++];
	}
	while(a <= mid)
		new_array[num++] = array[a++];
	while(b <= last)
		new_array[num++] = array[b++];
	int i;
	for(i = 0; i < num; i++)
		array[first + i] = new_array[i];
}

void merge_sort1(int *array, int *new_array, int first, int last) {
	if(first < last) {
		int mid = (first + last) / 2;
		merge_sort1(array, new_array, first, mid);
		merge_sort1(array, new_array, mid + 1, last);
		merge_array(array, new_array, first, last);
	}
}

void merge_sort2(int *array, int *new_array, int first, int last) {
	int i, k, j, m;
	int a, b, a_max, b_max;
	int num = 0;
	int flag = 0;
	for(i = 2; ; i *= 2) {
		if(flag)
			break;
		if(i >= (last - first + 1))
			flag = 1;
		for(k = first; k <= last; k += i) {
			a = k;
			b = k + (i - 1) / 2 + 1;
			a_max = min(k + (i - 1) / 2, last);
			b_max = min(k + i - 1, last);
			num = 0;
			while(a <= a_max && b <= b_max)
				if(array[a] < array[b])
					new_array[num++] = array[a++];
				else
					new_array[num++] = array[b++];
			while(a <= a_max)
				new_array[num++] = array[a++];
			while(b <= b_max)
				new_array[num++] = array[b++];
			for(m = 0; m < num; m++)
				array[k + m] = new_array[m];
		}
	}
}

int main() {
	int array[Max];
	int new_array[Max];
	int i, n;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &array[i]);
	merge_sort2(array, new_array, 0, n - 1);
	for(i = 0; i < n; i++)
		printf("%d ", new_array[i]);
	printf("\n");
	return 0;
}
