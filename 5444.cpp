#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define Max 1010
using namespace std;

int n, dex;
int T[Max], l[Max], r[Max];

int Create(int a) {
	T[++dex] = a;
	l[dex] = r[dex] = 0;
	return dex;
}

int BuildT(int root, int a) {
	if(T[root] == 0) {
		root = Create(a);
		return root;
	}
	if(a > T[root])
		r[root] = BuildT(r[root], a);
	else
		l[root] = BuildT(l[root], a);	
	return root;
}

void Query(int root, int a) {
	if(T[root] == a) {
		printf("\n");
		return ;
	}
	if(a > T[root]) {
		printf("W");
		Query(r[root], a);
	}
	else {
		printf("E");
		Query(l[root], a);
	}
}

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);		
		int root, a;
		dex = root = 0;
		memset(T, 0, sizeof(T));
		for(int i = 1; i <= n; i++) {
			scanf("%d", &a);
			root = BuildT(1, a);	
		}
		int q;
		scanf("%d", &q);
		while(q--) {
			scanf("%d", &a);
			Query(1, a);
		}
	}
	return 0;
}
