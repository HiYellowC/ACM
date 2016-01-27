#include <stdio.h>
#include <string.h>
#define Max 1010

char str1[Max], str2[Max];
//int array[Max][Max];
int new_array[Max];

int max(int a, int b) {
	return a > b ? a : b;
}

int main() {
	int total;
	int len1, len2;
	int i, k;
	int con, last;
	scanf("%d", &total);
	while(total--) {
		memset(new_array, 0, sizeof(new_array));
		scanf("%s%s", str1, str2);
		len1 = strlen(str1);
		len2 = strlen(str2);
		for(i = 0; i < len1; i++) {
			con = 0;
			for(k = 0; k < len2; k++) {
				last = new_array[k + 1];
				if(str1[i] == str2[k])
					new_array[k + 1] = con + 1; 
				else
					new_array[k + 1] = max(new_array[k], new_array[k + 1]);
				con = last;
			}
		}
		printf("%d\n", new_array[len2]);
	}
	return 0;
}
