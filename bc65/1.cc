#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char str1[110], str2[110];

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n;
		scanf("%d", &n);
		scanf("%s%s", str1, str2);
		for(int i = 0; i < n; i++) {
			if(str1[i] == 'A') str1[i] = 'U';
			else if(str1[i] == 'T') str1[i] = 'A';
			else if(str1[i] == 'C') str1[i] = 'G';
			else str1[i] = 'C';
		}
		if(strcmp(str1, str2) == 0) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
