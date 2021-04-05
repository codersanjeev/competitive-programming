#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, x, y, ele;
    bool flag = true;
    cin >>n >>x >>y;
    while(n--){
        cin >>ele;
        if(ele < x || ele > y){
            flag = false;
            break;
        }
    }
    if(flag){
        cout <<"YES" <<endl;
    }
    else{
        cout <<"NO" <<endl;
    }
    return 0;
}