#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b;
	scanf("%d%d", &a, &b);
	int c = a + b;
	if(c < 0) printf("-"), c *= -1;
	char str[20];
	int dex = 0;
	int t = 0;
	while(c) {
		if(t && t % 3 == 0) str[dex++] = ',';	
		t++;
		str[dex++] = '0' + (c % 10);
		c /= 10;
	}
	if(t == 0) str[dex++] = '0';
	for(int i = dex - 1; i >= 0; i--) printf("%c", str[i]);
	puts("");
	return 0;
}
