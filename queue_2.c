#include <stdio.h>
#include <stdlib.h>

int main(){
	int *queue;
	int head, rear;
	int Switch = 1;
	int flag = 0;
	while(Switch){
		printf("1 - create queue  2 - push queue  3 - pop queue  4 - get the head data  5 - get the rear data  6 - get the len of stack  0 - exit\n");
		scanf("%d", &Switch);
		if(Switch > 1 && flag == 0){
			printf("Error!\n");
			continue;
		}
		switch(Switch){
			case 1:{
					   queue = (int *)malloc(100 * sizeof(int));
					   if(queue == NULL)
						   exit(1);
					   rear = -1;
					   head = 0;
					   flag = 1;
					   break;
				   }
			case 2:{
					   int data;
					   printf("please input the data\n");
					   scanf("%d", &data);
					   queue[++rear] = data;
					   break;
				   }
			case 3:{
					   if(rear < head)
						   printf("No data!\n");
					   else
						   head++;
					   break;
				   }
			case 4:{
					   if(rear < head)
						   printf("Error!\n");
					   else
						   printf("the head data is %d\n", queue[head]);
					   break;
				   }
			case 5:{
					   if(rear < head)
						   printf("Error!\n");
					   else
						   printf("the rear data is %d\n", queue[rear]);
					   break;
				   }
			case 6:{
					   printf("the length of queue is %d\n", rear - head + 1);
					   break;
				   }
			case 0:
				   break;
		}
	}
	return 0;
}
