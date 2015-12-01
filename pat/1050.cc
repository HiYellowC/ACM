#include <bits/stdc++.h>
using namespace std;

char str1[10010], str2[10010];
bool vis[10010];

int main() {
	gets(str1), gets(str2);
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	for(int i = 0; i < len2; i++) vis[(int)str2[i]] = true;
	for(int i = 0; i < len1; i++)
		if(!vis[(int)str1[i]]) printf("%c", str1[i]);
	printf("\n");
	return 0;
}
