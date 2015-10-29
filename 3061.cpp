#include <stdio.h>
#define Max 100000
#define INF 0x7f7f7f7f

int Array[Max];

int main() {
	int total;
    int i, n, s;
    int left, right;
    int sum, result, flag;
	scanf("%d", &total);
	while(total--) {
	    left = 1;
	    right = sum = flag = 0;
	    result = INF;
	    scanf("%d%d", &n, &s);
	    for(i = 1; i <= n; i++)
		    scanf("%d", &Array[i]);
	    while(right < n) {
	        while(sum < s) {
			    sum += Array[++right];
			    if(right >= n)
			        break;
		    }
		    while(sum >= s) {
	            if(right - left + 1 < result) {
			        result = right - left + 1;
					flag = 1;
				}
		        sum -= Array[left++];
	        }
	        if(left > right)
		        right = left;
		}
		if(flag)
		    printf("%d\n", result);
		else
			printf("0\n");
	}
    return 0;
}
