#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int data;
	struct Node *next;
}node, *pnode;

typedef struct Queue{
	pnode head;
	pnode rear;
	int Len;
}queue, *pqueue;

pnode create_node(int data){
	pnode New = (pnode)malloc(sizeof(node));
	if(New == NULL)
		exit(1);
	New->data = data;
	New->next = NULL;
	return New;
}

pqueue create_queue(){
	pqueue New = (pqueue)malloc(sizeof(queue));
	if(New == NULL)
		exit(1);
	New->head = NULL;
	New->rear = NULL;
	New->Len = 0;
	return New;
}

void push_queue(int data, pqueue q){
	pnode New = create_node(data);
	if(q->head == NULL && q->rear == NULL){
		q->head = New;
		q->rear = New;
	}
	else{
		q->rear->next = New;
		q->rear = New;
	}
	q->Len++;
}

void pop_queue(pqueue q){
	if(q->head == NULL && q->rear == NULL)
		printf("No data!\n");
	else if(q->head == q->rear){
		free(q->head);
		q->head = NULL;
		q->rear = NULL;
		q->Len--;
	}
	else{
		pnode del = q->head;
		q->head = del->next;
		free(del);
		q->Len--;
	}
}

int get_head(pqueue q){
	return q->head->data;
}

int get_rear(pqueue q){
	return q->rear->data;
}

int get_len(pqueue q){
	return q->Len;
}

int main(){
	pqueue q;
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
					   q = create_queue();
					   flag = 1;
					   break;
				   }
			case 2:{
					   int data;
					   printf("please input the data\n");
					   scanf("%d", &data);
					   push_queue(data, q);
					   break;
				   }
			case 3:{
					   pop_queue(q);
					   break;
				   }
			case 4:{
					   if(q->head == NULL)
						   printf("Error!\n");
					   else{
						   int num;
						   num = q->head->data;
						   printf("the head data is %d\n", num);
					   }
					   break;
				   }
			case 5:{
					   if(q->rear == NULL)
						   printf("Error!\n");
					   else{
						   int num;
						   num = q->rear->data;
						   printf("the rear data is %d\n", num);
					   }
					   break;
				   }
			case 6:{
					   int num;
					   num = q->Len;
					   printf("the len of queue is %d\n", num);
					   break;
				   }
			case 0:
				   break;
		}
	}
	return 0;
}

