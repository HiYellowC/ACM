#include <stdio.h>
#include <stdlib.h>
#define nsize sizeof(node)
#define lsize sizeof(linked_list)
typedef struct Node{
	int data;
	struct Node *front;
	struct Node *next;
}node, *pnode;
typedef struct Linked_list{
	pnode head;
	int Len;
}linked_list, *plinked_list;
pnode creat_node(int num){
	pnode New = (pnode)malloc(nsize);
	if(!New) exit(1);
	New->data = num;
	New->front = NULL;
	New->next = NULL;
	return New;
}
plinked_list creat_list(){
	plinked_list New = (plinked_list)malloc(lsize);
	if(!New) exit(1);
	pnode p = creat_node(-1);
	New->head = p;
	New->Len = 0;
	return New;
}
void add_node(int num, plinked_list l){
	pnode New = creat_node(num);
	if(l->head->next) l->head->next->front = New;
	New->next = l->head->next;
	New->front = l->head;
	l->head->next = New;
	l->Len++;
}
void insert_node(int num, int cur, plinked_list l){
	if(cur > l->Len || cur <= 0) printf("Error!\n");
	else{
		pnode New = creat_node(num);
		pnode p = l->head;
		cur--;
		while(cur--) p = p->next;
		New->next = p->next;
		p->next->front = New;
		New->front = p;
		p->next = New;
		l->Len++;
	}
}
void del_node(int cur, plinked_list l){
	if(cur > l->Len || cur <= 0) printf("Error!\n");
	else{
		pnode p = l->head;
		cur--;
		while(cur--) p = p->next;
		pnode del = p->next;
		if(del->next) del->next->front = p;
		p->next = del->next;
		free(del);
		l->Len--;
	}
}
void search_node(int num, plinked_list l){
	pnode p = l->head->next;
	int res = 1;
	while(p && p->data != num){
		p = p->next;
		res++;
	}
	if(!p) printf("No the data!\n");
	else printf("The data is NO.%d\n",res);
}
void destroy_list(plinked_list l){
	pnode p1, p2;
	p1 = l->head;
	p2 = p1->next;
	while(p2){
		p1 = p2;
		p2 = p2->next;
		free(p1);
	}
	l->head->next = NULL;
	l->Len = 0;
}
void output_list(plinked_list l){
	pnode p = l->head->next;
	if(!p) printf("No data!\n");
	else{
		pnode rear = p;
		while(p){
			printf("%d",p->data);
			p = p->next;
			if(p) printf("->");
			if(p) rear = p;
		}
		printf("\n");
		while(rear != l->head){
			printf("%d",rear->data);
			rear = rear->front;
			if(rear != l->head) printf("->");
		}
		printf("\n");
	}
}
int main(){
	plinked_list l = creat_list();
	int i;
	for(i = 10; i >= 1; i--) add_node(i,l);
	search_node(1,l);
	destroy_list(l);
	output_list(l);
	return 0;
}
