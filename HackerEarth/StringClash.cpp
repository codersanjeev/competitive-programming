#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s, t;
    cin >>s >>t;
    map<char, int> sfreq;
    for(int i = 0; i < s.size(); i++)
        sfreq[s[i]]++;
    for(int i = 0; i < t.size(); i++)
        sfreq[t[i]]++;
    int ans = 0;
    bool flag = 0;
    for(int i = 0; i < sfreq.size(); i++){
        ans += sfreq[i] - (sfreq[i]%2);
        if(sfreq[i]%2)
            flag = 1;
    }
    cout <<ans + flag;
    return 0;
}