#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char str1[110];
char str2[110];

int main() {
	scanf("%s", str1);
	scanf("%s", str2);
	swap(str1, str2);
	printf("str1: %s\n", str1);
	printf("str2: %s\n", str2);
	return 0;
}
