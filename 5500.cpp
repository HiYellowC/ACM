#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 25
using namespace std;

int pos[MAXN];

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n;
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) scanf("%d", &pos[i]);
		int p = n;
		int con = 0;
		for(int i = n; i >= 1; i--)
			if(pos[i] == p) p--, con++;
		printf("%d\n", n - con);
	}
	return 0;
}
