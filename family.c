#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Person{
	char name[20];
	int flag;
	struct Person *father;
	struct Person *son;
	struct Person *brother1;
	struct Person *brother2;
}person, *pperson;

typedef struct Family{
	pperson top;
	int num_of_person;
}family, *pfamily;

pperson create_person(char *name){
	pperson New = (pperson)malloc(sizeof(person));
	if(New == NULL)
		exit(1);
	strcpy(New->name, name);
	New->flag = 1;
	New->father = NULL;
	New->son = NULL;
	New->brother1 = NULL;
	New->brother2 = NULL;
	return New;
}

pfamily create_family(){
	pfamily New = (pfamily)malloc(sizeof(family));
	if(New == NULL)
		exit(1);
	printf("please input the first person's name\n");
	char name[20];
	scanf("%s", name);
	pperson p = create_person(name);
	New->top = p;
	New->num_of_person = 1;
	return New;
}

pperson search_person(char *name, pperson top){
	pperson res;
	if(top == NULL)
		res = NULL;
	else if(strcmp(name, top->name) == 0)
		res = top;
	else if(search_person(name, top->son))
		res = search_person(name, top->son);
	else
		res = search_person(name, top->brother2);
	return res;
}

void add_son(pfamily f){
	char name[20];
	printf("please input the father's name\n");
	scanf("%s", name);
	pperson father = search_person(name, f->top);
	if(father == NULL)
		printf("No the person!\n");
	else{
		char sname[20];
		printf("please input the son's name\n");
		scanf("%s", sname);
		pperson son = create_person(sname);
		son->father = father;
		son->brother2 = father->son;
		if(father->son)
			father->son->brother1 = son;
		father->son = son;
		f->num_of_person++;
	}
}

void add_brother(pfamily f){
	char name[20];
	printf("please input the brother's name\n");
	scanf("%s", name);
	pperson brother1 = search_person(name, f->top);
	if(brother1 == NULL)
		printf("No the person!\n");
	else{
		char bname[20];
		printf("please input the add brother'name\n");
		scanf("%s", bname);
		pperson brother2 = create_person(bname);
		brother2->father = brother1->father;
		brother2->brother1 = brother1;
		brother2->brother2 = brother1->brother2;
		brother1->brother2 = brother2;
		if(brother2->brother2)
			brother2->brother2->brother1 = brother2;
		f->num_of_person++;
	}
}

void del_person(pfamily f){
	char name[20];
	printf("please input the person's name\n");
	scanf("%s", name);
	pperson del = search_person(name, f->top);
	if(del == NULL || del->flag == 0)
		printf("No the person\n");
	else{
		del->flag = 0;
		f->num_of_person--;
	}
}

void get_father(pfamily f){
	char name[20];
	printf("please input the person's name\n");
	scanf("%s", name);
	pperson p = search_person(name, f->top);
	if(p == NULL)
		printf("No the person\n");
	else if(p->father == NULL)
		printf("the person do not have father\n");
	else
		printf("the person's father is %s\n", p->father->name);
}

void get_brother(pfamily f){
	char name[20];
	printf("please input the person's name\n");
	scanf("%s", name);
	pperson p = search_person(name, f->top);
	if(p == NULL)
		printf("No the person\n");
	else if(p->brother1 == NULL && p->brother2 == NULL)
		printf("the person do not have brother\n");
	else{
		printf("the brother(s) is(are):\n");
		pperson p2 = p->brother1;
		while(p2){
			printf("%s\n", p2->name);
			p2 = p2->brother1;
		}
		p2 = p->brother2;
		while(p2){
			printf("%s\n", p2->name);
			p2 = p2->brother2;
		}
	}
}

void get_number(pfamily f){
	printf("the number of people is %d\n", f->num_of_person);
}

void output_person(pperson top){
	if(top == NULL) return ;
	if(top->flag == 0)
		printf("(*)");
	printf("%s\n", top->name);
	output_person(top->son);
	output_person(top->brother2);
}

void output_family(pfamily f){
	pperson top = f->top;
	output_person(top);
}

int main(){
	pfamily f;
	int Switch = 1;
	int flag = 0;
	while(Switch){
		printf("1 - create family  2 - add son  3 - add brother  4 - delete person  5 - get the person'father  6 - get the person'brother  7 - get the number of people  8 - output family  0 - exit\n");
		scanf("%d", &Switch);
		if(Switch > 1 && flag == 0){
			printf("Error!\n");
			continue;
		}
		switch(Switch){
			case 1:{
					   f = create_family();
					   flag = 1;
					   break;
				   }
			case 2:{
					   add_son(f);
					   break;
				   }
			case 3:{
					   add_brother(f);
					   break;
				   }
			case 4:{
					   del_person(f);
					   break;
				   }
			case 5:{
					   get_father(f);
					   break;
				   }
			case 6:{
					   get_brother(f);
					   break;
				   }
			case 7:{
					   get_number(f);
					   break;
				   }
			case 8:{
					   output_family(f);
					   break;
				   }
			case 0:
				   break;
		}
	}
	return 0;
}
