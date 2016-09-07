#include <stdio.h>

int heap_size;

void max_heapify(int *array, int i){
	int left = i * 2;
	int right = i * 2 + 1;
	int large;
	if(left <= heap_size && array[i] < array[left])
		large = left;
	else
		large = i;
	if(right <= heap_size && array[large] < array[right])
		large = right;
	if(large != i){
		int temp;
		temp = array[i];
		array[i] = array[large];
		array[large] = temp;
		max_heapify(array, large);
	}
}


void build_max_heap(int *array){
	int i;
	for(i = heap_size / 2; i >= 1; i--)
		max_heapify(array, i);
}

void heap_sort(int *array){
	build_max_heap(array);
	int i;
	for(i = heap_size; i > 1; i--){
		int temp;
		temp = array[1];
		array[1] = array[heap_size];
		array[heap_size] = temp;
		heap_size--;
		max_heapify(array, 1);
	}
}

int main(){
	int array[100];
	int n;
	scanf("%d", &n);
	heap_size = n;
	int i;
	for(i = 1; i <= n; i++)
		scanf("%d", &array[i]);
	heap_sort(array);
	for(i = 1; i <= n; i++)
		printf("%d ", array[i]);
	printf("\n");
	return 0;
}
