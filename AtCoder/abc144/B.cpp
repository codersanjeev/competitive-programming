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
    int n;
    cin >>n;
    bool flag = false;
    for(int i = 1; i < 10; i++){
        for(int j = i; j < 10; j++){
            if((i * j) == n){
                flag = true;
                break;
            }
        }
    }
    if(flag)
        cout <<"Yes";
    else 
        cout <<"No";
    return 0;
}
