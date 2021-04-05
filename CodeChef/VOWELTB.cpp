#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	char c;
	cin >>c;
	string x = "AEIOU";
	if(x.find(c) != string::npos)
		cout <<"Vowel\n";
	else
		cout <<"Consonant\n";
	return 0;
}