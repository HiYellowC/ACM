#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
#define Max 100

typedef struct Edge {
	int a, b;
	int w;
}edge, *pedge;

int father[Max], son[Max];
edge e[Max];

bool cmp(const edge a, const edge b) {
	return a.w < b.w;
}

int get_father(int a) {
	return a == father[a] ? a : get_father(father[a]);
}

bool find(int a, int b) {
	int root1, root2;
	root1 = get_father(a);
	root2 = get_father(b);
	if(root1 == root2)
		return false;
	else if(son[root1] > son[root2]) {
		father[root2] = root1;
		son[root1] += son[root2];
	}
	else {
		father[root1] = root2;
		son[root2] += son[root1];
	}
	return true;
}

int main() {
	int v, l;
	int a, b, w;
	int i;
	scanf("%d%d", &v, &l);
	for(i = 1; i <= v; i++) {
		son[i] = 1;
		father[i] = i;
	}
	for(i = 1; i <= l; i++) {
		scanf("%d%d%d", &a, &b, &w);
		e[i].a = a;
		e[i].b = b;
		e[i].w = w;
	}	
	sort(e + 1, e + 1 + l, cmp);
	int sum = 0;
	int s = 0;
	for(i = 1; i <= l; i++) {
		if(find(e[i].a, e[i].b)) {
			sum += e[i].w;
			s++;
		}
	}
	printf("s: %d\n", s);
	if(s == v - 1)
		printf("the result is %d\n", sum);
	else
		printf("error!\n");
	return 0;
}
