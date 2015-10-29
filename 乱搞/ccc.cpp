#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
	int n, u, d;
	while(~scanf("%d%d%d", &n, &u, &d) && n)
		printf("%d\n", (n - u) % (u - d) == 0 ? (n - u) / (u - d) * 2 + 1 : (n - u) / (u - d) * 2 + 3);	
	return 0;
}
