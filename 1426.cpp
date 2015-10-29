#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
using namespace std;

int n;

typedef struct Node {
	int num[101];
	int len_of_num;
}node;

bool get_res(int *num, int len) {
	int i;
	int sum = 0;
	for(i = 0; i < len; i++) {
		sum += num[i];
		sum %= n;
		sum *= 10;
	}
	if(sum == 0)
		return true;
	else
		return false;
}

void bfs() {
	queue<node>q;
	node New;
	int i;
	int len_now;
	int num_now[101];
	New.num[0] = 1;
	New.len_of_num = 1;
	q.push(New);
	while(!q.empty()) {
		len_now = q.front().len_of_num;
		for(i = 0; i < len_now; i++)
			num_now[i] = q.front().num[i];
		q.pop();
		if(get_res(num_now, len_now) == true) {
			for(i = 0; i < len_now; i++)
				printf("%d", num_now[i]);
			printf("\n");
			return ;
		}
		node s1;
		for(i = 0; i < len_now; i++)
			s1.num[i] = num_now[i];
		s1.num[len_now] = 1;
		s1.len_of_num = len_now + 1;
		q.push(s1);
		node s2;
		for(i = 0; i < len_now; i++)
			s2.num[i] = num_now[i];
		s2.num[len_now] = 0;
		s2.len_of_num = len_now + 1;
		q.push(s2);
	}
}

int main() {
	int i;
	while(scanf("%d", &n)) {
		if(!n)
			break;
		bfs();
	}
	return 0;
}
