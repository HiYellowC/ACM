#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int data;
	struct Node *next;
}node, *pnode;

typedef struct Stack{
	pnode top;
	int Len;
}stack, *pstack;

pnode create_node(int data){
	pnode New = (pnode)malloc(sizeof(node));
	if(New == NULL)
		exit(1);
	New->data = data;
	New->next = NULL;
	return New;
}

pstack create_stack(){
	pstack New = (pstack)malloc(sizeof(stack));
	if(New == NULL)
		exit(1);
	New->top = NULL;
	New->Len = 0;
	return New;
}

void push_stack(int data, pstack s){
	pnode New = create_node(data);
	New->next = s->top;
	s->top = New;
	s->Len++;
}

void pop_stack(pstack s){
	if(s->top == NULL)
		printf("No data!\n");
	else{
		pnode del = s->top;
		s->top = s->top->next;
		free(del);
		s->Len--;
	}
}

int get_top(pstack s){
	return s->top->data;
}

int get_len(pstack s){
	return s->Len;
}

int main(){
	int Switch = 1;
	pstack s;
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
						s = create_stack();
						flag = 1;
						break;
				   }
			case 2:{
						int data;
						printf("please input the data\n");
						scanf("%d", &data);
						push_stack(data, s);
						break;
				   }
			case 3:{
					   pop_stack(s);
					   break;
				   }
			case 4:{
					   if(s->Len == 0){
						   printf("Error!\n");
						   break;
					   }
					   int top;
					   top = get_top(s);
					   printf("the top data is %d\n", top);
					   break;
				   }
			case 5:{
					   int Len;
					   Len = get_len(s);
					   printf("the len of stack is %d\n", Len);
					   break;
				   }
			case 0:
				   break;
		}
	}
	return 0;
}
