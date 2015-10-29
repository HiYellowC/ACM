#include <stdio.h>
#include <string.h>
#define Max 10

int n, k;
char map[Max][Max];
int num_of_key;
int place_of_key[Max * Max][2];
int flag_of_r[Max], flag_of_c[Max];
int result;
int con;

void dfs(int cur) {
	int i;
	int r, c;
	if(cur == k + 1) {
		result++;
		return ;
	}
	else {
		for(i = con; i <= num_of_key; i++) {
			r = place_of_key[i][0];
			c = place_of_key[i][1];
			if(flag_of_r[r] == 0 && flag_of_c[c] == 0) {
				flag_of_r[r] = 1;
				flag_of_c[c] = 1;
				con = i + 1;
				dfs(cur + 1);
				flag_of_r[r] = 0;
				flag_of_c[c] = 0;
			}
		}
	}
}

int main() {
	int i, j;
	char str[Max];
	while(scanf("%d%d", &n, &k)) {
		num_of_key = 0;
		result = 0;
		con = 1;
		memset(flag_of_r, 0, sizeof(flag_of_r));
		memset(flag_of_c, 0, sizeof(flag_of_c));
		if(n == -1 && k == -1)
			break;
		for(i = 1; i <= n; i++) {
			scanf("%s", str);
			for(j = 1; j <= n; j++) {
				map[i][j] = str[j - 1];
				if(map[i][j] == '#') {
					num_of_key++;
					place_of_key[num_of_key][0] = i, place_of_key[num_of_key][1] = j;
				}
			}
		}
		if(k > num_of_key)
			printf("0\n");
		else {
			dfs(1);
			printf("%d\n", result);
		}
	}
	return 0;
}
