#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int a[110];

int main() {
	int n;
	scanf("%d", &n);
	int i;
	int con = 0;
	int sum = 0;
	int flag = 0;
	for(i = 1; i <= n; i++) scanf("%d", &a[i]);
	for(i = 1; i <= n; i++) {
		if(a[i] == 1) break;
		con++;
	}
	int j;
	for(j = n; j > i; j--) {
		if(a[j] == 1) break;
		con++;
	}
	for(int k = i + 1; k < j; k++) {
		if(a[k] == 1) con += sum, sum = 0, flag = 0;
		else if(flag == 1) sum = 2, flag = 2;
		else if(flag == 2) sum++;
		else flag = 1;
	}
	con += sum;
	printf("%d\n", n - con);
	return 0;
}
