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
    int t;
    string s;
    cin >>t;
    while(t--){
        cin >>s;
        int n = s.size();
        map<char, int> freq;
        for(int i = 0; i < n; i++)
            freq[s[i]]++;
        bool flag = false;
        for(auto ele : freq)
            if(ele.second > 1)
                flag = true;
        if(flag)
            cout <<"yes\n";
        else
            cout <<"no\n";
    }
    return 0;
}