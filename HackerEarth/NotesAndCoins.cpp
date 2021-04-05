/****************************************************
*   Template for coding contests                    *
*   Author    :    Sanjeev Sharma                   *
*   Email     :    thedevelopersanjeev@gmail.com    *
*****************************************************/

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    string s;
    int amount;
    cin >>t;
    vector<int> c, n;
    while(t--){
        cin >>s >>amount;
        if(s == "Coin")
            c.push_back(amount);
        else
            n.push_back(amount);
    }
    cout <<"Coins :\n";
    for(auto ele : c)
        cout <<ele <<"\n";
    cout <<"Notes :\n";
    for(auto ele : n)
        cout <<ele <<"\n";
    return 0;
}