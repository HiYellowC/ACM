#include <stdio.h>
#include <string.h>
#define Max 1001

int father[Max];
int v[Max];

int get_father(int n) {
	int root = n;
	while(father[root] != root)
		root = father[root];
	while(n != root) {
		n = father[n];
		father[n] = root;
	}
	return root;
}

int main() {
	int total;
	int i, P, Q;
	int a, b;
	int afather, bfather;
	int flag1, flag2;
	int sum, pa;
	scanf("%d", &total);
	while(total--) {
		scanf("%d%d", &P, &Q);
		for(i = 1; i <= P; i++)
			father[i] = i;
		memset(v, 0, sizeof(v));
		flag1 = flag2 = sum = pa = 0;
		for(i = 1; i <= Q; i++) {
			scanf("%d%d", &a, &b);
			v[a]++;
			v[b]++;
			afather = get_father(a);
			bfather = get_father(b);
			if(afather != bfather) {
				pa++;
				father[afather] = bfather;
			}
		}
		for(i = 1; i <= P; i++) {
			if(v[i] % 2)
				sum++;
		}
		if(sum != 0 && sum != 2)
			flag1 = 1;
		if(pa != P - 1)
			flag2 = 1;
		if(!flag1 && !flag2)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
