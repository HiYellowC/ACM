#include <stdio.h>
#include <stdlib.h>

#define nsize sizeof(node)
#define lsize sizeof(linked_list)

typedef struct Node{
	int data;
	struct Node *next;
}node, *pnode;

typedef struct Linked_list{
	pnode head;
	int Len;
}linked_list, *plinked_list;

pnode creat_node(int num){
	pnode New = (pnode)malloc(nsize);
	if(!New)
		exit(1);
	New->data = num;
	New->next = NULL;
	return New;
}

plinked_list creat_list(){
	plinked_list New = (plinked_list)malloc(lsize);
	if(!New)
		exit(1);
	pnode p = creat_node(-1);
	New->head = p;
	p->next = p;
	New->Len = 0;
}

void add_node(int num, plinked_list l){
	pnode New = creat_node(num);
	if(l->head->next == l->head){
		l->head->next = New;
		New->next = l->head;
	}
	else{
		New->next = l->head->next;
		l->head->next = New;
	}
	l->Len++;
}

void insert_node(int num, int cur, plinked_list l){
	if(l->Len < cur || cur <= 0)
		printf("Error!\n");
	else{
		pnode p = l->head;
		cur--;
		while(cur--) p = p->next;
		pnode New = creat_node(num);
		New->next = p->next;
		p->next = New;
		l->Len++;
	}
}

void del_node(int cur, plinked_list l){
	if(l->Len < cur || cur <= 0)
		printf("Error!\n");
	else{
		pnode p = l->head;
		cur--;
		while(cur--) p = p->next;
		pnode Del = p->next;
		p->next = p->next->next;
		free(Del);
		l->Len--;
	}
}

void search_node(int num, plinked_list l){
	pnode p = l->head->next;
	int res = 1;
	while(p != l->head && p->data != num){
		p = p->next;
		res++;
	}
	if(p == l->head)
		printf("No the data!\n");
	else
		printf("the data is NO.%d\n",res);
}

void destroy_list(plinked_list l){
	pnode p1, p2;
	p1 = l->head;
	p2 = p1->next;
	while(p2 != l->head){
		p1 = p2;
		p2 = p2->next;
		free(p1);
	}
	l->head->next = l->head;
	l->Len = 0;
}

void output_list(plinked_list l){
	pnode p = l->head->next;
	if(p == l->head)
		printf("No data!\n");
	else{
		while(p != l->head){
			printf("%d",p->data);
			p = p->next;
			if(p != l->head) printf("->");
		}
		printf("\n");
	}
}

int main(){
	return 0;
}
