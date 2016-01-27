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

pnode create_node(int num){
	pnode New = (pnode)malloc(nsize);
	if(!New)
		exit(1);
	New->data = num;
	New->next = NULL;
	return New;
}

plinked_list create_list(){
	plinked_list New = (plinked_list)malloc(lsize);
	if(!New)
		exit(1);
	New->head = create_node(-1);
	New->Len = 0;
	return New;
}

void add_node(int num, plinked_list l){
	pnode New = create_node(num);
	New->next = l->head->next;
	l->head->next = New;
	l->Len++;
}

void insert_node(int num, int cur, plinked_list l){
	if(cur > l->Len || cur <= 0)
		printf("Error!\n");
	else{
		pnode New = create_node(num);
		pnode p = l->head->next;
		cur--;
		while(cur--) p = p->next;
		New->next = p->next;
		p->next = New;
		l->Len++;
	}
}

void del_node(int cur, plinked_list l){
	if(cur > l->Len || cur <= 0)
		printf("Error!\n");
	else{
		pnode p = l->head;
		cur--;
		while(cur--) p = p->next;
		pnode a = p->next;
		p->next = p->next->next;
		free(a);
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
	if(!p)
		printf("No the data!\n");
	else
		printf("the data is NO.%d\n",res);
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
	if(!p)
		printf("No data!\n");
	while(p){
		printf("%d",p->data);
		p = p->next;
		if(p)
			printf("->");
	}
	printf("\n");
}

int main(){
	int n = 0;
	plinked_list l[10];
	char Switch = '1';
	while(Switch != '0'){
		printf("1 - create  2 - add  3 - insert  4 - delete  5 - search  6 - output  7 - destroy  0 - exit\n");
		do {
			Switch = getchar();
		} while(Switch > '7' || Switch < '0');
		switch(Switch) {
			case '0': break;
			case '1':{
						l[n++] = create_list();
						printf("heave created the NO.%d list\n",n);
						break;
					 }
			case '2':{
						printf("please input the data and the number of list\n");
						int num, s;
						scanf("%d%d", &num, &s);
						if(s > n ){
							printf("Error!\n");
							break;
						}
						else{
							add_node(num,l[s - 1]);
						}
						break;
					 }
			case '3':{
						printf("please input the data, the order and the number of list\n");
						int num, cur, s;
						scanf("%d%d%d", &num, &cur, &s);
						if(s > n || s <= 0){
							printf("Error!\n");
							break;
						}
						else{
							insert_node(num, cur, l[s - 1]);
						}
						break;
					 }
			case '4':{
						printf("please intput the order and the number of list\n");
						int cur, s;
						scanf("%d%d", &cur, &s);
						if(s > n || s <= 0){
							printf("Error!\n");
							break;
						}
						else{
							del_node(cur,l[s - 1]);
						}
						break;
					 }
			case '5':{
						printf("please input the data and the number of list\n");
						int num, s;
						scanf("%d%d", &num, &s);
						if(s > n || s <= 0){
							printf("Error!\n");
							break;
						}
						else{
							search_node(num,l[s - 1]);
						}
						break;
					 }
			case '6':{
						printf("please input the number of list\n");
						int s;
						scanf("%d", &s);
						if(s > n || s <= 0){
							printf("Error!\n");
							break;
						}
						else{
							output_list(l[s - 1]);
						}
						break;
					 }
			case '7':{
						printf("please input the number of list\n");
						int s;
						scanf("%d", &s);
						if(s > n || s <= 0){
							printf("Error!\n");
							break;
						}
						else{
							destroy_list(l[s - 1]);
						}
						break;
					}
		}
	}
	return 0;
}
