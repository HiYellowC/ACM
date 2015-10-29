#include <iostream>
#include <cstdio>
#include <cstring>
#define Max1 10  
#define Max2 59049 // 3^10
#define INF 0x3f3f3f3f
using namespace std;
/*由于每个点可经过两次 用三进制数表示状态  例10020（三进制）表示经过点2两次点1一次其余点都没经过*/
int n, m, ans;
int Pow[Max1 + 2], State[Max2 + 2][Max1 + 2];
//Pow[n]意为3^n, State[n][m]意为状态n下经过m点的次数
int dp[Max2 + 2][Max1 + 2], Map[Max1 + 2][Max1 + 2];
//dp[n][m]意为状态为n且现位于m点时的费用， Map即为邻接矩阵存图

inline int min(int a, int b) {
	return a < b ? a : b;
}

void Init() {
	int i;
	Pow[0] = 1;
	for(i = 1; i <= Max1; i++)
		Pow[i] = Pow[i - 1] * 3;
	for(i = 0; i < Pow[Max1]; i++) {
		int num = i;
		int cur = 1;
		while(num) {
			State[i][cur] = num % 3;
			num /= 3, cur++;
		}
	}
	//将十进制数i转化为三进制数，初始化State
}

bool Check(int x) {
	int i;
	bool flag = 1;
	for(i = 1; i <= n; i++)
		if(State[x][i] == 0) {
			flag = 0;
			break;
		}
	return flag;
	//检测状态x是否经过所有点
}

void Dp() {
	int i, j, k;
	for(i = 0; i < Pow[n]; i++) {
		//枚举状态i
		for(j = 1; j <= n; j++) {
			//枚举当前所在点j
			if(dp[i][j] == INF)
				continue;
			//该情况不存在
			for(k = 1; k <= n; k++) {
				//枚举下一步到达的点k
				if((j == k) || (Map[j][k] == INF))
					continue;
				if(State[i][k] == 2)
					continue;
				//j和k同一点  不存在j到k的路线  i状态下已经经过两次k点
				dp[i + Pow[k - 1]][k] = min(dp[i + Pow[k - 1]][k], dp[i][j] + Map[j][k]);
				//从j点到k点  状态i转变为i + Pow[k - 1][k]
				//例 状态i为10020（三进制）j为2 k为1时满足上述条件 即状态变为10021（三进制）
				if(Check(i + Pow[k - 1]))
					ans = min(ans, dp[i + Pow[k - 1]][k]);
			}
		}
	}
}

int main() {
	int i, a, b, v;
	Init();
	while(~scanf("%d%d", &n, &m)) {
		ans = INF;
		memset(dp, INF, sizeof(dp));
		memset(Map, INF, sizeof(Map));
		for(i = 1; i <= n; i++)
			dp[Pow[i - 1]][i] = 0;
		//只经过点i的状态 且位于点i 初始化为0
		for(i = 1; i <= m; i++) {
			scanf("%d%d%d", &a, &b, &v);
			Map[a][b] = Map[b][a] = min(Map[a][b], v);
		}
		Dp();
		if(ans == INF)
			ans = -1;
		printf("%d\n", ans);
	}
	return 0;
}
