#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 100010
using namespace std;

int T[MAXN * 3];
int ans[MAXN];

struct Node {
	int h, pos;
};

Node node[MAXN];

bool cmp(Node x, Node y) {
	return x.h < y.h;
}

void Build(int l, int r, int i) {
	if(l == r) {
		T[i] = 1;
		return ;
	}
	int mid = (l + r) >> 1;
	Build(l, mid, i << 1);
	Build(mid + 1, r, i << 1 | 1);
	T[i] = T[i << 1] + T[i << 1 | 1];
}

int Query(int l, int r, int x, int i) {
	if(l == r) {
		return l;	
	}
	int mid = (l + r) >> 1;
	if(x <= T[i << 1]) return Query(l, mid, x, i << 1);
	else return Query(mid + 1, r, x - T[i << 1], i << 1 | 1);
}

void Update(int l, int r, int x, int i) {
	if(l == r) {
		T[i] = 0;
		return ;
	}
	int mid = (l + r) >> 1;
	if(x <= mid) Update(l, mid, x, i << 1);
	else Update(mid + 1, r, x, i << 1 | 1);
	T[i] = T[i << 1] + T[i << 1 | 1];
}

int main() {
	int t, tt = 1;
	scanf("%d", &t);
	while(t--) {
		int n;
		scanf("%d", &n);
		Build(1, n, 1);
		for(int i = 1; i <= n; i++)
			scanf("%d%d", &node[i].h, &node[i].pos);
		sort(node + 1, node + 1 + n, cmp);
		bool flag = false;
		for(int i = 1; i <= n; i++) {
			if(T[1] <= node[i].pos) {
				flag = true;
				break;
			}	
			int p = Query(1, n, min(node[i].pos + 1, T[1] - node[i].pos), 1);
			ans[p] = node[i].h;
			Update(1, n, p, 1);
		}
		printf("Case #%d: ", tt++);
		if(flag) 
			printf("impossible\n");
		else {
			for(int i = 1; i <= n; i++)
				printf("%d%c", ans[i], " \n"[i == n]);
		}
	}
	return 0;
}
