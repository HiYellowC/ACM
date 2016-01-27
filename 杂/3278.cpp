#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
using namespace std;

int N, K;
int flag[100010];
int result;

typedef struct Node {
	int num, t;
}node;

void bfs() {
	queue<node>q;
	node New;
	New = (node){N, 0};
	flag[N] = 1;
	q.push(New);
	while(!q.empty()) {
		int n = q.front().num;
		int t = q.front().t;
		if(n == K) {
			result = t;
			return ;
		}
		q.pop();
		if(n * 2 >= 0 && n * 2 <= 100000 && !flag[n * 2]) {
			New = (node){n * 2, t + 1};
			flag[n * 2] = 1;
			q.push(New);
		}
		if(n + 1 >= 0 && n + 1 <= 100000 && !flag[n + 1]) {
			New = (node){n + 1, t + 1};
			flag[n + 1] = 1;
			q.push(New);
		}
		if(n - 1 >= 0 && n - 1 <= 100000 && !flag[n - 1]) {
			New = (node){n - 1, t + 1};
			flag[n - 1] = 1;
			q.push(New);
		}
	}
}

int main() {
	scanf("%d%d", &N, &K);
	bfs();
	printf("%d\n", result);
	return 0;
}
