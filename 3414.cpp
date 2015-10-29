#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
using namespace std;

int A, B, C;
bool pre[101][101];
int pace[101][101][3];
typedef struct Node {
	int a, b, t;
}node;
int result;
int aa, bb;

void bfs() {
	queue<node>q;
	node n;
	int a_now, b_now, t_now;
	n = (node){0, 0, 0};
	pre[0][0] = true;
	q.push(n);
	while(!q.empty()) {
		a_now = q.front().a;
		b_now = q.front().b;
		t_now = q.front().t;
		q.pop();
		if(a_now == C || b_now == C) {
			aa = a_now;
			bb = b_now;
			result = t_now;
			return ;
		}
		if(a_now < A && pre[A][b_now] == false) {
			n = (node){A, b_now, t_now + 1};
			pre[A][b_now] = true;
			pace[A][b_now][0] = a_now;
			pace[A][b_now][1] = b_now;
			pace[A][b_now][2] = 3;
			q.push(n);
		}
		if(b_now < B && pre[a_now][B] == false) {
			n = (node){a_now, B, t_now + 1};
			pre[a_now][B] = true;
			pace[a_now][B][0] = a_now;
			pace[a_now][B][1] = b_now;
			pace[a_now][B][2] = 4;
			q.push(n);
		}
		if(a_now && pre[0][b_now] == false) {
			n = (node){0, b_now, t_now + 1};
			pre[0][b_now] = true;
			pace[0][b_now][0] = a_now;
			pace[0][b_now][1] = b_now;
			pace[0][b_now][2] = 1;
			q.push(n);
		}
		if(b_now && pre[a_now][0] == false) {
			n = (node){a_now, 0, t_now + 1};
			pre[a_now][0] = true;
			pace[a_now][0][0] = a_now;
			pace[a_now][0][1] = b_now;
			pace[a_now][0][2] = 2;
			q.push(n);
		}
		if(b_now && a_now < A) {
			if(b_now + a_now <= A && pre[a_now + b_now][0] == false) {
				n = (node){a_now + b_now, 0, t_now + 1};
				pre[a_now + b_now][0] = true;
				pace[a_now + b_now][0][0] = a_now;
				pace[a_now + b_now][0][1] = b_now;
				pace[a_now + b_now][0][2] = 6;
				q.push(n);
			}
			else if(a_now + b_now > A && pre[A][a_now + b_now - A] == false){
				n = (node){A, a_now + b_now - A, t_now + 1};
				pre[A][a_now + b_now - A] = true;
				pace[A][a_now + b_now - A][0] = a_now;
				pace[A][a_now + b_now - A][1] = b_now;
				pace[A][a_now + b_now - A][2] = 6;
				q.push(n);
			}
		}
		if(a_now && b_now < B) {
			if(a_now + b_now <= B && pre[0][a_now + b_now] == false) {
				n = (node){0, a_now + b_now, t_now + 1};
				pre[0][a_now + b_now] = true;
				pace[0][a_now + b_now][0] = a_now;
				pace[0][a_now + b_now][1] = b_now;
				pace[0][a_now + b_now][2] = 5;
				q.push(n);
			}
			else if(a_now + b_now > B && pre[a_now + b_now - B][B] == false){
				n = (node){a_now + b_now - B, B, t_now + 1};
				pre[a_now + b_now - B][B] = true;
				pace[a_now + b_now - B][B][0] = a_now;
				pace[a_now + b_now - B][B][1] = b_now;
				pace[a_now + b_now - B][B][2] = 5;
				q.push(n);
			}
		}
	}
}
/*
int pace[10000];
int s[10000];

void dfs(int a, int b, int t) {
	int i;
	if(a == C || b == C) {
		if(result == -1 || t < result) {
			result = t;
			for(i = 1; i <= t; i++)
				pace[i] = s[i];
		}
	}
	else {
		if(a && pre[0][b] == false) {
			s[t + 1] = 1;
			pre[0][b] = true;
			dfs(0, b, t + 1);
			pre[0][b] = false;
		}
		if(b && pre[a][0] == false) {
			s[t + 1] = 2;
			pre[a][0] = true;
			dfs(a, 0, t + 1);
			pre[a][0] = false;
		}
		if(a < A && pre[A][b] == false) {
			s[t + 1] = 3;
			pre[A][b] = true;
			dfs(A, b, t + 1);
			pre[A][b] = false;
		}
		if(b < B && pre[a][B] == false) {
			s[t + 1] = 4;
			pre[a][B] = true;
			dfs(a, B, t + 1);
			pre[a][B] = false;
		}
		if(a && b < B) {
			s[t + 1] = 5;
			if(a + b <= B && pre[0][a + b] == false) {
				pre[0][a + b] = true;
				dfs(0, a + b, t + 1);
				pre[0][a + b] = false;
			}
			else if(a + b > B && pre[a + b - B][B] == false) {
				pre[a + b - B][B] = true;
				dfs(a + b - B, B, t + 1);
				pre[a + b - B][B] = false;
			}
		}
		if(b && a < A) {
			s[t + 1] = 6;
			if(a + b <= A && pre[a + b][0] == false) {
				pre[a + b][0] = true;
				dfs(a + b, 0, t + 1);
				pre[a + b][0] = false;
			}
			else if(a + b > A && pre[A][a + b - A] == false) {
				pre[A][a + b - A] = true;
				dfs(A, a + b - A, t + 1);
				pre[A][a + b - A] = false;
			}
		}
	}
}*/
int s[10000];

int main() {
	scanf("%d%d%d", &A, &B, &C);
	result = -1;
	bfs();
	int i;
	int a, b;
	int num1, num2;
	if(result == -1)
		printf("impossible\n");
	else {
		printf("%d\n", result);
		if(result) {
			a = aa, b = bb;
			for(i = result; i >= 1; i--) {
				s[i] = pace[a][b][2];
				num1 = pace[a][b][0];
				num2 = pace[a][b][1];
				a = num1, b = num2;
			}
			for(i = 1; i <= result; i++) {
				switch(s[i]) {
					case 1:{
							   printf("DROP(1)\n");
							   break;
						   }
					case 2:{
							   printf("DROP(2)\n");
							   break;
						   }
					case 3:{
							   printf("FILL(1)\n");
							   break;
						   }
					case 4:{
							   printf("FILL(2)\n");
							   break;
						   }
					case 5:{
							   printf("POUR(1,2)\n");
							   break;
						   }
					case 6:{
							   printf("POUR(2,1)\n");
							   break;
						   }
				}
			}
		}
	}
	return 0;
}
