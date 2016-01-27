#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Max 100001

typedef struct Node {
	int point;
	struct Node *next;
}node, *pnode;

node v[Max];
int pre[Max];

void build_edge(int a, int b) {
	pnode p1, p2;
	p1 = (pnode)malloc(sizeof(node));
	p2 = (pnode)malloc(sizeof(node));
	p1->point = a;
	p1->next = v[b].next;
	v[b].next = p1;
	p2->point = b;
	p2->next = v[a].next;
	v[a].next = p2;
}

void dfs(int s) {
	pnode p = v[s].next;
	while(p) {
		if(!pre[p->point]) {
			pre[p->point] = s;
			dfs(p->point);
		}
		p = p->next;
	}
}

void des(pnode p) {
	if(p) {
		des(p->next);
		free(p);
	}
}

int main() {
	int total;
	int i, N, S;
	int a, b;
	scanf("%d", &total);
	while(total--) {
		scanf("%d%d", &N, &S);
		memset(pre, 0, sizeof(pre));
		pre[S] = -1;
		for(i = 1; i <= N; i++)
			v[i].next = NULL;
		for(i = 1; i < N; i++) {
			scanf("%d%d", &a, &b);
			build_edge(a, b);
		}
		dfs(S);
		for(i = 1; i <= N; i++) {
			printf("%d ", pre[i]);
			des(v[i].next);
		}
		printf("\n");
	}
	return 0;
}
