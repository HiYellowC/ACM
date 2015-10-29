#include <stdio.h>
#include <string.h>

char str[110];

int main() {
	int total;
	int n, m;
	int i, k, l, r, Max, len;
	scanf("%d", &total);
	while(total--) {
		scanf("%s", str);
		n = strlen(str);
		len = n;
		scanf("%d", &m);
		l = 0, r = m;
		n -= m;
		while(n--) {
			Max = -1;
			for(i = l; i <= r && i <= len; i++) {
				if(str[i] - '0' > Max) {
					Max = str[i] - '0';
					k = i;
				}
			}
			printf("%c", str[k]);
			l = k + 1, r += 1;
		}
		printf("\n");
	}
	return 0;
}
