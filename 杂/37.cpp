#include <stdio.h>
#include <string.h>
#define Max 1010

char str1[Max], str2[Max];
int result[Max];

inline int max(int a, int b) {
	return a > b ? a : b;
}

int main() {
	int i, k, len;
	int total;
	int num;
	int s, con;
	scanf("%d", &total);
	while(total--) {
		scanf("%s", str1);
		len = strlen(str1);
		memset(result, 0, sizeof(result));
		for(i = 0; i < len; i++)
			str2[i] = str1[len - 1 - i];
		str2[i] = 0;
		for(i = 1; i <= len; i++) {
			con = 0;
			for(k = 1; k <= len; k++) {
				s = result[k];
				if(str1[i - 1] == str2[k - 1])
					result[k] = con + 1;
				else
					result[k] = max(result[k - 1], result[k]);
				con = s;
			}
		}
		num = len - result[len];
		printf("%d\n", num);
	}
	return 0;
}
