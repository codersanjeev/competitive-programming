/**
 * Template for Contests
 *
 *  @author Sanjeev
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    string s;
    cin >>n;
    int ans = 0;
    while(n--){
        cin >>s;
        int size = s.size();
        if(size >= 2 && (s.find("ch") != string::npos || s.find("ef") != string::npos) || s.find("he") != string::npos)
            ans++;
    }
    cout <<ans <<"\n";
    return 0;
}