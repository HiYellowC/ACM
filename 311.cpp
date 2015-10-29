#include <stdio.h>
#include <string.h>
#define M 2010
#define V 50001

//int array[M][2];
int res[V];

inline int max(int a, int b) {
	return a > b ? a : b;
}

/*int dp1(int m, int v) {
	if(result[m][v])
		return result[m][v];
	else {
	int num1, num2, num3;
	num1 = num2 = num3 = -1;
	if(m == 0 && v > 0)
		return result[m][v] = -1;
	if(v == 0 || m <= 0)
		return result[m][v] = 0;
	num1 = dp1(m - 1, v);
	if(v - array[m - 1][0] >= 0) {
		num2 = dp1(m - 1, v - array[m - 1][0]);
		if(num2 != -1)
			num2 += array[m - 1][1];
		num3 = dp1(m, v - array[m - 1][0]);
		if(num3 != -1)
			num3 += array[m - 1][1];
	}
	if(!(~num1 || ~num2 || ~num3))
		return result[m][v] = -1;
	return result[m][v] = max(max(num1, num2), num3);
	}
}*/

int main() {
	int total;
	int m, v;
	int i, k;
	int a, b;
	scanf("%d", &total);
	while(total--) {
		scanf("%d%d", &m, &v);
//		for(i = 0; i < m; i++)
//			scanf("%d%d", &array[i][0], &array[i][1]);
		memset(res, -100, sizeof(res));
		res[0] = 0;
		for(i = 1; i <= m; i++) {
			scanf("%d%d", &a, &b);
			for(k = a; k <= v; k++) {
//				res[k] = max(res[k], res[k - a] + b);
//				if(k - a == 0 || (k - a >= 0 && res[k - a]))
					res[k] = max(res[k], res[k - a] + b);
			}
		}
		if(res[v] < 0)
			printf("NO\n");
		else
			printf("%d\n", res[v]);
	}
	return 0;
}
