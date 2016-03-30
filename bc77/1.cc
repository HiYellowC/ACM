#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n, num;
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) scanf("%d", &num);
		if(n == 1) printf("%d\n", num);
		else printf("0\n");
	}
	return 0;
}

