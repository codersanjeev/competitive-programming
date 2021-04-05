#include<bits/stdc++.h>
using namespace std;

int main(){
    int s, n, r, last_max, ans;
    cin >>s;
    while(s--){
        ans = 0;
        cin >>n >>r;
        long long arr[n];
        for(int i=0; i<n; i++){
            cin >>arr[i];
        }
        last_max = arr[0];
        ans = 1;
        if(n == 1){
            cout <<1*r <<endl;
            break;
        }
        for(int i=1; i<n; i++){
            if(arr[i] > last_max){
                ans++;
                last_max = arr[i];
            }
        }
        cout <<ans*r <<endl;
    }
}