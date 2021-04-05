/**
 * Template for Contests
 *
 *  @author Sanjeev
 */
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    string s;
    cin >>n >>s;
    if(s.find('a') != string::npos && 
    s.find('e') != string::npos &&
    s.find('i') != string::npos &&
    s.find('o') != string::npos &&
    s.find('u') != string::npos)
        cout <<"YES\n";
    else
        cout <<"NO\n";
	return 0;
}