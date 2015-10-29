#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char str[200010];
int to[50];

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	scanf("%s", str);
	for(int i = 0; i < 50; i++) to[i] = i;
	char a[2], b[2];
	for(int i = 1; i <= m; i++) {
		scanf("%s%s", a, b);
		for(int k = 0; k < 26; k++)
			if(to[k] == a[0] - 'a') to[k] = b[0] - 'a';
			else if(to[k] == b[0] - 'a') to[k] = a[0] - 'a';
	}
	for(int i = 0; i < n; i++)
		str[i] = to[str[i] - 'a'] + 'a';
	printf("%s\n", str);
	return 0;
}
