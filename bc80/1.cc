#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n;
		scanf("%d", &n);
		int a, b;
		a = b = 0;
		int num;
		for(int i = 1; i <= n; i++) {
			scanf("%d", &num);	
			if(num == 1) a = 1;
			if(num == 0) b = 1;
		}
		if(a + b == 2) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}

