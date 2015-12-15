#include <bits/stdc++.h>
using namespace std;

void fun(char * str) {
	str[1] = 'o';
}

int main() {
	char str[10] = "hello";
	fun(str);
	printf("str: %s\n", str);
	return 0;
}
