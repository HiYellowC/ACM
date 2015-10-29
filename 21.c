#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
	int e1, e2, e3;
	int t;
	struct Node *next;
}node, *pnode;

typedef struct Queue{
	pnode front, rear;
}queue, *pqueue;

pqueue q;

pnode create_node(int e1, int e2, int e3, int t) {
	pnode New = (pnode)malloc(sizeof(node));
	New->e1 = e1;
	New->e2 = e2;
	New->e3 = e3;
	New->t = t;
	New->next = NULL;
	return New;
}

pqueue create_queue() {
	pqueue New = (pqueue)malloc(sizeof(queue));
	New->front = NULL;
	New->rear = NULL;
	return New;
}

void push_queue(int e1, int e2, int e3, int t) {
	pnode New = create_node(e1, e2, e3, t);
	if(q->front == NULL) {
		q->front = New;
		q->rear = New;
	}
	else {
		q->rear->next = New;
		q->rear = New;
	}
}

void pop_queue() {
	if(q->front == q->rear) {
		free(q->front);
		q->front = q->rear = NULL;
	}
	else{
		pnode del = q->front;
		q->front = q->front->next;
		free(del);
	}
}

int V1, V2, V3;
int E1, E2, E3;
int flag[100][100][100];
void bfs() {
	push_queue(V1, 0, 0, 0);
	flag[V1][0][0] = 1;
	while(q->front) {
		int a, b, c, t;
		a = q->front->e1;
		b = q->front->e2;
		c = q->front->e3;
		t = q->front->t;
		if(a == E1 && b == E2 && c == E3) {
			printf("%d\n", t);
			return ;
		}
		pop_queue();
		if(a) {
			if(b != V2) {
				if(a + b <= V2 && flag[0][a + b][c] == 0) {
					push_queue(0, a + b, c, t + 1);
					flag[0][a + b][c] = 1;
				}
				else if(a + b > V2 && flag[a + b - V2][V2][c] == 0){
					push_queue(a + b - V2, V2, c, t + 1);
					flag[a + b - V2][V2][c] = 1;
				}
			}
			if(c != V3) {
				if(a + c <= V3 && flag[0][b][a + c] == 0) {
					push_queue(0, b, a + c, t + 1);
					flag[0][b][a + c] = 1;
				}
				else if(a + c > V3 && flag[a + c - V3][b][V3] == 0){
					push_queue(a + c - V3, b, V3, t + 1);
					flag[a + c - V3][b][V3] = 1;
				}
			}
		}
		if(b) {
			if(a != V1) {
				if(a + b <= V1 && flag[a + b][0][c] == 0) {
					push_queue(a + b, 0, c, t + 1);
					flag[a + b][0][c] = 1;
				}
				else if(a + b > V2 && flag[V1][a + b - V1][c] == 0){
					push_queue(V1, a + b - V1,c, t + 1);
					flag[V1][a + b - V1][c] = 1;
				}
			}
			if(c != V3) {
				if(b + c <= V3 && flag[a][0][b + c] == 0) {
					push_queue(a, 0, b + c, t + 1);
					flag[a][0][b + c] = 1;
				}
				else if(b + c > V3 && flag[a][b + c - V3][V3] == 0){
					push_queue(a, b + c - V3, V3, t + 1);
					flag[a][b + c - V3][V3] = 1;
				}
			}
		}
		if(c) {
			if(a != V1) {
				if(a + c <= V1 && flag[a + c][b][0] == 0) {
					push_queue(a + c, b, 0, t + 1);
					flag[a + c][b][0] = 1;
				}
				else if(a + c > V1 && flag[V1][b][a + c - V1] == 0) {
					push_queue(V1, b, a + c - V1, t + 1);
					flag[V1][b][a + c - V1] = 1;
				}
			}
			if(b != V2) {
				if(b + c <= V2 && flag[a][b + c][0] == 0) {
					push_queue(a, b + c, 0, t + 1);
					flag[a][b + c][0] = 1;
				}
				else if(b + c > V2 && flag[a][V2][b + c - V2] == 0) {
					push_queue(a, V2, b + c - V2, t + 1);
					flag[a][V2][b + c - V2] = 1;
				}
			}
		}
	}
	printf("-1\n");
}

int main() {
	int total;
	scanf("%d", &total);
	while(total--) {
		scanf("%d %d %d", &V1, &V2, &V3);
		scanf("%d %d %d", &E1, &E2, &E3);
		q = create_queue();
		memset(flag, 0, sizeof(flag));
		bfs();
		while(q->front)
			pop_queue();
	}
	return 0;
}
