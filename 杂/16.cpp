#include <stdio.h>
#include <string.h>
#define Max 1000

int array[Max][2];
bool flag[Max][Max];
int result[Max];
int n;

int dp(int k) {
	int i;
	int & con = result[k];
	if(con > 0) 
		return con;
	con = 1;
	for(i = 0; i < n; i++)
		if(flag[k][i]) {
			int num = dp(i);
			if(con < num + 1)
				con = num + 1;
		}
	return con;
}

int main() {
	int total;
	int i, k;
	int max;
	scanf("%d", &total);
	while(total--) {
		scanf("%d", &n);
		max = 0;
		memset(flag, 0, sizeof(flag));
		memset(result, 0, sizeof(result));
		for(i = 0; i < n; i++)
			scanf("%d%d", &array[i][0], &array[i][1]);
		for(i = 0; i < n; i++)
			for(k = 0; k < n; k++)
				if((array[i][0] > array[k][0] && array[i][1] > array[k][1]) || (array[i][0] > array[k][1] && array[i][1] > array[k][0]))	
					flag[i][k] = 1;
		for(i = 0; i < n; i++) {
			int num = dp(i);
			if(max < num)
				max = num;
		}
		printf("%d\n", max);
	}
	return 0;
}
