#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >>s;
    map<char, int> freq;
    for(int i = 0; i < s.size(); i++)
        freq[s[i]]++;
    int count = 0;
    for(auto ele : freq){
        if(ele.second > 1){
            count = count + (ele.second-1);
        }
    }
    cout <<count <<endl;
    return 0;
}