#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<fstream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<deque>
#include<queue>
#include<stack>

using namespace std;

typedef long long LL;

char c[7][233] = {"qwertyuiop", "asdfghjkl;", "zxcvbnm,./"};

char s[2333];

int main(){
	char C;
	scanf("%c", &C);
	int lr = C == 'R'? -1: 1;
	scanf("%s", s);
	for (int i = 0; s[i] != '\0'; ++i){
		bool flag = 0;
		for (int j = 0; j<3 && !flag; ++j)
			for (int k = 0; k<10 && !flag; ++k)
				if (c[j][k] == s[i]){
					flag = 1;
					printf("%c", c[j][k + lr]);
				}
	}
	printf("\n");
	return 0;
}
