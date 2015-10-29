#include <stdio.h>
#include <stdlib.h>

int main(){
	int *stack;
	int top;
	int Switch = 1;
	int flag = 0;
	while(Switch){
		printf("1 - create stack  2 - push stack  3 - pop stack  4 - get the top data  5 - get the len of stack  0 - exit\n");
		scanf("%d", &Switch);
		if(Switch > 1 && flag == 0){
			printf("Error!\n");
			continue;
		}
		switch(Switch){
			case 1:{
					   stack = (int *)malloc(100 * sizeof(int));
					   if(stack == NULL)
						   exit(1);
					   top = -1;
					   flag = 1;
					   break;
				   }
			case 2:{
					   printf("please input the data\n");
					   int data;
					   scanf("%d", &data);
					   stack[++top] = data;
					   break;
				   }
			case 3:{
					   if(top < 0)
						   printf("No data!\n");
					   else
						   top--;
					   break;
				   }
			case 4:{
					   if(top < 0)
						   printf("Error!\n");
					   else
						   printf("the top data is %d\n", stack[top]);
					   break;
				   }
			case 5:{
					   printf("the len of stack is %d\n", top + 1);
					   break;
				   }
			case 0:
				   break;
		}
	}
	return 0;
}
