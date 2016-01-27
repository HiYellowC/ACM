#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

struct node {
	int v, w;
}n[11];


bool cmp(const node & a, const node & b) {
	return a.v > b.v;
}

int main() {
	int total;
	int s, m;
	int i;
	int sum;
	scanf("%d", &total);
	while(total--) {
		sum = 0;
		scanf("%d%d", &s, &m);
		for(i = 0; i < s; i++)
			scanf("%d%d", &(n[i].v), &(n[i].w));
		sort(n, n + s, cmp);
		for(i = 0; m; i++) {
			if(n[i].w <= m) {
				sum += n[i].v * n[i].w;
				m -= n[i].w;
			}
			else {
				sum += n[i].v * m;
				m = 0;
			}
		}
		printf("%d\n", sum);
	}
	return 0;
}
