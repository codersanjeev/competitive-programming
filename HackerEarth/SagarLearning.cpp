#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    long long n;
    cin >>t;
    while(t--){
        cin >>n;
        if(n/3 == 0){
            cout <<"-1" <<endl;
        }
        else{
            cout <<(n/3) <<" " <<(n/3 * 2) <<" " <<(n/3 * 3) <<endl;
        }
    }
    return 0;
}