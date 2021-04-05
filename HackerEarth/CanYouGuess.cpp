#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(false);
    cout.tie(false);
    int q, n;
    cin >>q;
    while(q--){
        int ans = 0;
        cin >>n;
        for(int i = 1; i < n; i++){
            if(n%i == 0){
                ans += i;
            }
        }
        cout <<ans <<endl;
    }
    return 0;
}