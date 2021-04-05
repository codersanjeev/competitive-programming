#include<bits/stdc++.h>
using namespace std;

int arr[123];
int n;

int count(){
    int ones = 0, ret = 0;
    for(int i=0; i<n; i++){
        if(arr[i] == 1){
            ones++;
        }
        else{
            ones = 0;
        }
        ret = max(ret, ones);
    }    
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >>n;
    for(int i=0; i<n; i++)
        cin >>arr[i];
    int ans = count();
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            swap(arr[i], arr[j]);
            ans = max(ans, count());
            swap(arr[i], arr[j]);
        }
    }
    cout <<ans;
    return 0;
}