#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

bool flag[10000];
bool pre[10000];
int m, N;
int result;

typedef struct Node {
	int data;
	int t;
}node;

void bfs() {
	queue<node>q;
	int data, t;
	int i;
	int sum;
	int num[4];
	node n = (node){m, 0};
	pre[m] = true;
	q.push(n);
	while(!q.empty()) {
		data = q.front().data;
		t = q.front().t;
		if(data == N) {
			result = t;
			return ;
		}
		for(i = 0; i < 4; i++) {
			num[i] = data % 10;
			data /= 10;
		}
		q.pop();
		for(i = 1; i <= 9; i++) {
			sum = i * 1000 + num[2] * 100 + num[1] * 10 + num[0];
			if(pre[sum] == false && flag[sum] == false) {
				pre[sum] = true;
				n = (node){sum, t + 1};
				q.push(n);
			}
		}
		for(i = 0; i <= 9; i++) {
			sum = i * 100 + num[3] * 1000 + num[1] * 10 + num[0];
			if(pre[sum] == false && flag[sum] == false) {
				pre[sum] = true;
				n = (node){sum, t + 1};
				q.push(n);
			}
		}
		for(i = 0; i <= 9; i++) {
			sum = i * 10 + num[3] * 1000 + num[2] * 100 + num[0];
			if(pre[sum] == false && flag[sum] == false) {
				pre[sum] = true;
				n = (node){sum, t + 1};
				q.push(n);
			}
		}
		for(i = 0; i <= 9; i++) {
			sum = i + num[3] * 1000 + num[2] * 100 + num[1] * 10;
			if(pre[sum] == false && flag[sum] == false) {
				pre[sum] = true;
				n = (node){sum, t + 1};
				q.push(n);
			}
		}
	}
}

int main() {
	int i, k;
	flag[1] = true;
	for(i = 2; i + i < 10000; i++) {
		if(flag[i] == false) {
			for(k = i + i; k < 10000; k += i)
				flag[k] = true;
		}
	}
	int total;
	scanf("%d", &total);
	while(total--) {
		memset(pre, 0, sizeof(pre));
		result = -1;
		scanf("%d%d", &m, &N);
		bfs();
		if(result == -1)
			printf("Impossible\n");
		else
			printf("%d\n", result);
	}
	return 0;
}
