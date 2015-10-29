#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5010;

char strs[MAXN], strt[MAXN];
int chars[30], chart[30];

bool check() {
	int con = 0;
	for(int i = 0; i < 26; i++)
		if(chars[i] < chart[i]) return false;
		else if(chars[i] == chart[i]) con++;
	if(con == 26) return false;
	return true;
}

bool check2() {
	for(int i = 0; i < 26; i++)
		if(chars[i] < chart[i]) return false;
	return true;
}

int main() {
	scanf("%s%s", strs, strt);
	int lens = strlen(strs);
	int lent = strlen(strt);
	for(int i = 0; i < lens; i++) chars[strs[i] - 'a']++;
	for(int i = 0; i < lent; i++) chart[strt[i] - 'a']++;
	if(check()) {
		printf("%s", strt);
		for(int i = 0; i < 26; i++) {
			chars[i] -= chart[i];
			for(int k = 0; k < chars[i]; k++)
				printf("%c", 'a' + i);
		}
	}
	else {
		bool flag = false;
		int dex;
		for(int i = lent - 1; i >= 0; i--) {
			chart[strt[i] - 'a']--;
			if(check2()) {
				for(int k = strt[i] - 'a' + 1; k < 26; k++)
					if(chars[k] - chart[k] > 0) {
						dex = k;
						flag = true;
						break;
					}
				if(flag) {
					for(int k = 0; k < i; k++)
						printf("%c", strt[k]), chars[strt[k] - 'a']--;
					printf("%c", 'a' + dex), chars[dex]--;
					for(int k = 0; k < 26; k++)
						for(int j = 0; j < chars[k]; j++)
							printf("%c", 'a' + k);
				}
			}
			if(flag) break;
		}

		if(!flag) printf("-1");
	}
	puts("");
	return 0;
}
