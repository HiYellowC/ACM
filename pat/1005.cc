#include <bits/stdc++.h>
using namespace std;

char str[110];

map <int, string> M;
vector <int> V;

int main() {
	M[0] = "zero", M[1] = "one", M[2] = "two", M[3] = "three", M[4] = "four", M[5] = "five", M[6] = "six", M[7] = "seven", M[8] = "eight", M[9] = "nine";
	scanf("%s", str);
	int len = strlen(str);
	int sum = 0;
	for(int i = 0; i < len; i++) sum += str[i] - '0';
	if(sum == 0) cout << M[0] << endl;
	else {
		while(sum) {
			V.push_back(sum % 10);
			sum /= 10;
		}	
		for(int i = (int)V.size() - 1; i >= 0; i--)
			cout << M[V[i]] << " \n"[i == 0];
	}
	return 0;
}
