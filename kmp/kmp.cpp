#include <stdio.h>
#include <string.h>
#include <ctime>

char s[1001], p[1001];

void normal() {
	clock_t t1, t2;
	t1 = clock();
	int len1, len2;
	len1 = strlen(s);
	len2 = strlen(p);
	int a, b;
	a = b = 0;
	while(a < len1 && b < len2) {
		if(s[a] == p[b]) {
			a++;
			b++;
		}
		else {
			a = a - b + 1;
			b = 0;
		}
	}
	if(b == len2)
		printf("yes: %d\n", a - b);
	else
		printf("no\n");
	t2 = clock();
	printf("normal: %lf\n", (double)(t2 - t1) / CLOCKS_PER_SEC);
}

void kmp() {
	clock_t t1, t2;
	t1 = clock();
	int next[1001];
	int len1, len2;
	len1 = strlen(s);
	len2 = strlen(p);
	next[0] = -1;
	int i, j;
	i = -1;
	j = 0;
	while(j < len2 - 1) {
		if(i == -1 || p[i] == p[j]) {
			i++;
			j++;
		//	next[j] = i;
			if(p[j] == p[i])
				next[j] = next[k];
			else
				next[j] = k;
		}
		else
			i = next[i];
	}
	int a, b;
	a = b = 0;
	while(a < len1 && b < len2) {
		if(b == -1 || s[a] == p[b]) {
			a++;
			b++;
		}
		else {
			b = next[b];
		}
	}
	if(b == len2)
		printf("yes: %d\n", a - b);
	else
		printf("no\n");
	t2 = clock();
	printf("kmp: %lf\n", (double)(t2 - t1) / CLOCKS_PER_SEC);
}

int main() {
	scanf("%s%s", s, p);
	normal();
	kmp();
	return 0;
}
