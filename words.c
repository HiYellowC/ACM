#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
	int times;
	struct Node *next[26];
}node, *pnode;

void init_node(pnode p){
	p->times = 0;
	int i;
	for(i = 0; i < 26; i++)
		p->next[i] = NULL;
}

int search_node(const pnode head){
	char words[20];
	scanf("%s", words);
	int Len = strlen(words);
	int i;
	pnode p = head;
	for(i = 0; i < Len; i++){
		if(p->next[words[i] - 'a'] == NULL)
			return 0;
		p= p->next[words[i] - 'a'];
	}
	return p->times;
}

int main(){
	pnode head = (pnode)malloc(sizeof(node));
	init_node(head);
	int n;
	scanf("%d", &n);
	char words[15];
	int Max = 0;
	char res[15];
	int i;
	while(n--){
		scanf("%s", words);
		int Len = strlen(words);
		pnode p = head;
		for(i = 0; i < Len; i++){
			if(p->next[words[i] - 'a'] == NULL)
				p->next[words[i] - 'a'] = (pnode)malloc(sizeof(node));
			p = p->next[words[i] - 'a'];
		}
		p->times++;
		if(Max < p->times){
			Max = p->times;
			strcpy(res, words);
		}
	}
	printf("%s %d\n", res, Max);
	return 0;
}
