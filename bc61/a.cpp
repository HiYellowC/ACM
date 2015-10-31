#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main() {
	int n, s, t;
	while(~scanf("%d%d%d", &n, &s, &t)) {
		if(n == 1) {
			printf("0\n");
			continue;
		}
		if((s == 1 && t == n) || (s == n && t == 1)) {
			printf("0\n");	
			continue;
		}
		if(s == t) {
			printf("-1\n");
			continue;
		}
		if(s == 1 || s == n) {
			printf("1\n");
			continue;
		}
		if((t == n && s == n - 1) || (t == 1 && s == 2)) {
			printf("1\n");
			continue;
		}
		if(s - t == 1 || t - s == 1) {
			printf("1\n");	
			continue;
		}
		printf("2\n");
	}
	return 0;
}

