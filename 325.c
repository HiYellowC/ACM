#include <stdio.h>
#include <string.h>

int weight[1510];
int flag[1510];
int N;
int sum;
int num;
int res;

void fun(int x) {
	int i;
	if(x > sum / 2) {
		return ;
	}
	else {
		for(i = num; i < N; i++) {
			if(flag[i] == 0) {
				flag[i] = 1;
				num = i + 1;
				if(res < x + weight[i] && x + weight[i] <= sum / 2)
					res = x + weight[i];
				fun(x + weight[i]);
				flag[i] = 0;
			}
		}
	}
}

int main() {
	while(~scanf("%d", &N)) {
		int i;
		sum = 0;
		num = 0;
		res = 0;
		memset(flag, 0, sizeof(flag));
		for(i = 0; i < N; i++) {
			scanf("%d", &weight[i]);
			sum += weight[i];		
		}
		fun(0);
		printf("%d\n", sum - 2 * res);
	}
	return 0;
}
