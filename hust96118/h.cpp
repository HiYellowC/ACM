#include <bits/stdc++.h>
using namespace std;

const int MAXN = 400010;

char str[MAXN];

vector <int> V;

int main() {
    scanf("%s", str);
    int len = strlen(str);
    int con = 0;
    bool flag, key;
    flag = false;
    key = true;
    for(int i = 0; i < len; i++) {
        if(str[i] == '.') {
            if(!flag) {
                flag = true;
                if(con < 1 || con > 8) key = false;
            }
            else {
                if(con < 2 || con > 11) key = false;
            }
            V.push_back(con);
            con = 0;
        }
        else con++;
        if(!key) break;
    }
    if(con < 1 || con > 3 || flag == false) key = false;
    V.push_back(con);
	vector <int> :: iterator it = V.begin();
	V.erase(it);
	it = V.end();
	it--;
	V.erase(it);
    int Size = (int)V.size();
    for(int i = 0; i < Size; i++)
        if(V[i] > 3) V[i] = 3;
        else V[i] = 1;
    if(!key) printf("NO\n");
    else {
        printf("YES\n");
        con = 0;
		flag = false;
        int pos = 0;
        for(int i = 0; i < len; i++) {
            printf("%c", str[i]);
            if(flag) con++;
            if(str[i] == '.') flag = true;
            if(pos < Size && con == V[pos]) {
                flag = false;
                pos++;
				con = 0;
                printf("\n");
            }
        }
		puts("");
    }
    return 0;
}
