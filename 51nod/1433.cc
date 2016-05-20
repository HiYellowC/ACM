#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, num, con;
	con = 0;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &num);
		if(num == 5) con++;
	}
	if(con < 9 && n != con) printf("0\n");
	else if(n == con && con < 9) printf("-1\n");
	else {
		if(n != con) {
			for(int i = 1; i <= con / 9 * 9; i++) printf("5");	
			for(int i = 1; i <= n - con; i++) printf("0");
		}	
		else printf("-1");
		printf("\n");
	}
	return 0;
}
