#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n, m;
		scanf("%d%d", &n, &m);
		n = (n - 2) * 180 / n;
		m = (m - 2) * 180 / m;
		bool flag = false;
		for(int i = 0; i <= 360; i++) {
			for(int k = 0; k <= 360; k++)
				if(n * i + m * k == 360) {
					flag = true;
					break;
				}
			if(flag) break;
		}
		if(flag) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}

